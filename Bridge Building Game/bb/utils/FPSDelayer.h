
#ifndef __BB_UTILS_FPSDELAYER_H
#define __BB_UTILS_FPSDELAYER_H

#include <chrono>

// This class handles the stuff about maintaining the program's FPS.
class FPSDelayer {

	public:

		// Arguments:
		// - FPS (default = 60)
		FPSDelayer( int = 60 );

		// Stores the time that this functions
		// was called in a variable.
		void startCounting();
		// Waits some amount of time in order to
		// keep the FPS at the wanted order.
		void wait();
		// Returns the passed time (since the startCounting() is called).
		// call count() member function for output to get the time in seconds.
		std::chrono::duration<double> passedTime();

	private:

		const int FPS;
		std::chrono::system_clock::time_point startTime;

};

#endif
