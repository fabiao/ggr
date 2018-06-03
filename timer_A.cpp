#include "timer_A.h"

timer_A::timer_A(int tms)
 {
 	tick=tms;
  ms=clock(); on=0;
 }

timer_A::~timer_A() { }

bool timer_A::isOn() { return on; }

void timer_A::time()
 {
  if(on) ms=clock(); on=0;
  if(clock()-ms>tick) on=1; else on=0;
 }

void timer_A::reset()
 {
  ms=clock(); on=0;
 }
