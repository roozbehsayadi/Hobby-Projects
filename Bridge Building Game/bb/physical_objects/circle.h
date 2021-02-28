
#ifndef __BRIDGE_BUILDING_CIRCLE_H
#define __BRIDGE_BUILDING_CIRCLE_H

#include <utility>
#include <math.h>

#include "../utils/color.h"

class Physics;

class Circle {

	public:

		Circle( double, double, double, const Color & = {0, 0, 0} );

		double getDensity() const;
		double getRadius() const;
		const std::pair<double, double> &getCenter() const;
		const std::pair<double, double> &getVelocity() const;
		double getVelocityX() const;
		double getVelocityY() const;
		const Color &getColor() const;

		bool setDensity( double );
		bool setRadius( double );
		bool setCenter( const std::pair<double, double> & );
		bool setVelocity( const std::pair<double, double> & );
		bool setVelocityX( double );
		bool setVelocityY( double );
		bool setColor( const Color & );

	private:

		double density;
		double radius;
		std::pair<double, double> center;
		std::pair<double, double> v;
		Color color;

		double getArea() const;
		double getMass() const;
	
	friend class Physics;

};

#endif
