
#include "flockingMonitor.h"

FlockingMonitor::FlockingMonitor() {}

FlockingMonitor::FlockingMonitor( Flock *flock, int &screenWidth, int &screenHeight ) {

	this->flock = flock;

	SDLHandler::initSDL( SDL_INIT_EVERYTHING );

	screen = SDLHandler::initWindow( "Flocking Boid", screenWidth, screenHeight );

}

FlockingMonitor::~FlockingMonitor() {
	SDL_Quit();
}

