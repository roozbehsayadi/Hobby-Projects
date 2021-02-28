
#ifndef __BRIDGE_BUILDING_CIRCLE_H
#define __BRIDGE_BUILDING_CIRCLE_H

#include <iostream>
#include <utility>
#include <functional>
#include <math.h>

#include "../utils/color.h"
#include "object.h"

class Physics;

// Class for circle Derived from Object.
class Circle : public Object {

	public:

		// Arguments:
		// - radius
		// - density
		// - x of center
		// - y of center
		// - color (default = black)
		Circle( double, double, double, double, const Color & = {0, 0, 0} );

		// Move the object based on the velocity.
		virtual void move() override;
		// Draw the object on the screen.
		// Arguments:
		// - A function with no return value and two int inputs. This function must draw a point on some screen (but we don't care for that here. Isn't it beautiful?).
		virtual void draw( std::function<void(int, int)> & ) override;

		// Getter for radius of the circle.
		double getRadius() const;
		// Getter for cordinates of the circle's center.
		const std::pair<double, double> &getCenter() const;

		// Setter for radius of the circle.
		bool setRadius( double );
		// Setter for cordinates of the circle's center.
		bool setCenter( const std::pair<double, double> & );

	private:

		double radius;
		std::pair<double, double> center;

		virtual double getArea() const override;
		virtual double getMass() const override;

};

#endif
