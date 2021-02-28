
#ifndef __BB_UTILS_PHYSICS_H
#define __BB_UTILS_PHYSICS_H

#include <iostream>

#include "../physical_objects/circle.h"

// All physics stuff are handled in this class.
class Physics {

	public:

		const static double g;

		// Arguments:
		// - Object that we want to handle
		// - Width of the screen
		// - Height of the screen
		static void applyPhysics( Object &, int, int );

	private:

		// Arguments:
		// - Object to be handled
		// Output:
		// - Did the object hit the floor?
		static bool applyFloor( Object &, int );

};

#endif
