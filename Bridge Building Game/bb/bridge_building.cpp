
#include "bridge_building.h"

void BridgeBuilding::start() {
	while ( 1 ) {
		delayer.startCounting();

		SDLEventType eventType = monitor.handleEvents();
		if ( eventType == SDLEventType::QUIT ) 
			return;

		monitor.draw( objects );
		monitor.update();

		objects[0].setColor( rand() % 256 );
		delayer.wait();
	}
}

void BridgeBuilding::addObject( const Circle &circle ) {
	objects.push_back( circle );
}
