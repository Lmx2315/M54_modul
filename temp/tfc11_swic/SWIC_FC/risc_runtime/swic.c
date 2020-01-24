// ***************** simple_time.с ***********************************
//                 Risc-Dsp runtime library
//
// This file implements interface to SpaceWire
//
// (c) multicore.ru
//
// *******************************************************************
#include "swic.h"
#include "system.h"
#include "erlcommon.h"
#include "mc30sf.h"
#include "risc_interrupt.h"

#define XTIclk 5  //Mhz

unsigned int txDescr[2]__attribute__ ((aligned(8))) = {0,};

void ClearSwic(int id)
{
  MODE_CR(id)    =   0x021;
  TX_SPEED(id)   =   0x300;
  CNT_RX_PACK(id) =   0;
  CSR_SWIC_TX_DAT(id) = 0;
  CSR_SWIC_TX_DES(id) = 0;
  CSR_SWIC_RX_DAT(id) = 0;
  CSR_SWIC_RX_DES(id) = 0;
}

void InitSwic(int id)
{
  //TX_SPEED(id)   =   0x302;
  //MODE_CR(id)    =   0x06 | 0x1C0000;
  MODE_CR(id)    =   0x06;
}

int IsConnected(int id)
{
  if((STATUS(id) & 0x30F0) == 0x30A0) return 1;
  else return 0;
}

void SetSwicSpeed(int id, int speed)
{
  if (speed < 5  || speed > 1275) return;
  unsigned int tx_speed = speed/XTIclk;
  TX_SPEED(id)   =   0x300 | tx_speed;
}

enum ERL_ERROR swic_send_packet(int id, void * src, int size, int type)
{
  txDescr[0] = 0;
  txDescr[1] = id; // & number port

  txDescr[0] = 0x80000000 + size + (type<<29);
  unsigned int wsize = size >> 3;

  // Prepare SWIC DMA channels
  IR_SWIC_TX_DES(id) = sys_kernel_va_to_pa((unsigned)txDescr);
  IR_SWIC_TX_DAT(id) = sys_kernel_va_to_pa((unsigned)src);
  CSR_SWIC_TX_DAT(id) = ((wsize-1) << 16);

  // Run transfer
  CSR_SWIC_TX_DES(id) = 1;
  CSR_SWIC_TX_DAT(id) |= 1;
  return ERL_NO_ERROR;
}

enum ERL_ERROR swic_receiver_wait(int id)
{
  // waiting for receiving descriptor
  unsigned int param = get_cpu_clock();
  param *= 5;
  asm volatile ("mtc0 %0, $11" : : "r"(param));
  param= 0;
  asm volatile ("mtc0 %0, $9" : : "r"(param));
  risc_enable_interrupt(RISC_COMPARE);

  while(1)
  {
    int is_run = RUN_SWIC_RX_DES(id)&0x1;
    if (!is_run) break;
  }
  risc_disable_interrupt(RISC_COMPARE);
  return ERL_NO_ERROR;
}

enum ERL_ERROR swic_receiver_run(int id, void * dst, unsigned int *descr, int size)
{
  descr[0] = 0;
  descr[1] = 0;
  IR_SWIC_RX_DAT(id) = sys_kernel_va_to_pa((unsigned)dst);
  CSR_SWIC_RX_DAT(id) = (size<<16);
  //CSR_SWIC_RX_DAT(id) = (0xFFFF<<16);
  IR_SWIC_RX_DES(id) = sys_kernel_va_to_pa((unsigned)descr);
  CSR_SWIC_RX_DES(id) = 1;
  CSR_SWIC_RX_DAT(id) |= 1;
  return ERL_NO_ERROR;
}

enum ERL_ERROR swic_receive_packet(unsigned int *dst, int *len)
{
  unsigned int rxDescr[2]__attribute__ ((aligned(8))) = {0, 0};
  IR_SWIC_RX_DES0 = sys_kernel_va_to_pa((unsigned) rxDescr);
  IR_SWIC_RX_DAT0 = sys_kernel_va_to_pa((unsigned) dst);
  CSR_SWIC_RX_DES0 = 1; // прием одного дескриптора (пакета)
  CSR_SWIC_RX_DAT0 = (0xffff<<16) | 1;
  while (RUN_SWIC_RX_DES0&1) ;
  *len = rxDescr[0] & 0xFFFFFFF;
  if ( (rxDescr[0]&0xF0000000) != 0xA0000000 )
  {
    return ERL_SYSTEM_ERROR;
  }
  else
  {
    return ERL_NO_ERROR;
  }
}