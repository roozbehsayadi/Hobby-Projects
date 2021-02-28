
#include "bridge_building.h"

void BridgeBuilding::start() {
	while ( 1 ) {
		delayer.startCounting();

		SDLEventType eventType = monitor.handleEvents();
		if ( eventType == SDLEventType::QUIT ) 
			return;

		for ( auto &i : objects ) { 
			Physics::applyPhysics( *i, monitor.getWidth(), monitor.getHeight() );
			i->move();
		}

		monitor.clearScreen();
		monitor.draw( objects );
		monitor.update();

		delayer.wait();
	}
}

void BridgeBuilding::addObject( Object &object ) {
	objects.push_back( &object );
}
