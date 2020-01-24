#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "mcb_pci_driver.h"
#include "memory_manager.h"
#include "swic.h"

#define MCB02

unsigned int num = 0;
unsigned int i = 0;
unsigned int erorrs =0;

HANDLE thread;
DWORD thrId;

BOOL WINAPI consoleHandler(DWORD signal) {

    if (signal == CTRL_C_EVENT)
        printf("Ctrl-C handled\n"); // do cleanup
//        swic_reset(0); //TODO SWIC_RESET_ALL
//        swic_reset(3);
        mcb_deinit();
        exit(0);


    return TRUE;
}

WORD WINAPI interupt_thread(void)
{
 printf("Interupt_thread\n\n");
 mcb_clear_interrupts();

 mcb_enable_interrupt(int_swic2_link);
 mcb_enable_interrupt(int_swic1_link);
 printf("Interupt_ENABLE\n\n");
 while(1){
  mcb_clear_interrupts();
  printf("MODE_CR 1     :0x%x\n",mcb_read_reg(SWIC_MODE_CR(1)));
  printf("MODE_CR 2     :0x%x\n",mcb_read_reg(SWIC_MODE_CR(2)));
  mcb_wait_interrupt(INFINITE);
  printf("\nLINK_INTERUPT\n");
 }

  printf("\nEXIT INT TREAD\n");
}

void print_status(int tx_chan,int rx_chan)
{
	printf("\n");
    printf("TX CHANNEL STATUS:  %08X\n", mcb_read_reg(SWIC_STATUS(tx_chan)));
    printf("RX CHANNEL STATUS:  %08X\n", mcb_read_reg(SWIC_STATUS(rx_chan)));
    printf("RX DESC DMA CSR:    %08X\n", mcb_read_reg(SWIC_DMA_RX_DES_CSR(rx_chan)));
    printf("RX DATA DMA CSR:    %08X\n", mcb_read_reg(SWIC_DMA_RX_DATA_CSR(rx_chan)));
    printf("TX DESC DMA CSR:    %08X\n", mcb_read_reg(SWIC_DMA_TX_DES_CSR(tx_chan)));
    printf("TX DATA DMA CSR:    %08X\n", mcb_read_reg(SWIC_DMA_TX_DATA_CSR(tx_chan)));
}

struct timeval start_0_3, end_0_3, start_3_0, end_3_0;
long elapsed_ms, seconds, useconds;

int main() 
{
	SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    if (!SetConsoleCtrlHandler(consoleHandler, TRUE)) 
	{
        printf("\nERROR: Could not set control handler");
        return 1;
    }

    if (mcb_init()) 
	{
        printf("mcb02 :: [ERROR] initialization\n");
        while(1);
        return -1;
    } else {
        printf("mcb02 :: [SUCESS] initialization\n");
    }

    CreateThread(NULL, 0, &interupt_thread, 0, 0, &thrId); //Thread for interupts

    mcb_pmsc_dump();
    RAM_memtest_random();
	
	init_LANE (0xaaaa);
	
	init_LANE (0xbbbb);
	
	init_LANE (0xcccc);

//	print_status(1,1);
//	print_status(2,2);

    mcb_deinit();

	printf("press any\n");
	getchar();

    return 0;
}

