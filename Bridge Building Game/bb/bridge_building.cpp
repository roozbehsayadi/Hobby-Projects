
#include "bridge_building.h"

void BridgeBuilding::start() {

	// Main loop of the program.
	while ( 1 ) {
		// This object stores the start time of the loop.
		// It helps us to maintain the FPS of the program.
		delayer.startCounting();

		// See if any events did happen in the program,
		// and handle them if there were any.
		SDLEventType eventType = monitor.handleEvents();
		if ( eventType == SDLEventType::QUIT ) 
			return;

		// Loop through all objects, apply physics to them
		// and move them based on the physical conditions.
		for ( auto &i : objects ) { 
			Physics::applyPhysics( *i, monitor.getWidth(), monitor.getHeight() );
			i->move();
		}

		// Now that all objects have moved to their place,
		// we must clear the screen, draw all the objects on
		// the screen again (in their new positions), and 
		// update the screen after that.
		monitor.clearScreen();
		monitor.draw( objects );
		monitor.update();

		// Remember when we stored the start time of the loop?
		// Here we use that and wait until appropriate amount
		// of time passed.
		delayer.wait();
	}
}

void BridgeBuilding::addObject( Object &object ) {
	objects.push_back( &object );
}
