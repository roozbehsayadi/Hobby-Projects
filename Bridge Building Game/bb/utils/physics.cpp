
#include "physics.h"

const double Physics::g = 4.9;

void Physics::applyPhysics( std::vector<Object*> &objects, int screenWidth, int screenHeight ) {
	static Timer timer;
	double timeTemp = timer.passedTime().count();
	for ( auto &i : objects ) {
		Circle *c = (Circle*) i;
		double Fy = 0;
		Fy = c->getMass() * Physics::g;
		double ay = Fy / c->getMass();
		c->setAcceleratoinY( ay );
		i->move( timeTemp, screenHeight );
		c->setVelocityY( c->getVelocityY() + c->getAccelerationY() * timeTemp );
	}
	timer.startCounting();
}
