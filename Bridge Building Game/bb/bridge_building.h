
#ifndef __BRIDGE_BUILDING_BRIDGE_BUILDING_H
#define __BRIDGE_BUILDING_BRIDGE_BUILDING_H

#include <stdlib.h>
#include <vector>

#include "physical_objects/object.h"
#include "utils/bbmonitor.h"
#include "utils/timers/FPSDelayer.h"
#include "utils/physics.h"
#include "utils/screenScale.h"

// Main class for Bridge Building.
// Usage: Create an instance of class, 
// add objects to it using addObject()
// function, then call start().
class BridgeBuilding {

	public:

		// Arguments:
		// - Scale of the screen. how many meters is the width of the screen?
		BridgeBuilding( double );

		void start();

		void addObject( Object & );

	private:

		std::vector<Object*> objects;
		BBMonitor monitor;
		FPSDelayer delayer;

};

#endif 
