
#ifndef __UTILS_FLOCK_H
#define __UTILS_FLOCK_H

#include <stdlib.h>
#include <vector>

#include "boid.h"
#include "color.h"
#include "flockingMonitor.h"

class FlockingMonitor;

// Each flock consists of some boids. Creates and
// holds one flock and handles their movements.
class Flock {

	private:

		static const int MARGIN = 30;

		FlockingMonitor *monitor;

		int screenWidth, screenHeight;
		std::vector<Boid> boids;
		Color color;

	public:

		// The first one does nothing.
		Flock();
		Flock( int, int );
		Flock( int, int, const Color & );

		// Resizes the vector of Boids according to the first argument.
		// Initializes the attributes of each boid with a random value.
		void initializeRandomly( int );


};

#endif

