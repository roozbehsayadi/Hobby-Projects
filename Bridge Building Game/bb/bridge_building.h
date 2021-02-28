
#ifndef __BRIDGE_BUILDING_BRIDGE_BUILDING_H
#define __BRIDGE_BUILDING_BRIDGE_BUILDING_H

#include <vector>

#include "physical_objects/circle.h"
#include "utils/bbmonitor.h"

class BridgeBuilding {

	public:

		void start();

		void addObject( const Circle &circle );

	private:

		std::vector<Circle> objects;
		BBMonitor monitor;

};

#endif 
