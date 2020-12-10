
#ifndef __BOID_H
#define __BOID_H

#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>

#include "utils/point.h"

class Flock;

// Each boid in a flock is represented by this class.
class Boid {

	private:

		std::array<int, 2> velocity;
		Point location;

	public:

		Boid();
		Boid( int, int, int, int );
		Boid( const Point &, int, int );
		// Will get the first two elements of the iterable for location. 
		template<typename Iter> Boid( int, int, Iter );
		template<typename Iter> Boid( Iter );


	friend class Flock;

};

#endif 

