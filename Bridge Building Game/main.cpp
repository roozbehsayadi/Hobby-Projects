
#include <iostream>

#include "bb/bridge_building.h"

int main() { 

	BridgeBuilding bb;

	bb.addObject( Circle( 50, 200, 200, {255, 255, 255} ) );
	bb.addObject( Circle( 25, 500, 300, {255, 128, 128} ) );
	bb.start();

	return 0;

}
