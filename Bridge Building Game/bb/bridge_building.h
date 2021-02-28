
#ifndef __BRIDGE_BUILDING_BRIDGE_BUILDING_H
#define __BRIDGE_BUILDING_BRIDGE_BUILDING_H

#include <stdlib.h>
#include <vector>

#include "physical_objects/object.h"
#include "utils/bbmonitor.h"
#include "utils/FPSDelayer.h"
#include "utils/physics.h"

class BridgeBuilding {

	public:

		void start();

		void addObject( Object & );

	private:

		std::vector<Object*> objects;
		BBMonitor monitor;
		FPSDelayer delayer;

};

#endif 
