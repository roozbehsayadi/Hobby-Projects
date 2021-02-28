
#ifndef __BB_UTILS_FPSDELAYER_H
#define __BB_UTILS_FPSDELAYER_H

#include <chrono>

class FPSDelayer {

	public:

		FPSDelayer( int = 30 );

		void startCounting();
		void wait();
		// Returns the passed time (since the startCounting() is called) in seconds.
		std::chrono::duration<double> passedTime();

	private:

		const int FPS;
		std::chrono::system_clock::time_point startTime;

};

#endif
