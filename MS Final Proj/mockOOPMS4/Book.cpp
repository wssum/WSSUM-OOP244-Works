/*/////////////////////////////////////////////////////////////////////////

Workshop - #MS4

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
#include <iomanip>
#include "Book.h"
#include "LibB.h"

using namespace std;

namespace sdds {
	Book::Book()
	{

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

	char Book::Type()const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os)const
	{
		Publication::write(os);

		if (conIO(os))
		{
			os << ' ';
			os << setw(SDDS_AUTHOR_WIDTH) << m_authorName;
			os << " |";
		}
		else
		{

			os << "\t" << m_authorName;


		}

		return os;
	}

	void Book::displayAuthorName()
	{
		cout << m_authorName << endl;
	}

	std::istream& Book::read(std::istream& istr)
	{
		string author{};
		bool passed{};
		if (Publication::read(istr))
		{
			passed = true;
			istr.clear();
			istr.ignore(1, '\n');
		}
		
		

		if (!m_authorName)
		{
			delete[] m_authorName;
			m_authorName = nullptr;
		}	

		if (conIO(istr))
		{
			cout << "Author: ";
			if (passed)
			{
				getline(istr, author);
			}		
		}
		else
		{
			istr.ignore('\t');
			getline(istr, author);
		}

		if ((passed == true)&& istr)
		{
			m_authorName = new char[strlen(author.c_str()) + 1];//This part for some odd reason is not copying the authors name correctly.
			strcpy(m_authorName, author.c_str());
		}
		else
		{
			istr.setstate(std::ios::failbit);
		}
		
		return istr;
	}

	Book::Book(const Book& arg):Publication(arg)
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

	
}