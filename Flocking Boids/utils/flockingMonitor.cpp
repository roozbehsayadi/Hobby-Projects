
#include "flockingMonitor.h"

FlockingMonitor::FlockingMonitor() {}

FlockingMonitor::FlockingMonitor( int screenWidth, int screenHeight ) {

	SDLHandler::initSDL( SDL_INIT_EVERYTHING );

	screen = SDLHandler::initWindow( "Flocking Boid", screenWidth, screenHeight );

}

FlockingMonitor::~FlockingMonitor() {
	SDL_Quit();
}

