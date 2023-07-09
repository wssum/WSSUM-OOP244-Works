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

#include<iostream>
#include "Truck.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
	Truck::Truck()
	{


	}

	Truck::~Truck()
	{

	}

	Truck::Truck(const char* lPlate, int yyyy, float capacity, const char* currentAddress):MotorVehicle(lPlate, yyyy)
	{
		moveTo(currentAddress);
		loadInKg = capacity;
		cargo = 0;
	}

	bool Truck::addCargo(double cargo)
	{
		bool changed{};

		if (this->cargo < loadInKg)
		{
			if ((this->cargo + cargo) < loadInKg)
			{
				this->cargo = this->cargo + cargo;
			}
			else
			{
				this->cargo = loadInKg;
			}
			
			changed = true;
		}
		else
		{
			changed = false;
		}

		return changed;

	}
	//bool unloadCargo();
	ostream& Truck::write(ostream& os)
	{
		MotorVehicle::write(os);
		os << " | " << cargo << "/" << loadInKg;
		return os;
	}
	//istream& read(istream& in);


//istream& operator>>(Truck& arg);
	ostream& operator<<(ostream& os, Truck& vehicle)
	{
		vehicle.write(os);
		return os;
	}
}
