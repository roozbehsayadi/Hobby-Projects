
#include "flock.h"

const int Flock::MARGIN = 30;
const int Flock::VISUAL_RANGE = 20;

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
		double vxRandom = ( (double) std::rand() / RAND_MAX ) * 8 - 4;
		double vyRandom = ( (double) std::rand() / RAND_MAX ) * 8 - 4;
		// double vxRandom = (double) std::rand() / ( ( RAND_MAX + 1u ) / 3 );
		// double vyRandom = (double) std::rand() / ( ( RAND_MAX + 1u ) / 3 );
		// I tried to subtract 1 from these values at the above lines,
		// but their outputs got all messed up and I don't know why,
		// so I put these operation down here. 
		boid.velocity = { vxRandom, vyRandom };

		// Why didn't I use rand() % screenWidth or rand() % screenHeight?
		// Because that would be biased.
		// source: https://en.cppreference.com/w/cpp/numeric/random/rand
		double xRandom = std::rand() / ( ( RAND_MAX + 1u ) / screenWidth );
		double yRandom = std::rand() / ( ( RAND_MAX + 1u ) / screenHeight );
		boid.location = Point( xRandom, yRandom );
	}

}

void Flock::moveBoids() { 

	for ( auto &boid : boids ) {
		std::vector<std::array<double, 2>> vs( 0 );
		vs.push_back( moveTowardCenterOfMass( boid ) );
		
		for ( int i = 0; i < vs.size(); i++ ) {
			boid.velocity[0] += vs[i][0];
			boid.velocity[1] += vs[i][1];
		}

		boid.location = { boid.location.x + boid.velocity[0], boid.location.y + boid.velocity[1] };
	}

}

std::array<double, 2> Flock::moveTowardCenterOfMass( const Boid &boid ) {

	std::vector<std::pair<double, int>> distsAndIndexes;

	for ( int i = 0; i < boids.size(); i++ )
		distsAndIndexes.push_back( std::make_pair( Boid::getDistance( boids[i], boid ), i ) );

	std::sort( distsAndIndexes.begin(), distsAndIndexes.end() );

	std::array<double, 2> returnValue = {0, 0};
	for ( int i = 1; i <= std::min( Flock::VISUAL_RANGE, (int) distsAndIndexes.size() - 1 ); i++ ) {
		returnValue[0] += boids[ distsAndIndexes[i].second ].location.x;
		returnValue[1] += boids[ distsAndIndexes[i].second ].location.y;
	}

	int temp = std::min( Flock::VISUAL_RANGE, (int) distsAndIndexes.size() );
	returnValue = { returnValue[0] / temp, returnValue[1] / temp };

	returnValue = { returnValue[0] - boid.location.x, returnValue[1] - boid.location.y };
	returnValue = { returnValue[0] / 100, returnValue[1] / 100 };

	return returnValue;

}

