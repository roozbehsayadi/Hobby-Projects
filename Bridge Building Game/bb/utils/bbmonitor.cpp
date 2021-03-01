
#include "bbmonitor.h"

void BBMonitor::draw( std::vector<Object*> &objects ) {
	SDL_Renderer *temp = renderer;
	std::function<void(int, int)> drawPixel = [temp](int x, int y) { SDL_RenderDrawPoint( temp, x, y ); };
	for ( Object *&i : objects ) {
		const Color colorTemp = i->getColor();
		SDL_SetRenderDrawColor( renderer, colorTemp.getRed(), colorTemp.getGreen(), colorTemp.getBlue(), colorTemp.getAlpha() );
		i->draw( drawPixel );
	}
}

void BBMonitor::update() {
	SDL_RenderPresent( renderer );
}

void BBMonitor::clearScreen() {
	int width, height;
	SDL_GetWindowSize( window, &width, &height );
	SDL_Rect fillRect = {0, 0, width, height};
	SDL_SetRenderDrawColor( renderer, 50, 50, 50, 255 );
	SDL_RenderFillRect( renderer, &fillRect );
}

SDLEventType BBMonitor::handleEvents() {

	SDL_Event event;
	if ( SDL_PollEvent( &event ) ) {
		if ( event.type == SDL_KEYDOWN )
			if ( event.key.keysym.sym == SDLK_q )
				return SDLEventType::QUIT;
		if ( event.type == SDL_QUIT ) 
			return SDLEventType::QUIT;
	}
	return SDLEventType::NONE;

}

int BBMonitor::getWidth() const {
	int returnValue, foo;
	SDL_GetWindowSize( window, &returnValue, &foo );
	return returnValue;
}

int BBMonitor::getHeight() const {
	int returnValue, foo;
	SDL_GetWindowSize( window, &foo, &returnValue );
	return returnValue;
}

std::pair<int, int> BBMonitor::getMonitorSize() {
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode( 0, &dm );
	return std::make_pair( dm.w, dm.h );
}

BBMonitor::BBMonitor() {
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) 
		std::cerr << "SDL Could not be initialized. Error: " << SDL_GetError() << std::endl;
	else {
		window = SDL_CreateWindow( "Bridge Building", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN );
		if ( window == NULL ) 
			std::cerr << "Window could not be created. Error: " << SDL_GetError() << std::endl;
		else {
			// screenSurface = SDL_GetWindowSurface( window );
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
