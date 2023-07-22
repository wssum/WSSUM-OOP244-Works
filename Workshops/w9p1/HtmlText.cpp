/*/////////////////////////////////////////////////////////////////////////

Workshop - #9 (P1)

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
#include "HtmlText.h"
#include "cstring.h"
#include "Text.h"

using namespace std;

namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title):Text(filename)
	{
		if (title != nullptr)
		{
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}

	HtmlText& HtmlText::operator=(const HtmlText& arg)
	{
		if (this != &arg)
		{
			delete[] m_title;
			m_title = nullptr;

			Text::operator=(arg);

			m_title = new char[strLen(arg.m_title) + 1];
			strCpy(m_title, arg.m_title);
		}

		return *this;
	}

	HtmlText::HtmlText(const HtmlText& arg):Text(arg)
	{

		m_title = new char[strLen(arg.m_title) + 1];
		strCpy(m_title, arg.m_title);
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	void HtmlText::write(std::ostream& os)const
	{
		bool ms{};

		os << "<html><head><title>";
		if (m_title != nullptr)
		{
			os << m_title;
		}
		else
		{
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";

		if (m_title != nullptr)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}

		
		for (int i = 0; Text::operator[](i) != '\0'; i++)
		{
			if (Text::operator[](i) == ' ')
			{
				if (ms == true)
				{
					os << "&nbsp;";
				}
				else
				{
					ms = true;
					os << ' ';
				}	
			}
			else if(Text::operator[](i) == '<')
			{
				os << "&lt;";
				ms = false;
			}
			else if(Text::operator[](i) == '>')
			{
				os << "&gt;";
				ms = false;
			}
			else if(Text::operator[](i) == '\n')
			{
				os << "<br />\n";
				ms = false;
			}
            else
			{
				os << Text::operator[](i);
				ms = false;
			}
		}
		os << "</body>\n</html>";
	}
}