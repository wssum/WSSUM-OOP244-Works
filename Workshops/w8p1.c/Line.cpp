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
#include <cstring>
#include <cstdio>
#include "Line.h"

using namespace std;

namespace sdds
{
	Line::Line() :LblShape()
	{
		m_length = 0;
	}

	Line::Line(const char* string, int length) :LblShape(string)
	{
		m_length = length;
	}

	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}

	void Line::draw(std::ostream& os)const
	{
		if (m_length > 0)
		{
			if (label() != nullptr)
			{
				os << label() << endl;
				for (int i = 0; i < m_length; i++)
				{
					os << '=';
				}
			}
		}
	}
}