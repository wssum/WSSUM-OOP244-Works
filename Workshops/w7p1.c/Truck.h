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

#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

namespace sdds
{
	class Truck:public MotorVehicle
	{
		float loadInKg;
		float currentLoad;

	public:
		//Truck(char* lPlate, int yyyy);
		//bool addCargo(double cargo);
		//bool unloadCargo();
		//ostream& write(ostream& os);
		//istream& read(istream& in);

	};
	//istream& operator>>(Truck& arg);
//ostream& operator<<(Truck& arg);
}

#endif
