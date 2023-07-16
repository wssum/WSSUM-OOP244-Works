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
#include <iostream>


namespace sdds {
	
		class Streamable
		{
		public:
			virtual operator bool()const = 0;
			virtual bool conIO(std::ios& io)const = 0;
			virtual std::ostream& write(std::ostream& os)const = 0;
			virtual std::istream& read(std::istream& os) = 0;
			virtual ~Streamable();
		};
		std::ostream& operator<<(std::ostream& os, const Streamable& obj);


		std::istream& operator>>(std::istream& is, Streamable& obj);


}