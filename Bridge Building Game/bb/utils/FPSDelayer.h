
#ifndef __BB_UTILS_FPSDELAYER_H
#define __BB_UTILS_FPSDELAYER_H

#include <chrono>

class FPSDelayer {

	public:

		FPSDelayer( int = 30 );

		void startCounting();
		void wait();

	private:

		const int FPS;
		decltype(std::chrono::system_clock::now()) startTime;

};

#endif
