
#ifndef __UTILS_POINT_H
#define __UTILS_POINT_H

class Flock;
class Boid;

class Point {

	private:

		double x, y;

	public:

		Point();
		Point( double, double );

		double getX() const;
		double getY() const; 

		void setX( double );
		void setY( double );
	
	friend class Flock;
	friend class Boid;

};

#endif

