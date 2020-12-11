
#ifndef __UTILS_FLOCK_H
#define __UTILS_FLOCK_H

#include <stdlib.h>
#include <iostream>
#include <utility>
#include <array>
#include <vector>
#include <algorithm>

#include "boid.h"
#include "color.h"
#include "flockingMonitor.h"

class FlockingMonitor;
class FlockingBoids;
class Point;

// Each flock consists of some boids. Creates and
// holds one flock and handles their movements.
class Flock {

	private:

		static const int MARGIN;
		static const int VISUAL_RANGE; //How many boids can a single boid see? 

		FlockingMonitor *monitor;

		int screenWidth, screenHeight;
		std::vector<Boid> boids;
		Color color;

		void moveBoids();

		// Resizes the vector of Boids according to the first argument.
		// Initializes the attributes of each boid with a random value.
		void initializeRandomly( int );

		std::array<double, 2> moveTowardCenterOfMass( const Boid & );

	public:

		// The first one does nothing.
		Flock();
		Flock( int, int );
		Flock( int, int, const Color & );

		~Flock();

	friend class FlockingMonitor;
	friend class FlockingBoids;

};

#endif

