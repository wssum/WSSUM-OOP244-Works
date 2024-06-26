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
#include <cstring>
#include <ctype.h>
#include <ctime>
#include "UtilsB.h"
#include <iomanip>
#include "PublicationB.h"
#include "DateB.h"
#include "LibB.h"

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

		if ((m_membership >= 10000) && (m_membership <= 99999))
		{
			yesORno = true;
		}

		return yesORno;
	}

	void Publication::resetDate()//Tested odd its returning the worng date.
	{
		m_date = Date();
	}

	Publication::Publication() :m_date()
	{
		m_title = new char[255];
		strcpy(m_title, "");
		strcpy(m_shelfId, "");
		set(0);
		setRef(-1);

	}


	bool Publication:: operator==(const char* title)const
	{
		bool yesORno{};

		if (m_title != nullptr)
		{
			if (strstr(m_title, title))
			{
				yesORno = true;
			}
			else
			{
				yesORno = false;
			}
		}		return yesORno;
	}

	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	Publication::~Publication()
	{
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}
	}

	Publication::operator bool()const//Tested good
	{
		bool yesORno{};
		if (m_title == nullptr)
		{
			yesORno = false;
		}
		else
		{
			yesORno = true;
		}
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

	std::istream& Publication::read(std::istream& istr)//Unfinished
	{
		strcpy(m_shelfId, "");
		resetDate();
		char id[100] = " ";
		string title{};

		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr >> id;
			if (strlen(id) > SDDS_SHELF_ID_LEN)
			{
				istr.setstate(std::ios::failbit);
			}
			else
			{
				istr.clear();
				istr.ignore(1000, '\n');
			}
			cout << "Title: ";
			getline(istr, title);
			cout << "Date: ";
			m_date.read(istr);

		}
		else
		{
			istr >> m_libRef;
			istr.ignore();

			istr.get(id, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.ignore();

			getline(istr, title, '\t');


			istr >> m_membership;
			istr.ignore();


			m_date.read(istr);

		}



		if (m_date.errCode() != 0)
		{
			istr.setstate(std::ios::failbit);
		}

		if (istr)
		{
			if (m_title != nullptr)
			{
				delete[] m_title;
				m_title = nullptr;
				m_title = new char[strlen(title.c_str()) + 1];
			}

			strcpy(m_shelfId, id);
			strcpy(m_title, title.c_str());
		}

		return istr;

	}

	std::ostream& Publication::write(std::ostream& os)const//Tested good
	{

		if (conIO(os))
		{
			os << "| " << m_shelfId << " | ";
			if (static_cast<int>(strlen(m_title)) < SDDS_TITLE_WIDTH)
			{
				os << left << setw(SDDS_TITLE_WIDTH) << setfill('.') << m_title;
			}
			else 
			{
				for (int i = 0; i < SDDS_TITLE_WIDTH; i++)
				{
					os << m_title[i];
				}
			}
			
			if ((m_membership >= 10000) && (m_membership <= 99999))
			{
				os << " | " << m_membership << " | " << m_date << " |";
			}
			else
			{
				os << " |" << "  N/A  " << "| " << m_date << " |";
			}

		}
		else
		{
			os << endl << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}
	Publication& Publication:: operator=(const Publication& arg)
	{
		if (this != &arg)
		{
			delete[] m_title;
			m_title = new char[strlen(arg.m_title) + 1];

			strcpy(m_title, arg.m_title);
			strcpy(m_shelfId, arg.m_shelfId);

			m_date = arg.m_date;

			m_membership = arg.m_membership;

			m_libRef = arg.m_libRef;
		}
		return *this;
	}
	Publication::Publication(const Publication& arg)
	{
		m_title = new char[strlen(arg.m_title) + 1];

		strcpy(m_title, arg.m_title);
		strcpy(m_shelfId, arg.m_shelfId);

		m_date = arg.m_date;

		m_membership = arg.m_membership;

		m_libRef = arg.m_libRef;
	}

	void Publication::display()
	{
		cout << m_title << " " << m_shelfId << " " << m_date<<endl;
	}
}