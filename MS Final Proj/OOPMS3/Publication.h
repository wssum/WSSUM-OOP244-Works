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
#ifndef PUBLICATION_H
#define PUBLICATION_H

#include "Date.h"
//Still need to implement 3 funcs
namespace sdds {

	class Streamable
	{
	public:
		virtual operator bool()const = 0;
		virtual bool conIO(std::ios& io)const = 0;
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~Streamable()
		{}
	};

	class Publication: public Streamable
	{
		char m_title[255];
		char m_shelfId[4 + 1];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		//bool operator==(const char* title)const;
		Date checkoutDate()const;
		virtual char type()const;
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		bool onLoan()const;
		int getRef()const;
		operator const char* ()const;
		Publication();
		~Publication();
		operator bool()const;
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);

	};

	std::ostream& operator<<(std::ostream& os, const Streamable& obj);
	std::istream& operator>>(std::istream& is, Streamable& obj);
}
#endif

//bool operator==(const char* title)const;
//Returns true if the argument title appears anywhere in the title of the 
//publication. Otherwise, it returns false; (use strstr() function in <cstring>)

