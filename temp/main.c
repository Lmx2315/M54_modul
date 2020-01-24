#include <stdbool.h>
#include "risc_runtime/mc30sf.h"
#include "risc_runtime/swic.h"
#include "risc_runtime/risc_interrupt.h"
#include "risc_runtime/system.h"
#include "gigaspwr_reg_fields.hpp"
#include "gigaspwr_misc.hpp"
#include "Convert.h"
#include "DMA_Class.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define GIGASPWR_cl void
#define u64 unsigned long long
#define u32 unsigned int
#define u16 unsigned short
#define u8  unsigned char
#define Bufer_size   4096u   //16384

#define RESET 0u
#define SET   1u

//������� 2 �����
#define P2LDAT0_0 init_GPIO_DR2(0x01,RESET)
#define P2LDAT0_1 init_GPIO_DR2(0x01,  SET)

#define P2LDAT1_0 init_GPIO_DR2(0x02,RESET)
#define P2LDAT1_1 init_GPIO_DR2(0x02,  SET)

#define P2LDAT2_0 init_GPIO_DR2(0x04,RESET)
#define P2LDAT2_1 init_GPIO_DR2(0x04,  SET)

#define P2LDAT3_0 init_GPIO_DR2(0x08,RESET)
#define P2LDAT3_1 init_GPIO_DR2(0x08,  SET)

#define P2LDAT4_0 init_GPIO_DR2(0x10,RESET)
#define P2LDAT4_1 init_GPIO_DR2(0x10,  SET)

#define P2LDAT5_0 init_GPIO_DR2(0x20,RESET)
#define P2LDAT5_1 init_GPIO_DR2(0x20,  SET)

#define P2LDAT6_0 init_GPIO_DR2(0x40,RESET)
#define P2LDAT6_1 init_GPIO_DR2(0x40,  SET)

#define P2LDAT7_0 init_GPIO_DR2(0x80,RESET)
#define P2LDAT7_1 init_GPIO_DR2(0x80,  SET)

//������� 3 �����
#define P3LDAT0_0 init_GPIO_DR3(0x01,RESET)
#define P3LDAT0_1 init_GPIO_DR3(0x01,  SET)

#define P3LDAT1_0 init_GPIO_DR3(0x02,RESET)
#define P3LDAT1_1 init_GPIO_DR3(0x02,  SET)

#define P3LDAT2_0 init_GPIO_DR3(0x04,RESET)
#define P3LDAT2_1 init_GPIO_DR3(0x04,  SET)

#define P3LDAT3_0 init_GPIO_DR3(0x08,RESET)
#define P3LDAT3_1 init_GPIO_DR3(0x08,  SET)

#define P3LDAT4_0 init_GPIO_DR3(0x10,RESET)
#define P3LDAT4_1 init_GPIO_DR3(0x10,  SET)

#define P3LDAT5_0 init_GPIO_DR3(0x20,RESET)
#define P3LDAT5_1 init_GPIO_DR3(0x20,  SET)

#define P3LDAT6_0 init_GPIO_DR3(0x40,RESET)
#define P3LDAT6_1 init_GPIO_DR3(0x40,  SET)

#define P3LDAT7_0 init_GPIO_DR3(0x80,RESET)
#define P3LDAT7_1 init_GPIO_DR3(0x80,  SET)


#define TST2(a)     ((a==1)?P2LDAT0_1:P2LDAT0_0)
#define A2_CSB(a)   ((a==1)?P2LDAT1_1:P2LDAT1_0)
//#define A2_SO(a)    ((a==1)?P2LDAT2_1:P2LDAT2_0)
#define A2_SPLIN(a) ((a==1)?P2LDAT3_1:P2LDAT3_0)
#define A2_PWRDN(a) ((a==1)?P2LDAT4_1:P2LDAT4_0)
#define AT1_5(a)    ((a==1)?P2LDAT5_1:P2LDAT5_0)
#define AT1_6(a)    ((a==1)?P2LDAT6_1:P2LDAT6_0)

#define PF1_SYNC_START(a)    ((a==1)?P2LDAT7_1:P2LDAT7_0)


#define TST1(a)     ((a==1)?P3LDAT0_1:P3LDAT0_0)
#define A1_CSB(a)   ((a==1)?P3LDAT1_1:P3LDAT1_0)
//#define A1_SO(a)    ((a==1)?P3LDAT2_1:P3LDAT2_0)
#define A1_SPLIN(a) ((a==1)?P3LDAT3_1:P3LDAT3_0)
#define A1_PWRDN(a) ((a==1)?P3LDAT4_1:P3LDAT4_0)

#define RST_1288(a) ((a==1)?P3LDAT7_1:P3LDAT7_0)

char Readed_value;
unsigned int tmp_read;

u8 flag_pachka_TXT; //
u16  text_lengh;
u8 text_buffer[Bufer_size];

// USART1 Receiver buffer
#define RX_BUFFER_SIZE0 64u
volatile char          rx_buffer0[RX_BUFFER_SIZE0];
volatile unsigned int rx_wr_index0,rx_rd_index0,rx_counter0;
volatile u8  rx_buffer_overflow0;

#define buf_IO   32u
#define buf_Word 32u
#define buf_DATA_Word 200u
#define BUFFER_SR 64u
#define BUF_STR 64

char sr[BUFFER_SR+1];
unsigned char lsr=0;
unsigned char lk=0;
unsigned int led_tick=0;

#define MAX_PL 157u

char  strng[buf_IO];
char      InOut[BUFFER_SR+1];
char      Word [buf_Word];    //
char DATA_Word [buf_DATA_Word];    //
char DATA_Word2[buf_DATA_Word];    //

char Master_flag=0; //
char Adress=0;  //

u16 lenght=0;
u16 SCH_LENGHT_PACKET=0;

unsigned     int index1=0;
unsigned     char crc_ok=0;
unsigned     char packet_ok=0;
unsigned     char packet_flag=0;
unsigned     int indexZ=0;
unsigned     int index_word=0;
unsigned     int index_data_word=0;
unsigned     int index_data_word2=0;
unsigned     int lenght_data=0;//
unsigned     char data_flag=0;
unsigned     char data_flag2=0;
unsigned     char FLAG_lenght=0;//
unsigned     int sch_lenght_data=0;
unsigned     char FLAG_DATA=0;
unsigned char FLAG_CW=0;
float time_uart=0; //

u32 VAR_RESIVER=0;

//---------------------------

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



unsigned int Flag_Timeout = 0;
unsigned int Flag_Corr = 1; // ���� ������������ ������ ����� (0 - ���������, 1 - �� ���������)
unsigned int Flag_Disconnect = 0;

volatile unsigned int SWIC_Speed = 0x00000050;
unsigned  int speed;
unsigned  int SWIC_Number = 5;
int errors=0;

#define  ARRAY_LEN 1024

unsigned int OutputArray0[ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};
unsigned int OutputArray1[ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};
unsigned int InputArray0[ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};
unsigned int InputArray1[ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};

//-------��������� �������------------------
u32 IO ( char* );
void Transf(const char *);
void u_out (const char *,u32);
void x_out (const char *,u32);
void xn_out (const char *,u32);
u32 spi (u32 );
u32 spi_1288_rd (u16 );
u32 spi_1288_wr (u16 ,u16 );
void dsp_1288hk1t_init (void);
void SW_init (void);
void sw_data_obmen (u32);
void lPORT_DMA (void);
//void dsp_1288hk1t_reg (void);
//------------------------------------------
#define FREQ 100000000  //������� CPU
//--------------------------
typedef struct  reg_1288  // �������� ���������
{
	u32 R[128];

    u16 SWRST           :16;//������� ������������ ������
	u16 DEVID           :16;//������������� ����������, ������ ������
	u16 INT				:16;//����� ����������
	u16 INTE			:16;//����� ������ ����������
	u16 INTR			:16;//������� ������ ����������
	u16 SYNC			:16;//������� ���������� ��������������
	u16 ADC_OVF			:16;//������� ������ ���������� ���, ������������ ��� ������
	u16 ADC_CFG			:16;//������� ���������� ����������� ������� ��������
	u16 RX_CFG			:16;//������� ����� ������������ ������� ������
	u16 RX_FIFO_THRESH	:16;//����� ����� PF - ������������� ������ �������� �������
	u16 RX_LINK			:16;//������� ���������� ����-������ �������� �������

	u16 RX1				:16;//�������� ������� ������ ������
	u16 RX1_OVF			:16;//������� ������ ������������, ������������ ��� ������
	u16 RX1_LCFG		:16;//������� ������������ ���������� ������
	u16 RX1_DCIC2		:16;//������� ������������ ������ ������� CIC-�����������
	u16 RX1_DCICN		:16;//������� ������������ ������ ������� CIC-�����������
	u16 RX1_DFIR1_CFG1	:16;//������� ������������ 1 ������� ���-�������-����������
	u16 RX1_DFIR1_CFG2 	:16;//������� ������������ 2 ������� ���-�������-����������
	u16 RX1_DFIR2_CFG1	:16;//������� ������������ 1 ������� ���-�������-����������
	u16 RX1_DFIR2_CFG2 	:16;//������� ������������ 2 ������� ���-�������-����������
	u16 RX1_GAIN_I		:16;//������� ��������� �������� ������������ ������������ �������� (I ����������)
	u16 RX1_GAIN_Q		:16;//������� ��������� �������� ������������ ������������ �������� (Q ����������)
	u16 RX1_NCO_PHASE	:16;//������� ��������� ���� ����������
	u16 RX1_NCO_FRQL	:16;//������� ������� ����������, ������� 16 ��������
	u16 RX1_NCO_FRQH	:16;//������� ������� ����������, ������� 16 ��������
	u16 RX1_CF_DFIR1[64];//������������ ������� DFIR �������-����������
	u16 RX1_CF_DFIR2[64];//������������ ������� DFIR �������-����������

	u16 RX2				:16;//�������� ������� ������ ������
	u16 RX2_OVF			:16;//������� ������ ������������, ������������ ��� ������
	u16 RX2_LCFG		:16;//������� ������������ ���������� ������
	u16 RX2_DCIC2		:16;//������� ������������ ������ ������� CIC-�����������
	u16 RX2_DCICN		:16;//������� ������������ ������ ������� CIC-�����������
	u16 RX2_DFIR1_CFG1	:16;//������� ������������ 1 ������� ���-�������-����������
	u16 RX2_DFIR1_CFG2 	:16;//������� ������������ 2 ������� ���-�������-����������
	u16 RX2_DFIR2_CFG1	:16;//������� ������������ 1 ������� ���-�������-����������
	u16 RX2_DFIR2_CFG2 	:16;//������� ������������ 2 ������� ���-�������-����������
	u16 RX2_GAIN_I		:16;//������� ��������� �������� ������������ ������������ �������� (I ����������)
	u16 RX2_GAIN_Q		:16;//������� ��������� �������� ������������ ������������ �������� (Q ����������)
	u16 RX2_NCO_PHASE	:16;//������� ��������� ���� ����������
	u16 RX2_NCO_FRQL	:16;//������� ������� ����������, ������� 16 ��������
	u16 RX2_NCO_FRQH	:16;//������� ������� ����������, ������� 16 ��������
	u16 RX2_CF_DFIR1[64];//������������ ������� DFIR �������-����������
	u16 RX2_CF_DFIR2[64];//������������ ������� DFIR �������-����������

	u16 RX3				:16;//�������� ������� ������ ������
	u16 RX3_OVF			:16;//������� ������ ������������, ������������ ��� ������
	u16 RX3_LCFG		:16;//������� ������������ ���������� ������
	u16 RX3_DCIC2		:16;//������� ������������ ������ ������� CIC-�����������
	u16 RX3_DCICN		:16;//������� ������������ ������ ������� CIC-�����������
	u16 RX3_DFIR1_CFG1	:16;//������� ������������ 1 ������� ���-�������-����������
	u16 RX3_DFIR1_CFG2 	:16;//������� ������������ 2 ������� ���-�������-����������
	u16 RX3_DFIR2_CFG1	:16;//������� ������������ 1 ������� ���-�������-����������
	u16 RX3_DFIR2_CFG2 	:16;//������� ������������ 2 ������� ���-�������-����������
	u16 RX3_GAIN_I		:16;//������� ��������� �������� ������������ ������������ �������� (I ����������)
	u16 RX3_GAIN_Q		:16;//������� ��������� �������� ������������ ������������ �������� (Q ����������)
	u16 RX3_NCO_PHASE	:16;//������� ��������� ���� ����������
	u16 RX3_NCO_FRQL	:16;//������� ������� ����������, ������� 16 ��������
	u16 RX3_NCO_FRQH	:16;//������� ������� ����������, ������� 16 ��������
	u16 RX3_CF_DFIR1[64];//������������ ������� DFIR �������-����������
	u16 RX3_CF_DFIR2[64];//������������ ������� DFIR �������-����������

	u16 RX4				:16;//�������� ������� ������ ������
	u16 RX4_OVF			:16;//������� ������ ������������, ������������ ��� ������
	u16 RX4_LCFG		:16;//������� ������������ ���������� ������
	u16 RX4_DCIC2		:16;//������� ������������ ������ ������� CIC-�����������
	u16 RX4_DCICN		:16;//������� ������������ ������ ������� CIC-�����������
	u16 RX4_DFIR1_CFG1	:16;//������� ������������ 1 ������� ���-�������-����������
	u16 RX4_DFIR1_CFG2 	:16;//������� ������������ 2 ������� ���-�������-����������
	u16 RX4_DFIR2_CFG1	:16;//������� ������������ 1 ������� ���-�������-����������
	u16 RX4_DFIR2_CFG2 	:16;//������� ������������ 2 ������� ���-�������-����������
	u16 RX4_GAIN_I		:16;//������� ��������� �������� ������������ ������������ �������� (I ����������)
	u16 RX4_GAIN_Q		:16;//������� ��������� �������� ������������ ������������ �������� (Q ����������)
	u16 RX4_NCO_PHASE	:16;//������� ��������� ���� ����������
	u16 RX4_NCO_FRQL	:16;//������� ������� ����������, ������� 16 ��������
	u16 RX4_NCO_FRQH	:16;//������� ������� ����������, ������� 16 ��������
	u16 RX4_CF_DFIR1[64];//������������ ������� DFIR �������-����������
	u16 RX4_CF_DFIR2[64];//������������ ������� DFIR �������-����������


} reg_1288;

 reg_1288 DSP;


void INIT_REG_DSP (reg_1288 *dsp)
{
	int i=0;

 //dsp->output_delayab			  =0;
 dsp->SWRST = 0x0078;
 dsp->DEVID = 0x0000;
 dsp->INT   = 0x0000;
 dsp->INTE	= 0x0000;
 dsp->INTR  = 0xffff;

 dsp->SYNC  = 0x0000;
 dsp->SYNC  = (0<<15) // �1����������� �Master� �������������
			 |(0<<10) // ���������������
			 |(0<<9 ) // ������ ���������� �1� �������� ����� FIFO.
			 |(0<<8 ) // ������ �1� ��������� ������� ������� ������� ������, ������� ����� FIFO.
			 |(0<<3 ) // ���������������
			 |(0<<2 ) // ������������� ��������� �������� ������������ ��������
			 |(0<<1 ) // ��� ���������� ��������� ������� � ���� ����������� ���� �������
			 |(0<<0 );// ������ �1� ��������� 1288��1� � ��������� ��������� ������� � ������������ ������������� ������ ���������� ���������.

  dsp->ADC_CFG = 0x0000;
  dsp->ADC_CFG = (0<<15)
				|(0<<14)  //enc_mode  | �1� ������������� ������� ������� �������� �� ������ ENCODE.������������ ������ � ��� ������, ���� ������ ENCODE�������� (enc_dir =0 )
				|(0<<13)  //enc_phase |�0� ������������� ����, ��� �������� ������� � ������� ��� �� �������� ����� � ������������;
				|(0<<12)  //enc_dir   |���������� ���������� ������� ENCODE:�0� ������������� ����, ��� ������ ENCODE �������� ������� ��������;
				|(0<<8 )  //enc_div   |����������� ������� �������� �������� ������� ENCODE:0 - 1/1
				|(0<<7 )  //�������� ���. ��� ���������� ������ ������ ���� ���������� � 0
				|(0<<4 )  //���������������
				|(0<<0 ); //�������� ���. ��� ���������� ������ ������ ���� ���������� � 0

   dsp->RX_CFG = 0x0000;
   dsp->RX_CFG = (0<<15) //wr_all  | �1� ������������� ������������� ������ �� ��� ������
				|(0<<11) //res     |
				|(2<<9 ) //pf_mode | ������ ������ PF:- �0� ������������� ����, ��� �������� - ������� �������;
				|(0<<8 ) //out_fmt | ������ �������� ������ ������� ������:�0� ������������� ������� 16+16;
				|(1<<6 ) //Mode    | - �01� - ������������� ����� (������������ ������ 1+2 � 3+4);
				|(0<<3 ) //in_type | ������������� �������, �������������� ������
				|(0<<2 ) //Res     | ���������������
				|(1<<0 );//in_fmt  | ������ ������� ������ ������� ������:������

	dsp->RX_FIFO_THRESH = 256;//�������� ������������������ ����� ������������� FIFO ������� ������.

	dsp->RX_LINK = 0x0000;
	dsp->RX_LINK = (0<<6 ) //���������������
				  |(0<<4 ) //�������� �������� ������� ����-�����:PCLK/2 50 MHz
				  |(0<<3 ) //���������������
				  |(0<<1 ) //�������� �������� ������� ����-�����:8-������� SHAR�
				  |(1<<0 );//�1� ������������� ����, ��� ���� - ���� �������

	dsp-> RX1_LCFG = 0x0000;
	dsp-> RX1_LCFG = (1<<15)
					|(1<<14) //�1� �������� � ��������� ��������� ����������
					|(0<<10) //���������������
					|(0<<8 ) //src |����� ��������� �������. ��� ������������ �������:- ����� �src� ������������� ���������� I;
					|(0<<5 ) //���������������
					|(0<<4 ) //���������� ���������� �� ���������� ������������ ����������� ������������ ���������� �z�
					|(0<<3 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� FIR - ���������
					|(0<<2 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� FIR - ���������
					|(0<<1 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� CIC - ���������
					|(0<<0 );//���������� ���������� �� ���������� ������������ ����������� ������� ������� CIC - ���������

	dsp-> RX2_LCFG = 0x0000;
	dsp-> RX2_LCFG = (1<<15)
					|(1<<14) //�1� �������� � ��������� ��������� ����������
					|(0<<10) //���������������
					|(0<<8 ) //src |����� ��������� �������. ��� ������������ �������:- ����� �src� ������������� ���������� I;
					|(0<<5 ) //���������������
					|(0<<4 ) //���������� ���������� �� ���������� ������������ ����������� ������������ ���������� �z�
					|(0<<3 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� FIR - ���������
					|(0<<2 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� FIR - ���������
					|(0<<1 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� CIC - ���������
					|(0<<0 );//���������� ���������� �� ���������� ������������ ����������� ������� ������� CIC - ���������

	dsp-> RX3_LCFG = 0x0000;
	dsp-> RX3_LCFG = (1<<15)
					|(1<<14) //�1� �������� � ��������� ��������� ����������
					|(0<<10) //���������������
					|(2<<8 ) //src |����� ��������� �������. ��� ������������ �������:- ����� �src� ������������� ���������� I;
					|(0<<5 ) //���������������
					|(0<<4 ) //���������� ���������� �� ���������� ������������ ����������� ������������ ���������� �z�
					|(0<<3 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� FIR - ���������
					|(0<<2 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� FIR - ���������
					|(0<<1 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� CIC - ���������
					|(0<<0 );//���������� ���������� �� ���������� ������������ ����������� ������� ������� CIC - ���������

	dsp-> RX4_LCFG = 0x0000;
	dsp-> RX4_LCFG = (1<<15)
					|(1<<14) //�1� �������� � ��������� ��������� ����������
					|(0<<10) //���������������
					|(2<<8 ) //src |����� ��������� �������. ��� ������������ �������:- ����� �src� ������������� ���������� I;
					|(0<<5 ) //���������������
					|(0<<4 ) //���������� ���������� �� ���������� ������������ ����������� ������������ ���������� �z�
					|(0<<3 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� FIR - ���������
					|(0<<2 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� FIR - ���������
					|(0<<1 ) //���������� ���������� �� ���������� ������������ ����������� ������� ������� CIC - ���������
					|(0<<0 );//���������� ���������� �� ���������� ������������ ����������� ������� ������� CIC - ���������

	dsp-> RX1_DCIC2 = 0x0000;
	dsp-> RX1_DCIC2 = (0<<15)
					 |(7<<8 )  //����������� ��������� ������ ������� CIC - ����������:M = dr + 1
					 |(0<<4 )  //���������������
					 |(12 ); //����������� ������ ��������� ������� ������ ������� CIC - ����������.

	dsp-> RX2_DCIC2 = 0x0000;
	dsp-> RX2_DCIC2 = (0<<15)
					 |(7<<8)  //����������� ��������� ������ ������� CIC - ����������:M = dr + 1
					 |(0<<4 )  //���������������
					 |(12 ); //����������� ������ ��������� ������� ������ ������� CIC - ����������.

	dsp-> RX3_DCIC2 = 0x0000;
	dsp-> RX3_DCIC2 = (0<<15)
					 |(7<<8 )  //����������� ��������� ������ ������� CIC - ����������:M = dr + 1
					 |(0<<4 )  //���������������
					 |(12 ); //����������� ������ ��������� ������� ������ ������� CIC - ����������.

	dsp-> RX4_DCIC2 = 0x0000;
	dsp-> RX4_DCIC2 = (0<<15)
					 |(7<<8 )  //����������� ��������� ������ ������� CIC - ����������:M = dr + 1
					 |(0<<4 )  //���������������
					 |(12 ); //����������� ������ ��������� ������� ������ ������� CIC - ����������.

	dsp-> RX1_DCICN = 0x0000;
	dsp-> RX1_DCICN = (2<<14) //���� ������������ 2-� ������� CIC�����������:- �112� - 2-� ������ ��������� ������� � ������ CIC6
					 |(15<<8 ) //����������� ��������� 2-� ������� CIC-����������:M = dr + 1
					 |(0<<5 ) //���������������
					 |(1<<4 ) //����� ��������� ����������� ������ ��������� ������� 2-� ������� CIC-����������
					 |(0 );//����������� ������ ��������� ������� 2-� ������� CIC-����������:- ���� scl_mx = 1, �� ����������� �������� CIC�����������

	dsp-> RX2_DCICN = 0x0000;
	dsp-> RX2_DCICN = (2<<14) //���� ������������ 2-� ������� CIC�����������:- �112� - 2-� ������ ��������� ������� � ������ CIC6
					 |(15<<8 ) //����������� ��������� 2-� ������� CIC-����������:M = dr + 1
					 |(0<<5 ) //���������������
					 |(1<<4 ) //����� ��������� ����������� ������ ��������� ������� 2-� ������� CIC-����������
					 |(0 );//����������� ������ ��������� ������� 2-� ������� CIC-����������:- ���� scl_mx = 1, �� ����������� �������� CIC�����������

	dsp-> RX3_DCICN = 0x0000;
	dsp-> RX3_DCICN = (2<<14) //���� ������������ 2-� ������� CIC�����������:- �112� - 2-� ������ ��������� ������� � ������ CIC6
					 |(15<<8 ) //����������� ��������� 2-� ������� CIC-����������:M = dr + 1
					 |(0<<5 ) //���������������
					 |(1<<4 ) //����� ��������� ����������� ������ ��������� ������� 2-� ������� CIC-����������
					 |(0 );//����������� ������ ��������� ������� 2-� ������� CIC-����������:- ���� scl_mx = 1, �� ����������� �������� CIC�����������

	dsp-> RX4_DCICN = 0x0000;
	dsp-> RX4_DCICN = (2<<14) //���� ������������ 2-� ������� CIC�����������:- �112� - 2-� ������ ��������� ������� � ������ CIC6
					 |(15<<8 ) //����������� ��������� 2-� ������� CIC-����������:M = dr + 1
					 |(0<<5 ) //���������������
					 |(1<<4 ) //����� ��������� ����������� ������ ��������� ������� 2-� ������� CIC-����������
					 |(0 );//����������� ������ ��������� ������� 2-� ������� CIC-����������:- ���� scl_mx = 1, �� ����������� �������� CIC�����������

	dsp->RX1_DFIR1_CFG1 = 0x0000;
	dsp->RX1_DFIR1_CFG1 = (0  <<15) //���������������
						 |(0  <<14) //��������������:- �0� - ������������;
						 |(63 <<8 ) //��������� ������� �������: Ntap = order + 1
						 |(0  <<4 ) //dly|��������� �������� ������������� (0:15)  ��� �������������� ������!!!!
						 |(1     );//dr |��������� ������������ ���������: M = (dr + 1)/2

	dsp->RX2_DFIR1_CFG1 = 0x0000;
	dsp->RX2_DFIR1_CFG1 = (0 <<15) //���������������
						 |(0 <<14) //��������������:- �0� - ������������;
						 |(63<<8 ) //��������� ������� �������: Ntap = order + 1
						 |(1 <<4 ) //��������� �������� ������������� (0:15)
						 |(1     );//��������� ������������ ���������: M = (dr + 1)/2

	dsp->RX3_DFIR1_CFG1 = 0x0000;
	dsp->RX3_DFIR1_CFG1 = (0 <<15) //���������������
						 |(0 <<14) //��������������:- �0� - ������������;
						 |(63<<8 ) //��������� ������� �������: Ntap = order + 1
						 |(0 <<4 ) //��������� �������� ������������� (0:15)  ��� �������������� ������!!!!
						 |(1     );//��������� ������������ ���������: M = dr + 1

	dsp->RX4_DFIR1_CFG1 = 0x0000;
	dsp->RX4_DFIR1_CFG1 = (0 <<15) //���������������
						 |(0 <<14) //��������������:- �0� - ������������;
						 |(63<<8 ) //��������� ������� �������: Ntap = order + 1
						 |(1 <<4 ) //��������� �������� ������������� (0:15)
						 |(1     );//��������� ������������ ���������: M = dr + 1

	dsp->RX1_DFIR1_CFG2 = 0x0000;
	dsp->RX1_DFIR1_CFG2 = (0<<4 ) //���������������
						 |(10);//����������� ������ ��������� ������� DFIR1.����������� �������� �� ������ DFIR1 ����� 2scl-21

	dsp->RX2_DFIR1_CFG2 = 0x0000;
	dsp->RX2_DFIR1_CFG2 = (0<<4 ) //���������������
						 |(10);//����������� ������ ��������� ������� DFIR1.����������� �������� �� ������ DFIR1 ����� 2scl-21

	dsp->RX3_DFIR1_CFG2 = 0x0000;
	dsp->RX3_DFIR1_CFG2 = (0<<4 ) //���������������
						 |(10);//����������� ������ ��������� ������� DFIR1.����������� �������� �� ������ DFIR1 ����� 2scl-21

	dsp->RX4_DFIR1_CFG2 = 0x0000;
	dsp->RX4_DFIR1_CFG2 = (0<<4 ) //���������������
					     |(10);//����������� ������ ��������� ������� DFIR1.����������� �������� �� ������ DFIR1 ����� 2scl-21


	dsp->RX1_DFIR2_CFG1 = 0x0000;
	dsp->RX1_DFIR2_CFG1 = (0 <<15) //���������������
						 |(0 <<14) //��������������:- �0� - ������������;
						 |(63<<8 ) //��������� ������� �������: Ntap = order + 1
						 |(0 <<4 ) //��������� �������� ������������� (0:15)
						 |(1     );//��������� ������������ ���������: (M = dr + 1)/2

	dsp->RX2_DFIR2_CFG1 = 0x0000;
	dsp->RX2_DFIR2_CFG1 = (0 <<15) //���������������
						 |(0 <<14) //��������������:- �0� - ������������;
						 |(63<<8 ) //��������� ������� �������: Ntap = order + 1
						 |(1 <<4 ) //��������� �������� ������������� (0:15)
						 |(1     );//��������� ������������ ���������: (M = dr + 1)/2

	dsp->RX3_DFIR2_CFG1 = 0x0000;
	dsp->RX3_DFIR2_CFG1 = (0 <<15) //���������������
						 |(0 <<14) //��������������:- �0� - ������������;
						 |(63<<8 ) //��������� ������� �������: Ntap = order + 1
						 |(0 <<4 ) //��������� �������� ������������� (0:15)
						 |(1     );//��������� ������������ ���������: (M = dr + 1)/2

	dsp->RX4_DFIR2_CFG1 = 0x0000;
	dsp->RX4_DFIR2_CFG1 = (0 <<15) //���������������
						 |(0 <<14) //��������������:- �0� - ������������;
						 |(63<<8 ) //��������� ������� �������: Ntap = order + 1
						 |(1 <<4 ) //��������� �������� ������������� (0:15)
						 |(1     );//��������� ������������ ���������: M = (dr + 1)/2

	dsp->RX1_DFIR2_CFG2 = 0x0000;
	dsp->RX1_DFIR2_CFG2 = (0 <<4) //���������������
						 |(8);//����������� ������ ��������� ������� DFIR2.����������� �������� �� ������ DFIR2 ����� 2scl-21

	dsp->RX2_DFIR2_CFG2 = 0x0000;
	dsp->RX2_DFIR2_CFG2 = (0 <<4) //���������������
						 |(8);//����������� ������ ��������� ������� DFIR2.����������� �������� �� ������ DFIR2 ����� 2scl-21

	dsp->RX3_DFIR2_CFG2 = 0x0000;
	dsp->RX3_DFIR2_CFG2 = (0 <<4) //���������������
						 |(8);//����������� ������ ��������� ������� DFIR2.����������� �������� �� ������ DFIR2 ����� 2scl-21

	dsp->RX4_DFIR2_CFG2 = 0x0000;
	dsp->RX4_DFIR2_CFG2 = (0 <<4) //���������������
						 |(8);//����������� ������ ��������� ������� DFIR2.����������� �������� �� ������ DFIR2 ����� 2scl-21

//-------------��� ���������� ���������� �������� ���������� �������� �1� � ��� SYNC_sync_nco.	----------------------------

	dsp->RX1_NCO_PHASE = 0x0000; //������� ��������� ��������� ����
	dsp->RX2_NCO_PHASE = 0x0000; //������� ��������� ��������� ����
	dsp->RX3_NCO_PHASE = 0x0000; //������� ��������� ��������� ����
	dsp->RX4_NCO_PHASE = 0x0000; //������� ��������� ��������� ����

	dsp->RX1_NCO_FRQL  = 0x0000;//25 MHz
	dsp->RX1_NCO_FRQH  = 0x4000;

	dsp->RX2_NCO_FRQL  = 0x0000;//25 MHz
	dsp->RX2_NCO_FRQH  = 0x4000;

	dsp->RX3_NCO_FRQL  = 0x0000;//25 MHz
	dsp->RX3_NCO_FRQH  = 0x4000;

	dsp->RX4_NCO_FRQL  = 0x0000;//25 MHz
	dsp->RX4_NCO_FRQH  = 0x4000;

//-------------��� ���������� ���������� �������� ���������� �������� �1� � ��� SYNC_sync_gain.	--------------------------

	dsp->RX1_GAIN_I = 0x4000;//�������� ��������� ������������ ������������ �������� (GAIN_I+j*GAIN_Q) ������������ ��������� � ���������� �� ����
	dsp->RX1_GAIN_Q = 0x4000;

	dsp->RX2_GAIN_I = 0x4000;//�������� ��������� ������������ ������������ �������� (GAIN_I+j*GAIN_Q) ������������ ��������� � ���������� �� ����
	dsp->RX2_GAIN_Q = 0x4000;

	dsp->RX3_GAIN_I = 0x4000;//�������� ��������� ������������ ������������ �������� (GAIN_I+j*GAIN_Q) ������������ ��������� � ���������� �� ����
	dsp->RX3_GAIN_Q = 0x4000;

	dsp->RX4_GAIN_I = 0x4000;//�������� ��������� ������������ ������������ �������� (GAIN_I+j*GAIN_Q) ������������ ��������� � ���������� �� ����
	dsp->RX4_GAIN_Q = 0x4000;

//-----��� ������ ������� ������� ������������ ������������ ��� ����. ��� ��������
//		������� ������� ������������ �������� ������������ ������������ ������ ���� �����
//			�������� �������� ������������ ������������.
//				�������� �������� ��������������� ��� ���������� ����������� �������������.


dsp->RX1_CF_DFIR1[0]  =82;
dsp->RX1_CF_DFIR1[1]  =0;
dsp->RX1_CF_DFIR1[2]  =-98;
dsp->RX1_CF_DFIR1[3]  =0;
dsp->RX1_CF_DFIR1[4]  =110;
dsp->RX1_CF_DFIR1[5]  =0;
dsp->RX1_CF_DFIR1[6]  =-117;
dsp->RX1_CF_DFIR1[7]  =0;
dsp->RX1_CF_DFIR1[8]  =112;
dsp->RX1_CF_DFIR1[9]  =0;
dsp->RX1_CF_DFIR1[10]  =-89;
dsp->RX1_CF_DFIR1[11]  =0;
dsp->RX1_CF_DFIR1[12]  =40;
dsp->RX1_CF_DFIR1[13]  =0;
dsp->RX1_CF_DFIR1[14]  =41;
dsp->RX1_CF_DFIR1[15]  =0;
dsp->RX1_CF_DFIR1[16]  =-153;
dsp->RX1_CF_DFIR1[17]  =0;
dsp->RX1_CF_DFIR1[18]  =291;
dsp->RX1_CF_DFIR1[19]  =0;
dsp->RX1_CF_DFIR1[20]  =-443;
dsp->RX1_CF_DFIR1[21]  =0;
dsp->RX1_CF_DFIR1[22]  =586;
dsp->RX1_CF_DFIR1[23]  =0;
dsp->RX1_CF_DFIR1[24]  =-693;
dsp->RX1_CF_DFIR1[25]  =0;
dsp->RX1_CF_DFIR1[26]  =732;
dsp->RX1_CF_DFIR1[27]  =0;
dsp->RX1_CF_DFIR1[28]  =-674;
dsp->RX1_CF_DFIR1[29]  =0;
dsp->RX1_CF_DFIR1[30]  =493;
dsp->RX1_CF_DFIR1[31]  =0;
dsp->RX1_CF_DFIR1[32]  =-174;
dsp->RX1_CF_DFIR1[33]  =0;
dsp->RX1_CF_DFIR1[34]  =-280;
dsp->RX1_CF_DFIR1[35]  =0;
dsp->RX1_CF_DFIR1[36]  =847;
dsp->RX1_CF_DFIR1[37]  =0;
dsp->RX1_CF_DFIR1[38]  =-1482;
dsp->RX1_CF_DFIR1[39]  =0;
dsp->RX1_CF_DFIR1[40]  =2120;
dsp->RX1_CF_DFIR1[41]  =0;
dsp->RX1_CF_DFIR1[42]  =-2672;
dsp->RX1_CF_DFIR1[43]  =0;
dsp->RX1_CF_DFIR1[44]  =3034;
dsp->RX1_CF_DFIR1[45]  =0;
dsp->RX1_CF_DFIR1[46]  =-3091;
dsp->RX1_CF_DFIR1[47]  =0;
dsp->RX1_CF_DFIR1[48]  =2720;
dsp->RX1_CF_DFIR1[49]  =0;
dsp->RX1_CF_DFIR1[50]  =-1789;
dsp->RX1_CF_DFIR1[51]  =0;
dsp->RX1_CF_DFIR1[52]  =151;
dsp->RX1_CF_DFIR1[53]  =0;
dsp->RX1_CF_DFIR1[54]  =2382;
dsp->RX1_CF_DFIR1[55]  =0;
dsp->RX1_CF_DFIR1[56]  =-6114;
dsp->RX1_CF_DFIR1[57]  =0;
dsp->RX1_CF_DFIR1[58]  =11627;
dsp->RX1_CF_DFIR1[59]  =0;
dsp->RX1_CF_DFIR1[60]  =-20143;
dsp->RX1_CF_DFIR1[61]  =0;
dsp->RX1_CF_DFIR1[62]  =32767;
dsp->RX1_CF_DFIR1[63]  =0;




for (i=0;i<64;i++) dsp->RX2_CF_DFIR1[i] = dsp->RX1_CF_DFIR1[i];
for (i=0;i<64;i++) dsp->RX3_CF_DFIR1[i] = dsp->RX1_CF_DFIR1[i];
for (i=0;i<64;i++) dsp->RX4_CF_DFIR1[i] = dsp->RX1_CF_DFIR1[i];

//-----��� ������ ������� ������� ������������ ������������ ��� ����. ��� ��������
//		������� ������� ������������ �������� ������������ ������������ ������ ���� �����
//			�������� �������� ������������ ������������.
//				�������� �������� ��������������� ��� ���������� ����������� �������������.

dsp->RX1_CF_DFIR2[0]  =82;
dsp->RX1_CF_DFIR2[1]  =0;
dsp->RX1_CF_DFIR2[2]  =-98;
dsp->RX1_CF_DFIR2[3]  =0;
dsp->RX1_CF_DFIR2[4]  =110;
dsp->RX1_CF_DFIR2[5]  =0;
dsp->RX1_CF_DFIR2[6]  =-117;
dsp->RX1_CF_DFIR2[7]  =0;
dsp->RX1_CF_DFIR2[8]  =112;
dsp->RX1_CF_DFIR2[9]  =0;
dsp->RX1_CF_DFIR2[10]  =-89;
dsp->RX1_CF_DFIR2[11]  =0;
dsp->RX1_CF_DFIR2[12]  =40;
dsp->RX1_CF_DFIR2[13]  =0;
dsp->RX1_CF_DFIR2[14]  =41;
dsp->RX1_CF_DFIR2[15]  =0;
dsp->RX1_CF_DFIR2[16]  =-153;
dsp->RX1_CF_DFIR2[17]  =0;
dsp->RX1_CF_DFIR2[18]  =291;
dsp->RX1_CF_DFIR2[19]  =0;
dsp->RX1_CF_DFIR2[20]  =-443;
dsp->RX1_CF_DFIR2[21]  =0;
dsp->RX1_CF_DFIR2[22]  =586;
dsp->RX1_CF_DFIR2[23]  =0;
dsp->RX1_CF_DFIR2[24]  =-693;
dsp->RX1_CF_DFIR2[25]  =0;
dsp->RX1_CF_DFIR2[26]  =732;
dsp->RX1_CF_DFIR2[27]  =0;
dsp->RX1_CF_DFIR2[28]  =-674;
dsp->RX1_CF_DFIR2[29]  =0;
dsp->RX1_CF_DFIR2[30]  =493;
dsp->RX1_CF_DFIR2[31]  =0;
dsp->RX1_CF_DFIR2[32]  =-174;
dsp->RX1_CF_DFIR2[33]  =0;
dsp->RX1_CF_DFIR2[34]  =-280;
dsp->RX1_CF_DFIR2[35]  =0;
dsp->RX1_CF_DFIR2[36]  =847;
dsp->RX1_CF_DFIR2[37]  =0;
dsp->RX1_CF_DFIR2[38]  =-1482;
dsp->RX1_CF_DFIR2[39]  =0;
dsp->RX1_CF_DFIR2[40]  =2120;
dsp->RX1_CF_DFIR2[41]  =0;
dsp->RX1_CF_DFIR2[42]  =-2672;
dsp->RX1_CF_DFIR2[43]  =0;
dsp->RX1_CF_DFIR2[44]  =3034;
dsp->RX1_CF_DFIR2[45]  =0;
dsp->RX1_CF_DFIR2[46]  =-3091;
dsp->RX1_CF_DFIR2[47]  =0;
dsp->RX1_CF_DFIR2[48]  =2720;
dsp->RX1_CF_DFIR2[49]  =0;
dsp->RX1_CF_DFIR2[50]  =-1789;
dsp->RX1_CF_DFIR2[51]  =0;
dsp->RX1_CF_DFIR2[52]  =151;
dsp->RX1_CF_DFIR2[53]  =0;
dsp->RX1_CF_DFIR2[54]  =2382;
dsp->RX1_CF_DFIR2[55]  =0;
dsp->RX1_CF_DFIR2[56]  =-6114;
dsp->RX1_CF_DFIR2[57]  =0;
dsp->RX1_CF_DFIR2[58]  =11627;
dsp->RX1_CF_DFIR2[59]  =0;
dsp->RX1_CF_DFIR2[60]  =-20143;
dsp->RX1_CF_DFIR2[61]  =0;
dsp->RX1_CF_DFIR2[62]  =32767;
dsp->RX1_CF_DFIR2[63]  =0;

for (i=0;i<64;i++) dsp->RX2_CF_DFIR2[i] = dsp->RX1_CF_DFIR2[i];
for (i=0;i<64;i++) dsp->RX3_CF_DFIR2[i] = dsp->RX1_CF_DFIR2[i];
for (i=0;i<64;i++) dsp->RX4_CF_DFIR2[i] = dsp->RX1_CF_DFIR2[i];


}



void defrag_REG_DSP (reg_1288 *dsp)
{

}

//---------------------------------------------------------------------
int SYS_timer0=0;
int SYS_timer1=0;
int Dtimer0=0;

void Delay_ms (int a)
{
	SYS_timer0=a;
	while (SYS_timer0!=0){};
}

void report_high(const char * str)
{
	Transf(str);
	Transf("\r\n");
}

volatile struct GIGASPWR_REGS_BASE * REGS = (volatile struct GIGASPWR_REGS_BASE *) 0xB82FA000;
volatile struct GIGASPWR_PMA_TEST_CSR_BASE * PMA_TEST_CSR = (volatile struct GIGASPWR_PMA_TEST_CSR_BASE *) 0xB82FA200;
volatile unsigned int * ROUTING_TABLE = (volatile unsigned int *)0xB82FA400;


void unmask_irq(unsigned int mask) {
  REGS->RISC_IRQ_MASK &= ~mask;
}

void mask_irq(unsigned int mask) {
  REGS->RISC_IRQ_MASK |= mask;
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
//            tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_RX(tx_speed, 1);
//            tx_speed = SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_TX(tx_speed, 1);
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


void FillArray(unsigned int *array, unsigned int len, int first)
{
 u32 i;
 array[0] = 0; // Always config
 for (i=1;i<len;i++)
 {
// array[i] = i-1+first;
   array[i] = first;
  }
}

int VerifyArray(unsigned int *array, unsigned int len, int first)
{
u32 error=0;
u32 i;

if (array[0] != 0) return 1;

for (i=1;i<len;i++)
{
	x_out(":",array[i]);
// if(array[i] != i-1+first) error++;
   if(array[i] != first) error++;
}
 return error;
}

void timer_hnlr(int a)
{
  Flag_Timeout = 1;
  unsigned int param= 0;
  asm volatile ("mtc0 %0, $11" : : "r"(param));
  asm volatile ("nop");
//asm volatile ("break 0x0, 0x1");
  asm volatile ("nop");
}

void dc_hnlr(int a)
{
  Flag_Disconnect = 1;
  asm volatile ("nop");
  asm volatile("break 0x0, 0x1");
  asm volatile ("nop");
}

//---------------------------------

/* reverse:  �������������� ������ s �� ����� */
 void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

 /* itoa:  ������������ n � ������� � s */
 void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* ���������� ���� */
         n = -n;          /* ������ n ������������� ������ */
     i = 0;
     do {       /* ���������� ����� � �������� ������� */
         s[i++] = n % 10 + '0';   /* ����� ��������� ����� */
     } while ((n /= 10) > 0);     /* ������� */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

 void itox(u32 i, char *s)
{
  u8 n;
  s += 8;
  *s = '\0';
    for (n = 8; n != 0; --n)
	{
        *--s = "0123456789ABCDEF"[i & 0x0F];
        i >>= 4;
    }
}



// ������������� UART
// ����������� ������ �������� ������
// ��������� ��������� �� ��������
// ����� ����� - 8 ���
// ����-��� - 1
// �������� �� ��������������
// ���������� ������� ������ �����������
// BaudRate - �������� ������
// Freq - ������� ����������
void UART1_conf(int BaudRate, int Frq) {
      int dlm;

      dlm = (Frq)/(BaudRate*16);

      UART1_LCR = (int)0x80;
      UART1_SCLR  = 0;
      UART1_DLL   = dlm&0xFF;
      UART1_DLM   = (dlm>>8);
      UART1_LCR   = 3;

} // UART_conf

void UART0_conf(int BaudRate, int Frq) {
      int dlm;

      dlm = (Frq)/(BaudRate*16);

      UART0_LCR = (int)0x80;
      UART0_SCLR  = 0;
      UART0_DLL   = dlm&0xFF;
      UART0_DLM   = (dlm>>8);
      UART0_LCR   = 3;

} // UART_conf


void UART_sendByte(char Sym) {
// ����� ������ � ����
     UART1_THR = Sym;
// ����, ���� �� ����� ���������
    while ( ( UART1_LSR & 0x60 ) != 0x60 ) ;
}// UART_sendByte

char UART_receiveByte() {
   char Readed_value;
 // ����, ���� �� RBR ���-�� ��������
   while ( ( UART1_LSR & 0x01) != 0x01);
   Readed_value = UART1_RBR;
   return Readed_value;
}


 void Transf(const char *Str)
 {
       while (*Str != 0)
          UART_sendByte(*Str++);
 }

  void tx_uart(const char *Str,u16 n)
 {
    u16 i=0;

	for (i=0;i<n;i++) UART_sendByte(*Str++);
 }

void u_out (const char *s,u32 a)
{
   Transf (s);
   itoa (a,strng);
// sprintf (strng,"%u",a);
   Transf(strng);
   Transf ("\r");
}

void x_out (const char *s,u32 a) //
{
   Transf (s);
   itox (a,strng);
// sprintf (strng,"%X",a);
   Transf(strng);
   Transf ("\r");
}

void xn_out (const char *s,u32 a) //
{
   Transf (s);
   itox (a,strng);
// sprintf (strng,"%X",a);
   Transf(strng);
}

void un_out (const char *s,u32 a)
{
   Transf (s);
   itoa (a,strng);
// sprintf (strng,"%u",a);
   Transf(strng);
}

// ������� ��������� ������ ������
void ZeroArray(unsigned int *array, unsigned int len)
{
        unsigned int i;

        for (i=0;i<len;i++) {
                array[i] = 0;
        }
}

// ���������� ���������� ������ UART
void IER_UART()
{
//	UART0_IER = UART0_IER|0x01;// ERBI ���������� ���������� �� ������� �������� ������ (RDAI), � ����� �� �������� (CTI)
	UART1_IER = UART1_IER|0x01;// ERBI ���������� ���������� �� ������� �������� ������ (RDAI), � ����� �� �������� (CTI)
}

char getchar0(void)
{
   u8 data;
   while (rx_counter0 == 0);
   data = rx_buffer0[ rx_rd_index0++ ];
   if (rx_rd_index0 == RX_BUFFER_SIZE0) rx_rd_index0 = 0;
    --rx_counter0;
    return data;
}


void UART_conrol (void)
{
 u16 i=0;
 u16 j=0;

  if (rx_counter0!=0u)
    {
      if (rx_counter0<BUFFER_SR) j = rx_counter0; else j=BUFFER_SR;

      for (i=0u;i<j; i++)
         {
           sr[i]=getchar0();
           lenght=i+1;
           if (sr[i]==';') {break;}
          }
            sr[lenght]=0x00;
            //Transf("*");
            IO (sr);
        };
}


u8 leng ( char *s)
{
  u8 i=0;

   while ((s[i]!='\0')&&(i<120)) { i++;}

  return i;
}

void AT1(u8 a)
{
	if (a&0x01) GPIO_DR0 |=(1<<8);else GPIO_DR0 &=(~(1<<8));
	if (a&0x02) GPIO_DR0 |=(1<<9);else GPIO_DR0 &=(~(1<<9));

	if (a&0x04) GPIO_DR0 |=(1<<0);else GPIO_DR0 &=(~(1<<0));
	if (a&0x08) GPIO_DR0 |=(1<<1);else GPIO_DR0 &=(~(1<<1));

	if (a&0x10) GPIO_DR2 |=(1<<7);else GPIO_DR2 &=(~(1<<7));
	if (a&0x20) GPIO_DR2 |=(1<<8);else GPIO_DR2 &=(~(1<<8));
}

void AT2(u8 a)
{
	if (a&0x01) GPIO_DR0 |=(1<<2);else GPIO_DR0 &=(~(1<<2));
	if (a&0x02) GPIO_DR0 |=(1<<3);else GPIO_DR0 &=(~(1<<3));

	if (a&0x04) GPIO_DR0 |=(1<<4);else GPIO_DR0 &=(~(1<<4));
	if (a&0x08) GPIO_DR0 |=(1<<5);else GPIO_DR0 &=(~(1<<5));

	if (a&0x10) GPIO_DR0 |=(1<<6);else GPIO_DR0 &=(~(1<<6));
	if (a&0x20) GPIO_DR0 |=(1<<7);else GPIO_DR0 &=(~(1<<7));
}

void MFBSP0_init ()//����� ����� �����-������ ������ ����������
{
//	TX_MFBSP0
//	RX_MFBSP0

	CSR_MFBSP0=0;//������� ���������� � ���������
	CSR_MFBSP0|=(0x00)|//LEN � ������ I2S ������ ���� ���������� � 0
				(0<< 1)|//LTRAN
				(0<< 2)|//-----
				(0<< 3)|//LSTAT read only
				(0<< 9)|//SPI_I2S_EN  0 � ������ � ������ LPORT  1 � ������ � ������ SPI/I2S
				(0<<15)|//���������� ���������� MFBSP_RXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<16)|//���������� ���������� MFBSP_TXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<30)|//TX_RDY_MODE
				(0<<31);//RX_RDY_MODE

	DIR_MFBSP0=0x3ff;//��� ������
	GPIO_DR0  =0x000;

	TCTR0     =0;     //����� ��� - ����� SPI
	TCTR0    |=(0<< 0)|//TEN ���������� ������ �����������:
			   (0<< 1)|//TMODE  ����� ������ �����������:0 � ����� I2S;1 � ����� SPI
			   (0<< 3)|//SS_DO ���������� �������� SS ;0 � ���������� �������� SS ������������ � �������������� ������.
			   (0<< 9)|//TDSPMODE ������ �������� ������:0 � �������� � ������� I2S;1 � �������� � ������� DSP
			   (0<<10)|//TNEG ���������� ��������� ������� ����������� (������������ CPOL � ������������ Motorola)
			   (0<<11)|//TDEL �������� ������ �������� ������ �� ����  (������������ CPHA � ������������ Motorola)
			   (0<<19)|//TMBF ������� �������� ���:0 � ������� ����� ������;1 � ������� ����� ������
			   (0<<20)|//TWORDLEN ����� ������������� �����:����� ��� � ������������ ����� ����� TWORDLEN + 1.TWORDLEN ������ ���� ������ 0.
			   (0<<30)|//SS[0] ���� ���������� ����� Slave Select:��������� ������������ ������������ ������� ����������.
					  //��� SS_DO = 0 ��������� ���������������� ���� SS � 1
					  //�������� ����� �������� ����������, � ������� �����
					  //������������ ����� �������
					  //��� SS_DO = 1 �������� ��� SS ���������� �� ������
					  //SS ��������
			   (0<<31);//SS[1]  ��� SS_DO = 1 �������� ���� SS ���������� �� ����� LDAT[0]

	RCTR0	 =0;
	RCTR0	|=(0x00)|//REN ���������� ������ ��������:0 � �������� �������� 1 � �������� �������
			  (0<< 1)|//RMODE ����� ������ ��������:0 � ����� I2S 1 � ����� SPI
			  (0<< 2)|//RCLK_CP ������������ ������� RSCK:0 � RSCK ����������� ��� ����������� ���������� �� �����������
					 // 1 � RSCK �������� ��������� TSCK ����������� (� ���� ������ RCS_CP ������ ���� ��� �� � 1).
			  (0<< 3)|//RCS_CP ���������� �������� ������ �������� ��������:0 � ������ SS[1] ����������� ��������� � �������������� ��� ����������� ����� ���������
			  (0<<10)|//RNEG ���������� ��������� ������� ��������:(������������ CPOL � ������������ Motorola).
			  (0<<11)|//RDEL �������� ������ ����� ������ �� ��� �����:(������������ CPHA � ������������ Motorola).
			  (0<<19)|//RMBF ������� �������� ���:0 � ������� ����� ������ 1 � ������� ����� ������
			  (0<<20);//RWORDLEN ����� ������������ �����:����� ��� � ����������� ����� ����� RWORDLEN + 1. RWORDLEN ������ ���� ������ 0


	TSR0	=0;//������� ��������� ����������� TSR (����� SPI)
	TSR0   |=0;

	RSR0    =0;// ������� ��������� �������� RSR (����� SPI)
}

//  LPORT
// ������� LPORT � ��
#define LPORT_FRQ 50000000

// ����� ������� � 32-��������� ������
#define ARRAY_LEN_lport 3000

// ������ �������� ������ ���� ��������� �� ������� 64-���������� �����,
// ���� ��� ����� ������������ �� DMA
//unsigned int lport_OutputArray[ARRAY_LEN_lport] __attribute__ ((aligned (8)));
unsigned int lport_InputArray[ARRAY_LEN_lport] __attribute__ ((aligned (8)));

unsigned int flag_DMA_LPORT    =0;
unsigned int flag_DMA_LPORT_old=0;

// ��������� �������� �������� CP0 Status
void SetCP0_Status(unsigned int value)
{
  asm volatile ("mtc0 %0, $12" ::"r"(value));
}


// ��������� ������ ���������� �������� ���������� TR_CRAM �� ���������� ������
void TR_CRAM_set()
{
   //  CSR |= (1<<1);   //TR_CRAM
}

// ��������� �������� MASKR2 �� ����������
void MASKR2_set()
{
    // ����������� ������� ����� ���������� (MASKR2)
    // ���������� ������ MASKR2[29], ����������� ���������� �� DMA ������
    MASKR2 |= (1<<7);
}


// ������� �����������
void ID1_LPORT_handler()
{

//---------DMA ����� MFBSP---------
unsigned int ActiveIRQ;
unsigned int tmp_read;

    ActiveIRQ = QSTR2 & MASKR2;
    if ( (ActiveIRQ & (1<<7)) != 0 )
	{  // ���� ��� ���������� �� ������ DMA ����� MFBSP1 ��� ������ ������
    // ���������� ���� DONE � END ��������� ���������� � ��������� DMA ������, ����� ����� ����������
       tmp_read = CSR_MFBSP_RX_CH1;
//     tmp_read = CSR_MFBSP_TX_CH1;
	 //  lPORT_DMA ();
       flag_DMA_LPORT++;    //  ���� ���������� ��������� ����������
    }
}

// ������� �����������
void int_handler()
{
//---------UART--------------------
    tmp_read = UART1_IIR;

   rx_buffer0[rx_wr_index0++]= UART1_RBR; //��������� ������ � �����, ������������� ����� ������
   if ( rx_wr_index0 == RX_BUFFER_SIZE0) rx_wr_index0=0; //���� �� �����

    if (++rx_counter0 == RX_BUFFER_SIZE0) //������������ ������
      {
        rx_counter0=0; //�������� ������� (������� ��� ������)
        rx_buffer_overflow0=1;  //�������� � ������������
      }
}


void MFBSP1_init ()//����� ����� LPORT
{
   unsigned int LCLK_RATE;

   LCLK_RATE = (FREQ/(2*LPORT_FRQ)) - 1;

//	TX_MFBSP1
//	RX_MFBSP1
//	CSR_MFBSP1=0;//������� ���������� � ���������
	CSR_MFBSP1|=(0x01)|//LEN � ������ �������� ����(LPORT)
				(0<< 1)|//LTRAN 0 � ��������;
    ((LCLK_RATE&1)<< 2)|//LCLK_RATE[0] �������� ������� LPORT:LCLK = CLK/(2*(LCLK_RATE+1))
				(0<< 3)|//LSTAT read only
				(0<< 5)|//LRERR read only ������ ������ ������.
				(1<< 6)|//LDW ����������� ������� ���� ������:1 - 8-������� (32-��������� ����� ���������� �� 4 �������).
				(0<< 7)|//SRQ_TX ������� ������� ������������ �� �������� ������
				(0<< 8)|//SRQ_RX ������� ������� ������������ �� ����� ������
				(0<< 9)|//SPI_I2S_EN  0 � ������ � ������ LPORT  1 � ������ � ������ SPI/I2S
				(0<<10)|//LPT_IRQ_EN ���������� ���������� SRQ:1 � ���������� �� ������� ������������ LPORT ���������
   ((LCLK_RATE>>1)<<11)|//LCLK_RATE[4:1] �������� ������� LPORT:LCLK = CLK/(2*(LCLK_RATE+1))
				(0<<15)|//���������� ���������� MFBSP_RXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<16)|//���������� ���������� MFBSP_TXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<30)|//TX_RDY_MODE ����� ������������ �������� ���������� �������� ������ �� MFBSP � DMA:
				(0<<31);//RX_RDY_MODE ����� ������������ �������� ���������� ������ ������ �� DMA � MFBSP:

	DIR_MFBSP1=0x001;//LACK - �����, ��������� �����
	GPIO_DR1  =0x000;

	TCTR1     =0;     //����� ��� - ����� SPI
	TCTR1    |=(0<< 0)|//TEN ���������� ������ �����������:
			   (0<< 1)|//TMODE  ����� ������ �����������:0 � ����� I2S;1 � ����� SPI
			   (0<< 3)|//SS_DO ���������� �������� SS ;0 � ���������� �������� SS ������������ � �������������� ������.
			   (0<< 9)|//TDSPMODE ������ �������� ������:0 � �������� � ������� I2S;1 � �������� � ������� DSP
			   (0<<10)|//TNEG ���������� ��������� ������� ����������� (������������ CPOL � ������������ Motorola)
			   (0<<11)|//TDEL �������� ������ �������� ������ �� ����  (������������ CPHA � ������������ Motorola)
			   (0<<19)|//TMBF ������� �������� ���:0 � ������� ����� ������;1 � ������� ����� ������
			   (0<<20)|//TWORDLEN ����� ������������� �����:����� ��� � ������������ ����� ����� TWORDLEN + 1.TWORDLEN ������ ���� ������ 0.
			   (0<<30)|//SS[0] ���� ���������� ����� Slave Select:��������� ������������ ������������ ������� ����������.
					  //��� SS_DO = 0 ��������� ���������������� ���� SS � 1
					  //�������� ����� �������� ����������, � ������� �����
					  //������������ ����� �������
					  //��� SS_DO = 1 �������� ��� SS ���������� �� ������
					  //SS ��������
			   (0<<31);//SS[1]  ��� SS_DO = 1 �������� ���� SS ���������� �� ����� LDAT[0]

	RCTR1	 =0;
	RCTR1	|=(0x00)|//REN ���������� ������ ��������:0 � �������� �������� 1 � �������� �������
			  (0<< 1)|//RMODE ����� ������ ��������:0 � ����� I2S 1 � ����� SPI
			  (0<< 2)|//RCLK_CP ������������ ������� RSCK:0 � RSCK ����������� ��� ����������� ���������� �� �����������
					 // 1 � RSCK �������� ��������� TSCK ����������� (� ���� ������ RCS_CP ������ ���� ��� �� � 1).
			  (0<< 3)|//RCS_CP ���������� �������� ������ �������� ��������:0 � ������ SS[1] ����������� ��������� � �������������� ��� ����������� ����� ���������
			  (0<<10)|//RNEG ���������� ��������� ������� ��������:(������������ CPOL � ������������ Motorola).
			  (0<<11)|//RDEL �������� ������ ����� ������ �� ��� �����:(������������ CPHA � ������������ Motorola).
			  (0<<19)|//RMBF ������� �������� ���:0 � ������� ����� ������ 1 � ������� ����� ������
			  (0<<20);//RWORDLEN ����� ������������ �����:����� ��� � ����������� ����� ����� RWORDLEN + 1. RWORDLEN ������ ���� ������ 0


	TSR1	=0;//������� ��������� ����������� TSR (����� SPI)
	TSR1   |=0;

	RSR1    =0;// ������� ��������� �������� RSR (����� SPI)
}

void MFBSP2_init ()//����� ����� SPI + �����-������ ������ ����������
{
//	TX_MFBSP1
//	RX_MFBSP1

	DIR_MFBSP2  =0;
	DIR_MFBSP2 |=
				(1<< 0)|//����������� ������ RSCK:0 � RSCK � ���� (�������� ������ RSCK ����������� �� �������� ���������)
				(1<< 1)|//����������� ������ TSCK:1 � TSCK � ����� (�������� ������ TSCK ����������� ������������)
				(1<< 2)|//����������� ������ SS[1]
				(1<< 3)|//����������� ������ SS[0] 1 � SS[0] - �����, ����������� ������ ����������� ������������
				(0<< 4)|//����������� ������ MISO:0 � MISO � ���� (���������������� ������ ����������� �� ����� MISO - ���������� SDI)
				(1<< 5)|//����������� ������ MOSI:1 � MOSI - ����� (MOSI � �������� ������� ��� �������� ���������������� ������ � �������� ������������ SDO)
				(1<< 6)|//PWRDWN_A1
				(1<< 7)|//At
				(1<< 8)|//At
				(1<< 9);//RST_1288


	GPIO_DR2  =0xfff;

	CSR_MFBSP2=0;//������� ���������� � ���������

/*	CSR_MFBSP2|=(0x00)|//LEN � ������ SPI
				(0<< 1)|//LTRAN 0 � ��������;
				(0<< 2)|//LCLK_RATE[0] �������� ������� LPORT:LCLK = CLK/(2*(LCLK_RATE+1))
				(0<< 3)|//LSTAT read only
				(0<< 5)|//LRERR read only ������ ������ ������.
				(1<< 6)|//LDW ����������� ������� ���� ������:1 - 8-������� (32-��������� ����� ���������� �� 4 �������).
				(0<< 7)|//SRQ_TX ������� ������� ������������ �� �������� ������
				(0<< 8)|//SRQ_RX ������� ������� ������������ �� ����� ������
				(0<< 9)|//SPI_I2S_EN  0 � ������ � ������ LPORT  1 � ������ � ������ SPI/I2S
				(0<<10)|//LPT_IRQ_EN ���������� ���������� SRQ:1 � ���������� �� ������� ������������ LPORT ���������
				(0<<11)|//LCLK_RATE[4:1] �������� ������� LPORT:LCLK = CLK/(2*(LCLK_RATE+1))
				(0<<15)|//���������� ���������� MFBSP_RXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<16)|//���������� ���������� MFBSP_TXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<30)|//TX_RDY_MODE ����� ������������ �������� ���������� �������� ������ �� MFBSP � DMA:
				(0<<31);//RX_RDY_MODE ����� ������������ �������� ���������� ������ ������ �� DMA � MFBSP:

	DIR_MFBSP2 =0;//

	DIR_MFBSP2|=(0x00)|
				(0<< 0)|//����������� ������ RSCK:0 � RSCK � ���� (�������� ������ RSCK ����������� �� �������� ���������)
				(0<< 1)|//����������� ������ TSCK:1 � TSCK � ����� (�������� ������ TSCK ����������� ������������)
				(1<< 2)|//����������� ������ SS[1]
				(1<< 3)|//����������� ������ SS[0] 1 � SS[0] - �����, ����������� ������ ����������� ������������
				(0<< 4)|//����������� ������ MISO:0 � MISO � ���� (���������������� ������ ����������� �� ����� MISO - ���������� SDI)
				(1<< 5)|//����������� ������ MOSI:1 � MOSI - ����� (MOSI � �������� ������� ��� �������� ���������������� ������ � �������� ������������ SDO)
				(1<< 6)|//PWRDWN_A2
				(1<< 7)|//AT1_5
				(1<< 8)|//AT1_6
				(1<< 9);//PF1_SYNC_START


	GPIO_DR2  =0x03f;

	TCTR2     =0;     //����� ��� - ����� SPI
	TCTR2    |=(1<< 0)|//TEN ���������� ������ �����������:
			   (1<< 1)|//TMODE  ����� ������ �����������:0 � ����� I2S;1 � ����� SPI
			   (0<< 3)|//SS_DO ���������� �������� SS ;0 � ���������� �������� SS ������������ � �������������� ������.
			   (0<< 9)|//TDSPMODE ������ �������� ������:0 � �������� � ������� I2S;1 � �������� � ������� DSP
			   (0<<10)|//TNEG ���������� ��������� ������� ����������� (������������ CPOL � ������������ Motorola)
			   (0<<11)|//TDEL �������� ������ �������� ������ �� ����  (������������ CPHA � ������������ Motorola)
			   (1<<19)|//TMBF ������� �������� ���:0 � ������� ����� ������;1 � ������� ����� ������
			   (0<<20)|//TWORDLEN ����� ������������� �����:����� ��� � ������������ ����� ����� TWORDLEN + 1.TWORDLEN ������ ���� ������ 0.
			   (0<<30)|//SS[0] ���� ���������� ����� Slave Select:��������� ������������ ������������ ������� ����������.
					  //��� SS_DO = 0 ��������� ���������������� ���� SS � 1
					  //�������� ����� �������� ����������, � ������� �����
					  //������������ ����� �������
					  //��� SS_DO = 1 �������� ��� SS ���������� �� ������
					  //SS ��������
			   (0<<31);//SS[1]  ��� SS_DO = 1 �������� ���� SS ���������� �� ����� LDAT[0]

	RCTR2	 =0;
	RCTR2	|=(0x01)|//REN ���������� ������ ��������:0 � �������� �������� 1 � �������� �������
			  (1<< 1)|//RMODE ����� ������ ��������:0 � ����� I2S 1 � ����� SPI
			  (1<< 2)|//RCLK_CP ������������ ������� RSCK:0 � RSCK ����������� ��� ����������� ���������� �� �����������
					 // 1 � RSCK �������� ��������� TSCK ����������� (� ���� ������ RCS_CP ������ ���� ��� �� � 1).
			  (1<< 3)|//RCS_CP ���������� �������� ������ �������� ��������:0 � ������ SS[1] ����������� ��������� � �������������� ��� ����������� ����� ���������
			  (0<<10)|//RNEG ���������� ��������� ������� ��������:(������������ CPOL � ������������ Motorola).
			  (0<<11)|//RDEL �������� ������ ����� ������ �� ��� �����:(������������ CPHA � ������������ Motorola).
			  (1<<19)|//RMBF ������� �������� ���:0 � ������� ����� ������ 1 � ������� ����� ������
			  (7<<20);//RWORDLEN ����� ������������ �����:����� ��� � ����������� ����� ����� RWORDLEN + 1. RWORDLEN ������ ���� ������ 0


	TSR2	=0;//������� ��������� ����������� TSR (����� SPI)
	TSR2   |=0;

	RSR2    =0;// ������� ��������� �������� RSR (����� SPI)
	*/
}

void MFBSP3_init ()//����� ����� SPI + �����-������ ������ ����������
{
//	TX_MFBSP1
//	RX_MFBSP1

u16 l=0;

// DIR_MFBSP3 = 0xff;   // ����������� LDAT[7:0] � ����� ������
// GPIO_DR3   = 0xff;   // ������� ������

	CSR_MFBSP3=0;//������� ���������� � ���������
/*
	CSR_MFBSP3|=(0x00)|//LEN � ������ SPI
				(0<< 1)|//LTRAN 0 � ��������;
				(0<< 2)|//LCLK_RATE[0] �������� ������� LPORT:LCLK = CLK/(2*(LCLK_RATE+1))
				(0<< 3)|//LSTAT read only
				(0<< 5)|//LRERR read only ������ ������ ������.
				(1<< 6)|//LDW ����������� ������� ���� ������:1 - 8-������� (32-��������� ����� ���������� �� 4 �������).
				(0<< 7)|//SRQ_TX ������� ������� ������������ �� �������� ������
				(0<< 8)|//SRQ_RX ������� ������� ������������ �� ����� ������
				(0<< 9)|//SPI_I2S_EN  0 � ������ � ������ LPORT  1 � ������ � ������ SPI/I2S
				(0<<10)|//LPT_IRQ_EN ���������� ���������� SRQ:1 � ���������� �� ������� ������������ LPORT ���������
				(0<<11)|//LCLK_RATE[4:1] �������� ������� LPORT:LCLK = CLK/(2*(LCLK_RATE+1))
				(0<<15)|//���������� ���������� MFBSP_RXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<16)|//���������� ���������� MFBSP_TXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<30)|//TX_RDY_MODE ����� ������������ �������� ���������� �������� ������ �� MFBSP � DMA:
				(0<<31);//RX_RDY_MODE ����� ������������ �������� ���������� ������ ������ �� DMA � MFBSP:
				*/

//	DIR_MFBSP3 =0x26c;//


	DIR_MFBSP3  =0x00000000;
	DIR_MFBSP3 |=
				(1<< 0)|//����������� ������ RSCK:0 � RSCK � ���� (�������� ������ RSCK ����������� �� �������� ���������)
				(1<< 1)|//����������� ������ TSCK:1 � TSCK � ����� (�������� ������ TSCK ����������� ������������)
				(1<< 2)|//����������� ������ SS[1]
				(1<< 3)|//����������� ������ SS[0] 1 � SS[0] - �����, ����������� ������ ����������� ������������
				(0<< 4)|//����������� ������ MISO:0 � MISO � ���� (���������������� ������ ����������� �� ����� MISO - ���������� SDI)
				(1<< 5)|//����������� ������ MOSI:1 � MOSI - ����� (MOSI � �������� ������� ��� �������� ���������������� ������ � �������� ������������ SDO)
				(1<< 6)|//PWRDWN_A1
				(0<< 7)|//NA
				(0<< 8)|//NA
				(1<< 9);//RST_1288


	GPIO_DR3  =0xfff;

//			 x_out("l=",l);
/*
	TCTR3     =0;     //����� ��� - ����� SPI

	TCTR3    |=(1<< 0)|//TEN ���������� ������ �����������:
			   (1<< 1)|//TMODE  ����� ������ �����������:0 � ����� I2S;1 � ����� SPI
			   (1<< 3)|//SS_DO  �������� ��� SS �������� ���������� �� ������� ������.
			   (0<< 9)|//TDSPMODE ������ �������� ������:0 � �������� � ������� I2S;1 � �������� � ������� DSP
			   (0<<10)|//TNEG ���������� ��������� ������� ����������� (������������ CPOL � ������������ Motorola)
			   (0<<11)|//TDEL �������� ������ �������� ������ �� ����  (������������ CPHA � ������������ Motorola)
			   (1<<19)|//TMBF ������� �������� ���:0 � ������� ����� ������;1 � ������� ����� ������
			   (0<<20)|//TWORDLEN ����� ������������� �����:����� ��� � ������������ ����� ����� TWORDLEN + 1.TWORDLEN ������ ���� ������ 0.
			   (0<<30)|//SS[0] ���� ���������� ����� Slave Select:��������� ������������ ������������ ������� ����������.
					  //��� SS_DO = 0 ��������� ���������������� ���� SS � 1
					  //�������� ����� �������� ����������, � ������� �����
					  //������������ ����� �������
					  //��� SS_DO = 1 �������� ��� SS ���������� �� ������
					  //SS ��������
			   (0<<31);//SS[1]  ��� SS_DO = 1 �������� ���� SS ���������� �� ����� LDAT[0]

	RCTR3	 =0;*/
/*
	RCTR3	|=(0x01)|//REN ���������� ������ ��������:0 � �������� �������� 1 � �������� �������
			  (1<< 1)|//RMODE ����� ������ ��������:0 � ����� I2S 1 � ����� SPI
			  (1<< 2)|//RCLK_CP ������������ ������� RSCK:0 � RSCK ����������� ��� ����������� ���������� �� �����������
					 // 1 � RSCK �������� ��������� TSCK ����������� (� ���� ������ RCS_CP ������ ���� ��� �� � 1).
			  (1<< 3)|//RCS_CP ���������� �������� ������ �������� ��������:0 � ������ SS[1] ����������� ��������� � �������������� ��� ����������� ����� ���������
			  (0<<10)|//RNEG ���������� ��������� ������� ��������:(������������ CPOL � ������������ Motorola).
			  (0<<11)|//RDEL �������� ������ ����� ������ �� ��� �����:(������������ CPHA � ������������ Motorola).
			  (1<<19)|//RMBF ������� �������� ���:0 � ������� ����� ������ 1 � ������� ����� ������
			  (7<<20);//RWORDLEN ����� ������������ �����:����� ��� � ����������� ����� ����� RWORDLEN + 1. RWORDLEN ������ ���� ������ 0


	TSR3	=0;//������� ��������� ����������� TSR (����� SPI)
	TSR3   |=0;

	RSR3    =0;// ������� ��������� �������� RSR (����� SPI)

*/
}

void init_GPIO_DR2 (u16 a,u8 z)
{
	if (z==RESET) GPIO_DR2&=(~(a<<2)); else GPIO_DR2|=(a<<2);
}

void init_GPIO_DR3 (u16 a,u8 z)
{
	if (z==RESET) GPIO_DR3&=(~(a<<2)); else GPIO_DR3|=(a<<2);
}


// ���� �������
 void LED(u8 a)
{
	if ((a&0x01)==1) TST1(1); else TST1(0);
//	u_out("a:",a);
// GPIO_DR3 =a;

} //LED_on

void adc1_init (u8 a)
{
	A1_CSB(1);
	A1_SPLIN(0);

	if (a==1) A1_PWRDN(0); else	A1_PWRDN(1);

//	Delay_ms(100);

//	A1_SPLIN(1);

//	Delay_ms(50);

//	A1_SPLIN(0);
}

void adc2_init (u8 a)
{
	A2_CSB(1);
	A2_SPLIN(0);

	if (a==1) A2_PWRDN(0); else	A2_PWRDN(1);

//	Delay_ms(100);

//	A2_SPLIN(1);

//	Delay_ms(50);

//	A2_SPLIN(0);
}

void Menu1()
{
//***************************************************************************

    int i;
/*
  for (i=0;i<20;i++) Transf("\r");    // ������� ���������
  for (i=0; i<20; i++) Transf ("-");  // ����� �����������
  Transf("\r");
  Transf("..........Terminal �������� �����.........\r\n");
  Transf("\r");
  Transf("MENU :\r");
  Transf("-------\r");
  Transf("����������� ��������� �������:\r");
  Transf("~ - ��������� ����\r");
  Transf("1 - ����� ��������\r");
  Transf(";- ����� ����� \r");
  Transf(".............. \r");
  Transf("---------------------------------------------\r\n");
  Transf("IP  :192.168.1.163 - IP �����    �����\r");
  Transf("PORT:2054          - ����� ����� �����\r");
  Transf("~0 help; - ������� ����\r");
  Transf("~0 info; - ���������� \r");
  Transf("~0 dac1_init; - \r");
  Transf("~0 dac1_r:0;   - ������ ��������\r");
  Transf("~0 dac1_w:0.0; - ������ ��������\r");
  Transf("~0 dac1_serdes_pll:1; - ������� �������� ������� ������� PLL Serdes\r");
  Transf("~0 dac1_info:0; \r");
  Transf("~0 dac1_init:0; \r");
  Transf("~0 dac1_phy_wr:0; \r");
  Transf("~0 dac1_phy_info; \r");
  Transf("~0 lmk_sync; - sync �� LMK\r");
  Transf("~0 init_lmk; - init �� LMK\r");
  Transf("-------------------------------------------\r");
  Transf("\r");
  Transf("\r");
  Transf("++++++++++++++++++++\r");
  Transf("\r");
  Transf("\r");
  //for (i=0; i<64; i++) zputs ("*",1);  // ����� �����������
  //for (i=0;i<10;i++) puts("\r",1);  // ������� ���������
  Transf("\r");
  //*******************************************************************************
  */
}


u32 crc_input=0u;
u32 crc_comp=0u;

u32 IO ( char* str)      // ������� ��������� ��������� ������
{

 unsigned int i=0;

  i = lenght;//������ �������� �����
  if (lenght==0) i = leng(str);
  lenght = 0;
  indexZ = 0;

  while (i>0u)   //���������� ��������� ������ � ������ ���������
  {


  if ((str[indexZ]==0x7e)&&(packet_flag==0))// ���������� ������ ������
    {
    //-------------------
    packet_flag=1;
    //-------------------
    time_uart=0u;  //��������� �������� ���� ����
    index1=0u;
    crc_ok=0;
    packet_ok=0;
    index_word=0u;
    index_data_word =1u;
    index_data_word2=1u;
    data_flag =0;
    data_flag2=0;
      FLAG_lenght=0u;
      lenght_data=0u;
      sch_lenght_data=0u;
    DATA_Word [0]=' ';
    DATA_Word2[0]=' ';
      FLAG_CW = 0u; //���� ������������ �����, ��������� ����� ����� ����������
    FLAG_DATA = 0u;
    SCH_LENGHT_PACKET=0;

    }

   InOut[index1]=str[indexZ];
   SCH_LENGHT_PACKET++;//������������ ������ ������

  if (( InOut[index1]==';')&&(FLAG_DATA==0u)&&(packet_flag==1))  {packet_flag=0;packet_ok=1u;FLAG_CW=1u;}

  if (((InOut[index1]=='=')||(InOut[index1]==':'))&&(data_flag==0)) {data_flag=1u;FLAG_CW=1u;}

  if (( InOut[index1]=='.')&&(data_flag2==0)&&(FLAG_DATA==0))   {data_flag2=1u; FLAG_CW=1u;}

  if (( InOut[index1]=='$')&&(FLAG_lenght==0u)) {FLAG_lenght=2u;FLAG_CW=1u;}

  if ((index1>2u)&&(InOut[2]==' ')&&(FLAG_CW==0u)&&(FLAG_lenght<2u))
            {
                             if   (data_flag!=1u) {Word[index_word]=InOut[index1];} // ��������� ��������� �����

                             if  ((data_flag==1u)&&(data_flag2==0u))     DATA_Word[index_data_word]=InOut[index1];// ���������  ����� ������1
                             if  ((data_flag==1u)&&(data_flag2==1u))     DATA_Word2[index_data_word2]=InOut[index1]; // ���������  ����� ������2

                             if  (data_flag!=1u)
                                     {if (index_word<buf_Word) index_word++;}
                                   else
                                            {
                                             if ((data_flag==1u)&&(data_flag2==0u)) if (index_data_word<buf_DATA_Word)  {index_data_word++;sch_lenght_data++;}

                                             if ((data_flag==1u)&&(data_flag2==1u)) if (index_data_word2<buf_DATA_Word) index_data_word2++;
                                            }
      }

    if ((FLAG_lenght==2u)&&(FLAG_CW==0u)) {lenght_data = (u8)(InOut[index1]);FLAG_lenght=1u;} //���������� ������ ������ ������ ����� ":"

    if ((sch_lenght_data<lenght_data)&&(FLAG_lenght==1u)) FLAG_DATA = 1u; else {FLAG_DATA = 0u;}

    if (index1<BUFFER_SR)  index1++;
    if (indexZ <BUFFER_SR)  indexZ ++;
    i--;
    FLAG_CW=0u;

  }


if (packet_ok==1u)
  {
      if (InOut[0]==0x7e)   crc_ok=crc_ok|0x1;   // �������� ������� ������� ������ - ������ ������
      if (InOut[1]==Adress) crc_ok=crc_ok|0x2;   // �������� ������� ������� ������ - ������� ����������

if (crc_ok==0x3)  //��������� ������ ��������� ������� �������� ������
{
/*
  if (strcmp(Word,"reg_1288")==0)
   {
	 u_out ("������ reg_1288:",1);
	 dsp_1288hk1t_reg ();
   } else
	   */
   if (strcmp(Word,"resiver")==0)
   {
	 crc_comp =atoi(DATA_Word);
	 u_out ("������ resiver:",crc_comp);
	 VAR_RESIVER=crc_comp;
   } else
  if (strcmp(Word,"LPORT_DMA")==0)
   {
	 crc_comp =atoi(DATA_Word);
	 u_out ("������ LPORT_DMA:",crc_comp);
	 lPORT_DMA ();
   } else
  if (strcmp(Word,"SW_tx")==0)
   {
	 crc_comp =atoi(DATA_Word);
	 u_out ("������ SW_tx:",crc_comp);
	 sw_data_obmen (crc_comp);
   } else
  if (strcmp(Word,"SW_init")==0)
   {
	 crc_comp =atoi(DATA_Word);
	 u_out ("������ SW_init:",crc_comp);
	  SW_init ();
   } else
  if (strcmp(Word,"init_1288")==0)
   {
	 crc_comp =atoi(DATA_Word);
	 u_out ("������ init_1288:",crc_comp);
	 dsp_1288hk1t_init();

   } else
 if (strcmp(Word,"rst_1288")==0)
   {
	 crc_comp =atoi(DATA_Word);
	 u_out ("������ rst_1288:",crc_comp);
	  RST_1288(crc_comp);
   } else
if (strcmp(Word,"help")==0)
   {
     Transf ("������ help\r"    );
     Transf("\r");
     Menu1(0);
   } else
if (strcmp(Word,"adc")==0) //
   {
	Transf ("----------\r"    );
	crc_comp =atoi(DATA_Word);
	u_out ("������ adc:",crc_comp);
	adc1_init (crc_comp);
	adc2_init (crc_comp);
    } else

 if (strcmp(Word,"init_adc1")==0) //
   {
	Transf ("----------\r"    );
	crc_comp =atoi(DATA_Word);
	u_out ("������ init_adc1:",crc_comp);
	adc1_init (crc_comp);
    } else

 if (strcmp(Word,"init_adc2")==0) //
   {
	Transf ("----------\r"    );
	crc_comp =atoi(DATA_Word);
	u_out ("������ init_adc2:",crc_comp);
	adc2_init (crc_comp);
    } else

if (strcmp(Word,"upr_at1")==0) //
   {
	crc_comp =atoi(DATA_Word);
	u_out ("������ upr_at1:",crc_comp);
	AT1(crc_comp);
    } else

if (strcmp(Word,"upr_at2")==0) //
   {
	crc_comp =atoi(DATA_Word);
	u_out ("������ upr_at2:",crc_comp);
	AT2(crc_comp);
    } else

if (strcmp(Word,"spi_w")==0) //
   {
	crc_comp =atoi(DATA_Word);  //������
	crc_input=atoi(DATA_Word2); //������
	un_out ("������ spi_w:",crc_comp);
	u_out (".",crc_input);
	spi_1288_wr (crc_comp,crc_input);
   } else

if (strcmp(Word,"spi_r")==0) //
   {
	crc_comp =atoi(DATA_Word);  //������
	crc_input=atoi(DATA_Word2); //������
	u_out ("������ spi_r:",crc_comp);
	x_out(">",spi_1288_rd (crc_comp));
   }
}
      for (i=0u;i<buf_Word;i++)               Word[i]     =0x0;
      for (i=0u;i<buf_DATA_Word;  i++)   DATA_Word[i]     =0x0;
      for (i=0u;i<buf_DATA_Word;  i++)  DATA_Word2[i]     =0x0;
      for (i=0u;i<BUFFER_SR;i++)
      {
        InOut[i]     =0x0;
      }

      time_uart=0;  //��������� �������� ���� ����
      packet_flag=0;
      index1=0u;
      crc_ok=0;
      i=0;
      packet_ok=0;
      index_word=0u;
      index_data_word=0u;
      data_flag=0;
      index_data_word2=0u;
      data_flag2=0;
      indexZ =0u;
      FLAG_lenght=0u;
      lenght_data=0u;
      sch_lenght_data=0u;
      FLAG_CW = 0u; //���� ������������ �����, ��������� ����� ����� ����������
      FLAG_DATA = 0u;

      DATA_Word [0]=' ';
      DATA_Word2[0]=' ';
    SCH_LENGHT_PACKET=0;
  }

  if ((packet_ok==1)&&(crc_ok==0x1))     //��������� ������ ��������� ������� �������� �����
  {
    if (Master_flag==0)
      {

      }
  }

  return  0;
}



//-------------������ IT0--------------------
void ID0_init (void)
{
	ITCSR0    = 0x00;
	ITPERIOD0 = 1000; //1 ms
	ITSCALE0  = 100;  //1 MHz
//	ITCOUNT0  = 0;

	ITCSR0    = ITCSR0|0x01;
}



void ID0_IT_handler ()
{
	ITCSR0    = ITCSR0&(~0x02);
	if (SYS_timer0!=0) SYS_timer0--;
	if (SYS_timer1!=0) SYS_timer1--;
	if (Dtimer0   !=0) Dtimer0   --;
//	Transf(">");
}
//---------------------------------



//---------------------------------

u32 spi (u32 a)
{
	u32 data=0;
	TX_SPI=a;                 //�������� ���������� ��������
    while (!(CSR_SPI & 1<<4));//�������� ��������� ����� ������
    data=RX_SPI;              //������ ����������� ��������
	return (data&0xffffff);
}

#define SETA   0x18
#define GETA   0x90
#define WR     0x28
#define WRI    0x38
#define GETD   0xa0
#define SETAFT 0xb8


u32 spi_1288_wr (u16 adr,u16 data)
{
	u32 var=0;
	var=(SETA<<16)|adr;
	spi (var);//��������� ������ �� ���������� �������� ������ �����
	var=(WR<<16)|data;
	spi (var);//������ ������ � ������� 1288��1� �� ����� �������������� ������
	return 0;
}

u32 spi_1288_rd (u16 adr)
{
	u32 var=0;
	u32 z=0;
	var=(SETAFT<<16)|adr;//��������� ������ �� ���������� �������� ����� c �������� �������� �������� 1288��1� �� ����� ������ �� ���������� ������� ������ �����
	spi (var);
	var=(GETD<<16)&0xffff0000;//������ �� ����������� �������� ������ �����
	z=spi(var);
	return (z&0xffff);
}


void SPI_init ()
{
//	TX_SPI
//	RX_SPI
//	CSR_SPI
//	DIR_SPI
//	TCTR
//	RCTR
//	TSR
//	RSR

//	TX_MFBSP1
//	RX_MFBSP1

	CSR_SPI =0;//������� ���������� � ���������
	CSR_SPI|=(0x00)|//LEN � ������ SPI
				(0<< 1)|//LTRAN 0 � ��������;
				(0<< 3)|//LSTAT read only
				(1<< 9)|//SPI_I2S_EN  0 � ������ � ������ LPORT  1 � ������ � ������ SPI/I2S
				(0<<15)|//���������� ���������� MFBSP_RXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<16)|//���������� ���������� MFBSP_TXBUF:0 � ���������� ���������;1- ���������� ���������.
				(0<<30)|//TX_RDY_MODE ����� ������������ �������� ���������� �������� ������ �� MFBSP � DMA:
				(0<<31);//RX_RDY_MODE ����� ������������ �������� ���������� ������ ������ �� DMA � MFBSP:

	DIR_SPI =0;//
	DIR_SPI|=   (0x00)|
				(0<< 0)|//����������� ������ RSCK:0 � RSCK � ���� (�������� ������ RSCK ����������� �� �������� ���������)
				(1<< 1)|//����������� ������ TSCK:1 � TSCK � ����� (�������� ������ TSCK ����������� ������������)
				(1<< 2)|//����������� ������ SS[1]
				(1<< 3)|//����������� ������ SS[0] 1 � SS[0] - �����, ����������� ������ ����������� ������������
				(0<< 4)|//����������� ������ MISO:0 � MISO � ���� (���������������� ������ ����������� �� ����� MISO - ���������� SDI)
				(1<< 5);//����������� ������ MOSI:1 � MOSI - ����� (MOSI � �������� ������� ��� �������� ���������������� ������ � �������� ������������ SDO)



	 TCTR     =0;     //����� ��� - ����� SPI
	 TCTR    |=(1 << 0)|//TEN ���������� ������ �����������:
			   (1 << 1)|//TMODE  ����� ������ �����������:0 � ����� I2S;1 � ����� SPI
			   (0 << 3)|//SS_DO ���������� �������� SS ;0 � ���������� �������� SS ������������ � �������������� ������.
			   (30<< 4)|
			   (1 <<10)|//TNEG ���������� ��������� ������� ����������� (������������ CPOL � ������������ Motorola)
			   (1 <<11)|//TDEL �������� ������ �������� ������ �� ����  (������������ CPHA � ������������ Motorola)
			   (1 <<19)|//TMBF ������� �������� ���:0 � ������� ����� ������;1 � ������� ����� ������
			   (23<<20)|//TWORDLEN ����� ������������� �����:����� ��� � ������������ ����� ����� TWORDLEN + 1.TWORDLEN ������ ���� ������ 0.
			   (1 <<30)|//SS[0] ���� ���������� ����� Slave Select:��������� ������������ ������������ ������� ����������.
					  //��� SS_DO = 0 ��������� ���������������� ���� SS � 1
					  //�������� ����� �������� ����������, � ������� �����
					  //������������ ����� �������
					  //��� SS_DO = 1 �������� ��� SS ���������� �� ������
					  //SS ��������
			   (1<<31);//SS[1]  ��� SS_DO = 1 �������� ���� SS ���������� �� ����� LDAT[0]



	RCTR	 =0;
	RCTR	|=(0x01)|//REN ���������� ������ ��������:0 � �������� �������� 1 � �������� �������
			  (1 << 1)|//RMODE ����� ������ ��������:0 � ����� I2S 1 � ����� SPI
			  (1 << 2)|//RCLK_CP ������������ ������� RSCK:0 � RSCK ����������� ��� ����������� ���������� �� �����������
					 // 1 � RSCK �������� ��������� TSCK ����������� (� ���� ������ RCS_CP ������ ���� ��� �� � 1).
			  (1 << 3)|//RCS_CP ���������� �������� ������ �������� ��������:0 � ������ SS[1] ����������� ��������� � �������������� ��� ����������� ����� ���������

			  (1 <<10)|//RNEG ���������� ��������� ������� ��������:(������������ CPOL � ������������ Motorola).
			  (1 <<11)|//RDEL �������� ������ ����� ������ �� ��� �����:(������������ CPHA � ������������ Motorola).
			  (1 <<19)|//RMBF ������� �������� ���:0 � ������� ����� ������ 1 � ������� ����� ������
			  (23<<20);//RWORDLEN ����� ������������ �����:����� ��� � ����������� ����� ����� RWORDLEN + 1. RWORDLEN ������ ���� ������ 0



	TSR  	=0;//������� ��������� ����������� TSR (����� SPI)
	TSR    |=0;

	RSR     =0;// ������� ��������� �������� RSR (����� SPI)
}


void dsp_1288hk1t_init (void)
{
	u16 z=0;
	u16 i=0;
	u16 adr=0;
	u16 error=0;

	z=spi_1288_rd (0x0001);//������ �������������� DSP
	if (z!=0x0101) Transf ("��� ����� c 1288!\r\n");
	else
	{
		//Transf ("--------\r\n");
		//Transf ("DSP init\r\n");
	};

   INIT_REG_DSP (&DSP); //������������� ��������� DSP

   spi_1288_wr (0x0005,DSP.SYNC);    		if (spi_1288_rd (0x0005)!=DSP.SYNC)    		  error++;

// spi_1288_wr (0x0002,DSP.INT);     		if (spi_1288_rd (0x0002)!=DSP.INT)   		  error++;
   spi_1288_wr (0x0003,DSP.INTE);    	//	if (spi_1288_rd (0x0003)!=DSP.INTE)   		  error++;
   spi_1288_wr (0x0004,DSP.INTR);

   spi_1288_wr (0x0009,DSP.ADC_CFG); 	//	if (spi_1288_rd (0x0009)!=DSP.ADC_CFG) 		  error++;
   spi_1288_wr (0x0010,DSP.RX_CFG);  	//	if (spi_1288_rd (0x0010)!=DSP.RX_CFG) 		  error++;
   spi_1288_wr (0x0014,DSP.RX_FIFO_THRESH);// if (spi_1288_rd (0x0014)!=DSP.RX_FIFO_THRESH) error++;
   spi_1288_wr (0x0015,DSP.RX_LINK);  //      if (spi_1288_rd (0x0015)!=DSP.RX_LINK)        error++;

//-----------������ �����--------------
   spi_1288_wr (0x0022,DSP.RX1_LCFG);
   spi_1288_wr (0x0024,DSP.RX1_DCIC2);
   spi_1288_wr (0x0025,DSP.RX1_DCICN);
   spi_1288_wr (0x0026,DSP.RX1_DFIR1_CFG1);
   spi_1288_wr (0x0027,DSP.RX1_DFIR1_CFG2);
   spi_1288_wr (0x0028,DSP.RX1_DFIR2_CFG1);
   spi_1288_wr (0x0029,DSP.RX1_DFIR2_CFG2);
   spi_1288_wr (0x002a,DSP.RX1_GAIN_I);
   spi_1288_wr (0x002b,DSP.RX1_GAIN_Q);
   spi_1288_wr (0x002d,DSP.RX1_NCO_PHASE);
   spi_1288_wr (0x002e,DSP.RX1_NCO_FRQL);
   spi_1288_wr (0x002f,DSP.RX1_NCO_FRQH);

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0040+i;
	  spi_1288_wr (adr,DSP.RX1_CF_DFIR1[i]);
   }

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0080+i;
	  spi_1288_wr (adr,DSP.RX1_CF_DFIR2[i]);
   }

//-----------������ �����--------------
   spi_1288_wr (0x0122,DSP.RX2_LCFG);
   spi_1288_wr (0x0124,DSP.RX2_DCIC2);
   spi_1288_wr (0x0125,DSP.RX2_DCICN);
   spi_1288_wr (0x0126,DSP.RX2_DFIR1_CFG1);
   spi_1288_wr (0x0127,DSP.RX2_DFIR1_CFG2);
   spi_1288_wr (0x0128,DSP.RX2_DFIR2_CFG1);
   spi_1288_wr (0x0129,DSP.RX2_DFIR2_CFG2);
   spi_1288_wr (0x012a,DSP.RX2_GAIN_I);
   spi_1288_wr (0x012b,DSP.RX2_GAIN_Q);
   spi_1288_wr (0x012d,DSP.RX2_NCO_PHASE);
   spi_1288_wr (0x012e,DSP.RX2_NCO_FRQL);
   spi_1288_wr (0x012f,DSP.RX2_NCO_FRQH);

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0140+i;
	  spi_1288_wr (adr,DSP.RX2_CF_DFIR1[i]);
   }

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0180+i;
	  spi_1288_wr (adr,DSP.RX2_CF_DFIR2[i]);
   }
//-----------������ �����--------------
   spi_1288_wr (0x0222,DSP.RX3_LCFG);
   spi_1288_wr (0x0224,DSP.RX3_DCIC2);
   spi_1288_wr (0x0225,DSP.RX3_DCICN);
   spi_1288_wr (0x0226,DSP.RX3_DFIR1_CFG1);
   spi_1288_wr (0x0227,DSP.RX3_DFIR1_CFG2);
   spi_1288_wr (0x0228,DSP.RX3_DFIR2_CFG1);
   spi_1288_wr (0x0229,DSP.RX3_DFIR2_CFG2);
   spi_1288_wr (0x022a,DSP.RX3_GAIN_I);
   spi_1288_wr (0x022b,DSP.RX3_GAIN_Q);
   spi_1288_wr (0x022d,DSP.RX3_NCO_PHASE);
   spi_1288_wr (0x022e,DSP.RX3_NCO_FRQL);
   spi_1288_wr (0x022f,DSP.RX3_NCO_FRQH);

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0240+i;
	  spi_1288_wr (adr,DSP.RX3_CF_DFIR1[i]);
   }

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0280+i;
	  spi_1288_wr (adr,DSP.RX3_CF_DFIR2[i]);
   }
//-----------�������� �����--------------
   spi_1288_wr (0x0322,DSP.RX4_LCFG);
   spi_1288_wr (0x0324,DSP.RX4_DCIC2);
   spi_1288_wr (0x0325,DSP.RX4_DCICN);
   spi_1288_wr (0x0326,DSP.RX4_DFIR1_CFG1);
   spi_1288_wr (0x0327,DSP.RX4_DFIR1_CFG2);
   spi_1288_wr (0x0328,DSP.RX4_DFIR2_CFG1);
   spi_1288_wr (0x0329,DSP.RX4_DFIR2_CFG2);
   spi_1288_wr (0x032a,DSP.RX4_GAIN_I);
   spi_1288_wr (0x032b,DSP.RX4_GAIN_Q);
   spi_1288_wr (0x032d,DSP.RX4_NCO_PHASE);
   spi_1288_wr (0x032e,DSP.RX4_NCO_FRQL);
   spi_1288_wr (0x032f,DSP.RX4_NCO_FRQH);

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0340+i;
	  spi_1288_wr (adr,DSP.RX4_CF_DFIR1[i]);
   }

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0380+i;
	  spi_1288_wr (adr,DSP.RX4_CF_DFIR2[i]);
   }



 //--------------------------------------

u_out("error=",error);

}
/*
void dsp_1288hk1t_reg (void)
{
	u16 z=0;
	u16 i=0;
	u16 adr=0;
	u16 error=0;

	z=spi_1288_rd (0x0001);//������ �������������� DSP
	if (z!=0x0101) Transf ("��� ����� c 1288!\r\n");
	else
	{
		//Transf ("--------\r\n");
		//Transf ("DSP init\r\n");
	};

   x_out("SYNC:",spi_1288_rd (0x0005));
   x_out("INT :",spi_1288_rd (0x0002));
   x_out("INTE:",spi_1288_rd (0x0003));
   x_out("INTR:",spi_1288_rd (0x0004));

   x_out("ADC_CFG:",spi_1288_rd (0x0009));
   x_out("RX_CFG :",spi_1288_rd (0x0010));
   x_out("RX_FIFO_THRESH :",spi_1288_rd (0x0014));
   x_out("RX_LINK :",spi_1288_rd (0x0015));

//-----------������ �����--------------
   x_out("RX1_LCFG  	 :",spi_1288_rd (0x0022));
   x_out("RX1_DCIC2 	 :",spi_1288_rd (0x0024));
   x_out("RX1_DCICN 	 :",spi_1288_rd (0x0025));
   x_out("RX1_DFIR1_CFG1 :",spi_1288_rd (0x0026));
   x_out("RX1_DFIR1_CFG2 :",spi_1288_rd (0x0027));
   x_out("RX1_DFIR2_CFG1 :",spi_1288_rd (0x0028));
   x_out("RX1_DFIR2_CFG2 :",spi_1288_rd (0x0029));
   x_out("RX1_GAIN_I     :",spi_1288_rd (0x002a));
   x_out("RX1_GAIN_Q     :",spi_1288_rd (0x002b));
   x_out("RX1_NCO_PHASE  :",spi_1288_rd (0x002d));
   x_out("RX1_NCO_FRQL   :",spi_1288_rd (0x002e));
   x_out("RX1_NCO_FRQH   :",spi_1288_rd (0x002f));

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0040+i;
	  xn_out("RX1_CF_DFIR1[",adr);
	   x_out("]:",spi_1288_rd (adr));
   }

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0080+i;
	  xn_out("RX1_CF_DFIR2[",adr);
	   x_out("]:",spi_1288_rd (adr));
   }

//-----------������ �����--------------
   x_out("RX2_LCFG  	 :",spi_1288_rd (0x0122));
   x_out("RX2_DCIC2 	 :",spi_1288_rd (0x0124));
   x_out("RX2_DCICN 	 :",spi_1288_rd (0x0125));
   x_out("RX2_DFIR1_CFG1 :",spi_1288_rd (0x0126));
   x_out("RX2_DFIR1_CFG2 :",spi_1288_rd (0x0127));
   x_out("RX2_DFIR2_CFG1 :",spi_1288_rd (0x0128));
   x_out("RX2_DFIR2_CFG2 :",spi_1288_rd (0x0129));
   x_out("RX2_GAIN_I     :",spi_1288_rd (0x012a));
   x_out("RX2_GAIN_Q     :",spi_1288_rd (0x012b));
   x_out("RX2_NCO_PHASE  :",spi_1288_rd (0x012d));
   x_out("RX2_NCO_FRQL   :",spi_1288_rd (0x012e));
   x_out("RX2_NCO_FRQH   :",spi_1288_rd (0x012f));

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0140+i;
	  xn_out("RX2_CF_DFIR1[",adr);
	   x_out("]:",spi_1288_rd (adr));
   }

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0180+i;
	  xn_out("RX2_CF_DFIR2[",adr);
	   x_out("]:",spi_1288_rd (adr));
   }

//-----------������ �����--------------
   x_out("RX3_LCFG  	 :",spi_1288_rd (0x0222));
   x_out("RX3_DCIC2 	 :",spi_1288_rd (0x0224));
   x_out("RX3_DCICN 	 :",spi_1288_rd (0x0225));
   x_out("RX3_DFIR1_CFG1 :",spi_1288_rd (0x0226));
   x_out("RX3_DFIR1_CFG2 :",spi_1288_rd (0x0227));
   x_out("RX3_DFIR2_CFG1 :",spi_1288_rd (0x0228));
   x_out("RX3_DFIR2_CFG2 :",spi_1288_rd (0x0229));
   x_out("RX3_GAIN_I     :",spi_1288_rd (0x022a));
   x_out("RX3_GAIN_Q     :",spi_1288_rd (0x022b));
   x_out("RX3_NCO_PHASE  :",spi_1288_rd (0x022d));
   x_out("RX3_NCO_FRQL   :",spi_1288_rd (0x022e));
   x_out("RX3_NCO_FRQH   :",spi_1288_rd (0x022f));

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0240+i;
	  xn_out("RX3_CF_DFIR1[",adr);
	   x_out("]:",spi_1288_rd (adr));
   }

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0280+i;
	  xn_out("RX3_CF_DFIR2[",adr);
	   x_out("]:",spi_1288_rd (adr));
   }

//-----------�������� �����--------------
   x_out("RX4_LCFG  	 :",spi_1288_rd (0x0322));
   x_out("RX4_DCIC2 	 :",spi_1288_rd (0x0324));
   x_out("RX4_DCICN 	 :",spi_1288_rd (0x0325));
   x_out("RX4_DFIR1_CFG1 :",spi_1288_rd (0x0326));
   x_out("RX4_DFIR1_CFG2 :",spi_1288_rd (0x0327));
   x_out("RX4_DFIR2_CFG1 :",spi_1288_rd (0x0328));
   x_out("RX4_DFIR2_CFG2 :",spi_1288_rd (0x0329));
   x_out("RX4_GAIN_I     :",spi_1288_rd (0x032a));
   x_out("RX4_GAIN_Q     :",spi_1288_rd (0x032b));
   x_out("RX4_NCO_PHASE  :",spi_1288_rd (0x032d));
   x_out("RX4_NCO_FRQL   :",spi_1288_rd (0x032e));
   x_out("RX4_NCO_FRQH   :",spi_1288_rd (0x032f));

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0340+i;
	  xn_out("RX4_CF_DFIR1[",adr);
	   x_out("]:",spi_1288_rd (adr));
   }

   for (i=0;i<64;i++) //������������ ������� DFIR �������-����������
   {
	  adr=0x0380+i;
	  xn_out("RX4_CF_DFIR2[",adr);
	   x_out("]:",spi_1288_rd (adr));
   }

 //--------------------------------------

}
*/
void SW_init (void)
{

  Transf("init SPACEWARE\r\n");

// �������� ��� ���������� �� gsw
//  assign_dma_rx_desc((struct DMA_PORT_CH_cl *) 0xb82fa800);
//  assign_dma_rx_data((struct DMA_PORT_CH_cl *) 0xb82fa840);
//  assign_dma_tx_desc((struct DMA_PORT_CH_cl *) 0xb82fa880);
//  assign_dma_tx_data((struct DMA_PORT_CH_cl *) 0xb82fa8C0);

  // ���������� ����������
  // cable_test_start
  unmask_irq(gigaspwr_irq_all);
  form_routing_table(false);
  gspwr_form_adg();

  set_transmit_speed(port_spw0, 5, true);
  set_transmit_speed(port_spw1, 5, true);

  set_recive_speed  (port_gigaspw2, gigasw_speed_125_mhz);
  set_transmit_speed(port_gigaspw3, gigasw_speed_125_mhz, true);
  set_recive_speed  (port_gigaspw3, gigasw_speed_125_mhz);
  set_transmit_speed(port_gigaspw2, gigasw_speed_125_mhz, true);

  REGS->SPW_MODE[port_gigaspw2] = SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(REGS->SPW_MODE[port_gigaspw2], 1);
  REGS->SPW_MODE[port_gigaspw3] = SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(REGS->SPW_MODE[port_gigaspw3], 1);

  set_dma_enabled(true);
  set_work_enabled(true);

  start_connect(port_spw0);
  start_connect(port_spw1);
  start_connect(port_gigaspw2);
  start_connect(port_gigaspw3);

  // �������� ����������
Transf("wait spaceware\r\n");
Delay_ms(10);

  int port_i;
  for (port_i = port_spw0; port_i <= port_spw1; port_i++)
     if (SPW_SPEC_CABLE_PORTS & (1 << port_i))
        {
			wait_link_status(port_i, link_status_run, 1000);
        }

  if (get_status(port_spw0,true)==link_status_run) Transf("Link0:established\r\n");
  if (get_status(port_spw1,true)==link_status_run) Transf("Link1:established\r\n");

  speed = SWIC_Speed;

Transf("stage 1\r\n");

  //,# ��� Spw ������� �� ������� ��������
  // �������� �������� ������������� ���� ���
  for (port_i = port_spw0; port_i <= port_spw1; port_i++)
      if (SPW_SPEC_CABLE_PORTS & (1 << port_i))
          set_transmit_speed(port_i, speed, true);

Delay_ms(10);

Transf("stage 2\r\n");
  //,# �������� ������� PLL
  for (port_i = port_spw0; port_i <= port_spw1; port_i++)
       if (SPW_SPEC_CABLE_PORTS & (1 << port_i)) {
         while (get_rx_speed(port_i) < speed - 3){};
         //,# ��������, ��� ���������� �� �����������
         errors += check_SpW_link_status_run((GIGASPWR_cl*)0, port_i);
       }

	get_status(port_spw0,true);
	get_status(port_spw1,true);

Delay_ms(10);

  if (errors)
      {
      Flag_Corr = 1; // ���������� �����������
	  Transf("���������� �����������\r\n");
      //asm volatile("break 0x0, 0x1");
      }


Delay_ms(10);
}

void sw_data_obmen (u32 a)
{
  int size = ARRAY_LEN*sizeof(int);
  unsigned int descr0[2]__attribute__ ((aligned(8))) = {0};
  unsigned int descr1[2]__attribute__ ((aligned(8))) = {0};
  u32 error=0;

Transf("stage 3\r\n");

 FillArray(OutputArray0,ARRAY_LEN,0xabcdef76);
 FillArray(OutputArray1,ARRAY_LEN,0xdeedbeef);

 swic_receiver_run(route_mask_spw0, InputArray0, descr0, 0xFFFF);
 swic_receiver_run(route_mask_spw1, InputArray1, descr1, 0xFFFF);

 swic_send_packet(route_mask_spw1, OutputArray0, size, 1);
 swic_send_packet(route_mask_spw0, OutputArray1, size, 1);

 x_out("route_mask_spw1:",route_mask_spw1);
 x_out("route_mask_spw0:",route_mask_spw0);

// swic_receiver_wait(1);
// swic_receiver_wait(0);

Delay_ms(10);

 Transf("\nArray0:\r\n");
 error = VerifyArray(InputArray0,ARRAY_LEN,a);
 x_out("descr0[0]:",descr0[0]);
 x_out("descr0[1]:",descr0[1]);
 Transf("\nArray1:\r\n");
 error = VerifyArray(InputArray1,ARRAY_LEN,a);
 x_out("descr1[0]:",descr1[0]);
 x_out("descr1[1]:",descr1[1]);

// MASKR0&=~(1<<19);

CSR_SWIC_TX_DES(0);
CSR_SWIC_TX_DAT(0);
CSR_SWIC_RX_DES(0);
CSR_SWIC_RX_DAT(0);

CSR_SWIC_TX_DES(1);
CSR_SWIC_TX_DAT(1);
CSR_SWIC_RX_DES(1);
CSR_SWIC_RX_DAT(1);

 	get_status(port_spw0,true);
	get_status(port_spw1,true);
}


void lPORT_DMA (void)
{
	IR_MFBSP_RX_CH1 = ((unsigned int) &lport_InputArray[0]) - 0xA0000000;
    CSR_MFBSP_RX_CH1 = (((ARRAY_LEN_lport/2)-1)<<16) | // WCX = LEN/2
                                             (15<<2) | // WN = 15 (������ ����� - 16 ����)
                                                  1;   // RUN = 1
}

u16 test_sin(u16 i)
{
	float f=0;
	u16 b=0;
	u16 a[16];

	a[0] =0;
	a[1] =3122;
	a[2] =6123;
	a[3] =8890;
	a[4] =11314;
	a[5] =13304;
	a[6] =14783;
	a[7] =15693;
	a[8] =16000;
	a[9] =15693;
	a[10]=14783;
	a[11]=13304;
	a[12]=11314;
	a[13]=8890;
	a[14]=6123;
	a[15]=3122;

	b=i&15;

	return a[b];
}

u16 test_cos(u16 i)
{
	float f=0;
	u16 b=0;
	u16 a[8];

	a[0] =1600;
	a[1] =15693;
	a[2] =14783;
	a[3] =13304;
	a[4] =11314;
	a[5] =8890;
	a[6] =6123;
	a[7] =3122;
	a[8] =1;
	a[9] =-3121;
	a[10]=-6122;
	a[11]=-8889;
	a[12]=-11313;
	a[13]=-13303;
	a[14]=-14782;
	a[15]=-15692;

	b=i&15;

	return a[b];
}

int sch;
u8 M[4100];

void main()
{
char temp_z0=0;
u32 temp_DMA=0;
u8 flag_1=0;
u32 i=0;

u16 data_i=0;
u16 data_q=0;
u16 j=0;
u8 h_byte=0;
u8 l_byte=0;

 //---------------------------------------------------
char readed;
        CLK_EN  = 0xFFFFFFFF; // ��������� �������� �������
        CR_PLL0 = 0;
		CR_PLL0 = (20<<0 ) //����������� ���������/������� ������� ������� PLL_CORE (������� XTI, �������� �� 2) :20 - 100 MHz
 				 |(1 <<7 ) //����� ��������� �������� ������� ��� ������ CPU, UART,IT, WDT, SPI, ����������� AXI,��������� ����� ���� ��������� ����������:1 � PLL_CORE;
				 |(20<<8 ) //����������� ���������/������� ������� ������� PLL_MPORT (������� XTI, �������� �� 2):20 - 100 MHz
				 |(1 <<15) //����� ��������� �������� ������� ��� ������ MPORT:1 � PLL_MPORT;
				 |(20<<16);//����������� ���������/������� ������� ������� PLL_DSP  (������� XTI, �������� �� 2) :20 - 100 MHz

   UART1_conf(115200,FREQ);

   SetCP0_Status(0x1001);  // ��������� �������� Status �� ���������� �� DMA ������
   MASKR2_set();

   MFBSP0_init();
   MFBSP1_init();//����� ����� LPORT - LPORT1(�����)
   MFBSP2_init();//����� ����� SPI + �����-������ ������ ����������
   MFBSP3_init();//����� ����� SPI + �����-������ ������ ����������
   SPI_init();
// GPIO_conf();
   LED(temp_z0);

 Transf("-----------------------\n\r");
 Transf("-       START         -\n\r");
 Transf("-----------------------\n\r");

 Adress=0x30; //������ �������
 sch=0;

 rx_counter0 =0;
 rx_rd_index0=0;
 rx_wr_index0=0;
 rx_buffer_overflow0=0;

//-------------����� ������������----------------------
AT1(60); //-- �������� ����!!!
AT2(60);
//-----------------------------------------------------
  SYS_CSR |= 2;

  risc_set_interrupts_vector(INTH_80000180);//INTH_80000180

  risc_register_interrupt(int_handler, RISC_INT_UART1);
  IER_UART();
  risc_enable_interrupt(RISC_INT_UART1);
//-----------------------------------------------------

  ID0_init ();
  risc_register_interrupt(ID0_IT_handler, RISC_INT_IT0);
  risc_enable_interrupt(RISC_INT_IT0);
//-----------------------------------------------------
//-----------------------------------------------------
  risc_register_interrupt(ID1_LPORT_handler, RISC_INT_DMA_MFBSP1);
  risc_enable_interrupt  (RISC_INT_DMA_MFBSP1);
//-----------------------------------------------------


 // ����������� DMA LPORT1 �� �����
  IR_MFBSP_RX_CH1 = ((unsigned int) &lport_InputArray[0]) - 0xA0000000; // ���������� ���������� ����� � ������� �������
  CSR_MFBSP_RX_CH1 = (((ARRAY_LEN_lport/2)-1)<<16) | // WCX = LEN/2
                                           (15<<2) | // WN = 15 (������ ����� - 16 ����)
												1;
//-----------------------------------------------------
 Delay_ms(50);

 adc1_init (1);
 adc2_init (1);

 PF1_SYNC_START(0);

 RST_1288(0);
 Delay_ms(5);
 RST_1288(1);
 Delay_ms(10);

 //---------1288-----------------
  dsp_1288hk1t_init();
  spi_1288_wr (0x0005,0x206);
  PF1_SYNC_START(1);

 while (1)
  {
    UART_conrol();

	temp_DMA=flag_DMA_LPORT;

	if ((flag_DMA_LPORT>0))
	{
		flag_DMA_LPORT=0;
		flag_1=1;
		//Transf("DMA LPORT!\r\n");
	};


	if (flag_1==1)
	{
	 M[0]=0x23;
	 M[1]=0x0a;
	 M[2]=0x3a;

	 j=3;

	 for (i=0;i<1024;i++)
	 {

		if (VAR_RESIVER==0)  //����� 1
		{
			h_byte=((lport_InputArray[2*i+514])>>24)&0xff;
			l_byte=((lport_InputArray[2*i+514])>>16)&0xff;
		} else
		{
			h_byte=((lport_InputArray[2*i+513])>>24)&0xff;
			l_byte=((lport_InputArray[2*i+513])>>16)&0xff;
		}

	//	h_byte=((test_sin(i))>>8)&0xff;
	//	l_byte=((test_sin(i))   )&0xff;

		M[j++]=h_byte;
	    M[j++]=l_byte;


		 if (VAR_RESIVER==0) //����� 0
		 {
			h_byte=((lport_InputArray[2*i+514])>>24)&0xff;
			l_byte=((lport_InputArray[2*i+514])>>16)&0xff;
		 } else
		 {
			h_byte=((lport_InputArray[2*i+513])>>24)&0xff;
			l_byte=((lport_InputArray[2*i+513])>>16)&0xff;
		 }

	//	h_byte=((test_cos(i))>>8)&0xff;
	//	l_byte=((test_cos(i))   )&0xff;

	//	M[j++]=h_byte;
	//  M[j++]=l_byte;
		
		M[j++]=0;
	    M[j++]=0;
	 }

	 //M[2047]=0x00;

	 tx_uart(M,4100);//�������� � ����

	 flag_1=0;

	 lPORT_DMA ();
	}

    if (Dtimer0==0)
	{
		temp_z0=~temp_z0;
		LED(temp_z0);
		Dtimer0=500;
	};

  }

}
