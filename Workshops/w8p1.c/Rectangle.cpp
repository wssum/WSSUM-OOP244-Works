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
#include <iomanip>
#include "Rectangle.h"

using namespace std;

namespace sdds
{
	Rectangle::Rectangle() :LblShape()
	{
		m_height = 0;
		m_width = 0;
	}

	Rectangle::Rectangle(const char* cstr, int width, int height) :LblShape(cstr)
	{

		if (height >= 3)
		{
			m_height = height;
		}
		else
		{
			m_height = 0;
		}

		if (width > (static_cast<int>(strlen(label())) + 2))
		{
			m_width = width;
		}
		else
		{
			m_width = 0;
		}
	}

	void Rectangle::draw(ostream& os)const
	{
		int i = 0;
		if (m_height > 0)
		{
			if (m_width > 0)
			{
				os << '+';
				for (i = 0; i < m_width - 2; i++)
				{
					os << '-';
				}
				os << '+' << endl;

				os << '|';
				os << setw(m_width - 2) << left << label();
				os << '|' << endl;

				for (i = 0; i < m_height - 3; i++)
				{
					os << '|';
					for (int a = 0; a < m_width - 2; a++)
					{
						os << ' ';
					}
					os << '|' << endl;
				}


				os << '+';
				for (i = 0; i < m_width - 2; i++)
				{
					os << '-';
				}
				os << '+';
			}
		}


	}

	void Rectangle::getSpecs(istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(1000, ',');
		is >> m_height;
		is.ignore(1000, '\n');
	}


}