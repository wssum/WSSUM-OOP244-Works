/*/////////////////////////////////////////////////////////////////////////

Workshop - #MS1

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

// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctype.h>
using namespace std;
#include "Menu.h"

namespace sdds {

	/*MenuItem funcs*/

	MenuItem::MenuItem(const char* name)
	{
		/*Checks to see if there is a valid argument passed to the constructor and if so memory decided by the
		length of the arg will be allocated and the name parameter will be copied to Name data memeber.*/
		if (name)
		{
			Name = new char[strlen(name) + 1];
			strcpy(Name, name);
		}
		else//If no valid argument the Name data member will be set to a safe null state to prevent any errors.
		{
			Name = nullptr;
		}

	}

	MenuItem::MenuItem()
	{
		Name = nullptr;//The Name data member will be set to a safe emtpy state to prevent any errors from occuring.
	}

	MenuItem::~MenuItem()
	{
		delete[] Name;//Deconstructor deletes the Name pointer.
	}

	MenuItem::operator bool()
	{
		/*If the current objects Name data member is not null then this operator will return true
		otherwise it will return false to signify that this object has not a valid name.*/
		if (Name)
		{
			return true;
		}

		return false;
	}

	MenuItem::operator const char* ()const
	{
		/*Returns the Name data member to be casted and used as a const char pointer.*/
		return Name;
	}

	ostream& MenuItem::displayName(std::ostream& os)
	{
		/*Checks to see if the object is not null and if so will output the data member
		representing the name of the object to the ostream object selected as the parameter
		which will then be returned as the value*/
		if (*this)
		{
			os << Name;
		}
		return os;
	}

	/*Menu funcs*/
	Menu::Menu()
	{
		amtOfItems = 0;//Initializes the amtOfItems as empty.              

		menuTitle = nullptr;//Sets the menuTitle pointer to a safe empty state to prevent any errors.

		for (int i = 0; i < MAX_MENU_ITEMS; i++)//Goes through the array MenuItems and sets them to a safe empty state to prevent any errors.
		{
			Items[i] = nullptr;
		}
	}

	Menu::Menu(const char* arg)
	{
		/*Allocates memory for the MenuItem pointer, using the char cast operator from MenuItem class
		and initializes its Name data member with the arg parameter reprpesenting the name*/
		menuTitle = new MenuItem(arg);

		for (int i = 0; i < MAX_MENU_ITEMS; i++)//Goes through the array MenuItems and sets them to a safe empty state to prevent any errors.
		{
			Items[i] = nullptr;
		}

		amtOfItems = 0;//Initializes the amtOfItems as empty.
	}



	Menu::~Menu()
	{
		for (int i = 0; i < MAX_MENU_ITEMS; i++)//Goes through the array MenuItems and deletes them to prevent memory leaks.
		{
			delete Items[i];
		}

		delete menuTitle;//Deletes the menuTitle to prevent memory leaks.
	}

	/*Returns true if the amtOfItems variable is more than 0 meaning its not empty.*/
	Menu::operator bool()
	{
		if (amtOfItems > 0)
		{
			return true;
		}

		return false;
	}

	/*Returns the amtOfItems as a unsigned int*/
	Menu::operator unsigned int()
	{
		return amtOfItems;
	}

	/*Returns the amtOfItems as a int*/
	Menu::operator int()
	{
		return amtOfItems;
	}

	ostream& Menu::displayTitle(std::ostream& os)
	{
		/*Checks to see if menuTitle is null or not and if it's not null it will use the displayName
		function to display and return the Name datamember representing the name of the object*/
		if (menuTitle)
		{
			menuTitle->displayName(os);
		}
		return os;
	}

	Menu& Menu::operator<<(const char* menuitemConent)
	{
		/*Checks to see if theres still room for more Items to be added by comparing amtOfItems
		already added with the max it can hold.*/
		if (amtOfItems < MAX_MENU_ITEMS)
		{
			/*If there amtOfItems is less than MAX_MENU_ITEMS then memory will
			be allocated for the new MenuItem object and be initialized by the
			menuitemContent parameter.*/
			Items[amtOfItems] = new MenuItem(menuitemConent);
			amtOfItems++;//amtOfItems will be incremented to represent anouther added item.
		}

		return *this;
	}

	/*A overload operator to display the title.*/
	ostream& operator<<(ostream& os, Menu& title)
	{
		return title.displayTitle(os);
	}

	ostream& Menu::displayMenu(std::ostream& os)
	{
		int a = 1;
		/*Checks to see if menuTitle is valid or not and if so will call the displayName
		function to display the menuTitles name.*/
		if (menuTitle)
		{
			menuTitle->displayName(os);
		}

		/*Will run through a loop by the amount of items added and using the displayName
		function will display the Name of the MenuItem.*/
		for (int i = 0; i < amtOfItems; i++)
		{
			os << a << "- ";
			Items[i]->displayName(os);
			os << endl;
			a++;
		}

		os << "0- Exit" << endl << '>';

		return os;
	}

	int Menu::run()
	{
		int selection = -1;//Variable to hold the entry set to a safe state that cannot be chosen to prevent errors.
		int flag = 0;

		displayMenu();//Displays the Menu.

		/*A loop that will continue to run till a valid entry is entered.*/
		while (flag == 0)
		{
			/*Checks to see that the cin is valid and if so will test to see if the selection
			is a valid number*/
			if (cin >> selection)
			{
				if ((selection >= 0) && (selection <= amtOfItems))
				{
					flag = 1;//If selection is valid the flag will be set to 1 so that the entry may be returned.
				}
				else
				{
					cin.clear();          //Safety protocol 
					cin.ignore(1000, '\n');//for the buffer.

					cout << "Invalid Selection, try again: ";
					selection = -1;//If the value entered is invalid a error message will prompt the user to empty a valid entry and the selection variable will be set back to a safe state.
				}
			}
			else
			{
				cin.clear();            //Safety protocol 
				cin.ignore(1000, '\n'); //for the buffer.
				cout << "Invalid Selection, try again: ";
			}
		}

		return selection;
	}


	int Menu::operator~()
	{
		return run();//Returns current run() output.
	}

	const char* Menu::operator[](int select)const
	{
		if (amtOfItems > 0)//Checks to see that there are any items to begin with.
		{
			select = select % amtOfItems; //Using modulus it will get the result of the selection and also if selection is more than the amtOfItems then it will loop back.

			return static_cast<const char*>(*Items[select]);//Returns selected item as const character type.
		}

		return nullptr; // Return nullptr if there are no items in the menu
	}

}





