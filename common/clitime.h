// Hey, Emacs, this a -*-C++-*- file !

// Copyright distributed.net 1997-1998 - All Rights Reserved
// For use in distributed.net projects only.
// Any other distribution or use of this source violates copyright.

// This file contains functions for obtaining/formatting/manipulating 
// the time. 'time' is always stored/passed/returned in timeval format.
// 
// $Log: clitime.h,v $
// Revision 1.6  1998/06/29 06:57:58  jlawson
// added new platform OS_WIN32S to make code handling easier.
//
// Revision 1.5  1998/06/14 08:12:46  friedbait
// 'Log' keywords added to maintain automatic change history
//
// 

#ifndef _CLITIME_H_
#define _CLITIME_H_

#include "client.h" //need definition of time functions and CLIENT_OS

// Get the current time in timeval format (pass NULL if storage not req'd)
struct timeval *CliTimer( struct timeval *tv );

// Get time as string. Curr time if tv is NULL. Separate buffers for each
// type: 0=blank type 1, 1="MMM dd hh:mm:ss GMT", 2="hhhh:mm:ss.pp"
const char *CliGetTimeString( struct timeval *tv, int strtype );

// Get the time since program start (pass NULL if storage not required)
struct timeval *CliClock( struct timeval *tv );

// Add 'tv1' to 'tv2' and store in 'result'. Uses curr time if a 'tv' is NULL
// tv1/tv2 are not modified (unless 'result' is the same as one of them).
int CliTimerAdd( struct timeval *result, struct timeval *tv1, struct timeval *tv2 );

// Store non-negative diff of tv1 and tv2 in 'result'. Uses current time if a 'tv' is NULL
// tv1/tv2 are not modified (unless 'result' is the same as one of them).
int CliTimerDiff( struct timeval *result, struct timeval *tv1, struct timeval *tv2 );

#endif //ifndef _CLITIME_H_


