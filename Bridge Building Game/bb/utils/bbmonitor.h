
#ifndef __BRIDGE_BUILDING_UTILS_BBMONITOR_H
#define __BRIDGE_BUILDING_UTILS_BBMONITOR_H

#include <iostream>
#include <vector>

#include "SDL2/SDL.h"

#include "../physical_objects/circle.h"

class BBMonitor {

	public:

		BBMonitor();
		~BBMonitor();

		void draw( const std::vector<Circle> & );
		void update();

	private:

		SDL_Window *window;
		SDL_Surface *screenSurface;
		SDL_Renderer *renderer;
		SDL_Texture *texture;

};

#endif
