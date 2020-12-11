
#ifndef __FLOCKING_BOIDS_H
#define __FLOCKING_BOIDS_H

#include <chrono>

#include "utils/flock.h"
#include "utils/SDLEventType.h"

class FlockingBoids {

	private:

		const static int FPS;

		Flock *flock;

	public:

		// -1 is for fullscreen.
		FlockingBoids( int = 100, int = -1, int = -1, const Color & = {255, 255, 255} );

		~FlockingBoids();

		void start();

};

#endif

