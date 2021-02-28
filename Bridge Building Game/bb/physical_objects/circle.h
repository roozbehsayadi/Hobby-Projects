
#ifndef __BRIDGE_BUILDING_CIRCLE_H
#define __BRIDGE_BUILDING_CIRCLE_H

#include <iostream>
#include <utility>
#include <functional>
#include <math.h>

#include "../utils/color.h"
#include "object.h"

class Physics;

class Circle : public Object {

	public:

		Circle( double, double, double, double, const Color & = {0, 0, 0} );

		virtual void move() override;
		virtual void draw( std::function<void(int, int)> & ) override;

		double getRadius() const;
		const std::pair<double, double> &getCenter() const;

		bool setRadius( double );
		bool setCenter( const std::pair<double, double> & );

	private:

		double radius;
		std::pair<double, double> center;

		virtual double getArea() const override;
		virtual double getMass() const override;

};

#endif
