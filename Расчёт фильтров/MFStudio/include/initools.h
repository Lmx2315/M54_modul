// ---------------------------------------------------------------------
//     This software is free, but in the event of publication, 
//     the following notice is applicable:
//
//                    (C) COPYRIGHT 2004 R&D center Elvees.
//
//     The entire notice above must be reproduced on all copies.
//
// ----------------------------------------------------------------------

#ifndef INITOOLS_H
#define INITOOLS_H
#include <map>
#include <string>

#include <stdio.h>

#define YY_DECL int scanner(struct ctx *data, Initools_ *cl)
#define PATH_MAX 4096

using namespace std;

struct ctx
{
  ctx *prev;
  char *curr_prefix;
  char *base_prefix;
  char *parm_name;
  char *filter;
  char *fname;
  char *basedir;
  static char *emptystr;
  int depth;
  void *bstate;
  ctx(ctx *p=0);
  ~ctx();
  ctx * pop();
};

class Initools_
{
private:
  typedef map<string, string> db_;
  typedef db_::iterator itr;

  db_ db;
  ctx *dat;
  string sectname;
public:
  Initools_();
  int update_param(string pname, char *pval, int maxlen);
  int update_param(string pname, string &s);
  int update_param(string pname, int &pval);
  int update_param(string pname, unsigned int &pval);
  int update_param(string pname, double &pval);
  int update_param(string pname, long &pval);
  int update_param(string pname, unsigned long &pval);
  int inifile(string fname);
  void section(string sname){sectname=sname+".";}
  int listall();
  friend YY_DECL;
};

#endif
