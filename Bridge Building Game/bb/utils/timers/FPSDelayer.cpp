
#include "FPSDelayer.h"

FPSDelayer::FPSDelayer( int FPS ) : FPS( FPS ) {}

void FPSDelayer::wait() {
	std::chrono::duration<double> elapsedTime;
	do
		elapsedTime = std::chrono::system_clock::now() - startTime;
	while ( elapsedTime.count() < ( 1.0 / FPS ) );
}
