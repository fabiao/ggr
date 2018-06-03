#pragma once

#include <ctime>

class timer_B
 {
 	private:
 	 bool on;
 	 clock_t ms;
 	 int tick;
 	 int count;
 	 int clock2();

 	public:
 	 timer_B(int);
 	 ~timer_B();
 	 bool isOn();
 	 void time();
 	 void reset();
 };