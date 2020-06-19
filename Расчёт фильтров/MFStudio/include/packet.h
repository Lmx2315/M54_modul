// ---------------------------------------------------------------------
//     This software is free, but in the event of publication, 
//     the following notice is applicable:
//
//                    (C) COPYRIGHT 2004 R&D center Elvees.
//
//     The entire notice above must be reproduced on all copies.
//
// ----------------------------------------------------------------------

#ifndef PACKET_H
#define PACKET_H

struct packet_
{
  static int npkt;
  packet_(){npkt++;}
  virtual void foo(){}
  virtual ~packet_();
};

#endif
