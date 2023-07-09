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
	MotorVehicle::MotorVehicle()
	{
	
	}

	MotorVehicle::MotorVehicle(const char* lPlate, int yyyy)
	{
		strCpy(licensePlate, lPlate);
		strCpy(address, "Factory");
		builtIn = yyyy;
	}

	bool MotorVehicle::truthSeeker(char* stringA, const char* stringB)
	{
		int lengthA = static_cast<int>(strLen(stringA));
		int lengthB = static_cast<int>(strLen(stringB));
		bool tRf{};

		if (lengthA != lengthB)
		{
			tRf = false;
		}
		else
		{
			int flag = 0, i = 0;

			while (flag == 0)
			{
				if(stringA[i] != stringB[i])
				{
					flag = 1;
					tRf = false;
				}

				if (i == lengthA)
				{
					flag = 1;
					tRf = true;
				}
				i++;
			}
		}
		return tRf;
	}

	void MotorVehicle::moveTo(const char* address)
	{

		if (!truthSeeker(this->address, address))
		{
			cout << "|" << right << setw(8) << licensePlate << "|";
			cout << " |" << right << setw(20) << this->address << " ---> ";
			cout << left << setw(20) << address << "|" << endl;

			strCpy(this->address, address);
		}

	}

	ostream& MotorVehicle :: write(ostream& os)
	{
		os << "| " << builtIn << " |" << " " << licensePlate << " | " << address;
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

	MotorVehicle::~MotorVehicle()
	{

	}

}
