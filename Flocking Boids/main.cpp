
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "flockingBoids.h"

Color colors[] = { {255, 0, 0 }, {255, 255, 0}, {0, 255, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255} };

int main ( int argc, char **argv ) {

	if ( argc != 3 ) {
		std::cout << "Usage:\n./Flocking Number_of_Flocks Total_Number_of_Boids" << std::endl;
		return 1;
	}

	int flocksCount = atoi( argv[1] );
	int totalBoidsCount = atoi( argv[2] );

	if ( flocksCount <= 0 ) {
		std::cout << "Number of flocks shoud be more that zero\nOr maybe you entered a string instead of a number...?" << std::endl;
		return 1;
	}

	if ( totalBoidsCount <= 0 ) {
		std::cout << "Total number of boids shoud be more that zero\nOr maybe you entered a string instead of a number...?" << std::endl;
		return 1;
	}

	if ( flocksCount > 6 ) {
		std::cout << "Sorry, we only have 6 colors available for now. :)\n" << std::endl;
		return 1;
	}

	srand( time( nullptr ) );

	FlockingBoids flockingBoids( 1280, 720 );
	for ( int i = 0; i < flocksCount; i++ )
		flockingBoids.addFlock( totalBoidsCount / flocksCount, colors[ i ] );
	flockingBoids.start();

	return 0;

}

