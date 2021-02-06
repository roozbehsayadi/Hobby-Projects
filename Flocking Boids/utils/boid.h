
#ifndef __UTILS_BOID_H
#define __UTILS_BOID_H

#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <math.h>

#include "point.h"

class Flock;
class FlockingMonitor;

// Each boid in a flock is represented by this class.
class Boid {

	private:

		std::array<double, 2> velocity;
		Point location;
		Point prevLocation;

	public:

		Boid();
		Boid( int, int, double, double );
		Boid( const Point &, double, double );

		static double getDistance( const Boid &, const Boid & );


	friend class Flock;
	friend class FlockingMonitor;

};

#endif 

