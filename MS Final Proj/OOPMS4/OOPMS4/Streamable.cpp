/*/////////////////////////////////////////////////////////////////////////

Workshop - #MS3

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

/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Streamable.h"

namespace sdds
{

	std::ostream& operator<<(std::ostream& os, const Streamable& obj)
	{
		if (obj)
		{
			obj.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& obj)
	{
		obj.read(is);

		return is;
	}

	Streamable::~Streamable()
	{

	}
}