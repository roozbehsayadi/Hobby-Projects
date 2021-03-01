
#ifndef __BB_UTILS_TIMERS_TIMER_H
#define __BB_UTILS_TIMERS_TIMER_H

#include <chrono>

class FPSDelayer;

class Timer {

	public:

		// Starts the chronometr.
		Timer();

		// Starts the chronometr.
		void startCounting();

		// Returns the passed time since the last call of 
		// startCounting(), or since the creation of the object
		// if startCounting() wasn't called. You have to call 
		// count() member function for the output to get
		// the passed time in seconds e.g. passedTime().count().
		std::chrono::duration<double> passedTime() const;

	private:

		std::chrono::system_clock::time_point startTime;
	
	friend class FPSDelayer;

};

#endif
