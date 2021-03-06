
#include "flock.h"

const int Flock::MARGIN = 30;
const int Flock::VISUAL_RANGE = 20;
const int Flock::VELOCITY_LIMIT = 10;

Flock::Flock() {}

Flock::Flock( FlockingMonitor * monitor ) : Flock( Color( 255, 255, 255 ), monitor ) {}

Flock::Flock( const Color &color, FlockingMonitor *monitor  ) {

	boids.clear();

	this->color.setColor( color );

	this->monitor = monitor;

}

void Flock::initializeRandomly( int boidsCount ) {

	boids.resize( boidsCount );

	for ( auto &boid : boids ) {
		double vxRandom = ( (double) std::rand() / RAND_MAX ) * 8 - 4;
		double vyRandom = ( (double) std::rand() / RAND_MAX ) * 8 - 4;
		boid.velocity = { vxRandom, vyRandom };

		// Why didn't I use rand() % screenWidth or rand() % screenHeight?
		// Because that would be biased.
		// source: https://en.cppreference.com/w/cpp/numeric/random/rand
		double xRandom = std::rand() / ( ( RAND_MAX + 1u ) / this->monitor->screen->w );
		double yRandom = std::rand() / ( ( RAND_MAX + 1u ) / this->monitor->screen->h );
		boid.prevLocation = boid.location = Point( xRandom, yRandom );
	}

}

void Flock::moveBoids() { 

	for ( auto &boid : boids ) {
		std::vector<std::array<double, 2>> vs( 0 );

		auto distsAndIndexes = getNearDistances( boid );
		vs.push_back( moveTowardCenterOfMass( boid, distsAndIndexes ) );
		vs.push_back( keepDistanceFromObjects( boid, distsAndIndexes ) );
		vs.push_back( matchVelocityWithOtherBoids( boid, distsAndIndexes ) );
		vs.push_back( boundPosition( boid ) );
		
		for ( int i = 0; i < vs.size(); i++ ) {
			boid.velocity[0] += vs[i][0];
			boid.velocity[1] += vs[i][1];
		}

		limitVelocity( boid );

		boid.prevLocation = boid.location;
		boid.location = { boid.location.x + boid.velocity[0], boid.location.y + boid.velocity[1] };
	}

}

std::vector<std::pair<double, int>> Flock::getNearDistances( const Boid &boid ) {

	std::vector<std::pair<double, int>> distsAndIndexes;

	for ( int i = 0; i < boids.size(); i++ )
		distsAndIndexes.push_back( std::make_pair( Boid::getDistance( boids[i], boid ), i ) );

	std::sort( distsAndIndexes.begin(), distsAndIndexes.end() );

	return std::vector<std::pair<double, int>>( distsAndIndexes.begin() + 1, distsAndIndexes.begin() + std::min( Flock::VISUAL_RANGE, (int) distsAndIndexes.size() ) );

}

std::array<double, 2> Flock::moveTowardCenterOfMass( const Boid &boid, std::vector<std::pair<double, int>> distsAndIndexes ) {

	std::array<double, 2> returnValue = {0, 0};
	for ( int i = 0; i < distsAndIndexes.size(); i++ ) {
		returnValue[0] += boids[ distsAndIndexes[i].second ].location.x;
		returnValue[1] += boids[ distsAndIndexes[i].second ].location.y;
	}

	returnValue = { returnValue[0] / distsAndIndexes.size(), returnValue[1] / distsAndIndexes.size() };

	returnValue = { returnValue[0] - boid.location.x, returnValue[1] - boid.location.y };
	returnValue = { returnValue[0] / 50, returnValue[1] / 50 };

	return returnValue;

}

std::array<double, 2> Flock::keepDistanceFromObjects( const Boid &boid, std::vector<std::pair<double, int>> distsAndIndexes ) { 

	std::array<double, 2> returnValue = {0, 0};

	for ( auto &otherBoidPair : distsAndIndexes ) {
		Boid &otherBoid = boids[ otherBoidPair.second ];
		if ( Boid::getDistance( boid, otherBoid ) < 30 ) {
			returnValue[0] -= ( otherBoid.location.x - boid.location.x ) / 10;
			returnValue[1] -= ( otherBoid.location.y - boid.location.y ) / 10;
		}
	}

	return returnValue;

}

std::array<double, 2> Flock::matchVelocityWithOtherBoids( const Boid &boid, std::vector<std::pair<double, int>> distsAndIndexes ) { 

	std::array<double, 2> returnValue = {0, 0};

	for ( auto &otherBoidPair : distsAndIndexes ) { 
		Boid &otherBoid = boids[ otherBoidPair.second ];
		returnValue = { returnValue[0] + otherBoid.velocity[0], returnValue[1] + otherBoid.velocity[1] };
	}

	returnValue = { returnValue[0] / distsAndIndexes.size(), returnValue[1] / distsAndIndexes.size() };

	returnValue = { returnValue[0] - boid.velocity[0], returnValue[1] - boid.velocity[1] };

	returnValue = { returnValue[0] / 8, returnValue[1] / 8 };

	return returnValue;

}

std::array<double, 2> Flock::boundPosition( const Boid &boid ) { 

	std::array<double, 2> returnValue = {0, 0};
	if ( boid.location.x < Flock::MARGIN ) 
		returnValue[0] = 5;
	if ( boid.location.x > this->monitor->screen->w - Flock::MARGIN )
		returnValue[0] = -5;
	if ( boid.location.y < Flock::MARGIN ) 
		returnValue[1] = 5;
	if ( boid.location.y > this->monitor->screen->h - Flock::MARGIN )
		returnValue[1] = -5;
	
	return returnValue;

}

void Flock::limitVelocity( Boid &boid ) {

	double boidVelocityMagnitude = sqrt( pow( boid.velocity[0], 2 ) + pow( boid.velocity[1], 2 ) );
	boid.velocity[0] = ( boid.velocity[0] / boidVelocityMagnitude ) * Flock::VELOCITY_LIMIT;
	boid.velocity[1] = ( boid.velocity[1] / boidVelocityMagnitude ) * Flock::VELOCITY_LIMIT;

}

void Flock::keepDistanceFromAllObjects( std::vector<Flock*> &flocks ) {

	int totalBoidsCount = 0;
	for ( auto &flock : flocks ) 
		totalBoidsCount += flock->boids.size();
	Boid **allBoids = new Boid*[ totalBoidsCount ];
//	std::vector<Boid*, std::allocator<Boid*>> allBoids;

	int allBoidsCounter = 0;
	for ( auto &flock : flocks ) 
		for ( auto &boid : flock->boids )
			allBoids[ allBoidsCounter++ ] = &boid;
	
	std::vector<std::pair<double, int>> distsAndIndexes;

	for ( int i = 0; i < totalBoidsCount; i++ ) {
		Boid &boid = *allBoids[ i ];
		for ( int i = 0; i < totalBoidsCount; i++ )
		
		distsAndIndexes.push_back( std::make_pair( Boid::getDistance( *(allBoids[i]), boid ), i ) );

		std::sort( distsAndIndexes.begin(), distsAndIndexes.end() );

		distsAndIndexes = std::vector<std::pair<double, int>>( distsAndIndexes.begin() + 1, distsAndIndexes.begin() + std::min( Flock::VISUAL_RANGE, (int) distsAndIndexes.size() ) );

		std::array<double, 2> deltaV = {0, 0};
		for ( auto &otherBoidPair : distsAndIndexes ) {
			Boid &otherBoid = *(allBoids[ otherBoidPair.second ]);
			if ( Boid::getDistance( boid, otherBoid ) < 30 ) {
				deltaV[0] -= ( otherBoid.location.x - boid.location.x ) / 10;
				deltaV[1] -= ( otherBoid.location.y - boid.location.y ) / 10;
			}
		}

		boid.velocity = { boid.velocity[0] + deltaV[0], boid.velocity[1] + deltaV[1] };

	}


}

