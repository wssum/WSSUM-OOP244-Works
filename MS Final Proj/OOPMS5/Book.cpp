/*/////////////////////////////////////////////////////////////////////////

Workshop - #MS5

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
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Lib.h"

using namespace std;

namespace sdds {
	Book::Book()
	{
		m_authorName = new char[255];
		strcpy(m_authorName, "");
	}

	Book:: ~Book()
	{
		delete[] m_authorName;
	}

	Book::operator bool()const
	{
		bool yesOrNo{};

		if (Publication::operator bool())
		{
			if (m_authorName != nullptr)
			{
				yesOrNo = true;
			}
		}

		return yesOrNo;
	}

	char Book::type()const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os)const
	{
		Publication::write(os);

		if (conIO(os))
		{
			if (static_cast<int>(strlen(m_authorName)) == SDDS_AUTHOR_WIDTH)
			{
				os << " ";
				os << m_authorName;
				os << " |";
			}
			else if (static_cast<int>(strlen(m_authorName)) > SDDS_AUTHOR_WIDTH)
			{
				os << " ";
				for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
				{
					os << m_authorName[i];
				}
				os << " |";
			}
			else
			{
				os << " ";
				os << left << setw(SDDS_AUTHOR_WIDTH) << setfill(' ') << m_authorName;
				os << " |";
			}

		}
		else
		{
			os << "\t" << m_authorName;

		}

		return os;
	}


	std::istream& Book::read(std::istream& istr)
	{
		char author[256];


		Publication::read(istr);

		if (m_authorName != nullptr)
		{
			delete[] m_authorName;
			m_authorName = nullptr;
		}

		if (conIO(istr))
		{
			cout << "Author: ";
			if (istr)
			{
				istr.ignore(1, '\n');
				istr.get(author, 256);

			}
		}
		else
		{
			istr.clear();
			istr.ignore(1, '\t');
			istr.get(author, 256);
		}

		if (istr)
		{
			m_authorName = new char[strlen(author) + 1];
			strcpy(m_authorName, author);
		}
		else
		{
			istr.setstate(std::ios::failbit);
		}

		return istr;
	}

	Book::Book(const Book& arg) :Publication(arg)
	{
		m_authorName = new char[strlen(arg.m_authorName) + 1];

		strcpy(m_authorName, arg.m_authorName);
	}

	Book& Book::operator=(const Book& arg)
	{
		if (this != &arg)
		{
			Publication::operator=(arg);
			if (arg.m_authorName != nullptr)
			{
				if (this->m_authorName != NULL)
				{
					delete[] this->m_authorName;
					this->m_authorName = nullptr;
				}
				this->m_authorName = new char[strlen(arg.m_authorName) + 1];

				strcpy(this->m_authorName, arg.m_authorName);
			}
		}

		return *this;
	}

	void Book::set(int id)
	{
		Publication::set(id);
		Publication::resetDate();
	}

	void Book::displayAuthorName()
	{
		cout << m_authorName << endl;
	}

}