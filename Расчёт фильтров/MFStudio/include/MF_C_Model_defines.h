// ---------------------------------------------------------------------
//     This software is free, but in the event of publication, 
//     the following notice is applicable:
//
//                    (C) COPYRIGHT 2004 R&D center Elvees.
//
//     The entire notice above must be reproduced on all copies.
//
// ----------------------------------------------------------------------

#ifndef MF_C_MODEL_DEFINES
#define MF_C_MODEL_DEFINES

#include "packet.h"

#ifdef WIN32 
typedef __int64 INT64;
#else
#include <stdint.h>
typedef int_fast64_t INT64;
#endif


const int max_8bit=127;
const int min_8bit=-128;

const int max_in=32767;
const int min_in=-32767;

const int max_out=32767;
const int min_out=-32767;

const int max_data=(1<<19)-1;
const int min_data=-max_data;

const int lut_size=256;
const int data_t_width=         20;
const int phase_t_width=        32;
const int frq_t_width=          32;
const int dphase_t_width=       16;
const int cicn_data_t_width=    44;
const int cic2_data_t_width=    36;
const int fir_data_t_width=     41;
const int fir_cf_t_width=       16;
const int scaler_in_t_width=    cic2_data_t_width;
const int nco_lut_data_t_width= 17;
const int nco_lut_sin_t_width=  16;
const int nco_lut_dsin_t_width= 9;
const int nco_lut_addr_width=   8;
const int nco_lut_lsb_width=    8;

typedef int         in_t;
typedef int         out_t;
typedef int data_t;
typedef unsigned int phase_t;  // phase accumulator
typedef unsigned int frq_t;    // NCO_FRQ
typedef unsigned int dphase_t; // NCO_PHASE
typedef INT64 cicn_data_t;
typedef INT64 cic2_data_t;
typedef INT64 fir_data_t;
typedef int fir_cf_t;   // fir coeff
typedef INT64 scaler_in_t;
typedef int nco_lut_data_t;   // sin gen output data
typedef int nco_lut_sin_t;    // main table width
typedef int nco_lut_dsin_t;   // delta table width

struct in_sample_ : public packet_
{
  in_t I;
  in_t Q;
  
  template<class T>
  in_sample_(const T i, const T q):
    I(i), Q(q)
  {
  }
  in_sample_():
    I(0), Q(0)
  {}
};

struct out_sample_ : public packet_
{
  out_t I;
  out_t Q;
  
  template<class T>
  out_sample_(const T i, const T q):
    I(i), Q(q)
  {
    if(I>max_out) I=max_out;
    else if(I<min_out) I=min_out;
    
    if(Q>max_out) Q=max_out;
    else if(Q<min_out) Q=min_out;
  }
  out_sample_():
    I(0), Q(0)
  {}
};

struct data_main_ : public packet_
{
  data_t I, Q;
  
  data_main_():
    I(0), Q(0)
  {}
  template<class T>
  data_main_(const T &i, const T &q):
    I(i), Q(q)
  {
    if(I>max_data) I=max_data;
    else if(I<min_data) I=min_data;
    
    if(Q>max_data) Q=max_data;
    else if(Q<min_data) Q=min_data;
  }
};

struct scaler_in_sample_ : public packet_
{
  scaler_in_t I, Q;
  template<class T>
  scaler_in_sample_(T i, T q):
    I(i), Q(q)
  {}
};


template<class T>
struct g_sample_
{ 
  T I;
  T Q;
  explicit 
  g_sample_(int v):
    I(v), Q(0){}
  template<typename T3>
  g_sample_(T3 i, T3 q):
    I(i), Q(q){}
  g_sample_():
    I(0), Q(0)
  {}
  
  g_sample_ &operator=(int v){I=v; Q=0; return *this; }
  g_sample_ &operator+=(const g_sample_ &o){ I+=o.I; Q+=o.Q; return *this;}
  g_sample_ &operator-=(const g_sample_ &o){ I-=o.I; Q-=o.Q; return *this;}
  g_sample_  operator+ (const g_sample_ &o){ return g_sample_<T>(I+o.I, Q+o.Q); }
  g_sample_  operator- (const g_sample_ &o){ return g_sample_<T>(I-o.I, Q-o.Q); }
  g_sample_  operator* (const T m){ return g_sample_<T>(I*m, Q*m); }
};

template<typename T>
inline void wlim_sign(T &val, int width)
{
  width--;
  if(val & ((T)1)<<width )
    val |= ~((((T)1)<<width)-1);
  else
    val &= ((((T)1)<<width)-1);
}
 
#endif
