
#include "physics.h"

const double Physics::g = 0.5;

void Physics::applyPhysics( std::vector<Object*> &objects, int screenWidth, int screenHeight ) {
	static Timer timer;
	for ( auto &i : objects ) {
		Circle *c = (Circle*) i;
		if ( !Physics::applyFloor( *i, screenHeight ) ) {
			bool b = ( fabs( c->getVelocityY() ) < Physics::g ) && ( c->getCenter().second + c->getRadius() + fabs( c->getVelocityY() ) + 10 >= screenHeight );
			if ( b ) {
				c->setVelocityY( 0.0 );
				return;
			}
			double Fy = 0;
			Fy = -1 * c->getMass() * Physics::g;
			double ay = Fy / c->getMass();
			c->setAcceleratoinY( -1 * ay );
		}
		double timeTemp = timer.passedTime().count();
		i->move( timeTemp );
		c->setVelocityY( c->getVelocityY() + c->getAccelerationY() * timeTemp );
	}
	timer.startCounting();
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
