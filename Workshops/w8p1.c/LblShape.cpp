/*/////////////////////////////////////////////////////////////////////////

Workshop - #8 (P1)

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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstdio>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{
	char* LblShape::label()const
	{
		return m_label;
	}

	LblShape::LblShape()
	{

	}

	LblShape::LblShape(const char* string)
	{
		m_label = new char[strlen(string) + 1];

		strcpy(m_label, string);
	}

	LblShape::~LblShape()
	{
		delete[]m_label;
	}

	void LblShape::getSpecs(istream& is)
	{
		string label{};
		getline(is, label,',');
		m_label = new char[strlen(label.c_str()) + 1];

		strcpy(m_label, label.c_str());
	}

}