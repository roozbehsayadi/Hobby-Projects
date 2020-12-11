
#include "flockingBoids.h"

const int FlockingBoids::FPS = 24;

FlockingBoids::FlockingBoids( int count, int screenWidth, int screenHeight, const Color &color ) {

	flock = new Flock( screenWidth, screenHeight, color );
	flock->initializeRandomly( count );

}

FlockingBoids::~FlockingBoids() {
	delete flock;
}

void FlockingBoids::start() {

	while ( true ) { 

		auto startTime = std::chrono::system_clock::now();
	
		SDLEventType eventType = flock->monitor->handleEvents();
		if ( eventType == SDLEventType::QUIT )
			return;
		flock->moveBoids();
		flock->monitor->drawBoids();
		flock->monitor->updateScreen();

		std::chrono::duration<double> elapsedTime;
		do
			elapsedTime = std::chrono::system_clock::now() - startTime;
		while ( elapsedTime.count() < ( 1.0 / FlockingBoids::FPS ) );

	}

}

