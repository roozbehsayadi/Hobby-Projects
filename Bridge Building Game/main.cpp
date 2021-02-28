
#include <iostream>

#include "bb/bridge_building.h"

int main() { 

	BridgeBuilding bb;

	Object *c1 = new Circle( 50, 2.6, 200, 200, {255, 255, 255} );
	Object *c2 = new Circle( 25, 2.6, 500, 300, {255, 128, 128} );
	bb.addObject( *c1 );
	bb.addObject( *c2 );
	// bb.addObject( Circle( 50, 200, 200, {255, 255, 255} ) );
	// bb.addObject( Circle( 25, 500, 300, {255, 128, 128} ) );
	bb.start();

	return 0;

}
