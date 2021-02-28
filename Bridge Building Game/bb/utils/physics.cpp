
#include "physics.h"

const double Physics::g = 1.0;

void Physics::applyPhysics( Object &circle, int screenWidth, int screenHeight ) {
	if ( !Physics::applyFloor( circle, screenHeight ) ) {
		double Fy = 0;
		Fy = -1 * circle.getMass() * Physics::g;
		double ay = Fy / circle.getMass();
		circle.setVelocityY( circle.getVelocityY() - ay );
	}
}

bool Physics::applyFloor( Object &object, int screenHeight ) {
	Circle *c = (Circle*) &object;
	if ( c->getCenter().second + c->getRadius() + c->getVelocityY() >= screenHeight ) {
		if ( fabs( object.getVelocityY() ) < 2.0 )
			object.setVelocityY( 0.0 );
		c->setCenter( std::make_pair( c->getCenter().first, screenHeight - c->getRadius() ) );
		c->setVelocityY( -1 * object.getVelocityY() * 0.95 );
		return true;
	}
	return false;
}
