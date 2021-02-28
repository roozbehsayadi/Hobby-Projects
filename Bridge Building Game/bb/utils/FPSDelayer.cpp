
#include "FPSDelayer.h"

FPSDelayer::FPSDelayer( int FPS ) : startTime( std::chrono::system_clock::now() ), FPS( FPS ) {}

void FPSDelayer::startCounting() {
	startTime = std::chrono::system_clock::now();
}

void FPSDelayer::wait() {
	std::chrono::duration<double> elapsedTime;
	do
		elapsedTime = std::chrono::system_clock::now() - startTime;
	while ( elapsedTime.count() < ( 1.0 / FPS ) );
}

std::chrono::duration<double> FPSDelayer::passedTime() {
	return std::chrono::system_clock::now() - startTime;
}
