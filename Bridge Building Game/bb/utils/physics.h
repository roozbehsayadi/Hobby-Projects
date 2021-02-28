
#ifndef __BB_UTILS_PHYSICS_H
#define __BB_UTILS_PHYSICS_H

#include <iostream>

#include "../physical_objects/circle.h"

class Physics {

	public:

		const static double g;

		static void applyPhysics( Circle &, int, int );
		static void moveObject( Circle & );

	private:

		static bool applyFloor( Circle &, int );

};

#endif
