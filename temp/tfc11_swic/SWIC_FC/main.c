#include <stdbool.h>
#include "risc_runtime/mc30sf.h"
#include "risc_runtime/swic.h"
#include "risc_runtime/risc_interrupt.h"
#include "risc_runtime/system.h"
#include "gigaspwr_reg_fields.hpp"
#include "gigaspwr_misc.hpp"
#include "Convert.h"
#include "DMA_Class.h"

#define GIGASPWR_cl void

unsigned int main_scale = 0x00000036;
//unsigned int SEED = 0x1e2279a0e;
unsigned int PLL_CTR = 0x00000000;
unsigned int ERR_PARAM = 0x00000001;
unsigned int SPEED = 0x00000000;
unsigned int PRINT_EN = 0x00000001;
unsigned int REPORT_EN = 0x00000001;
unsigned int TX_DATA_LENGTH = 0x00001024;
unsigned int SPW_SPEED_MIN = 0x00000010;
unsigned int SPW_SPEED_STEP = 0x00000010;
unsigned int SPW_SPEED_MAX = 0x00000200;
unsigned int GSPW_SPEED_SCALE = 0x00000005;
unsigned int SPW_SPEC_CABLE_PORTS = 0x00000003;


// ����� ������� � 32-��������� ������
#define ARRAY_LEN 1000

unsigned int Flag_Timeout = 0;
unsigned int Flag_Corr = 1; // ���� ������������ ������ ����� (0 - ���������, 1 - �� ���������)
unsigned int Flag_Disconnect = 0;

volatile unsigned int SWIC_Speed = 0x00000010;
unsigned  int speed;
unsigned  int SWIC_Number = 5;
int errors=0;

unsigned int OutputArray[ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};
unsigned int InputArray[ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};

void report_high(const char * str)
{

}

volatile struct GIGASPWR_REGS_BASE * REGS = (volatile struct GIGASPWR_REGS_BASE *) 0xB82FA000;
volatile struct GIGASPWR_PMA_TEST_CSR_BASE * PMA_TEST_CSR = (volatile struct GIGASPWR_PMA_TEST_CSR_BASE *) 0xB82FA200;
volatile unsigned int * ROUTING_TABLE = (volatile unsigned int *)0xB82FA400;


void unmask_irq(unsigned int mask) {
  REGS->RISC_IRQ_MASK &= ~mask;
}

void form_routing_table(bool del_header) {
  unsigned int i;
  for ( i=0; i < 16; i++)
    ROUTING_TABLE[i] = (((unsigned int)1 << i) & 0x7f) | 0x080 | ((del_header & 1) << 8);
}

void gspwr_form_adg() {
  report_high("form adg");
  int i;
  for (i = 0; i < 6; i++)
    REGS->ADG[i] = ((unsigned int)2 << i) ;
}

void set_transmit_speed(unsigned int port, int speed, bool pll_en) {
  unsigned int tx_speed;
  switch (port) {
    case port_spw0:
    case port_spw1:
      if (speed == 0)
            speed = GET_GIGASPWR_SPW_TX_SPEED_TX_SPEED(REGS->SPW_TX_SPEED[port]);
      else if (speed >= 5)
            speed = speed / 5;
      if (pll_en)
            speed |= 0x300;
      else
            speed &= ~0x300;
      tx_speed = REGS->SPW_TX_SPEED[port];
          tx_speed = SET_GIGASPWR_SPW_TX_SPEED_TX_SPEED(tx_speed, speed);
      tx_speed = SET_GIGASPWR_SPW_TX_SPEED_TX_SPEED10(tx_speed, speed);
      REGS->SPW_TX_SPEED[port] = tx_speed;
      break;
    case port_gigaspw0:
    case port_gigaspw1:
    case port_gigaspw2:
    case port_gigaspw3:
      if (speed > 0)
        REGS->GIGA_SPW_PMA_MODE[port - port_gigaspw0] = SET_GIGASPWR_GIGA_SPW_PMA_MODE_PMA_TX_SPEED(REGS->GIGA_SPW_PMA_MODE[port - port_gigaspw0], speed);

              tx_speed = REGS->GIGA_SPW_PMA_MODE[port - port_gigaspw0];
              tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_CDR_MODE(tx_speed, 1);
//               tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_RX(tx_speed, 1);
//               tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_TX(tx_speed, 1);
              REGS->GIGA_SPW_PMA_MODE[port - port_gigaspw0] = tx_speed;

      tx_speed = REGS->GIGA_SPW_TX_SPEED[port - port_gigaspw0];
      if (speed < gigasw_speed_312_mhz)
        tx_speed = SET_GIGASPWR_GIGA_SPW_TX_SPEED_KOEFF_COMMA(tx_speed, 1);
      else
        tx_speed = SET_GIGASPWR_GIGA_SPW_TX_SPEED_KOEFF_COMMA(tx_speed, 8);

      tx_speed = SET_GIGASPWR_GIGA_SPW_TX_SPEED_DISCONNECT_COUNTER(tx_speed, 0xf);

      tx_speed = SET_GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_TX(tx_speed, pll_en);
      tx_speed = SET_GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_RX(tx_speed, pll_en);
      tx_speed = SET_GIGASPWR_GIGA_SPW_TX_SPEED_COMMAEN(tx_speed, pll_en);
      tx_speed = SET_GIGASPWR_GIGA_SPW_TX_SPEED_COMPARE_EN(tx_speed, pll_en);
      REGS->GIGA_SPW_TX_SPEED[port - port_gigaspw0] = tx_speed;
      break;
  }
}

//void GIGASPWR_cl::set_recive_speed(unsigned int port, int speed) {
void set_recive_speed(unsigned int port, int speed) {
  switch (port) {
    case port_gigaspw0:
    case port_gigaspw1:
    case port_gigaspw2:
    case port_gigaspw3:
      if (speed > 0)
        REGS->GIGA_SPW_PMA_MODE[port - port_gigaspw0] = SET_GIGASPWR_GIGA_SPW_PMA_MODE_PMA_RX_SPEED(REGS->GIGA_SPW_PMA_MODE[port - port_gigaspw0], speed);
      break;
  }
}

//void GIGASPWR_cl::make_desc(unsigned int *desc_src, int data_len, int route) {
void make_desc(unsigned int *desc_src, int data_len, int route) {
  desc_src[0] = 0xA0000000 + (data_len & 0x0fffffff);
  desc_src[1] = route;
}

//void GIGASPWR_cl::set_dma_enabled(bool dma_en) {
void set_dma_enabled(bool dma_en) {
  REGS->MODE_R = SET_GIGASPWR_MODE_R_DMA_ENABLED(REGS->MODE_R, dma_en);
}

//void GIGASPWR_cl::set_work_enabled(bool work_en) {
void set_work_enabled(bool work_en) {
  REGS->MODE_R = SET_GIGASPWR_MODE_R_MAIN_KOEFF10(REGS->MODE_R, 0xb);
  REGS->MODE_R = SET_GIGASPWR_MODE_R_GIGASPWR_WE(REGS->MODE_R, work_en);
}

//void GIGASPWR_cl::start_connect(unsigned int port) {
void start_connect(unsigned int port) {
  unsigned int spw_mode;

  if (port > port_max_numb)
    return;

  spw_mode = REGS->SPW_MODE[port];
  spw_mode = SET_GIGASPWR_SPW_MODE_LINKSTART(spw_mode, 1);
//   spw_mode = SET_GIGASPWR_SPW_MODE_AUTO_SPEED_MODE(spw_mode, 1);
  spw_mode = SET_GIGASPWR_SPW_MODE_LINKDISABLED(spw_mode, 0);
  spw_mode = SET_GIGASPWR_SPW_MODE_BDS_RESET(spw_mode, 1);
  spw_mode = SET_GIGASPWR_SPW_MODE_AUTOSTART(spw_mode, 1);
  spw_mode = SET_GIGASPWR_SPW_MODE_D_INT_ACK_REGIMES(spw_mode, 0);
  spw_mode = SET_GIGASPWR_SPW_MODE_INT_CODES(spw_mode, 0);
  spw_mode = SET_GIGASPWR_SPW_MODE_ACK_CODES(spw_mode, 0);

  REGS->SPW_MODE[port] = spw_mode;
}

//unsigned int GIGASPWR_cl::get_status(unsigned int port, bool print) {
unsigned int get_status(unsigned int port, bool print) {
  unsigned int ds_state;

  if (port > port_max_numb)
    return 0xFFFFFFFF;

  ds_state = GET_GIGASPWR_SPW_STATUS_BDS_STATE(REGS->SPW_STATUS[port]);

  if (print) {
    switch (ds_state) {
      case link_status_err_reset:
        report_high("Error Reset");
        break;
      case link_status_err_wait:
        report_high("Error Wait");
        break;
      case link_status_ready:
        report_high("Ready");
        break;
      case link_status_started:
        report_high("Started");
        break;
      case link_status_connecting:
        report_high("Connecting");
        break;
      case link_status_run:
        report_high("Run");
        break;
      default:
        report_high("Unknown Status");
    }
  }
  return ds_state;
}


//int GIGASPWR_cl::wait_link_status(unsigned int port, unsigned int status, unsigned int timeout) {
int wait_link_status(unsigned int port, unsigned int status, unsigned int timeout) {
  unsigned int t = 0;
  //while (this->get_status(port, false) != status) {
  while (get_status(port, false) != status) {
    if ((++t >= timeout) && (timeout != 0)) {
      report_high("timeout reached");
      return 1;
    }
  }
  return 0;
}

//unsigned int GIGASPWR_cl::get_rx_speed(unsigned int port) {
unsigned int get_rx_speed(unsigned int port) {
  return REGS->SPW_RX_SPEED[port];
}

//,==== SpW_bridge_mcom02 - ���� ��� ������������ ������ �� ������ Space Wire �� ������� ���������� (mcom02) ====
unsigned int check_SpW_link_status_run(GIGASPWR_cl* gigaspwr, unsigned int SpW_port_n) {
  //unsigned int cur_link_status = gigaspwr->get_status(SpW_port_n, false);
  unsigned int cur_link_status = get_status(SpW_port_n, false);
  if (cur_link_status != link_status_run) {
    //report_error("Error link_status_run [SpW_port_n / cur_link_status]:");
    //print_val(SpW_port_n);
    //print_val(cur_link_status);
    return 1;
  }
  return 0;
}

void turn_off(unsigned int port){
  unsigned int spw_mode;

  if (port > port_max_numb)
    return;

  spw_mode = REGS->SPW_MODE[port];
  spw_mode = SET_GIGASPWR_SPW_MODE_LINKSTART(spw_mode, 0);
  spw_mode = SET_GIGASPWR_SPW_MODE_LINKDISABLED(spw_mode, 1);
  spw_mode = SET_GIGASPWR_SPW_MODE_BDS_RESET(spw_mode, 1);
  REGS->SPW_MODE[port] = spw_mode;

  spw_mode = REGS->STATE_R;
  spw_mode = SET_GIGASPWR_STATE_R_PORT_CONNECTED(spw_mode, 0x3f);
  spw_mode = SET_GIGASPWR_STATE_R_PORT_ERRORED(spw_mode, 0x3f);
  REGS->STATE_R = spw_mode;

  set_transmit_speed(port, 0, false);
  set_dma_enabled(false);
  set_work_enabled(false);
}


void FillArray(unsigned int *array, unsigned int len, int first) {
        unsigned int i;
        array[0] = 0; // Always config
        for (i=1;i<len;i++) {
                array[i] = i-1+first;
        }
}

int VerifyArray(unsigned int *array, unsigned int len, int first) {
        unsigned int i;
        if (array[0] != 0) return 0;
        for (i=1;i<len;i++) {
                if(array[i] != i-1+first) return 0;
        }
        return 1;
}

void timer_hnlr(int a)
{
  Flag_Timeout = 1;
  unsigned int param= 0;
  asm volatile ("mtc0 %0, $11" : : "r"(param));
  asm volatile ("nop");
  asm volatile ("break 0x0, 0x1");
  asm volatile ("nop");
}

void dc_hnlr(int a)
{
  Flag_Disconnect = 1;
  asm volatile ("nop");
  asm volatile("break 0x0, 0x1");
  asm volatile ("nop");
}

void main()
{
  risc_set_interrupts_vector(INTH_80000180);
  SYS_CSR |= 2;

  risc_register_interrupt(timer_hnlr, RISC_COMPARE);
  // �������� ��� ���������� �� gsw
  assign_dma_rx_desc((struct DMA_PORT_CH_cl *) 0xb82fa800);
  assign_dma_rx_data((struct DMA_PORT_CH_cl *) 0xb82fa840);
  assign_dma_tx_desc((struct DMA_PORT_CH_cl *) 0xb82fa880);
  assign_dma_tx_data((struct DMA_PORT_CH_cl *) 0xb82fa8C0);

  // ��������� ������� ������� ��� ��������
  unsigned int param = get_cpu_clock();
  param *= 5;
  asm volatile ("mtc0 %0, $11" : : "r"(param));
  param= 0;
  asm volatile ("mtc0 %0, $9" : : "r"(param));

  risc_enable_interrupt(RISC_COMPARE);

  int transmitter, receiver;
  transmitter = 0;
  receiver = 1;
  //SWIC_Speed = SPW_SPEED_MIN;

  // ���������� ����������
  // cable_test_start
  unmask_irq(gigaspwr_irq_all);
  form_routing_table(false);
  gspwr_form_adg();
  set_transmit_speed(port_spw0, 5, true);
  set_transmit_speed(port_spw1, 5, true);
     set_recive_speed(port_gigaspw2, gigasw_speed_125_mhz);
     set_transmit_speed(port_gigaspw3, gigasw_speed_125_mhz, true);
     set_recive_speed(port_gigaspw3, gigasw_speed_125_mhz);
     set_transmit_speed(port_gigaspw2, gigasw_speed_125_mhz, true);
  REGS->SPW_MODE[port_gigaspw2] = SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(REGS->SPW_MODE[port_gigaspw2], 1);
  REGS->SPW_MODE[port_gigaspw3] = SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(REGS->SPW_MODE[port_gigaspw3], 1);

  /*
  // ��� ������ �� ������� ���������
  memory_agent.fill_mem_block_rand(TX_Data, TX_DATA_LENGTH << 1, rand()); // ��������� ������ (��?)
  TX_Data[0] = 0;                        // always to conf port           // ?
  TX_Data[TX_DATA_LENGTH >> 2] = 0;        // always to conf port         // � ������?


  make_desc(TX_Desc, TX_DATA_LENGTH, route_mask_spw0);
  make_desc(&TX_Desc[2], TX_DATA_LENGTH, route_mask_spw1);
  */
  set_dma_enabled(true);
  set_work_enabled(true);

  start_connect(port_spw0);
  start_connect(port_spw1);
     start_connect(port_gigaspw2);
     start_connect(port_gigaspw3);
  // �������� ����������
  int port_i;
  for (port_i = port_spw0; port_i <= port_spw1; port_i++)
     if (SPW_SPEC_CABLE_PORTS & (1 << port_i))
        {
	wait_link_status(port_i, link_status_run, 0);
        }
  speed = SWIC_Speed;
  //,# ��� Spw ������� �� ������� ��������
  // �������� �������� ������������� ���� ���
  for (port_i = port_spw0; port_i <= port_spw1; port_i++)
      if (SPW_SPEC_CABLE_PORTS & (1 << port_i))
          set_transmit_speed(port_i, speed, true);

  //,# �������� ������� PLL
  for (port_i = port_spw0; port_i <= port_spw1; port_i++)
       if (SPW_SPEC_CABLE_PORTS & (1 << port_i)) {
         while (get_rx_speed(port_i) < speed - 3);
         //,# ��������, ��� ���������� �� �����������
         errors += check_SpW_link_status_run((GIGASPWR_cl*)0, port_i);
       }
  if (errors)
      {
      Flag_Corr = 1; // ���������� �����������
      asm volatile("break 0x0, 0x1");
      }


  // cable_test_end

  risc_disable_interrupt(RISC_COMPARE);

  int size = ARRAY_LEN*sizeof(int);
  int i=0;
  int corr_counter = 0;


  unsigned int descr[2]__attribute__ ((aligned(8))) = {0};

  int l_port;
  for (i=0; i<SWIC_Number; i++)
  {
      swic_receiver_run(receiver, InputArray, descr, 0xFFFF);    // +
      FillArray(OutputArray,ARRAY_LEN,i);                        // +
      if (transmitter)
          l_port = route_mask_spw1;
      else
          l_port = route_mask_spw0;
      swic_send_packet(l_port, OutputArray, size, 1);            // +
      swic_receiver_wait(receiver);                              // + // - port check?
      corr_counter += VerifyArray(InputArray,ARRAY_LEN,i);       // +
      transmitter ^= 1;
      receiver ^= 1;
  }

  if (corr_counter == SWIC_Number) Flag_Corr = 0;
  asm volatile("break 0x0, 0x1");
}

