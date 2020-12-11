
#include "flockingBoids.h"

FlockingBoids::FlockingBoids( int count, int screenWidth, int screenHeight, const Color &color ) {

	flock = Flock( screenWidth, screenHeight, color );
	flock.initializeRandomly( count );

}

void FlockingBoids::start() {
}

