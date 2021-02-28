
#ifndef __BRIDGE_BUILDING_UTILS_BBMONITOR_H
#define __BRIDGE_BUILDING_UTILS_BBMONITOR_H

#include <iostream>
#include <vector>
#include <functional>

#include "SDL2/SDL.h"

#include "../physical_objects/circle.h"
#include "SDLEventType.h"

class BBMonitor {

	public:

		BBMonitor();
		~BBMonitor();

		void draw( std::vector<Object*> & );
		void update();
		void clearScreen();
		SDLEventType handleEvents();

		int getWidth() const;
		int getHeight() const;

	private:

		SDL_Window *window;
		// SDL_Surface *screenSurface;
		SDL_Renderer *renderer;
		SDL_Texture *texture;

};

#endif
