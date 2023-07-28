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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"
namespace sdds {

	class LibApp {
		char m_fileName[256]{};
		Publication* PPA[SDDS_LIBRARY_CAPACITY]{};
		int NOLP{};
		int LLRN{};
		bool m_changed{};
		Menu publicationMenu;//proto Done
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();  //proto Done
		void save(); //proto Done
		int search(int method = 0);  //proto Done
		void returnPub();  //To Do
	public:
		void newPublication();//proto Done
		void removePublication();//proto Done
		void checkOutPub();//proto Done
		void run();
		Publication* getPub(int libRef);
		LibApp(const char* fileName);
		LibApp();
		~LibApp();
	};
}
#endif // !SDDS_LIBAPP_H

