// ******************** risc_interrupt.h ***************************************
//                 Risc-Dsp runtime library
//
// This file implements the interface to risk interrupt
// by setting MASKR registers and set handler vector
//
// (c) multicore.ru
//
// *******************************************************************

#ifndef _RISC_INTERRUPT_H_
#define _RISC_INTERRUPT_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include "erlcommon.h"

typedef void( *RISC_INTERRUPT )(int a);

#define UNKNOWN_RISC ((RISC_INTERRUPT)(-1))

typedef enum
{
        RISC_INT_SPWR7,                // QSTR0
		RISC_INT_SPWR6,
		RISC_INT_SPWR5,
		RISC_INT_SPWR4,
		RISC_INT_SPWR3,
		RISC_INT_SPWR2,
		RISC_INT_SPWR1,
		RISC_INT_SPWR0,
        RISC_INT_IT1,
        RISC_INT_IT0,
        RISC_INT_WDT,
        RISC_INT_SPWR_TX_DAT,
		RISC_INT_SPWR_TX_DES,
		RISC_INT_SPWR_RX_DAT,
		RISC_INT_SPWR_RX_DES,
        RISC_INT_EMAC_DMA_TX,
        RISC_INT_EMAC_DMA_RX,
        RISC_INT_EMAC_TX_FRAME,
        RISC_INT_EMAC_RX_FRAME,
        RISC_INT_USB_EP4,
        RISC_INT_USB_EP3,
        RISC_INT_USB_EP2,
        RISC_INT_USB_EP1,
        RISC_INT_USB,
		RISC_INT_SPI,
        RISC_INT_UART1,
        RISC_INT_UART0,
        RISC_INT_IRQ3,
        RISC_INT_IRQ2,
        RISC_INT_IRQ1,
        RISC_INT_IRQ0,
		RISC_INT_MEMCH17,        // QSTR1
        RISC_INT_MEMCH16,
        RISC_INT_MEMCH15,
        RISC_INT_MEMCH14,
        RISC_INT_MEMCH13,
        RISC_INT_MEMCH12,
        RISC_INT_MEMCH11,
        RISC_INT_MEMCH10,
		RISC_INT_MEMCH7,
        RISC_INT_MEMCH6,
        RISC_INT_MEMCH5,
        RISC_INT_MEMCH4,
        RISC_INT_MEMCH3,
        RISC_INT_MEMCH2,
        RISC_INT_MEMCH1,
        RISC_INT_MEMCH0,
		RISC_INT_MEMCH,
		RISC_INT_SPFMIC_TX_DAT_CH1,  // QSTR2
        RISC_INT_SPFMIC_TX_DES_CH1,
        RISC_INT_SPFMIC_RX_DAT_CH1,
        RISC_INT_SPFMIC_RX_DES_CH1,
		RISC_INT_SPFMIC1,
		RISC_INT_SPFMIC_TX_DAT_CH0,
        RISC_INT_SPFMIC_TX_DES_CH0,
        RISC_INT_SPFMIC_RX_DAT_CH0,
        RISC_INT_SPFMIC_RX_DES_CH0,
		RISC_INT_SPFMIC0,
        RISC_INT_DMA_MFBSP3,
        RISC_INT_MFBSP_TXBUF3,
        RISC_INT_MFBSP_RXBUF3,
        RISC_INT_SRQ3,
        RISC_INT_DMA_MFBSP2,
        RISC_INT_MFBSP_TXBUF2,
        RISC_INT_MFBSP_RXBUF2,
        RISC_INT_SRQ2,
        RISC_INT_DMA_MFBSP1,
        RISC_INT_MFBSP_TXBUF1,
        RISC_INT_MFBSP_RXBUF1,
        RISC_INT_SRQ1,
        RISC_INT_DMA_MFBSP0,
        RISC_INT_MFBSP_TXBUF0,
        RISC_INT_MFBSP_RXBUF0,
        RISC_INT_SRQ0,
		RISC_FROM_DSP,
		RISC_COMPARE,
        RICS_EXC_MOD,
        RICS_EXC_TLBL,
        RICS_EXC_TLBS,
        RICS_EXC_ADEL,
        RICS_EXC_ADES,
        RICS_EXC_SYS,
        RICS_EXC_BP,
        RICS_EXC_RI,
        RICS_EXC_CPU,
        RICS_EXC_OV,
        RICS_EXC_TRAP,
        RICS_EXC_FPE,
        RICS_EXC_MCHECK
} RISC_INTERRUPT_TYPE;

//Enumination: INTERRUPT_VECTORS
//
//List of location of interrupt vectors
typedef enum
{
    // Constant: INTH_80000180
    // BEV=0, IV=0, adress 0x80000180
    INTH_80000180,
    // Constant: INTH_BFC00380
    // BEV=1, IV=0, adress 0xBFC00380
    INTH_BFC00380,
    // Constant: INTH_80000200
    // BEV=0, IV=1, adress 0x80000200
    INTH_80000200,
    // Constant: INTH_BFC00400
    // BEV=1, IV=1, adress 0xBFC00400
    INTH_BFC00400,
} INTERRUPT_VECTORS;


// Section: Functions
//
// Function: risc_set_interrupts_vector
//
// Set adress of interrupts vector
//
// Parameters:
//      loc - location of interrupt vectors (from enum INTERRUPT_VECTORS)
//
// Examples:
//  > set_interrupts_vector(INTH_BFC00400);
//
void risc_set_interrupts_vector(INTERRUPT_VECTORS loc);

// Function: initialize_risc_hnlr
//
// Initialize vector of risc interrupt handlers
//
// Examples:
//  > initialize_risc_hnlr();
//
void initialize_risc_hnlr();

// Function: risc_enable_interrupt
//
// Enable risc interrupt by setting mask MASKR
//
// Parameters:
//      type - type of interrupt (from enum RISC_INTERRUPT_TYPE)
//
// Examples:
//  > risc_enable_interrupt(RISC_INT_IT);
//
// See also:
//
//      risc_disable_interrupt
//
void risc_enable_interrupt (RISC_INTERRUPT_TYPE type);

// Function: risc_disable_interrupt
//
// Disable risc interrupt by setting mask MASKR
//
// Parameters:
//      type - type of interrupt (from enum RISC_INTERRUPT_TYPE)
//
// Examples:
//  > risc_disable_interrupt(RISC_INT_IT);
//
// See also:
//
//      risc_enable_interrupt
//      risc_disable_interrupts
//
void risc_disable_interrupt (RISC_INTERRUPT_TYPE type);

// Function: risc_disable_interrupts
//
// Disable all risc interrupts by setting CP0 Status register
//
// Examples:
//  > risc_disable_interrupts();
//
// See also:
//
//      risc_enable_interrupt
//      risc_disable_interrupt
//
void risc_disable_interrupts();

// Function: risc_enable_interrupts
//
// Enable all risc interrupts by setting CP0 Status register
//
// Examples:
//  > risc_enable_interrupts();
//
// See also:
//
//      risc_enable_interrupt
//      risc_disable_interrupts
//
void risc_enable_interrupts();

// Function: risc_register_interrupt
//
// Register risc interrupt handler function in handlers vector
//
// Parameters:
//      fn - your handler function
//      type - type of interrupt, for which you set handler
//
// Returns:
//      ERL_ERROR - status of error (from enum ERL_ERROR)
//
// Examples:
//  > risc_register_interrupt(risc_tmr_hnlr, RISC_INT_IT);
//
// See also:
//
//      risc_enable_interrupt
//
enum ERL_ERROR risc_register_interrupt(RISC_INTERRUPT fn, RISC_INTERRUPT_TYPE type);

#ifdef	__cplusplus
}
#endif

#endif // _RISC_INTERRUPT_H_