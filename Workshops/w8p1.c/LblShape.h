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
#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"

namespace sdds
{
	class LblShape :public Shape
	{
		char* m_label{};
	protected:
		char* label()const;
	public:
		LblShape(const LblShape&) = delete;
		LblShape operator = (const LblShape&) = delete;
		LblShape();
		LblShape(const char* string);
		~LblShape();
		void getSpecs(std::istream& is);
	};


}
#endif