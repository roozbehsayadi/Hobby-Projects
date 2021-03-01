
#include "timer.h"

Timer::Timer() {
	startCounting();
}

void Timer::startCounting() {
	startTime = std::chrono::system_clock::now();
}

std::chrono::duration<double> Timer::passedTime() const {
	return std::chrono::system_clock::now() - startTime;
}
