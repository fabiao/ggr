#pragma once

#include <ctime>

class timer_A
 {
 	private:
 	 bool on;
 	 clock_t ms;
 	 int tick;

 	public:
 	 timer_A(int);
 	 ~timer_A();
 	 bool isOn();
 	 void time();
 	 void reset();
 };