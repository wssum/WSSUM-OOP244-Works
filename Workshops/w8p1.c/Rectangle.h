/*/////////////////////////////////////////////////////////////////////////

Workshop - #8 (P1)

Full Name :Wilson Sum

Student ID#:017142142

Email :wssum@myseneca.ca

Section :OOP244NAA

Section :OOP244NAA

Authenticity Declaration:

I declare this submission is the result of my own work and has not been

shared with any other student or 3rd party content provider. This submitted

piece of work is entirely of my own creation.

/////////////////////////////////////////////////////////////////////////*/

#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"

namespace sdds
{
	class Rectangle:public LblShape
	{
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* string,int width, int height);
		void draw(std::ostream& os)const;
		void getSpecs(std::istream& is);

	};

}
#endif