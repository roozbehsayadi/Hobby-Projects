
#ifndef __FLOCKING_BOIDS_H
#define __FLOCKING_BOIDS_H

#include "utils/flock.h"

class FlockingBoids {

	private:

		Flock flock;

	public:

		// -1 is for fullscreen.
		FlockingBoids( int = 100, int = -1, int = -1, const Color & = {255, 255, 255} );

		void start();

};

#endif

