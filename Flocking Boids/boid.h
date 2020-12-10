
#ifndef __BOID_H
#define __BOID_H

#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>

// Each boid in a flock is represented by this class.
class Boid {

	private:

		std::array<int, 2> velocity;

	public:

		Boid();
		Boid( int, int );
		// Will get the first two elements of the iterable.
		template<typename Iter> Boid( Iter );

};

#endif 

