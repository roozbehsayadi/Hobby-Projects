
#ifndef __FLOCKING_BOIDS_H
#define __FLOCKING_BOIDS_H

#include <chrono>
#include <vector>

#include "utils/flock.h"
#include "utils/flockingMonitor.h"
#include "utils/SDLEventType.h"

class FlockingBoids {

	private:

		const static int FPS;

		FlockingMonitor *monitor;

		std::vector<Flock*> flocks;

	public:

		// -1 is for fullscreen.
		FlockingBoids( int = -1, int = -1, const Color & = {255, 255, 255} );

		~FlockingBoids();

		void addFlock( int = 100, const Color & = {255, 255, 255 } );

		void start();

};

#endif

