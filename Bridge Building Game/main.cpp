
#include <iostream>

#include "bb/bridge_building.h"

int main() { 

	BridgeBuilding bb( 1.4 );

	Object *c1 = new Circle( 0.015, 2.6, 0.03, 0.05, {255, 255, 255} );
	Object *c2 = new Circle( 0.01, 2.6, 0.1, 0.1, {255, 128, 128} );
	bb.addObject( *c1 );
	// bb.addObject( *c2 );
	bb.start();

	return 0;

}
