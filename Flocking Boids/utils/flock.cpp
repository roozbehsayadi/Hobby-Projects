
#include "flock.h"

Flock::Flock() {}

Flock::Flock( int screenWidth, int screenHeight ) : Flock( screenWidth, screenHeight, Color( 255, 255, 255 ) ) {}

Flock::Flock( int screenWidth, int screenHeight, const Color &color ) {

	boids.clear();
	this->color.setColor( color );
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

	monitor = new FlockingMonitor( this, this->screenWidth, this->screenHeight );

}

Flock::~Flock() {
	delete monitor;
}

void Flock::initializeRandomly( int boidsCount ) {

	boids.resize( boidsCount );

	for ( auto &boid : boids ) {
		double vxRandom = std::rand() / ( ( RAND_MAX + 1u ) / 3 );
		double vyRandom = std::rand() / ( ( RAND_MAX + 1u ) / 3 );
		// I tried to subtract 1 from these values at the above lines,
		// but their outputs got all messed up and I don't know why,
		// so I put these operation down here. 
		vxRandom--;
		vyRandom--; 
		boid.velocity = { vxRandom, vyRandom };

		// Why didn't I use rand() % screenWidth or rand() % screenHeight?
		// Because that would be biased.
		// source: https://en.cppreference.com/w/cpp/numeric/random/rand
		double xRandom = std::rand() / ( ( RAND_MAX + 1u ) / screenWidth );
		double yRandom = std::rand() / ( ( RAND_MAX + 1u ) / screenHeight );
		boid.location = Point( xRandom, yRandom );
	}

}

