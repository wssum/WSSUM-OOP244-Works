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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include "Shape.h"

using namespace std;

namespace sdds
{
	Shape:: ~Shape()
	{

	}

	ostream& operator<<(ostream& os, const Shape& shp)
	{
		shp.draw(os);

		return os;
	}
    
	istream& operator>>(istream& is, Shape& shp)
	{
		shp.getSpecs(is);

		return is;
	}

}