#include "system.h"
#include "DMA_Class.h"
#include "dma_port_ch_misc.hpp"

struct DMA_PORT_CH_cl *DMA_RX_DESC;
struct DMA_PORT_CH_cl *DMA_RX_DATA;
struct DMA_PORT_CH_cl *DMA_TX_DESC;
struct DMA_PORT_CH_cl *DMA_TX_DATA;

void assign_dma_rx_desc(struct DMA_PORT_CH_cl *ptr)
{
	DMA_RX_DESC = ptr;
}

void assign_dma_rx_data(struct DMA_PORT_CH_cl *ptr)
{
	DMA_RX_DATA = ptr;
}

void assign_dma_tx_desc(struct DMA_PORT_CH_cl *ptr)
{
	DMA_TX_DESC = ptr;
}

void assign_dma_tx_data(struct DMA_PORT_CH_cl *ptr)
{
	DMA_TX_DATA = ptr;
}

int configure_wn(struct DMA_PORT_CH_cl *CHANNEL, void * Addr, unsigned int Size, int wn, int int_en){
  int Size_cor;
  if ((Size & 0x7) != 0) Size_cor = Size + 0x8; // correct block if Size not divisible on 64
  else                   Size_cor = Size;
  CHANNEL->REGS->CSR = DMA_PORT_CH_CSR_WN(wn) | DMA_PORT_CH_CSR_WCX((Size_cor>>3)-1) | DMA_PORT_CH_CSR_IM(int_en) ;
  //CHANNEL->REGS->IR  = vaddr_to_paddr((lp_uintptr_t*)Addr);
  CHANNEL->REGS->IR  = sys_kernel_va_to_pa((unsigned int)Addr);
  CHANNEL->REGS->CP  = 0;
  return 1;
}

int is_run(struct DMA_PORT_CH_cl *CHANNEL){
          // return true if DMA channel MemChPtr is running
 return CHANNEL->REGS->CSR & (DMA_PORT_CH_CSR_RUN(1));
}

int wait_not_run(struct DMA_PORT_CH_cl *CHANNEL){
  // Wait until MemChPtr is running
  while (is_run(CHANNEL));
  return 1;
}

int start(struct DMA_PORT_CH_cl *CHANNEL){
  CHANNEL->REGS->RUN = DMA_PORT_CH_CSR_RUN(1);
  return 1;
}

int start_wn(struct DMA_PORT_CH_cl *CHANNEL, void * Addr, unsigned int Size, int wn){
  configure_wn(CHANNEL, Addr, Size, wn, 0);
  return start(CHANNEL);
}

unsigned int get_raw_addr(struct DMA_PORT_CH_cl *CHANNEL) {
  return CHANNEL->REGS->IR;
}
