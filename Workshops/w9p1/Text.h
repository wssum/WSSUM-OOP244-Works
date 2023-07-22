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
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
    class Text {
        char* m_filename;
        char* m_content{};
        int getFileLength()const;
    protected:
        const char& operator[](int index)const;
    public:
        void read();
        Text(const char* filename = nullptr);
        Text(const Text& arg);
        ~Text();
        Text& operator=(const Text& arg);
        virtual void write(std::ostream& os)const;
    };
    std::ostream& operator << (std::ostream& os, const Text& arg);
}
#endif // !SDDS_PERSON_H__
