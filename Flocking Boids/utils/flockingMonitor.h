
#ifndef __UTILS_FLOCKING_MONITOR_H
#define __UTILS_FLOCKING_MONITOR_H

#include "SDL/SDL.h"

#include "flock.h"
#include "SDLHandler.h"
#include "SDLEventType.h"

class FlockingMonitor {

	private: 

		SDL_Surface *screen;
		Flock *flock;

	public:

		// Does nothing
		FlockingMonitor();
		// Starts the SDL stuff.
		// Pass -1 as the first argument to get a fullscreen window.
		FlockingMonitor( Flock *, int &, int & );

		// Closes the SDL stuff.
		~FlockingMonitor();

		SDLEventType handleEvents();
		void drawBoids();
		void updateScreen();

};

#endif

