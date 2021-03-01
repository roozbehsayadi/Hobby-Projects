
#ifndef __BRIDGE_BUILDING_UTILS_BBMONITOR_H
#define __BRIDGE_BUILDING_UTILS_BBMONITOR_H

#include <iostream>
#include <vector>
#include <functional>

#include "SDL2/SDL.h"

#include "../physical_objects/circle.h"
#include "SDLEventType.h"

// Monitor for Bridge Building.
class BBMonitor {

	public:

		// Initializes SDL stuff.
		BBMonitor();
		// Closes SDL stuff.
		~BBMonitor();

		// Gets a vector of objects, and draws them on the screen.
		void draw( std::vector<Object*> & );
		// Updates the screen.
		void update();
		// Fills the background with background color.
		void clearScreen();
		// Checks if any event happened, and returns the type of event.
		SDLEventType handleEvents();

		// Returns the width of the screen.
		int getWidth() const;
		// Returns the height of the screen.
		int getHeight() const;

		// returns width and height of the monitor.
		static std::pair<int, int> getMonitorSize();

	private:

		SDL_Window *window;
		// SDL_Surface *screenSurface;
		SDL_Renderer *renderer;
		SDL_Texture *texture;

};

#endif
