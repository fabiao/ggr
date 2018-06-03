#pragma once

#include <ctime>

class timer_C
 {
 	private:
 	 bool on;
 	 clock_t ms;
 	 int tick;

 	public:
 	 timer_C(int);
 	 ~timer_C();
 	 bool isOn();
 	 void time();
 	 void reset();
 };