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
#ifndef SHAPE_H
#define SHAPE_H


namespace sdds
{
	class Shape
	{
	public:
		virtual void draw(std::ostream& os)const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape();
	};
	std::ostream& operator<<(std::ostream& os, const Shape& shp);
	std::istream& operator>>(std::istream& is, Shape& shp);
}
#endif