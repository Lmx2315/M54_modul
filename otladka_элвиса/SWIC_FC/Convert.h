#define SPEC_CABLE_SPW0_MASK        1
#define SPEC_CABLE_SPW1_MASK        2

#include "gigaspwr_reg_fields.hpp"
#include "dma_port_ch_reg_fields.hpp"

#define GIGASPWR_cl void

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

void report_high(const char * str);
void unmask_irq(unsigned int mask);
void form_routing_table(bool del_header);
void gspwr_form_adg();
void set_transmit_speed(unsigned int port, int speed, bool pll_en);
void set_recive_speed(unsigned int port, int speed);
void make_desc(unsigned int *desc_src, int data_len, int route);
void set_dma_enabled(bool dma_en);
void set_work_enabled(bool work_en);
void start_connect(unsigned int port);
unsigned int get_status(unsigned int port, bool print);
int wait_link_status(unsigned int port, unsigned int status, unsigned int timeout);
void set_transmit_speed(unsigned int port, int speed, bool pll_en);
unsigned int get_rx_speed(unsigned int port);
unsigned int check_SpW_link_status_run(GIGASPWR_cl* gigaspwr, unsigned int SpW_port_n);
void turn_off(unsigned int port);
void report_high(const char * str);
