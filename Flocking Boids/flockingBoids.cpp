
#include "flockingBoids.h"

const int FlockingBoids::FPS = 24;

FlockingBoids::FlockingBoids( int screenWidth, int screenHeight, const Color &color ) {

	monitor = new FlockingMonitor( screenWidth, screenHeight );

	flocks.clear();

}

FlockingBoids::~FlockingBoids() {
	for ( auto &i : flocks ) 
		delete i;
	delete monitor;
}

void FlockingBoids::addFlock( int boidsCount, const Color &color  ) { 
	Flock *temp = new Flock( color, this->monitor );
	temp->initializeRandomly( boidsCount );
	flocks.push_back( temp );
}

void FlockingBoids::start() {

	while ( true ) { 

		auto startTime = std::chrono::system_clock::now();
	
		SDLEventType eventType = monitor->handleEvents();
		if ( eventType == SDLEventType::QUIT )
			return;
		for ( auto &flock : flocks ) {
			flock->moveBoids();
			monitor->drawBoids( flock );
		}
		// I'll uncomment this line when I improve the performance of the program.
		// Flock::keepDistanceFromAllObjects( flocks );
		monitor->updateScreen();

		std::chrono::duration<double> elapsedTime;
		do
			elapsedTime = std::chrono::system_clock::now() - startTime;
		while ( elapsedTime.count() < ( 1.0 / FlockingBoids::FPS ) );

	}

}

