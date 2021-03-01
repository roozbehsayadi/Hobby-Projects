
#ifndef __BB_UTILS_FPSDELAYER_H
#define __BB_UTILS_FPSDELAYER_H

#include <chrono>

#include "timer.h"

// This class handles the stuff about maintaining the program's FPS.
class FPSDelayer : public Timer {

	public:

		// Arguments:
		// - FPS (default = 60)
		// Also starts the chronometr.
		FPSDelayer( int = 60 );

		// Waits some amount of time in order to
		// keep the FPS at the wanted order.
		void wait();

	private:

		const int FPS;

};

#endif
