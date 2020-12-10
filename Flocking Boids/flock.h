
#ifndef __FLOCK_H
#define __FLOCK_H

#include <vector>

#include "boid.h"
#include "utils/color.h"

// Each flock consists of some boids. Creates and
// holds one flock and handles their movements.
class Flock {

	private:

		std::vector<Boid> boids;
		Color color;

	public:

		Flock();
		Flock( const Color & );

		// Resizes the vector of Boids according to the first argument.
		// Initializes the attributes of each boid with a random value.
		void initialize( int );

};

#endif

