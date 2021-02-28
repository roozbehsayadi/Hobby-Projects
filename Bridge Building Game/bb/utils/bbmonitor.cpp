
#include "bbmonitor.h"

void BBMonitor::draw( const std::vector<Circle> &objects ) {
	for ( Circle i : objects ) {
		const Color colorTemp = i.getColor();
		SDL_SetRenderDrawColor( renderer, colorTemp.getRed(), colorTemp.getGreen(), colorTemp.getBlue(), colorTemp.getAlpha() );
		for ( int c1 = i.getCenter().first - i.getRadius(); c1 <= i.getCenter().first + i.getRadius(); c1++ )
			for ( int c2 = i.getCenter().second - i.getRadius(); c2 <= i.getCenter().second + i.getRadius(); c2++ ) {
				if ( pow( c1 - i.getCenter().first, 2) + pow( c2 - i.getCenter().second, 2 ) < pow( i.getRadius(), 2 ) )
				SDL_RenderDrawPoint( renderer, c1, c2 );
			}
	}
}

void BBMonitor::update() {
	SDL_RenderPresent( renderer );
}

BBMonitor::BBMonitor() {
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) 
		std::cerr << "SDL Could not be initialized. Error: " << SDL_GetError() << std::endl;
	else {
		window = SDL_CreateWindow( "Bridge Building", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN );
		if ( window == NULL ) 
			std::cerr << "Window could not be created. Error: " << SDL_GetError() << std::endl;
		else {
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if ( renderer == NULL ) 
				std::cerr << "Renderer could not be initialized. Error: " << SDL_GetError() << std::endl;
		}
	}
}

BBMonitor::~BBMonitor() {
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}
