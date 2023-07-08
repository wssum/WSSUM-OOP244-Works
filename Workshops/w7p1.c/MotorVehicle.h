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
#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

namespace sdds
{
	class MotorVehicle
	{
		char licensePlate[9];
		char address[64];
		int builtIn;

	public:
		MotorVehicle(const char* lPlate, int yyyy);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
	};
	std::istream& operator>>(std::istream& os, MotorVehicle& vehicle);
	std::ostream& operator<<(std::ostream& os, MotorVehicle& vehicle);

}

#endif
