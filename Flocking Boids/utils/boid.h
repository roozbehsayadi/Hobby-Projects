
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

	public:

		Boid();
		Boid( int, int, double, double );
		Boid( const Point &, double, double );
		// Will get the first two elements of the iterable for location. 
		template<typename Iter> Boid( int, int, Iter );
		template<typename Iter> Boid( Iter );

		static double getDistance( const Boid &, const Boid & );


	friend class Flock;
	friend class FlockingMonitor;

};

#endif 

