
#ifndef __BRIDGE_BUILDING_UTILS_COLOR_H
#define __BRIDGE_BUILDING_UTILS_COLOR_H

class Color {

	public:

		Color();
		Color( unsigned char );
		Color( unsigned char, unsigned char, unsigned char, unsigned char = 255 );

		void setColor( unsigned char );
		void setColor( unsigned char, unsigned char, unsigned char, unsigned char = 255 );

		unsigned char getRed() const;
		unsigned char getGreen() const;
		unsigned char getBlue() const;
		unsigned char getAlpha() const;

	private:

		unsigned char r, g, b, alpha;

};

#endif 