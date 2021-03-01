
#ifndef __BB_UTILS_SCREENSCALE_H
#define __BB_UTILS_SCREENSCALE_H

#include <cstddef> // for NULL

#include "bbmonitor.h"

class ScreenScale {

	public:

		static ScreenScale *getInstance();

		// Argument: 
		// - How many meters is the width of the screen?
		void init( double );

		// gets number of pixels, returns number of meters.
		double getMeters( double ) const;
		// gets number of meters, returns number of pixels.
		double getPixels( double ) const;

		// 1 pixel = *scale* meters
		// For example if scale == 2, then each pixel represents 2 meters.
		double scale;

	private:

		static ScreenScale *instance;

		ScreenScale();

};

#endif 
