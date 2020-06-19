// ---------------------------------------------------------------------
//     This software is free, but in the event of publication, 
//     the following notice is applicable:
//
//                    (C) COPYRIGHT 2004 R&D center Elvees.
//
//     The entire notice above must be reproduced on all copies.
//
// ----------------------------------------------------------------------

#ifndef MODULE_H
#define MODULE_H

#include <string>
#include "err.h"
#include "packet.h"

class module_ : public err_
{
  int nconn;
  int maxconn;
  module_ **conn;
public:
  module_(string name):err_(name), nconn(0), maxconn(4)
  {
    conn=new module_ * [maxconn];
  }
  virtual void Connect(module_ &);
  virtual void Unconnect(module_ &);
  virtual void Put(packet_ &p){Out(p);};
  virtual void Clear(){}
protected:
  void Out(packet_ &);
};


#endif
