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
#include <fstream>
#include <iostream>
#include "Text.h"
#include"cstring.h"
using namespace std;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    void Text::read()
    {
        if (m_filename != nullptr)
        {
            ifstream istr(m_filename);
            m_content = new (nothrow) char[getFileLength() + 1];

            int i = 0;
            char ch;
            while (istr.get(ch))
            {
                m_content[i] = ch;
                i++;
            }

            m_content[i] = '\0';
        }
        else
        {
            m_content = new char[255];
            strCpy(m_content, "");
        }

    }

    Text::Text(const char* filename)
    {
        if (filename != nullptr)
        {
            m_filename = new (nothrow) char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
        else
        {
            m_filename = new char[255];
            strCpy(m_filename, "");
            read();
        }
    }

    Text::~Text()
    {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;
    }


    Text::Text(const Text& arg)
    {
        m_filename = new char[strLen(arg.m_filename) + 1];
        strCpy(m_filename, arg.m_filename);
        read();
    }

    const char& Text::operator[](int index)const
    {
        return m_content[index];
    }

    Text& Text::operator=(const Text& arg)
    {
        if (this != &arg)
        {
            delete[] m_filename;
            m_filename = nullptr;
            delete[] m_content;
            m_content = nullptr;

            m_filename = new char[strLen(arg.m_filename) + 1];
            strCpy(m_filename, arg.m_filename);
            read();
        }
        return *this;
    }

    void Text::write(std::ostream& os)const
    {
        if (m_content != nullptr)
        {
            os << m_content;
        }
    }

    std::ostream& operator << (std::ostream& os, const Text& arg)
    {
        arg.write(os);

        return os;
    }
}