// ---------------------------------------------------------------------
//     This software is free, but in the event of publication, 
//     the following notice is applicable:
//
//                    (C) COPYRIGHT 2004 R&D center Elvees.
//
//     The entire notice above must be reproduced on all copies.
//
// ----------------------------------------------------------------------

#ifndef MF01_MODEL_H
#define MF01_MODEL_H

#include <string>
#include <complex>
#include "err.h"
#include "module.h"
#include "MF_C_Model_defines.h"

using namespace std;

class MF01_model_ : public module_
{
public:
  MF01_model_(string name);
  ~MF01_model_();

  virtual void Setup (string file, string section);

  void Put(packet_ &p);
  virtual void Put(int I);
  virtual void Put(int I, int Q);
  virtual void Put(complex<int> r);

  // Read sample from FIFO. If Œ  return 1, else 0.  
  virtual int Get(out_sample_ &s); 
  virtual int Get(complex<int>&s);
  virtual int Get(int& i, int& q); 
  virtual int num_available();  //number of stored samples 

  virtual unsigned num_in_samples(); 
  virtual unsigned num_out_samples();

  virtual void set_Debug (int);
  virtual void set_in_fmt(int);

  virtual void set_HTRD(int pdith_en, frq_t nco_frq, phase_t nco_phase);
  virtual void set_in_type (int in_type );
  virtual void set_pdith_en(int pdith_en);
  virtual void set_NCO_FRQ (frq_t frq   );
  virtual void set_NCO_PHASE(phase_t ph );

  virtual void set_DCIC2(int mode, int dr, int scl); 
  virtual void set_DCIC2_mode (int mode);
  virtual void set_DCIC2_dr   (int dr  );
  virtual void set_DCIC2_scl  (int scl );
   
  virtual void set_DCICN(int mode, int dr, int scl_mx, int scl);
  virtual void set_DCICN_mode   (int mode  );
  virtual void set_DCICN_dr     (int dr    );
  virtual void set_DCICN_scl_mx (int scl_mx);
  virtual void set_DCICN_scl    (int scl   );

  virtual void set_DFIR1_CFG(int sym, int order, int dr, int scl, int dly);
  virtual void set_DFIR1_sym   (int sym  );
  virtual void set_DFIR1_order (int order);
  virtual void set_DFIR1_dr    (int dr   );
  virtual void set_DFIR1_scl   (int scl  );
  virtual void set_DFIR1_dly   (int dly  );
  virtual void set_DFIR1_coeff (int idx, int coeff  );
  virtual void load_DFIR1_from_file (string fileCoef);

  virtual void set_DFIR2_CFG(int sym, int order, int dr, int scl, int dly);
  virtual void set_DFIR2_sym   (int sym  );
  virtual void set_DFIR2_order (int order);
  virtual void set_DFIR2_dr    (int dr   );
  virtual void set_DFIR2_scl   (int scl  );
  virtual void set_DFIR2_dly   (int dly  );
  virtual void set_DFIR2_coeff (int idx, int coeff  );
  virtual void load_DFIR2_from_file (string fileCoef);

  virtual void set_GAIN_I (int);
  virtual void set_GAIN_Q (int);
  virtual void set_GAIN (int I, int Q);
  virtual void load_coef(string fileCoef, string filter);   

  virtual void set_dump_file_prefix(string str);
  virtual void set_dump(int bitmask, int num);
};

MF01_model_* Create_MF01_model(string name);

void Delete_MF01_model(MF01_model_* t);

#endif
