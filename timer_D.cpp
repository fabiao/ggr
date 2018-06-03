#include "timer_D.h"

timer_D::timer_D(int tms)
 {
  count=0;
  tick=tms;
  ms=Clock(); on=0;
 }

timer_D::~timer_D() { }

int timer_D::Clock() { return count; }

bool timer_D::isOn() { return on; }

void timer_D::time()
 {
  count++;
  if(on) ms=Clock(); on=0;
  if(Clock()-ms>tick) on=1; else on=0;
 }

void timer_D::reset()
 {
  ms=Clock(); on=0;
 }

void timer_D::setTick(int tms) { tick=tms; }
