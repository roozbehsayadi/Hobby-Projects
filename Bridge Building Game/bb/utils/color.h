
#ifndef __BRIDGE_BUILDING_UTILS_COLOR_H
#define __BRIDGE_BUILDING_UTILS_COLOR_H

// A class to represent colors. It has four attributes: RGBA.
class Color {

	public:

		// Sets the color to black
		Color();
		// Sets the color to a gray where all three channels of the color are the input number.
		Color( unsigned char );
		// Sets the color to the inputs obviously.
		Color( unsigned char, unsigned char, unsigned char, unsigned char = 255 );

		// Sets the color to a gray where all three channels of the color are the input number.
		void setColor( unsigned char );
		// Sets the color to the inputs obviously.
		void setColor( unsigned char, unsigned char, unsigned char, unsigned char = 255 );

		// Get red channel.
		unsigned char getRed() const;
		// Get green channel.
		unsigned char getGreen() const;
		// Get blue channel.
		unsigned char getBlue() const;
		// Get alpha (transparency).
		unsigned char getAlpha() const;

	private:

		unsigned char r, g, b, alpha;

};

#endif 