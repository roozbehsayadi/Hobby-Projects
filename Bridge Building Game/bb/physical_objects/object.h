
#ifndef __BB_PHYSICAL_OBJECTS_OBJECT_H
#define __BB_PHYSICAL_OBJECTS_OBJECT_H

#include <utility>
#include <vector>
#include <functional>

#include "../utils/color.h"

// Parent class for all objects on the screen.
class Object {

	public:

		// Arguments:
		// - density
		// - color of the object
		Object( double, const Color & );

		// Move the object based on velocity.
		virtual void move( double , int ) = 0;
		// Draw the object on the screen.
		virtual void draw( std::function<void(int, int)> & ) = 0;

		// Getter for density.
		double getDensity() const;
		// Getter for velocity vector.
		const std::pair<double, double> &getVelocity() const;
		// Getter for x velocity.
		double getVelocityX() const;
		// Getter for y velocity.
		double getVelocityY() const;
		// Getter for acceleration vector.
		const std::pair<double, double> &getAcceleration() const;
		// Getter for x acceleration.
		double getAccelerationX() const;
		// Getter for y acceleration.
		double getAccelerationY() const;
		// Getter for color of the object.
		const Color &getColor() const;

		// Setter for density.
		bool setDensity( double );
		// Setter for velocity vector.
		bool setVelocity( const std::pair<double, double> & );
		// Setter for x velocity.
		bool setVelocityX( double );
		// Setter for y velocity.
		bool setVelocityY( double );
		// Setter for acceleration vector.
		bool setAcceleration( const std::pair<double, double> & );
		// Setter for x acceleration.
		bool setAccelerationX( double );
		// Setter for y acceleration.
		bool setAcceleratoinY( double );
		// Setter for color of the object.
		bool setColor( const Color & );

	private:

		double density;
		std::pair<double, double> v;
		std::pair<double, double> a;

		Color color;

		virtual double getArea() const = 0;
		virtual double getMass() const = 0;

	friend class Physics;

};

#endif 
