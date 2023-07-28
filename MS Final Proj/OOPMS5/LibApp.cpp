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
#include <iomanip>
#include <iostream>
#include <ctype.h>
#include <cstring>
#include <fstream>
#include "string"
#include "Utils.h"
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;

namespace sdds {
	//With this method the one arg constructor from menu class is called multiple times to initialize the titles of the Menu type objects within the LibApp Object.
	LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")//<<<<(This Method)
	{
		load();
		/*Using the << overload operator the Items from the Menu class is initialized with multiple strings.*/
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		/*Same as above.*/
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
	}

	LibApp::LibApp(const char* fileName)
	{
		
		if (fileName != nullptr)
		{
		strcpy(m_fileName, fileName);
		}
		load();
		publicationMenu << "Book" << "Publication";
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";

		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
	}

	LibApp::~LibApp()
	{
		for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
		{
			delete PPA[i];
		}
	}
	void LibApp::load()
	{
		ifstream istr(m_fileName);
		cout << "Loading Data" << endl;

		char pType;
		while (istr >> pType)
		{
			if (pType == 'P')
			{
				PPA[NOLP] = new Publication;
				istr >> *PPA[NOLP];
				LLRN = PPA[NOLP]->getRef();
				cout << LLRN << endl;
				NOLP++;
			}
			else if (pType == 'B')
			{
				PPA[NOLP] = new Book;
				istr >> *PPA[NOLP];
				LLRN = PPA[NOLP]->getRef();
				cout << LLRN<<endl;
				NOLP++;
			}	
		}
	}

	void LibApp::save()
	{
		int i = 0;
		ofstream ostr(m_fileName);
		cout << "Saving Data" << endl;
		for (i = 0; i < NOLP; i++)
		{
			if (PPA[i]->getRef() != 0)
			{
				cout << PPA[i]->getRef()<<endl;
				ostr << *PPA[i];
			}
		}
	}

	int LibApp::search(int method)
	{
		int bOrP = -1, matches = 0, choice = -1;
		char ptype{};
		string filterTitleBy{};
		PublicationSelector filterMenu("Select one of the following found matches:");
		cout << "Choose the type of publication:" << endl;
		bOrP = publicationMenu.run();
		if (bOrP == 1)
		{
			ptype = 'B';
		}
		else if (bOrP == 2)
		{
			ptype = 'P';
		}
		else if (bOrP == 0)
		{
			cout << "Aborted!" << endl;
		}

		if (bOrP > 0)
		{
			cout << "Publication Title: ";
			cin.clear();
			cin.ignore(1000, '\n');
			getline(cin, filterTitleBy);

			for (int i = 0; i < NOLP; i++)
			{
				if (PPA[i]->type() == ptype)
				{
					if (strstr(static_cast<const char*>(*PPA[i]), filterTitleBy.c_str()))
					{
						if (method == 0)
						{
							filterMenu << PPA[i];
							matches++;
						}
						
					    if (method == 1)
						{
							if (!PPA[i]->onLoan())
							{
								filterMenu << PPA[i];
								matches++;
							}
						}

						if (method == 2)
						{
							if (PPA[i]->onLoan())
							{
								filterMenu << PPA[i];
								matches++;
							}
						}
						
					}
				}
			}

			if (matches > 0)
			{
				filterMenu.sort();
				choice = filterMenu.run();
				if (choice == 0)
				{
					cout << "Aborted!" << endl;
				}
			}
			else
			{
				cout << "No matches found!" << endl;
			}
		}
		return choice;
	}

	bool LibApp::confirm(const char* message)
	{
		Menu tempMenu(message);//Makes temp menu obj with parameter message to represent a question to ask for confirmation.
		int select = -1;//The variable that will hold the result.
		bool yeOrNo = false;

		tempMenu << "yes";//Using the << overload operator yes is the only given MenuItem as well as the mandatory exit from the menu.

		select = tempMenu.run();//Option chosen by user will be assigned to select variable and be evaluated to return the proper bool.

		if (select == 1)
		{
			yeOrNo = true;
		}

		return yeOrNo;
	}

	Publication* LibApp::getPub(int libRef)
	{
		int k = 0, i = 0;
		for (i = 0; i < NOLP; i++)
		{
			if (PPA[i]->getRef() == libRef)
			{
				k = i;
			}
		}

		return PPA[k];
	}

	void LibApp::newPublication()
	{
		bool decider{};
		int bOrP = 0;
		if (NOLP != SDDS_LIBRARY_CAPACITY)
		{
			cout << "Adding new publication to library" << endl;
			cout << "Choose the type of publication:" << endl;
			bOrP = publicationMenu.run();
			if (bOrP == 1)
			{
				PPA[NOLP] = new Book;
				if (cin >> *PPA[NOLP])
				{
					decider = confirm("Add this publication to library?");
				}
				else
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!" << endl;
				}
				
			}
			else if (bOrP == 2)
			{
				PPA[NOLP] = new Publication;
				if (cin >> *PPA[NOLP])
				{
					decider = confirm("Add this publication to library?");
				}
				else
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!" << endl;
				}
			}

			if (decider == true)
			{
				m_changed = true;
				cout << "Publication added" << endl << endl;
				LLRN++;
				PPA[NOLP]->setRef(LLRN);
				NOLP++;
			}
			else
			{
				delete PPA[NOLP];
				PPA[NOLP] = nullptr;
				cout << endl;
			}

		}
		else
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		
	}


	void LibApp::removePublication()
	{
		bool decider = false;
		int bookRef = -1;
		cout << "Removing publication from library" << endl;
		bookRef = search();
		if (bookRef > 0)
		{
			decider = confirm("Remove this publication from the library?");
		}

		if (decider == true)
		{
			for (int i = 0; i < NOLP; i++)
			{
				if (PPA[i]->getRef() == bookRef)
				{
					PPA[i]->setRef(0);
				}
			}
			m_changed = true;
			cout << "Publication removed" << endl << endl;
		}

	}

	void LibApp::checkOutPub()
	{
		bool decider = false;
		int bookRef = -1,memberId = -1, flag = 0;
		cout << "Checkout publication from the library" << endl;
		bookRef = search(1);
		if (bookRef > 0)
		{
			decider = confirm("Check out publication?");
		}

		if (decider == true)//If decider is true then the value of m_changed will become true to signify change.
		{
			cout << "Enter Membership number: ";
			while (flag == 0)
			{
				cin >> memberId;
				if ((memberId >= 10000) && (memberId <= 99999))
				{
					for (int i = 0; i < NOLP; i++)
					{
						if (PPA[i]->getRef() == bookRef)
						{
							PPA[i]->set(memberId);
						}
					}
					flag = 1;
				}
				else
				{
					"Invalid membership number, try again: ";
				}
			} 
		    
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		else
		{
			cout << endl;
		}
		cout << endl;
	}

	void LibApp::returnPub()
	{
		cout << "Return publication to the library" << endl;
		search();
		cout << "Returning publication" << endl;

		cout << "Publication returned" << endl << endl;
		m_changed = true;
	}

	void LibApp::run()
	{
		bool yRn = false; //Bool variable to hold confirmation value for exiting without saving changes.
		int selection = -1, subSelect = -1;//Variables to hold selections and subselection decisions from user that will determine the actions of this program.
		int flag = 0;

		while (flag == 0)//A while loop that wil continue running till a complete exit has been confirmed, this exit path may vary.
		{
			selection = m_mainMenu.run();//Using the run function from the m_mainMenu object within the LibApp class a selection will be made.

			/*A list of if statements separated as if statements rather than if else because this method will confuse teh compiler alot less.
			These if statements will trigger certain functions depending on the selection made by the user*/
			if (selection == 1)
			{
				newPublication();
			}

			if (selection == 2)
			{
				removePublication();
			}

			if (selection == 3)
			{
				checkOutPub();
			}

			if (selection == 4)
			{
				returnPub();
			}

			/*If selection 0 is selected which signifies an exit is triggered the m_changed data member wil be evaluated to see if
			there was a change and if so a bunch of other options will be given to the user.*/
			if (selection == 0)
			{
				if (m_changed == false)
				{
					flag = 1;
				}

				if (m_changed == true)
				{
					subSelect = m_exitMenu.run();
					/*If the user did change something the m_exitMenu will run it's run function that lists out more options and will be determined by
					the subselect variable which will hold the decision of the user.*/
					if (subSelect == 1)
					{
						save();//Option 1 will save all changes and then terminate the program by seeting flag to 1.
						flag = 1;
					}

					if (subSelect == 2)
					{
						selection = -1;//Option 2 will set both variables selection and subSelect back to their safe empty positions and then
						subSelect = -1;//since flag is still 0 will continue the program going back to the main menu.
						cout << endl;
					}

					if (subSelect == 0)
					{
						yRn = confirm("This will discard all the changes are you sure?");
						/*If 0 is selcted a confirmation will be made to make sure that the user trully wants to exit completely
						  without saving as option 0 will simply exit without making any changes whatsoever. The confirmation
						  will be from the confirm function and the result will be assigned to yRn which will then be validated.*/
						if (yRn == true)
						{
							flag = 1;//If the user chooses to exit without saving the flag will be set to 1 which will terminate the program.
						}
						else
						{
							selection = -1;//If the user wishes not to exit, they will be led back to the main screen and variables selection
							subSelect = -1;//and subSelect will be set back to their original position to be reused.
						}
					}
				}

			}
		}
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

}