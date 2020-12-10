
#ifndef __POINT_H
#define __POINT_H

class Point {

	private:

		int x, y;

	public:

		Point();
		Point( int, int );

		int getX() const;
		int getY() const; 

		void setX( int );
		void setY( int );

};

#endif

