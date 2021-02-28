
#ifndef __BB_UTILS_PHYSICS_H
#define __BB_UTILS_PHYSICS_H

#include <iostream>

#include "../physical_objects/circle.h"

class Physics {

	public:

		const static double g;

		static void applyPhysics( Object &, int, int );
		// static void moveObject( Object & );

	private:

		static bool applyFloor( Object &, int );

};

#endif
