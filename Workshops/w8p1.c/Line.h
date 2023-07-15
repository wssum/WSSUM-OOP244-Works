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
#ifndef LINE_H
#define LINE_H
#include "LblShape.h"

namespace sdds
{

	class Line:public LblShape
	{
		int m_length;
	public:
		Line();
		Line(const char* string, int length);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os)const;

	};

}
#endif