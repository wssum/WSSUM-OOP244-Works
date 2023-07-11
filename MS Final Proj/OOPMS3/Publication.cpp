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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctype.h>
#include <ctime>
#include "Utils.h"
#include "Publication.h"
#include "Date.h"

using namespace sdds;
using namespace std;

namespace sdds {
	Publication::operator const char* ()const//untested
	{
		return m_title;
	}
	char Publication::type()const
	{
		return 'P';
	}

	int Publication::getRef()const//Tested good
	{
		return m_libRef;
	}
	void Publication::set(int member_id)//Tested good
	{
		if ((member_id >= 10000) && (member_id <= 99999))
		{
			m_membership = member_id;
		}
		else
		{
			m_membership = 0;
		}
	}
	void Publication::setRef(int value)//Tested good
	{
		m_libRef = value;
	}

	bool Publication::onLoan()const//Tested good
	{
		bool yesORno{};
		if (m_membership > 0)
		{
			yesORno = true;
		}
		else
		{
			yesORno = false;
		}
		return yesORno;
	}

	void Publication::resetDate()//Tested odd its returning the worng date.
	{
		int day = currentDD();
		int mon = currentMM();
		int year = currentYYYY();

		Date* dummy = &m_date;

		dummy = new  Date(year, mon, day);

		delete dummy;

		dummy = nullptr;
	}

	Publication::Publication():m_date(currentYYYY(), currentMM(), currentDD())
	{
		strcpy(m_title, "");
		strcpy(m_shelfId, "");
		set(0);
		setRef(-1);
		//resetDate();
		
		m_date.display();

	}

	Publication::~Publication()
	{
		//delete m_date;
	}

	Publication::operator bool()const//Tested good
	{
		bool yesORno{};
		yesORno = strcmp(m_title, "");
		yesORno = strcmp(m_shelfId, "");

		return yesORno;
	}

	bool Publication::conIO(std::ios& io)const//Tested good
	{
		bool yesORno = false;

		if (&io == &cout)
		{
			yesORno = true;
		}

		if (&io == &cin)
		{
			yesORno = true;
		}
		return yesORno;

	}

	std::istream& Publication:: read(std::istream& is)//Unfinished
	{
		strcpy(m_title, "");
		strcpy(m_shelfId, "");
		resetDate();
		

		if (conIO(is))
		{

		}

		return is;

	}

	std::ostream& Publication:: write(std::ostream& os)const//Tested it doesn't die out atleast
	{
		bool yesORno = conIO(os);

		if (yesORno == true)
		{
			os << m_shelfId << " " << m_title << " " << m_membership << m_date;
		}
		return os;
	}


	std::ostream& operator<<(std::ostream& os, const Streamable& obj)//Tested good
	{
		if (obj)
		{
			obj.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& obj)//Untested
	{
		if (obj)
		{
			obj.read(is);
		}
		return is;
	}
	
}



//Date checkoutDate()const;

//bool operator==(const char* title)const;
