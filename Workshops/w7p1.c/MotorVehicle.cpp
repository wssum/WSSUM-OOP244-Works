/*/////////////////////////////////////////////////////////////////////////

Workshop - #7 (P1)

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

#include <iostream>
#include <iomanip>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	MotorVehicle::MotorVehicle(const char* lPlate, int yyyy)
	{
		strCpy(licensePlate, lPlate);
		strCpy(address, "Factory");
		builtIn = yyyy;
	}
	void MotorVehicle::moveTo(const char* address)
	{
		bool yeOrNo{};

		yeOrNo = strCmp(this->address, address);

		if (yeOrNo == true)
		{
			cout << "|" << right << setw(8) << licensePlate << "|"; 
			cout << " |" << right << setw(20) << this->address << " ---> ";
			cout << left << setw(20) << address << "|"  << endl;

			strCpy(this->address, address);
		}

	}

	ostream& MotorVehicle :: write(ostream& os)
	{
		os << "| " << builtIn << " |" << " " << licensePlate << " | " << address << endl;
		return os;
	}
	istream& MotorVehicle::read(istream& in)
	{
		cout << "Built year: ";
		in >> builtIn;
		cout << "License plate: ";
		in >> licensePlate;
		cout << "Current location: ";
		in >> address;

		return in;
	}

	
	istream& operator>>(istream& is, MotorVehicle& vehicle)
	{
		vehicle.read(is);
		return is;
	}

	ostream& operator<<(ostream& os, MotorVehicle& vehicle)
	{
		vehicle.write(os);
		return os;
	}

}
