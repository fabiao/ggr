#include "timer_C.h"
#include "util.h"

timer_C::timer_C(int tms)
 {
 	tick=tms;
  ms=AR_Clock(); on=0;
 }

timer_C::~timer_C() { }

bool timer_C::isOn() { return on; }

void timer_C::time()
 {
  if(on) ms=AR_Clock(); on=0;
  if(AR_Clock()-ms>tick) on=1; else on=0;
 }

void timer_C::reset()
 {
  ms=AR_Clock(); on=0;
 }
