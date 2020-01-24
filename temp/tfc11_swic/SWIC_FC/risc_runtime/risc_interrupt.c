// ******************** risc_interrupt.c ***************************************
//                 Risc-Dsp runtime library
//
// Interface to enable/disable risc interrupts
// by setting MASKR0, MASKR1, MASKR2
// This file contains handler function. Don't use it!
// Use library interface
//
// (c) multicore.ru
//
// *******************************************************************

#include "mc30sf.h"
#include "erlcommon.h"
#include "risc_interrupt.h"

RISC_INTERRUPT risc_hnlr_func[89] = {UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
										UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
										UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
										UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
										UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
										UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
                                        UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,UNKNOWN_RISC,
										UNKNOWN_RISC};

void initialize_risc_hnlr()
{
        int i;
        for (i=0; i<89; i++)
           risc_hnlr_func[i] = UNKNOWN_RISC;
}

void risc_set_interrupts_vector(INTERRUPT_VECTORS loc)
{
    unsigned int temp = 0;
    asm volatile ("mfc0 %0, $12" :"=r"(temp));
    temp &= ~(4);
    asm volatile ("mtc0 %0, $12" ::"r"(temp));
    switch(loc)
    {
    case INTH_80000180:
        temp = 0;
        asm volatile ("mtc0 %0, $13" ::"r"(temp));
        asm volatile ("mfc0 %0, $12" :"=r"(temp));
        temp &= ~(1<<22);
        asm volatile ("mtc0 %0, $12" ::"r"(temp));
        break;
    case INTH_BFC00380:
        temp = 0;
        asm volatile ("mtc0 %0, $13" ::"r"(temp));
        asm volatile ("mfc0 %0, $12" :"=r"(temp));
        temp |= (1<<22);
        asm volatile ("mtc0 %0, $12" ::"r"(temp));
        break;
    case INTH_80000200:
        temp = (1<<23);
        asm volatile ("mtc0 %0, $13" ::"r"(temp));
        temp = 0;
        asm volatile ("mfc0 %0, $12" :"=r"(temp));
        temp &= ~(1<<22);
        asm volatile ("mtc0 %0, $12" ::"r"(temp));
        break;
    case INTH_BFC00400:
        temp = (1<<23);
        asm volatile ("mtc0 %0, $13" ::"r"(temp));
        temp = 0;
        asm volatile ("mfc0 %0, $12" :"=r"(temp));
        temp |= (1<<22);
        asm volatile ("mtc0 %0, $12" ::"r"(temp));
        break;
    };
}

static void or_MASKR(unsigned int cp0_status, unsigned int mask, int reg)
{
    unsigned int CP0_Status = 0, st = 0;
    CP0_Status = cp0_status;
    asm volatile ("mfc0 %0, $12" :"=r"(st));
    CP0_Status |= st;
    asm volatile ("mtc0 %0, $12" ::"r"(CP0_Status));
    if (reg==0) MASKR0 |= mask;
    else if (reg==1) MASKR1 |= mask;
    else if (reg==2) MASKR2 |= mask;
}

static void andnot_MASKR(unsigned int mask, int reg)
{
    if (reg==0) MASKR0 &= ~(mask);
    else if (reg==1) MASKR1 &= ~(mask);
    else if (reg==2) MASKR2 &= ~(mask);
}

void risc_enable_interrupt(RISC_INTERRUPT_TYPE type)
{
    unsigned int CP0_Status = 0;
    asm volatile ("mfc0 %0, $12" :"=r"(CP0_Status));
    switch(type)
    {
    //QSTR0
    case RISC_INT_SPWR7:
       or_MASKR(0x401, (1<<31), 0);
       break;
	case RISC_INT_SPWR6:
       or_MASKR(0x401, (1<<30), 0);
       break;
	case RISC_INT_SPWR5:
       or_MASKR(0x401, (1<<29), 0);
       break;
	case RISC_INT_SPWR4:
       or_MASKR(0x401, (1<<28), 0);
       break;
	case RISC_INT_SPWR3:
       or_MASKR(0x401, (1<<27), 0);
       break;
	case RISC_INT_SPWR2:
       or_MASKR(0x401, (1<<26), 0);
       break;
	case RISC_INT_SPWR1:
       or_MASKR(0x401, (1<<25), 0);
       break;
	case RISC_INT_SPWR0:
       or_MASKR(0x401, (1<<24), 0);
       break;
    case RISC_INT_IT1:
       or_MASKR(0x401, (1<<22), 0);
       break;
	case RISC_INT_IT0:
       or_MASKR(0x401, (1<<21), 0);
       break;
    case RISC_INT_WDT:
       or_MASKR(0x401, (1<<20), 0);
       break;
    case RISC_INT_SPWR_TX_DAT:
       or_MASKR(0x401, (1<<19), 0);
       break;
	case RISC_INT_SPWR_TX_DES:
       or_MASKR(0x401, (1<<18), 0);
       break;
	case RISC_INT_SPWR_RX_DAT:
       or_MASKR(0x401, (1<<17), 0);
       break;
	case RISC_INT_SPWR_RX_DES:
       or_MASKR(0x401, (1<<16), 0);
       break;
    case RISC_INT_EMAC_DMA_TX:
       or_MASKR(0x401, (1<<15), 0);
       break;
    case RISC_INT_EMAC_DMA_RX:
       or_MASKR(0x401, (1<<14), 0);
       break;
    case RISC_INT_EMAC_TX_FRAME:
       or_MASKR(0x401, (1<<13), 0);
       break;
    case RISC_INT_EMAC_RX_FRAME:
       or_MASKR(0x401, (1<<12), 0);
       break;
    case RISC_INT_USB_EP4:
       or_MASKR(0x401, (1<<11), 0);
       break;
    case RISC_INT_USB_EP3:
       or_MASKR(0x401, (1<<10), 0);
       break;
    case RISC_INT_USB_EP2:
       or_MASKR(0x401, (1<<9), 0);
       break;
    case RISC_INT_USB_EP1:
       or_MASKR(0x401, (1<<8), 0);
       break;
    case RISC_INT_USB:
       or_MASKR(0x401, (1<<7), 0);
       break;
	case RISC_INT_SPI:
       or_MASKR(0x401, (1<<6), 0);
       break;
    case RISC_INT_UART1:
       or_MASKR(0x401, (1<<5), 0);
       break;
    case RISC_INT_UART0:
       or_MASKR(0x401, (1<<4), 0);
       break;
    case RISC_INT_IRQ3:
       or_MASKR(0x401, (1<<3), 0);
       break;
    case RISC_INT_IRQ2:
       or_MASKR(0x401, (1<<2), 0);
       break;
    case RISC_INT_IRQ1:
       or_MASKR(0x401, 2, 0);
       break;
    case RISC_INT_IRQ0:
       or_MASKR(0x401, 1, 0);
       break;

    //QSTR1
	case RISC_INT_SPFMIC_TX_DAT_CH1:
       or_MASKR(0x801, (1<<25), 1);
       break;
	case RISC_INT_SPFMIC_TX_DES_CH1:
       or_MASKR(0x801, (1<<24), 1);
       break;
	case RISC_INT_SPFMIC_RX_DAT_CH1:
       or_MASKR(0x801, (1<<23), 1);
       break;
	case RISC_INT_SPFMIC_RX_DES_CH1:
       or_MASKR(0x801, (1<<22), 1);
       break;
	case RISC_INT_SPFMIC1:
       or_MASKR(0x801, (1<<21), 1);
       break;
	case RISC_INT_SPFMIC_TX_DAT_CH0:
       or_MASKR(0x801, (1<<20), 1);
       break;
	case RISC_INT_SPFMIC_TX_DES_CH0:
       or_MASKR(0x801, (1<<19), 1);
       break;
	case RISC_INT_SPFMIC_RX_DAT_CH0:
       or_MASKR(0x801, (1<<18), 1);
       break;
	case RISC_INT_SPFMIC_RX_DES_CH0:
       or_MASKR(0x801, (1<<17), 1);
       break;
	case RISC_INT_SPFMIC0:
       or_MASKR(0x801, (1<<16), 1);
       break;
	   
	case RISC_INT_MEMCH17:
       or_MASKR(0x801, (1<<15), 1);
       break;
    case RISC_INT_MEMCH16:
       or_MASKR(0x801, (1<<14), 1);
       break;
    case RISC_INT_MEMCH15:
       or_MASKR(0x801, (1<13), 1);
       break;
    case RISC_INT_MEMCH14:
       or_MASKR(0x801, (1<<12), 1);
       break;
    case RISC_INT_MEMCH13:
       or_MASKR(0x801, (1<<11), 1);
       break;
    case RISC_INT_MEMCH12:
       or_MASKR(0x801, (1<<10), 1);
       break;
    case RISC_INT_MEMCH11:
       or_MASKR(0x801, (1<<9), 1);
       break;
    case RISC_INT_MEMCH10:
       or_MASKR(0x801, (1<<8), 1);
       break;
	case RISC_INT_MEMCH7:
       or_MASKR(0x801, (1<<7), 1);
       break;
    case RISC_INT_MEMCH6:
       or_MASKR(0x801, (1<<6), 1);
       break;
    case RISC_INT_MEMCH5:
       or_MASKR(0x801, (1<<5), 1);
       break;
    case RISC_INT_MEMCH4:
       or_MASKR(0x801, (1<<4), 1);
       break;
    case RISC_INT_MEMCH3:
       or_MASKR(0x801, (1<<3), 1);
       break;
    case RISC_INT_MEMCH2:
       or_MASKR(0x801, (1<<2), 1);
       break;
    case RISC_INT_MEMCH1:
       or_MASKR(0x801, 2, 1);
       break;
    case RISC_INT_MEMCH0:
       or_MASKR(0x801, 1, 1);
       break;

    //QSTR2
    case RISC_INT_DMA_MFBSP3:
       or_MASKR(0x1001, (1<<15), 2);
       break;
    case RISC_INT_MFBSP_TXBUF3:
       or_MASKR(0x1001, (1<<14), 2);
       break;
    case RISC_INT_MFBSP_RXBUF3:
       or_MASKR(0x1001, (1<<13), 2);
       break;
    case RISC_INT_SRQ3:
       or_MASKR(0x1001, (1<<12), 2);
       break;

    case RISC_INT_DMA_MFBSP2:
       or_MASKR(0x1001, (1<<11), 2);
       break;
    case RISC_INT_MFBSP_TXBUF2:
       or_MASKR(0x1001, (1<<10), 2);
       break;
    case RISC_INT_MFBSP_RXBUF2:
       or_MASKR(0x1001, (1<<9), 2);
       break;
    case RISC_INT_SRQ2:
       or_MASKR(0x1001, (1<<8), 2);
       break;

    case RISC_INT_DMA_MFBSP1:
       or_MASKR(0x1001, (1<<7), 2);
       break;
    case RISC_INT_MFBSP_TXBUF1:
       or_MASKR(0x1001, (1<<6), 2);
       break;
    case RISC_INT_MFBSP_RXBUF1:
       or_MASKR(0x1001, (1<<5), 2);
       break;
    case RISC_INT_SRQ1:
       or_MASKR(0x1001, (1<<4), 2);
       break;

    case RISC_INT_DMA_MFBSP0:
       or_MASKR(0x1001, (1<<3), 2);
       break;
    case RISC_INT_MFBSP_TXBUF0:
       or_MASKR(0x1001, (1<<2), 2);
       break;
    case RISC_INT_MFBSP_RXBUF0:
       or_MASKR(0x1001, 2, 2);
       break;
    case RISC_INT_SRQ0:
       or_MASKR(0x1001, 1, 2);
       break;


    case RISC_FROM_DSP:
        CP0_Status = 0;
        asm volatile ("mfc0 %0, $12" :"=r"(CP0_Status));
        CP0_Status |= 0x4001;
        asm volatile ("mtc0 %0, $12" ::"r"(CP0_Status));
        MASKR_DSP |= 0x101;
        break;
	case RISC_COMPARE:
        CP0_Status = 0;
        asm volatile ("mfc0 %0, $12" :"=r"(CP0_Status));
        CP0_Status |= 0x8001;
        asm volatile ("mtc0 %0, $12" ::"r"(CP0_Status));
        break;
    };
}

void risc_disable_interrupt(RISC_INTERRUPT_TYPE type)
{
    unsigned int CP0_Status = 0;
    switch(type)
    {
   //QSTR0
    case RISC_INT_SPWR7:
       andnot_MASKR((1<<31), 0);
       break;
	case RISC_INT_SPWR6:
       andnot_MASKR((1<<30), 0);
       break;
	case RISC_INT_SPWR5:
       andnot_MASKR((1<<29), 0);
       break;
	case RISC_INT_SPWR4:
       andnot_MASKR((1<<28), 0);
       break;
	case RISC_INT_SPWR3:
       andnot_MASKR((1<<27), 0);
       break;
	case RISC_INT_SPWR2:
       andnot_MASKR((1<<26), 0);
       break;
	case RISC_INT_SPWR1:
       andnot_MASKR((1<<25), 0);
       break;
	case RISC_INT_SPWR0:
       andnot_MASKR((1<<24), 0);
       break;
    case RISC_INT_IT1:
       andnot_MASKR((1<<22), 0);
       break;
	case RISC_INT_IT0:
       andnot_MASKR((1<<21), 0);
       break;
    case RISC_INT_WDT:
       andnot_MASKR((1<<20), 0);
       break;
    case RISC_INT_SPWR_TX_DAT:
       andnot_MASKR((1<<19), 0);
       break;
	case RISC_INT_SPWR_TX_DES:
       andnot_MASKR((1<<18), 0);
       break;
	case RISC_INT_SPWR_RX_DAT:
       andnot_MASKR((1<<17), 0);
       break;
	case RISC_INT_SPWR_RX_DES:
       andnot_MASKR((1<<16), 0);
       break;
    case RISC_INT_EMAC_DMA_TX:
       andnot_MASKR((1<<15), 0);
       break;
    case RISC_INT_EMAC_DMA_RX:
       andnot_MASKR((1<<14), 0);
       break;
    case RISC_INT_EMAC_TX_FRAME:
       andnot_MASKR((1<<13), 0);
       break;
    case RISC_INT_EMAC_RX_FRAME:
       andnot_MASKR((1<<12), 0);
       break;
    case RISC_INT_USB_EP4:
       andnot_MASKR((1<<11), 0);
       break;
    case RISC_INT_USB_EP3:
       andnot_MASKR((1<<10), 0);
       break;
    case RISC_INT_USB_EP2:
       andnot_MASKR((1<<9), 0);
       break;
    case RISC_INT_USB_EP1:
       andnot_MASKR((1<<8), 0);
       break;
    case RISC_INT_USB:
       andnot_MASKR((1<<7), 0);
       break;
	case RISC_INT_SPI:
       andnot_MASKR((1<<6), 0);
       break;
    case RISC_INT_UART1:
       andnot_MASKR((1<<5), 0);
       break;
    case RISC_INT_UART0:
       andnot_MASKR((1<<4), 0);
       break;
    case RISC_INT_IRQ3:
       andnot_MASKR((1<<3), 0);
       break;
    case RISC_INT_IRQ2:
       andnot_MASKR((1<<2), 0);
       break;
    case RISC_INT_IRQ1:
       andnot_MASKR(2, 0);
       break;
    case RISC_INT_IRQ0:
       andnot_MASKR(1, 0);
       break;

    //QSTR1
	case RISC_INT_SPFMIC_TX_DAT_CH1:
       andnot_MASKR((1<<25), 1);
       break;
	case RISC_INT_SPFMIC_TX_DES_CH1:
       andnot_MASKR((1<<24), 1);
       break;
	case RISC_INT_SPFMIC_RX_DAT_CH1:
       andnot_MASKR((1<<23), 1);
       break;
	case RISC_INT_SPFMIC_RX_DES_CH1:
       andnot_MASKR((1<<22), 1);
       break;
	case RISC_INT_SPFMIC1:
       andnot_MASKR((1<<21), 1);
       break;
	case RISC_INT_SPFMIC_TX_DAT_CH0:
       andnot_MASKR((1<<20), 1);
       break;
	case RISC_INT_SPFMIC_TX_DES_CH0:
       andnot_MASKR((1<<19), 1);
       break;
	case RISC_INT_SPFMIC_RX_DAT_CH0:
       andnot_MASKR((1<<18), 1);
       break;
	case RISC_INT_SPFMIC_RX_DES_CH0:
       andnot_MASKR((1<<17), 1);
       break;
	case RISC_INT_SPFMIC0:
       andnot_MASKR((1<<16), 1);
       break;
	   
	case RISC_INT_MEMCH17:
       andnot_MASKR((1<<15), 1);
       break;
    case RISC_INT_MEMCH16:
       andnot_MASKR((1<<14), 1);
       break;
    case RISC_INT_MEMCH15:
       andnot_MASKR((1<13), 1);
       break;
    case RISC_INT_MEMCH14:
       andnot_MASKR((1<<12), 1);
       break;
    case RISC_INT_MEMCH13:
       andnot_MASKR((1<<11), 1);
       break;
    case RISC_INT_MEMCH12:
       andnot_MASKR((1<<10), 1);
       break;
    case RISC_INT_MEMCH11:
       andnot_MASKR((1<<9), 1);
       break;
    case RISC_INT_MEMCH10:
       andnot_MASKR((1<<8), 1);
       break;
	case RISC_INT_MEMCH7:
       andnot_MASKR((1<<7), 1);
       break;
    case RISC_INT_MEMCH6:
       andnot_MASKR((1<<6), 1);
       break;
    case RISC_INT_MEMCH5:
       andnot_MASKR((1<<5), 1);
       break;
    case RISC_INT_MEMCH4:
       andnot_MASKR((1<<4), 1);
       break;
    case RISC_INT_MEMCH3:
       andnot_MASKR((1<<3), 1);
       break;
    case RISC_INT_MEMCH2:
       andnot_MASKR((1<<2), 1);
       break;
    case RISC_INT_MEMCH1:
       andnot_MASKR(2, 1);
       break;
    case RISC_INT_MEMCH0:
       andnot_MASKR(1, 1);
       break;

    //QSTR2
    case RISC_INT_DMA_MFBSP3:
       andnot_MASKR((1<<15), 2);
       break;
    case RISC_INT_MFBSP_TXBUF3:
       andnot_MASKR((1<<14), 2);
       break;
    case RISC_INT_MFBSP_RXBUF3:
       andnot_MASKR((1<<13), 2);
       break;
    case RISC_INT_SRQ3:
       andnot_MASKR((1<<12), 2);
       break;

    case RISC_INT_DMA_MFBSP2:
       andnot_MASKR((1<<11), 2);
       break;
    case RISC_INT_MFBSP_TXBUF2:
       andnot_MASKR((1<<10), 2);
       break;
    case RISC_INT_MFBSP_RXBUF2:
       andnot_MASKR((1<<9), 2);
       break;
    case RISC_INT_SRQ2:
       andnot_MASKR((1<<8), 2);
       break;

    case RISC_INT_DMA_MFBSP1:
       andnot_MASKR((1<<7), 2);
       break;
    case RISC_INT_MFBSP_TXBUF1:
       andnot_MASKR((1<<6), 2);
       break;
    case RISC_INT_MFBSP_RXBUF1:
       andnot_MASKR((1<<5), 2);
       break;
    case RISC_INT_SRQ1:
       andnot_MASKR((1<<4), 2);
       break;

    case RISC_INT_DMA_MFBSP0:
       andnot_MASKR((1<<3), 2);
       break;
    case RISC_INT_MFBSP_TXBUF0:
       andnot_MASKR((1<<2), 2);
       break;
    case RISC_INT_MFBSP_RXBUF0:
       andnot_MASKR(2, 2);
       break;
    case RISC_INT_SRQ0:
       andnot_MASKR(1, 2);
       break;


    case RISC_FROM_DSP:
        MASKR_DSP &= ~(0x101);
        break;
	case RISC_COMPARE:
        CP0_Status = 0;
        asm volatile ("mfc0 %0, $12" :"=r"(CP0_Status));
        CP0_Status &= ~(0x8000);
        asm volatile ("mtc0 %0, $12" ::"r"(CP0_Status));
        break;
    };
}

void risc_disable_interrupts()
{
    unsigned int CP0_Status = 0;
    asm volatile ("mfc0 %0, $12" :"=r"(CP0_Status));
    CP0_Status &= ~(0x1);
    asm volatile ("mtc0 %0, $12" ::"r"(CP0_Status));
}

void risc_enable_interrupts()
{
    unsigned int CP0_Status = 0;
    asm volatile ("mfc0 %0, $12" :"=r"(CP0_Status));
    CP0_Status |= 0x1;
    asm volatile ("mtc0 %0, $12" ::"r"(CP0_Status));
}

enum ERL_ERROR risc_register_interrupt(RISC_INTERRUPT fn, RISC_INTERRUPT_TYPE type)
{
    if (fn != 0)
        risc_hnlr_func[type] = fn;
    else return ERL_UNITIALIZED_ARG;
    return ERL_NO_ERROR;
}



static int get_cause_risc(unsigned int v)
{
    if (v&0x400)
    {
        if (QSTR0&(1<<31)) return RISC_INT_SPWR7;
        else if (QSTR0&(1<<30)) return RISC_INT_SPWR6;
		else if (QSTR0&(1<<29)) return RISC_INT_SPWR5;
		else if (QSTR0&(1<<28)) return RISC_INT_SPWR4;
		else if (QSTR0&(1<<27)) return RISC_INT_SPWR3;
		else if (QSTR0&(1<<26)) return RISC_INT_SPWR2;
		else if (QSTR0&(1<<25)) return RISC_INT_SPWR1;
		else if (QSTR0&(1<<24)) return RISC_INT_SPWR0;
        else if (QSTR0&(1<<22)) return RISC_INT_IT1;
        else if (QSTR0&(1<<21)) return RISC_INT_IT0;
        else if (QSTR0&(1<<20)) return RISC_INT_WDT;
        else if (QSTR0&(1<<19)) return RISC_INT_SPWR_TX_DAT;
        else if (QSTR0&(1<<18)) return RISC_INT_SPWR_TX_DES;
        else if (QSTR0&(1<<17)) return RISC_INT_SPWR_RX_DAT;
        else if (QSTR0&(1<<16)) return RISC_INT_SPWR_RX_DES;
        else if (QSTR0&(1<<15)) return RISC_INT_EMAC_DMA_TX;
        else if (QSTR0&(1<<14)) return RISC_INT_EMAC_DMA_RX;
        else if (QSTR0&(1<<13)) return RISC_INT_EMAC_TX_FRAME;
        else if (QSTR0&(1<<12)) return RISC_INT_EMAC_RX_FRAME;
        else if (QSTR0&(1<<11)) return RISC_INT_USB_EP4;
        else if (QSTR0&(1<<10)) return RISC_INT_USB_EP3;
        else if (QSTR0&(1<<9)) return RISC_INT_USB_EP2;
        else if (QSTR0&(1<<8)) return RISC_INT_USB_EP1;
        else if (QSTR0&(1<<7)) return RISC_INT_USB;
		else if (QSTR0&(1<<6)) return RISC_INT_SPI;
        else if (QSTR0&(1<<5)) return RISC_INT_UART1;
        else if (QSTR0&(1<<4)) return RISC_INT_UART0;
        else if (QSTR0&(1<<3)) return RISC_INT_IRQ3;
        else if (QSTR0&(1<<2)) return RISC_INT_IRQ2;
        else if (QSTR0&2) return RISC_INT_IRQ1;
        else if (QSTR0&1) return RISC_INT_IRQ0;
    }
    else if (v&0x800)
    {
		if (QSTR1&(1<<15)) return RISC_INT_MEMCH17;
        else if (QSTR1&(1<<14)) return RISC_INT_MEMCH16;
        else if (QSTR1&(1<<13)) return RISC_INT_MEMCH15;
        else if (QSTR1&(1<<12)) return RISC_INT_MEMCH14;
        else if (QSTR1&(1<<11)) return RISC_INT_MEMCH13;
        else if (QSTR1&(1<<10)) return RISC_INT_MEMCH12;
        else if (QSTR1&(1<<9)) return RISC_INT_MEMCH11;
        else if (QSTR1&(1<<8)) return RISC_INT_MEMCH10;
		else if (QSTR1&(1<<7)) return RISC_INT_MEMCH7;
        else if (QSTR1&(1<<6)) return RISC_INT_MEMCH6;
        else if (QSTR1&(1<<5)) return RISC_INT_MEMCH5;
        else if (QSTR1&(1<<4)) return RISC_INT_MEMCH4;
        else if (QSTR1&(1<<3)) return RISC_INT_MEMCH3;
        else if (QSTR1&(1<<2)) return RISC_INT_MEMCH2;
        else if (QSTR1&2) return RISC_INT_MEMCH1;
        else if (QSTR1&1) return RISC_INT_MEMCH0;
    }
    else if (v&0x1000)
    {
		if (QSTR1&(1<<25)) return RISC_INT_SPFMIC_TX_DAT_CH1;
		else if (QSTR1&(1<<24)) return RISC_INT_SPFMIC_TX_DES_CH1;
		else if (QSTR1&(1<<23)) return RISC_INT_SPFMIC_RX_DAT_CH1;
		else if (QSTR1&(1<<22)) return RISC_INT_SPFMIC_RX_DES_CH1;
		else if (QSTR1&(1<<21)) return RISC_INT_SPFMIC1;
		
		else if (QSTR1&(1<<20)) return RISC_INT_SPFMIC_TX_DAT_CH0;
		else if (QSTR1&(1<<19)) return RISC_INT_SPFMIC_TX_DES_CH0;
		else if (QSTR1&(1<<18)) return RISC_INT_SPFMIC_RX_DAT_CH0;
		else if (QSTR1&(1<<17)) return RISC_INT_SPFMIC_RX_DES_CH0;
		else if (QSTR1&(1<<16)) return RISC_INT_SPFMIC0;
		
        else if (QSTR2&(1<<15)) return RISC_INT_DMA_MFBSP3;
        else if (QSTR2&(1<<14)) return RISC_INT_MFBSP_TXBUF3;
        else if (QSTR2&(1<<13)) return RISC_INT_MFBSP_RXBUF3;
        else if (QSTR2&(1<<12)) return RISC_INT_SRQ3;

        else if (QSTR2&(1<<11)) return RISC_INT_DMA_MFBSP2;
        else if (QSTR2&(1<<10)) return RISC_INT_MFBSP_TXBUF2;
        else if (QSTR2&(1<<9)) return RISC_INT_MFBSP_RXBUF2;
        else if (QSTR2&(1<<8)) return RISC_INT_SRQ2;

        else if (QSTR2&(1<<7)) return RISC_INT_DMA_MFBSP1;
        else if (QSTR2&(1<<6)) return RISC_INT_MFBSP_TXBUF1;
        else if (QSTR2&(1<<5)) return RISC_INT_MFBSP_RXBUF1;
        else if (QSTR2&(1<<4)) return RISC_INT_SRQ1;

        else if (QSTR2&(1<<3)) return RISC_INT_DMA_MFBSP0;
        else if (QSTR2&(1<<2)) return RISC_INT_MFBSP_TXBUF0;
        else if (QSTR2&2) return RISC_INT_MFBSP_RXBUF0;
        else if (QSTR2&1) return RISC_INT_SRQ0;
    }

    else if (v&0x4000) return RISC_FROM_DSP;
    else if (v&0x8000) return RISC_COMPARE;

    //Exceptions
    else if (((v&0x7F)>>2) == 1) return RICS_EXC_MOD;
    else if (((v&0x7F)>>2) == 2) return RICS_EXC_TLBL;
    else if (((v&0x7F)>>2) == 3) return RICS_EXC_TLBS;
    else if (((v&0x7F)>>2) == 4) return RICS_EXC_ADEL;
    else if (((v&0x7F)>>2) == 5) return RICS_EXC_ADES;
    else if (((v&0x7F)>>2) == 8) return RICS_EXC_SYS;
    else if (((v&0x7F)>>2) == 9) return RICS_EXC_BP;
    else if (((v&0x7F)>>2) == 10) return RICS_EXC_RI;
    else if (((v&0x7F)>>2) == 11) return RICS_EXC_CPU;
    else if (((v&0x7F)>>2) == 12) return RICS_EXC_OV;
    else if (((v&0x7F)>>2) == 13) return RICS_EXC_TRAP;
    else if (((v&0x7F)>>2) == 15) return RICS_EXC_FPE;
    else if (((v&0x7F)>>2) == 24) return RICS_EXC_MCHECK;
}


void risc_common_handler()
{
   unsigned int v = 0;
   int cause = 0;
   asm volatile ("mfc0 %0, $13" :"=r"(v));
   cause = get_cause_risc(v);

   if ((cause >= RISC_INT_MEMCH17)&&(cause <= RISC_INT_MEMCH0)&&(risc_hnlr_func[RISC_INT_MEMCH] != UNKNOWN_RISC))
   {
      switch(cause)
      {
	  case RISC_INT_MEMCH17:
          risc_hnlr_func[RISC_INT_MEMCH](17);
          break;
      case RISC_INT_MEMCH16:
          risc_hnlr_func[RISC_INT_MEMCH](16);
          break;
      case RISC_INT_MEMCH15:
          risc_hnlr_func[RISC_INT_MEMCH](15);
          break;
	  case RISC_INT_MEMCH14:
          risc_hnlr_func[RISC_INT_MEMCH](14);
          break;
      case RISC_INT_MEMCH13:
          risc_hnlr_func[RISC_INT_MEMCH](13);
          break;
      case RISC_INT_MEMCH12:
          risc_hnlr_func[RISC_INT_MEMCH](12);
          break;
      case RISC_INT_MEMCH11:
          risc_hnlr_func[RISC_INT_MEMCH](11);
          break;
      case RISC_INT_MEMCH10:
          risc_hnlr_func[RISC_INT_MEMCH](10);
          break;
	  case RISC_INT_MEMCH7:
          risc_hnlr_func[RISC_INT_MEMCH](7);
          break;
      case RISC_INT_MEMCH6:
          risc_hnlr_func[RISC_INT_MEMCH](6);
          break;
      case RISC_INT_MEMCH5:
          risc_hnlr_func[RISC_INT_MEMCH](5);
          break;
      case RISC_INT_MEMCH4:
          risc_hnlr_func[RISC_INT_MEMCH](4);
          break;
      case RISC_INT_MEMCH3:
          risc_hnlr_func[RISC_INT_MEMCH](3);
          break;
      case RISC_INT_MEMCH2:
          risc_hnlr_func[RISC_INT_MEMCH](2);
          break;
      case RISC_INT_MEMCH1:
          risc_hnlr_func[RISC_INT_MEMCH](1);
          break;
      case RISC_INT_MEMCH0:
          risc_hnlr_func[RISC_INT_MEMCH](0);
          break;
      };
   }
   else if ((cause == RISC_FROM_DSP) && (risc_hnlr_func[RISC_FROM_DSP] != UNKNOWN_RISC))
   {
     if (DCSR(0)&0x1)
     {
       risc_hnlr_func[cause](R30_L(0));
     }
     else if (DCSR(1)&0x1)
     {
       risc_hnlr_func[cause](R30_L(1));
     }
   }
   else if (risc_hnlr_func[cause] != UNKNOWN_RISC)
   {
       risc_hnlr_func[cause](-1);
   }
}