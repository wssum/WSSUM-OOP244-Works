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
#include <string>
#include <ctype.h>
#include <ctime>
#include "Utils.h"
#include <iomanip>
#include "Publication.h"
#include "Date.h"
#include "Lib.h"

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

		m_date = Date(year, mon, day);
	}

	Publication::Publication():m_date(currentYYYY(), currentMM(), currentDD())
	{
		strcpy(m_title, "");
		strcpy(m_shelfId, "");
		set(0);
		setRef(-1);
		resetDate();
	}

	/*
	bool Publication:: operator==(const char* title)const
	{

	}
	*/

	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	Publication::~Publication()
	{
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
		bool yesORno{};

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

	std::istream& Publication:: read(std::istream& istr)//Unfinished
	{
		strcpy(m_title, "");
		strcpy(m_shelfId, "");
		resetDate();
		char id[100] = " ";
		string title{};
		bool test{};
		
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr >> id;
			istr.clear();
			istr.ignore(1000, '\n');
			cout << "Title: ";
			getline(istr, title);
			cout << "Date: ";
			m_date.read(istr);
		}
		else
		{

			cout << "Shelf No: ";
			istr >> id;
			istr.clear();
			istr.ignore(1000, '\n');
			cout << "Title: ";
			getline(istr, title);
			cout << "Date: ";
			m_date.read(istr);
		}

		if (strlen(id) > SDDS_SHELF_ID_LEN)
		{
			istr.setstate(std::ios::failbit);
		}

		if (m_date.errCode() != 0)
		{
			istr.setstate(std::ios::failbit);
		}

		if (istr)
		{
			strcpy(m_shelfId, id);
			strcpy(m_title, title.c_str());//
		}

		return istr;

	}

	std::ostream& Publication:: write(std::ostream& os)const//Tested good
	{

		if (conIO(os))
		{
			os << "1234567890123456789012345678901234567890123456789012345678901234567890" << endl;
			os << "| " << m_shelfId << " | ";
			os << left << setw(SDDS_TITLE_WIDTH)<< setfill('.') << m_title;
			if ((m_membership >= 10000) && (m_membership <= 99999))
			{
				os << " | " << m_membership << " | " << m_date << " |"<< endl;
			}
			else
			{
				os << " |" << "  N/A  " << "| " << m_date << " |" << endl;
			}
			
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
			obj.read(is);
		
		return is;
	}
	
}


//bool operator==(const char* title)const;
