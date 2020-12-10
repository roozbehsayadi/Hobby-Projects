
#ifndef __FLOCK_H
#define __FLOCK_H

#include <vector>

#include "boid.h"

// Each flock consists of some boids. Creates and
// holds one flock and handles their movements.
class Flock {

	private:

		std::vector<Boid> boids;

	public:

		Flock();

};

#endif

