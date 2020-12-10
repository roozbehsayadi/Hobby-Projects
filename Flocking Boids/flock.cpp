
#include "flock.h"

Flock::Flock() {
	boids.clear();
	color.setColor( 255, 255, 255 );
}

Flock::Flock( const Color &color ) {
	boids.clear();
	this->color.setColor( color );
}

void Flock::initialize( int boidsCount ) {
	boids.resize( boidsCount );
}

