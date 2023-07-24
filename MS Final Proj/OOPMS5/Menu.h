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
#ifndef SDDS_MENUB_H__
#define SDDS_MENUB_H__
#include <iostream>


namespace sdds
{
	const int MAX_MENU_ITEMS = 20;

	class MenuItem
	{
		char* Name{};
		MenuItem();
		MenuItem(const char* name);
		MenuItem(const MenuItem& src) = delete;
		void operator=(const MenuItem& src) = delete;
		~MenuItem();
		operator bool();
		operator const char* ()const;
		std::ostream& displayName(std::ostream& os);

		friend class Menu;
	};


	class Menu
	{
		MenuItem* menuTitle;
		MenuItem* Items[MAX_MENU_ITEMS]{};
		int amtOfItems;
	public:
		Menu();
		Menu(const char* arg);
		~Menu();
		Menu(const Menu& src) = delete;
		void operator=(const Menu& src) = delete;
		operator bool();
		operator int();
		operator unsigned int();
		std::ostream& displayTitle(std::ostream& os);
		std::ostream& displayMenu(std::ostream& os = std::cout);
		Menu& operator<<(const char* menuitemConent);
		int run();
		int operator~();
		const char* operator[](int select)const;
	};
	std::ostream& operator<<(std::ostream& os, Menu& title);


}
#endif



