
#include "physics.h"

const double Physics::g = 1.0;

void Physics::applyPhysics( Circle &circle, int screenWidth, int screenHeight ) {
	if ( !Physics::applyFloor( circle, screenHeight ) ) {
		double Fy = 0;
		Fy = -1 * circle.getMass() * Physics::g;
		double ay = Fy / circle.getMass();
		circle.setVelocityY( circle.getVelocityY() - ay );
	}
}

bool Physics::applyFloor( Circle &circle, int screenHeight ) {
	if ( circle.getCenter().second + circle.getRadius() + circle.getVelocityY() >= screenHeight ) {
		circle.setCenter( std::make_pair( circle.getCenter().first, screenHeight - circle.getRadius() ) );
		circle.setVelocityY( -1 * circle.getVelocityY() * 0.95 );
		return true;
	}
	return false;
}

void Physics::moveObject( Circle &circle ) {
	auto temp = circle.getCenter();
	circle.setCenter( std::make_pair( temp.first + circle.getVelocityX(), temp.second + circle.getVelocityY() ) );
}
