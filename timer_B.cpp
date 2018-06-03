#include "timer_B.h"

timer_B::timer_B(int tms)
 {
 	count=0;
 	tick=tms/10;
  ms=clock2(); on=0;
 }

timer_B::~timer_B() { }

int timer_B::clock2() {	return count; }

bool timer_B::isOn() { return on; }

void timer_B::time()
 {
 	count++;
  if(on) ms=clock2(); on=0;
  if(clock2()-ms>tick) on=1; else on=0;
 }

void timer_B::reset()
 {
  ms=clock2(); on=0;
 }
