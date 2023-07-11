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
#include "Streamable.h"
#include "Date.h"

namespace sdds {


	class Publication: public Streamable
	{
		char m_title[255];
		char m_shelfId[4];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication();
		~Publication();
		operator bool()const;
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os)const;
		//virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		//void setRef(int value);
		// Sets the **libRef** attribute value
		//void resetDate();
		// Sets the date to the current date of the system.
		//virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		//bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		//Date checkoutDate()const;
		//Returns the date attribute
		//bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		//operator const char* ()const;
		//Returns the title attribute
		//int getRef()const;
		//Returns the libRef attirbute. 
	};

	std::ostream& operator<<(std::ostream& os, const Streamable& obj);
}
#endif