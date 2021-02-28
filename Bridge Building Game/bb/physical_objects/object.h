
#ifndef __BB_PHYSICAL_OBJECTS_OBJECT_H
#define __BB_PHYSICAL_OBJECTS_OBJECT_H

#include <utility>
#include <vector>
#include <functional>

#include "../utils/color.h"

class Object {

	public:

		Object( double, const Color & );

		virtual void move() = 0;
		virtual void draw( std::function<void(int, int)> & ) = 0;

		double getDensity() const;
		const std::pair<double, double> &getVelocity() const;
		double getVelocityX() const;
		double getVelocityY() const;
		const Color &getColor() const;

		bool setDensity( double );
		bool setVelocity( const std::pair<double, double> & );
		bool setVelocityX( double );
		bool setVelocityY( double );
		bool setColor( const Color & );

	private:

		double density;
		std::pair<double, double> v;

		Color color;

		virtual double getArea() const = 0;
		virtual double getMass() const = 0;

	friend class Physics;

};

#endif 
