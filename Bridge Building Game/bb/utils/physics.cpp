
#include "physics.h"

const double Physics::g = 5.0;

void Physics::applyPhysics( Object &circle, int screenWidth, int screenHeight ) {
	if ( !Physics::applyFloor( circle, screenHeight ) ) {
		Circle *c = (Circle*) &circle;
		bool b = ( fabs( c->getVelocityY() ) < Physics::g ) && ( c->getCenter().second + c->getRadius() + fabs( c->getVelocityY() ) + 10 >= screenHeight );
		if ( b ) {
			c->setVelocityY( 0.0 );
			return;
		}
		double Fy = 0;
		Fy = -1 * circle.getMass() * Physics::g;
		double ay = Fy / circle.getMass();
		circle.setVelocityY( circle.getVelocityY() - ay );
	}
}

bool Physics::applyFloor( Object &object, int screenHeight ) {
	Circle *c = (Circle*) &object;
	bool b = c->getCenter().second + c->getRadius() + c->getVelocityY() >= screenHeight;
	if ( b ) {
		c->setCenter( std::make_pair( c->getCenter().first, screenHeight - c->getRadius() ) );
		if ( fabs( object.getVelocityY() ) < Physics::g * 2 )
			c->setVelocityY( 0.0 );
		c->setVelocityY( -1 * object.getVelocityY() * 0.95 );
		return true;
	}
	return false;
}
