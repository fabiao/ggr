#pragma once

#include <ctime>

class timer_D
 {
  private:
   bool on;
   clock_t ms;
   int tick;
   int count;
   int Clock();

  public:
   timer_D(int);
   ~timer_D();
   bool isOn();
   void time();
   void reset();
   void setTick(int);
 };