// ---------------------------------------------------------------------
//     This software is free, but in the event of publication, 
//     the following notice is applicable:
//
//                    (C) COPYRIGHT 2004 R&D center Elvees.
//
//     The entire notice above must be reproduced on all copies.
//
// ----------------------------------------------------------------------

#ifndef ERR_H
#define ERR_H

#include <string>
#include "initools.h"

#define DEBUG_NONE    0
#define DEBUG_LOW     1
#define DEBUG_MEDIUM  2
#define DEBUG_HIGH    3
#define DEBUG_FINE    4

#define IF_DEBUG_LOW    if(debug_level>=DEBUG_LOW)
#define IF_DEBUG_MEDIUM if(debug_level>=DEBUG_MEDIUM)
#define IF_DEBUG_HIGH   if(debug_level>=DEBUG_HIGH)
#define IF_DEBUG_FINE   if(debug_level>=DEBUG_FINE)

#define tc_assert(a) if(!(a)) Err("failed %s, file %s, line %d", #a, __FILE__, __LINE__);

#ifdef WIN32 
typedef unsigned __int64 UINT64;
#define snprintf _snprintf
#else
typedef unsigned long long UINT64; 
#endif

using namespace std;

class err_
{
protected:
  static int errnum;
  static int warnnum;
  static int step_errnum;
  static int step_warnnum;
public:
  err_(string name):debug_level(5)
  {
    Name =name;
  }
  virtual string GetName(){return Name;}
  void set_debug_level(int a){debug_level=a;}
  virtual void Setup(Initools_ &database, string);
  static double (* tptr)();
protected:
  int debug_level;
  virtual void Err(const char *, ...);
  virtual void Warn(const char *, ...);
  virtual void Msg(const char *, ...);
  string Name;
  friend int WrapUp();
  friend int EndStep(); 
};

#endif
