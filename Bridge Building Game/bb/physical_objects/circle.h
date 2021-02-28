
#ifndef __BRIDGE_BUILDING_CIRCLE_H
#define __BRIDGE_BUILDING_CIRCLE_H

#include <utility>
#include <math.h>

#include "../utils/color.h"

class Circle {

	public:

		Circle( double, double, double, const Color & = {0, 0, 0} );

		double getDensity() const;
		double getRadius() const;
		const std::pair<double, double> &getCenter() const;
		const Color &getColor() const;

		bool setDensity( double );
		bool setRadius( double );
		bool setCenter( const std::pair<double, double> & );
		bool setColor( const Color & );

	private:

		double density;
		double radius;
		std::pair<double, double> center;
		Color color;

		double getArea() const;
		double getMass() const;

};

#endif
