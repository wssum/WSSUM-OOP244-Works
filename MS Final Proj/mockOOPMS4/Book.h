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
#ifndef BOOK_H
#define BOOK_H
#include "PublicationB.h"

namespace sdds {

	class Book :public Publication
	{
		char* m_authorName{};
	public:
		Book();
		~Book();
		char Type()const;
		std::ostream& write(std::ostream& os)const;
		operator bool()const;
	};
}

#endif