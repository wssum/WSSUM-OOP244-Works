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
		Menu publicationMenu;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message);
		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		void search();  // prints: "Searching for publication"<NEWLINE>

		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
	public:
		void newPublication();
		void removePublication();
		void checkOutPub();
		void run();
		LibApp(const char* fileName);
		LibApp();
		virtual ~LibApp();
	};
}
#endif // !SDDS_LIBAPP_H

