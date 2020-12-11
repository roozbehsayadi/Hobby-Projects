
#include "flockingBoids.h"

FlockingBoids::FlockingBoids( int count, int screenWidth, int screenHeight, const Color &color ) {

	flock = new Flock( screenWidth, screenHeight, color );
	flock->initializeRandomly( count );

}

FlockingBoids::~FlockingBoids() {
	delete flock;
}

void FlockingBoids::start() {

	while ( true ) { 
	
		SDLEventType eventType = flock->monitor->handleEvents();
		if ( eventType == SDLEventType::QUIT )
			return;
		flock->monitor->drawBoids();
		flock->monitor->updateScreen();

	}

}

