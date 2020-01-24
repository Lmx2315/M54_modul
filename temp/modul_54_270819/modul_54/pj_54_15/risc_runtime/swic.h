// ***************** simple_time.h ***********************************
//                 Risc-Dsp runtime library
//
// This file implements interface to SpaceWire
//
// (c) multicore.ru
//
// *******************************************************************
#ifndef _SWIC_H_
#define _SWIC_H_

#include "erlcommon.h"

#define MAX_PACKET_LEN 1024

#ifdef	__cplusplus
extern "C" {
#endif

typedef union
{
    unsigned int _val;
    struct
    {
        unsigned dc_err       : 1;
        unsigned p_err        : 1;
        unsigned esc_err      : 1;
        unsigned credit_err   : 1;
        unsigned              : 1;
        unsigned link_state   : 3;
        unsigned rx_buf_full  : 1;
        unsigned rx_buf_empty : 1;
        unsigned tx_buf_full  : 1;
        unsigned tx_buf_empty : 1;
        unsigned got_first_bit : 1;
        unsigned connected    : 1;
        unsigned got_time     : 1;
        unsigned got_int      : 1;
        unsigned got_ack      : 1;
        unsigned fl_control   : 1;
        unsigned link         : 1;
        unsigned err          : 1;
        unsigned time         : 1;
        unsigned cc_11        : 1;
        unsigned cc_01        : 1;
        unsigned              : 7;
        unsigned s_lvds_rx    : 1;
        unsigned d_lvds_rx    : 1;
    };
} SWIC_STATUS;

typedef union
{
    unsigned int _val;
    struct
    {
        unsigned linkdisabled : 1;
        unsigned autostart    : 1;
        unsigned linkstart    : 1;
        unsigned              : 29;
    };
} SWIC_MODE_CR;

typedef union
{
    unsigned int _val;
    struct
    {
        unsigned tx_speed     : 8;
        unsigned              : 24;
    };
} SWIC_TX_SPEED;

typedef union
{
    unsigned int _val;
    struct
    {
        unsigned rx_speed     : 8;
        unsigned              : 24;
    };
} SWIC_RX_SPEED;




void ClearSwic(int id);
void InitSwic(int id);
void SetSwicSpeed(int id, int speed);
// type: 0 - no packet end, 1 - EOP, 2 - EEP, 3 - LOG_ADDR
enum ERL_ERROR swic_send_packet(int id, void * src, int size, int type);
enum ERL_ERROR swic_receiver_wait(int id);
enum ERL_ERROR swic_receiver_run(int id, void * dst, unsigned int *descr, int size);
enum ERL_ERROR swic_receive_packet(unsigned int *dst, int *len);


#ifdef	__cplusplus
}
#endif

#endif // _SWIC_H_