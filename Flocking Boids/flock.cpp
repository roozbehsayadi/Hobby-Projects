
#include "flock.h"

Flock::Flock() {
	boids.clear();
	color.setColor( 255, 255, 255 );
}

Flock::Flock( const Color &color ) {
	boids.clear();
	color.setColor( color );
}

