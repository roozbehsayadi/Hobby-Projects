
#include <iostream>

#include "bb/bridge_building.h"

int main() { 

	BridgeBuilding bb;

	bb.addObject( Circle( 50, 200, 200, {255, 255, 255} ) );
	bb.start();

	return 0;

}
