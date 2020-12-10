
#include "boid.h"

Boid::Boid() : Boid( 0, 0, 0, 0 ) {}

Boid::Boid( int x, int y, int xVel, int yVel ) {
	location = Point( x, y );
	velocity = {xVel, yVel};
}

Boid::Boid( const Point &location, int xVel, int yVel ) {
	this->location = location;
	velocity = {xVel, yVel};
}

template<typename Iter>
Boid::Boid( int x, int y, Iter begin ) {
	location = Point( x, y );
	velocity = { *begin, *(++begin) };
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

template Boid::Boid<std::vector<int>::iterator>( int, int, std::vector<int>::iterator );
template Boid::Boid<std::list<int>::iterator>( int, int, std::list<int>::iterator );
template Boid::Boid<std::deque<int>::iterator>( int, int, std::deque<int>::iterator );
template Boid::Boid<std::array<int, 2>::iterator>( int, int, std::array<int, 2>::iterator );
template Boid::Boid<std::forward_list<int>::iterator>( int, int, std::forward_list<int>::iterator );


