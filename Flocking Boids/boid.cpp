
#include "boid.h"

Boid::Boid() : Boid( 0, 0 ) {}

Boid::Boid( int xVel, int yVel ) {
	velocity = {xVel, yVel};
}

template<typename Iter>
Boid::Boid( Iter begin ) {
	velocity = { *begin, *(++begin) };
}

template Boid::Boid<std::vector<int>::iterator>( std::vector<int>::iterator );
template Boid::Boid<std::list<int>::iterator>( std::list<int>::iterator );
template Boid::Boid<std::deque<int>::iterator>( std::deque<int>::iterator );
template Boid::Boid<std::array<int, 2>::iterator>( std::array<int, 2>::iterator );
template Boid::Boid<std::forward_list<int>::iterator>( std::forward_list<int>::iterator );

