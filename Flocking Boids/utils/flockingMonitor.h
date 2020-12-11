
#ifndef __UTILS_FLOCKING_MONITOR_H
#define __UTILS_FLOCKING_MONITOR_H

#include "SDL/SDL.h"

#include "SDLHandler.h"

class FlockingMonitor {

	private: 

		SDL_Surface *screen;

	public:

		// Does nothing
		FlockingMonitor();
		// Starts the SDL stuff.
		// Pass -1 as the first argument to get a fullscreen window.
		FlockingMonitor( int, int );

		// Closes the SDL stuff.
		~FlockingMonitor();

};

#endif

