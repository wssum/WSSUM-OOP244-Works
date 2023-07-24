#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include "Book.h"
#include "Date.h"
#include "LibApp.h"
#include "Menu.h"
#include "Publication.h"

using namespace std;
using namespace sdds;

int main(void)
{
	sdds::LibApp theApp("Testing 123.txt");

	cout << endl << "Testing exiting with no change:" << endl;
	theApp.run();
	cout << endl << "Testing exiting with change and discarding data:" << endl;
	theApp.run();
	cout << endl << "Testing exiting with change and saving data:" << endl;
	theApp.run();
	cout << endl << "Testing all actions:" << endl;
	theApp.run();
	return 0;
}