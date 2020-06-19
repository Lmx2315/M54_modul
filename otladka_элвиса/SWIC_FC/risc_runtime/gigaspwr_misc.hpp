#ifndef GIGASPWR_MISC_H
#define GIGASPWR_MISC_H

#include "gigaspwr_reg_fields.hpp"

#define TOTAL_CNT_GIGASPWR_REGS_REDUCED 11
#define TOTAL_CNT_GIGASPWR_PMA_TEST_CSR_REDUCED 6


enum gigaspwr_link_status {
  link_status_err_reset = 0,
  link_status_err_wait = 1,
  link_status_ready = 2,
  link_status_started = 3,
  link_status_connecting = 4,
  link_status_run = 5
};

enum gigaspwr_ports {
  port_spw0	= 0x00,
  port_spw1	= 0x01,
  port_gigaspw0	= 0x02,
  port_gigaspw1	= 0x03,
  port_gigaspw2	= 0x04,
  port_gigaspw3	= 0x05,
  port_max_numb	= 0x05
};

enum gigaspwr_route_mask {
  route_mask_none	= 0,
  route_mask_conf	= (1 << 0),
  route_mask_spw0	= (1 << (port_spw0 + 1)),
  route_mask_spw1	= (1 << (port_spw1 + 1)),
  route_mask_gigaspw0	= (1 << (port_gigaspw0 + 1)),
  route_mask_gigaspw1	= (1 << (port_gigaspw1 + 1)),
  route_mask_gigaspw2	= (1 << (port_gigaspw2 + 1)),
  route_mask_gigaspw3	= (1 << (port_gigaspw3 + 1))
};

enum gigaspwr_irq_type {
  gigaspwr_irq_none = 0,
  gigaspwr_irq_connect = GIGASPWR_RISC_IRQ_MASK_IRQ_CONNECT_MASK(1),
  gigaspwr_irq_disconnect = GIGASPWR_RISC_IRQ_MASK_IRQ_DISCONNECT_MASK(1),
  gigaspwr_irq_ia_code = GIGASPWR_RISC_IRQ_MASK_IRQ_IA_CODE_GLOBAL_MASK(1),
  gigaspwr_irq_time = GIGASPWR_RISC_IRQ_MASK_IRQ_TIME_MASK(1),
  gigaspwr_irq_int = GIGASPWR_RISC_IRQ_MASK_IRQ_INT_MASK(1),
  gigaspwr_irq_ack = GIGASPWR_RISC_IRQ_MASK_IRQ_ACK_MASK(1),
  gigaspwr_irq_c01 = GIGASPWR_RISC_IRQ_MASK_IRQ_C01_MASK(1),
  gigaspwr_irq_c11 = GIGASPWR_RISC_IRQ_MASK_IRQ_C11_MASK(1),
  gigaspwr_irq_rst = GIGASPWR_RISC_IRQ_MASK_IRQ_INT_RST_MASK(1),
  gigaspwr_irq_touts = GIGASPWR_RISC_IRQ_MASK_IRQ_ISR_TOUTS_MASK(1),
  gigaspwr_irq_tarb = GIGASPWR_RISC_IRQ_MASK_IRQ_TARB_MASK(1),
  gigaspwr_irq_tres = GIGASPWR_RISC_IRQ_MASK_IRQ_TRES_MASK(1),
  gigaspwr_irq_tsend = GIGASPWR_RISC_IRQ_MASK_IRQ_TSEND_MASK(1),
  gigaspwr_irq_all= 0x1FFF
};

enum gigasw_speed_type {
  gigasw_speed_min = 1,
  gigasw_speed_5_mhz = 1,
  gigasw_speed_125_mhz = 25,

  gigasw_speed_312_mhz = 0x20,
  gigasw_speed_625_mhz = 0x40,
  gigasw_speed_1250_mhz = 0x60,
  gigasw_speed_max = gigasw_speed_1250_mhz
};

enum pma_test_tx_idle_cmd {
  pma_test_tx_cmd_idle = 0x1c,
  pma_test_tx_cmd_comma = 0xbc
};

enum pma_test_rx_accept_type {
  pma_test_rx_data_accept = 0x01,
  pma_test_rx_cmd_accept = 0x02,
  pma_test_rx_10b_accept = 0x04
};

#endif