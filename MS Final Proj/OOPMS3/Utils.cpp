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
#include <ctime>
#include "Utils.h"

namespace sdds {
	int daysInMonth(int yyyy, int mm)
	{
		int days = 0;//This days variable will be used to represent how many days are leading to the month and will be returned. 

		/*This super long list of if statements is to determine how many days are leading into the month determined by the mm parameter.
		Using multiple if statements over else if statements will prevent confusion to the compiler*/
		if (mm == 1)
		{
			days = 31;
		}

		if (mm == 2)
		{
			days = 31;
		}

		if (mm == 3)
		{
			days = 59;
		}

		if (mm == 4)
		{
			days = 90;
		}

		if (mm == 5)
		{
			days = 120;
		}

		if (mm == 6)
		{
			days = 151;
		}

		if (mm == 7)
		{
			days = 181;
		}

		if (mm == 8)
		{
			days = 212;
		}

		if (mm == 9)
		{
			days = 243;
		}

		if (mm == 10)
		{
			days = 273;
		}

		if (mm == 11)
		{
			days = 304;
		}

		if (mm == 12)
		{
			days = 334;
		}

		if ((yyyy % 4) == 0)
		{
			if ((yyyy % 100) != 0)
			{
				if ((mm >= 3) && (mm <= 12))
				{
					days = days + 1;
				}
			}
		}
		else if ((yyyy % 400) == 0)
		{
			days = days + 1;
		}
		return days;
	}


	int currentYYYY()
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		int year = lt.tm_year + 1900;

		return year;
	}

	int currentDD()
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		int day = lt.tm_mday;

		return day;
	}

	int currentMM()
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		int month = lt.tm_mon + 1;

		return month;
	}
}