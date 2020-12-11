
#include "boid.h"

Boid::Boid() : Boid( 0, 0, 0, 0 ) {}

Boid::Boid( int x, int y, double xVel, double yVel ) {
	location = Point( x, y );
	velocity = {xVel, yVel};
}

Boid::Boid( const Point &location, double xVel, double yVel ) {
	this->location = location;
	velocity = {xVel, yVel};
}
/*
template<typename Iter>
Boid::Boid( int x, int y, Iter begin ) {
	location = Point( x, y );
	velocity = { *begin, *(++begin) };
}

template<typename Iter>
Boid::Boid( Iter begin ) {
	velocity = { *begin, *(++begin) };
}
*/

double Boid::getDistance( const Boid &b1, const Boid &b2 ) {
	double deltaX = b1.location.x - b2.location.x;
	double deltaY = b1.location.y - b2.location.y;
	return sqrt( pow( deltaX, 2 ) + pow( deltaY, 2 ) );
}

/*
template Boid::Boid<std::vector<double>::iterator>( std::vector<double>::iterator );
template Boid::Boid<std::list<double>::iterator>( std::list<double>::iterator );
template Boid::Boid<std::deque<double>::iterator>( std::deque<double>::iterator );
template Boid::Boid<std::array<double, 2>::iterator>( std::array<double, 2>::iterator );
template Boid::Boid<std::forward_list<double>::iterator>( std::forward_list<double>::iterator );

template Boid::Boid<Boid*>( Boid* );

template Boid::Boid<std::vector<double>::iterator>( int, int, std::vector<double>::iterator );
template Boid::Boid<std::list<double>::iterator>( int, int, std::list<double>::iterator );
template Boid::Boid<std::deque<double>::iterator>( int, int, std::deque<double>::iterator );
template Boid::Boid<std::array<double, 2>::iterator>( int, int, std::array<double, 2>::iterator );
template Boid::Boid<std::forward_list<double>::iterator>( int, int, std::forward_list<double>::iterator );
*/

