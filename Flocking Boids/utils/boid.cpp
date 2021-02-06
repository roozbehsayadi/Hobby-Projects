
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

double Boid::getDistance( const Boid &b1, const Boid &b2 ) {
	double deltaX = b1.location.x - b2.location.x;
	double deltaY = b1.location.y - b2.location.y;
	return sqrt( pow( deltaX, 2 ) + pow( deltaY, 2 ) );
}

