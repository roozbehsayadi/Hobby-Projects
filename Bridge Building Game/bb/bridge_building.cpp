
#include "bridge_building.h"

void BridgeBuilding::start() {
	while ( 1 ) {
		monitor.draw( objects );
		monitor.update();
	}
}

void BridgeBuilding::addObject( const Circle &circle ) {
	objects.push_back( circle );
}
