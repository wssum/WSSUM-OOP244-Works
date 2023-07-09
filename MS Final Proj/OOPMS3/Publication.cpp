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
	Publication::Publication()
	{
		strcpy(m_title, "");
		strcpy(m_shelfId, "");
		m_membership = 0;
		m_libRef = -1;

		int yyyy = currentYYYY();
	
		int dd = currentDD();

		int mm = currentMM();

		//m_date = new Date(yyyy, mm, dd);//In case we are allowed to use pointers change your func to this and make m_date a pointer.

		Date* dummyDate = &m_date;

		dummyDate = new Date(yyyy,mm,dd);

		delete dummyDate;

		dummyDate = nullptr;
		//dummy func to display results
		//m_date.display();

	}

}