#define SPEC_CABLE_SPW0_MASK        1
#define SPEC_CABLE_SPW1_MASK        2

#include "gigaspwr_reg_fields.hpp"

#define GIGASPWR_cl void

unsigned int SPW_SPEC_CABLE_PORTS = 0x00000003;
unsigned int SPW_SPEED_MIN = 0x00000010;
unsigned int SPW_SPEED_STEP = 0x00000010;

void report_high(const char * str)
{
	//
}

struct GIGASPWR_REGS_BASE {
		volatile unsigned int ID_VER;
		volatile unsigned int ID_SWITCH;
		volatile unsigned int ID_NET;
		volatile unsigned int MODE_R;
		volatile unsigned int MODE_R1;
		volatile unsigned int STATE_R;
		volatile unsigned int RISC_IRQ_MASK;
		volatile unsigned int AUTO_COU;
		volatile unsigned int CONTROL_CONNECTION;
		volatile unsigned int STATE_CONNECTION;
		volatile unsigned int SW_DAT_TOUTS;
		volatile unsigned int SW_DAT_TOUTS2;
		volatile unsigned int SW_DAT_TOUTS3;
		volatile unsigned int SPEC_ARB;
		volatile unsigned int CCODE_OUT;
		volatile unsigned int CUR_TIME;
		volatile unsigned int ISR_L;
		volatile unsigned int ISR_H;
		volatile unsigned int INTR_IRQ_MASK_L;
		volatile unsigned int INTR_IRQ_MASK_H;
		volatile unsigned int INTA_IRQ_MASK_L;
		volatile unsigned int INTA_IRQ_MASK_H;
		volatile unsigned int CCODES_MASK1;
		volatile unsigned int CCODES_MASK2;
		volatile unsigned int DIST_INTS_TOUTS1;
		volatile unsigned int DIST_INTS_TOUTS2;
		volatile unsigned int ACK_NON_ACK_REGIME;
		volatile unsigned int CCODES_SPEC_REGIME;
		volatile unsigned int SPEC_ISR_REGIME;
		volatile unsigned int INTER_HANDLER_TERM_FUNCT;
		volatile unsigned int ISR_SOURCE_TERM_FUNCT;
		volatile unsigned int ISR_TOUTS_FLS_L;
		volatile unsigned int ISR_TOUTS_FLS_H;
		volatile unsigned int ISR_1101;
		volatile unsigned int EXTERNAL_RESET_PARAMETERS;
		volatile unsigned int SPW_STATUS[6];
		volatile unsigned int SPW_MODE[6];
		volatile unsigned int SPW_TX_SPEED[2];
		volatile unsigned int GIGA_SPW_TX_SPEED[4];
		volatile unsigned int SPW_RX_SPEED[6];
		volatile unsigned int ADG[6];
		volatile unsigned int GIGA_PMA_STATUS[4];
		volatile unsigned int GIGA_SPW_PMA_MODE[4];
};

struct GIGASPWR_PMA_TEST_CSR_BASE {
		volatile unsigned int TX_PMA_CTR;
		volatile unsigned int RX_PMA_CTR;
		volatile unsigned int TX_IDLE_CTR;
		volatile unsigned char RESERVED0[4];
		volatile unsigned int CMD_COUNTER;
		volatile unsigned int DATA_COUNTER;
		volatile unsigned int ERR_COUNTER;
		volatile unsigned int RX_BUF_STATE;
		volatile unsigned int MODE;
		volatile unsigned int RX_STATE;
};

volatile struct GIGASPWR_REGS_BASE * REGS = (volatile struct GIGASPWR_REGS_BASE *) 0xB82FA000;
volatile struct GIGASPWR_PMA_TEST_CSR_BASE * PMA_TEST_CSR = (volatile struct GIGASPWR_PMA_TEST_CSR_BASE *) 0xB82FA200;
volatile unsigned int * ROUTING_TABLE = (volatile unsigned int *)0xB82FA400;


void unmask_irq(unsigned int mask) {
  REGS->RISC_IRQ_MASK &= ~mask;
}

void form_routing_table(bool del_header) {
  for (unsigned int i=0; i < 16; i++)
    ROUTING_TABLE[i] = (((unsigned int)1 << i) & 0x7f) | 0x080 | ((del_header & 1) << 8);
}

void gspwr_form_adg() {
  report_high("form adg");
  for (int i = 0; i < 6; i++)
    //SYSTEM.GIGASPWR[0].REGS->ADG[i] = ((unsigned int)2 << i) ;
    REGS->ADG[i] = ((unsigned int)2 << i) ;
}

// void GIGASPWR_cl::set_transmit_speed(unsigned int port, int speed, bool pll_en) {
// 
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
// 	      tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_RX(tx_speed, 1);
// 	      tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_TX(tx_speed, 1);
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

//void GIGASPWR_cl::set_transmit_speed(unsigned int port, int speed, bool pll_en) {
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
// 	      tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_RX(tx_speed, 1);
// 	      tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_TX(tx_speed, 1);
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

//unsigned int GIGASPWR_cl::get_rx_speed(unsigned int port) {
unsigned int get_rx_speed(unsigned int port) {
  return REGS->SPW_RX_SPEED[port];
}

//,==== SpW_bridge_mcom02 - Мост для ретрансляции данных на портах Space Wire от другого устройства (mcom02) ====
unsigned int check_SpW_link_status_run(GIGASPWR_cl* gigaspwr, unsigned int SpW_port_n) {
  //unsigned int cur_link_status = gigaspwr->get_status(SpW_port_n, false);
  unsigned int cur_link_status = get_status(SpW_port_n, false);
  if (cur_link_status != link_status_run) {
    report_error("Error link_status_run [SpW_port_n / cur_link_status]:");
    print_val(SpW_port_n);
    print_val(cur_link_status);
    return 1;
  }
  return 0;
}

//void GIGASPWR_cl::turn_off(unsigned int port){
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

int SpW_spec_cable_test() {
   unsigned int errors = 0;
   
   //GIGASPWR_cl* gigaspwr = &SYSTEM.GIGASPWR[0];
   GIGASPWR_cl* gigaspwr = NULL;     // что и куда - фактически указатель на область памяти

   report_high("SWIC spec cable test for 2 plates:");
//,# Отключение прерываний gigaSpWR
   //SYSTEM.GIGASPWR[0].unmask_irq(gigaspwr_irq_all); // должно быть что-то вроде: unmask_irq(unsigned int mask)
   unmask_irq(gigaspwr_irq_all);
   
//,# Заполнение таблицы маршрутизации
   report_high("form routing table");
   //SYSTEM.GIGASPWR[0].form_routing_table(false);    // должно быть что-то вроде: form_routing_table(false);
   form_routing_table(false);
   
   gspwr_form_adg();

   report_high("Set init speed");
//,# Выставление скорости и включение PLL:
//,#* Для Spw соединение происходит на пониженной скорости
    /*
     gigaspwr->set_transmit_speed(port_spw0, 5, true);
     gigaspwr->set_transmit_speed(port_spw1, 5, true);
          gigaspwr->set_recive_speed(port_gigaspw2, gigasw_speed_125_mhz);
          gigaspwr->set_transmit_speed(port_gigaspw3, gigasw_speed_125_mhz, true);
          gigaspwr->set_recive_speed(port_gigaspw3, gigasw_speed_125_mhz);
          gigaspwr->set_transmit_speed(port_gigaspw2, gigasw_speed_125_mhz, true);
    */
	 set_transmit_speed(port_spw0, 5, true);
     set_transmit_speed(port_spw1, 5, true);
          set_recive_speed(port_gigaspw2, gigasw_speed_125_mhz);
          set_transmit_speed(port_gigaspw3, gigasw_speed_125_mhz, true);
          set_recive_speed(port_gigaspw3, gigasw_speed_125_mhz);
          set_transmit_speed(port_gigaspw2, gigasw_speed_125_mhz, true);
    /*
          SYSTEM.GIGASPWR[0].REGS->SPW_MODE[port_gigaspw2] = SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(SYSTEM.GIGASPWR[0].REGS->SPW_MODE[port_gigaspw2], 1);
          SYSTEM.GIGASPWR[0].REGS->SPW_MODE[port_gigaspw3] = SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(SYSTEM.GIGASPWR[0].REGS->SPW_MODE[port_gigaspw3], 1);
    */
	      REGS->SPW_MODE[port_gigaspw2] = SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(REGS->SPW_MODE[port_gigaspw2], 1);
          REGS->SPW_MODE[port_gigaspw3] = SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(REGS->SPW_MODE[port_gigaspw3], 1);
    
   report_high("Init desc and data");
   memory_agent.fill_mem_block_rand(TX_Data, TX_DATA_LENGTH << 1, rand()); // генерация пакета (ов?)
   TX_Data[0] = 0;                        // always to conf port           // ? 
   TX_Data[TX_DATA_LENGTH >> 2] = 0;        // always to conf port         // в словах? 
   
   /*
   gigaspwr->make_desc(TX_Desc, TX_DATA_LENGTH, route_mask_spw0);
   gigaspwr->make_desc(&TX_Desc[2], TX_DATA_LENGTH, route_mask_spw1);
   */
   make_desc(TX_Desc, TX_DATA_LENGTH, route_mask_spw0);
   make_desc(&TX_Desc[2], TX_DATA_LENGTH, route_mask_spw1);
      
   report_high("DMA & work enable");
//,# Включение работы DMA
   //gigaspwr->set_dma_enabled(true);
   set_dma_enabled(true);
//,# Разрешение работы gigaSpWR
   //gigaspwr->set_work_enabled(true);
   set_work_enabled(true);

//,# Установка соедениния портов
   report_high("Start connect");
   /*
   gigaspwr->start_connect(port_spw0);
   gigaspwr->start_connect(port_spw1);
            gigaspwr->start_connect(port_gigaspw2);
            gigaspwr->start_connect(port_gigaspw3);
	*/		
   start_connect(port_spw0);
   start_connect(port_spw1);
            start_connect(port_gigaspw2);
            start_connect(port_gigaspw3);
	
//,# Ожидание соединения
   const char *connect_print_info[2] = {"port_spw0 ok", "port_spw1 ok"};
   report_high("Wait link status:");
   for (int port_i = port_spw0; port_i <= port_spw1; port_i++)
     if (SPW_SPEC_CABLE_PORTS & (1 << port_i)) {
       //gigaspwr->wait_link_status(port_i, link_status_run, 0);
	   wait_link_status(port_i, link_status_run, 0);
       report_high(connect_print_info[port_i]);
     }

   unsigned int speed = SPW_SPEED_MIN;
   while (1) {
     report_high("Set transmit speed");
//,# Для Spw переход на рабочую скорость
     for (int port_i = port_spw0; port_i <= port_spw1; port_i++)
       if (SPW_SPEC_CABLE_PORTS & (1 << port_i))
         //gigaspwr->set_transmit_speed(port_i, speed, true);
	     set_transmit_speed(port_i, speed, true);
     TX_Data[1] = speed;

//,# Ожидание разгона PLL
     const char *wait_pll_print_info[2] = {"wait spw0 pll", "wait spw1 pll"};
     for (int port_i = port_spw0; port_i <= port_spw1; port_i++)
       if (SPW_SPEC_CABLE_PORTS & (1 << port_i)) {
         report_high(wait_pll_print_info[port_i]);
         //while (gigaspwr->get_rx_speed(port_i) < speed - 3);
		 while (get_rx_speed(port_i) < speed - 3);
         //print_val_dec(gigaspwr->get_rx_speed(port_i));
		 print_val_dec(get_rx_speed(port_i));
//,# Проверка, что соединение не разорвалось
         errors += check_SpW_link_status_run(gigaspwr, port_i);
       }

     if (errors)
       return errors;

     while (1) {
       for (int port_i = port_spw0; port_i <= port_spw1; port_i++)
           if (SPW_SPEC_CABLE_PORTS & (1 << port_i)) {
           const char *spw_port_name_run[2] = {"port_spw0 start", "port_spw1 start"};
           report_high(spw_port_name_run[port_i]);

           if (REPORT_EN) report_high("DMA RX start");
           gigaspwr->DMA_RX_DATA->start_wn(RX_Data, TX_DATA_LENGTH << 1, 0xf); // Непонятна связь с существующими процедурами
           gigaspwr->DMA_RX_DESC->start_wn(RX_Desc, 8*2, 0xf);                 // -"-

           if (REPORT_EN) report_high("DMA TX 1 start");
           unsigned int tx_data_ind = (TX_DATA_LENGTH >> 2)*port_i;
           unsigned int tx_desc_ind = 2*port_i;
           gigaspwr->DMA_TX_DATA->start_wn(&TX_Data[tx_data_ind], TX_DATA_LENGTH, 0xf);
           gigaspwr->DMA_TX_DESC->start_wn(&TX_Desc[tx_desc_ind], 8, 0xf);

           if (REPORT_EN) report_high("DMA TX 1 wait [TX_DESC / TX_DATA]:");
           gigaspwr->DMA_TX_DESC->wait_not_run();                              // Что тут? ожидают запуска?
           if (REPORT_EN) report_high("ok");
           gigaspwr->DMA_TX_DATA->wait_not_run();
           if (REPORT_EN) report_high("ok");

           if (REPORT_EN) report_high("DMA RX wait 1 desc:");
           while (gigaspwr->DMA_RX_DESC->get_raw_addr() == (unsigned int)RX_Desc); // И тут непонятно...
           if (REPORT_EN) report_high("ok");

           if (REPORT_EN) report_high("DMA TX 2 start");
           gigaspwr->DMA_TX_DATA->start_wn(RX_Data, TX_DATA_LENGTH, 0xf);
           gigaspwr->DMA_TX_DESC->start_wn(&TX_Desc[tx_desc_ind], 8, 0xf);

           if (REPORT_EN) report_high("DMA TX 2 wait [TX_DESC / TX_DATA]:");
           gigaspwr->DMA_TX_DESC->wait_not_run();
           if (REPORT_EN) report_high("ok");
           gigaspwr->DMA_TX_DATA->wait_not_run();
           if (REPORT_EN) report_high("ok");

           if (REPORT_EN) report_high("DMA RX wait [RX_DATA / RX_DESC]:");
           gigaspwr->DMA_RX_DATA->wait_not_run();
           if (REPORT_EN) report_high("ok");
           gigaspwr->DMA_RX_DESC->wait_not_run();
           if (REPORT_EN) report_high("ok");

           if (memory_agent.compare_mem_blocks(&TX_Desc[tx_desc_ind], RX_Desc, 4)) { // сравнение дескрипторов
             report_error("Error RX 1 DESC check:");
             print_val(RX_Desc[0]);
             print_val(RX_Desc[1]);
             errors++;
           }
           if (memory_agent.compare_mem_blocks(&TX_Desc[tx_desc_ind], &RX_Desc[2], 4)) { // сравнение дескрипторов
             report_error("Error RX 2 DESC check:");
             print_val(RX_Desc[0]);
             print_val(RX_Desc[1]);
             errors++;
           }
           if (memory_agent.compare_mem_blocks(&TX_Data[tx_data_ind], &RX_Data[TX_DATA_LENGTH >> 2], TX_DATA_LENGTH)) { // Сравнение пакетов
             report_error("Error RX DATA check:");
             print_val(RX_Data[0]);
             print_val(RX_Data[1]);
             return errors;
           }

           errors += check_SpW_link_status_run(gigaspwr, port_i);
           unsigned int rx_speed = gigaspwr->get_rx_speed(port_i);
           if ((rx_speed < speed - 3) || (rx_speed > speed + 3)) {
             report_error("Error RX SPEED check:");
             print_val(rx_speed);
             print_val(speed);
             errors++;
           }

           if (errors)
             return errors;
           else
             report_high(connect_print_info[port_i]);
         }

       if (speed < SPW_SPEED_MAX) {
         speed += SPW_SPEED_STEP;
         if (speed > SPW_SPEED_MAX)
           speed = SPW_SPEED_MAX;
         report_high("Set new speed:");
         print_val_dec(speed);
         break;
       }
     }
   }

//,# Выключение портов gigaSpWR
   /*
   gigaspwr->turn_off(port_spw0);
   gigaspwr->turn_off(port_spw1);
          gigaspwr->turn_off(port_gigaspw2);
          gigaspwr->turn_off(port_gigaspw3);
          SYSTEM.GIGASPWR[0].REGS->SPW_STATUS[port_gigaspw2] = 0xffffffff;
          SYSTEM.GIGASPWR[0].REGS->SPW_STATUS[port_gigaspw3] = 0xffffffff;
          SYSTEM.GIGASPWR[0].REGS->SPW_STATUS[port_spw0] = 0xffffffff;
          SYSTEM.GIGASPWR[0].REGS->SPW_STATUS[port_spw1] = 0xffffffff;
   */
   turn_off(port_spw0);
   turn_off(port_spw1);
          turn_off(port_gigaspw2);
          turn_off(port_gigaspw3);
          REGS->SPW_STATUS[port_gigaspw2] = 0xffffffff;
          REGS->SPW_STATUS[port_gigaspw3] = 0xffffffff;
          REGS->SPW_STATUS[port_spw0] = 0xffffffff;
          REGS->SPW_STATUS[port_spw1] = 0xffffffff;
   
//,# Печать результата
   if (errors)
     report_high("test ERR");
   else
     report_high("test OK");
   return errors;
}