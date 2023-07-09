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
		double loadInKg;
		double cargo;

	public:
		Truck();
		Truck(const char* lPlate, int yyyy,float capacity,const char* currentAddress);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
		~Truck();
	};
	std::istream& operator>>(std::istream& is, Truck& vehicle);
	std::ostream& operator<<(std::ostream& os, Truck& vehicle);
}

#endif
