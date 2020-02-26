#include "dma_port_ch_reg_fields.hpp"

struct DMA_PORT_CH_REGS_BASE {
    volatile unsigned int CSR;
    volatile unsigned int CP;
    volatile unsigned int IR;
    volatile unsigned int RUN;
};

struct DMA_PORT_CH_cl {
    volatile struct DMA_PORT_CH_REGS_BASE * REGS;
    int n_bit;
};

extern struct DMA_PORT_CH_cl *DMA_RX_DESC;
extern struct DMA_PORT_CH_cl *DMA_RX_DATA;
extern struct DMA_PORT_CH_cl *DMA_TX_DESC;
extern struct DMA_PORT_CH_cl *DMA_TX_DATA;

void assign_dma_rx_desc(struct DMA_PORT_CH_cl *ptr);
void assign_dma_rx_data(struct DMA_PORT_CH_cl *ptr);
void assign_dma_tx_desc(struct DMA_PORT_CH_cl *ptr);
void assign_dma_tx_data(struct DMA_PORT_CH_cl *ptr);

int configure_wn(struct DMA_PORT_CH_cl *CHANNEL, void * Addr, unsigned int Size, int wn, int int_en);
int is_run(struct DMA_PORT_CH_cl *CHANNEL);
int wait_not_run(struct DMA_PORT_CH_cl *CHANNEL);
int start(struct DMA_PORT_CH_cl *CHANNEL);
int start_wn(struct DMA_PORT_CH_cl *CHANNEL, void * Addr, unsigned int Size, int wn);
unsigned int get_raw_addr(struct DMA_PORT_CH_cl *CHANNEL);
