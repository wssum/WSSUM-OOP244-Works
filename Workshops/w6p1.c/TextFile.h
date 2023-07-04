/*/////////////////////////////////////////////////////////////////////////

Workshop - #6

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

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {

    class Line {
        char* m_value{ nullptr };
        operator const char* ()const;
        Line() {}
        Line& operator=(const char*);
        ~Line();
        friend class TextFile;
        // copy and copy assignment prevention goes here

    };

    class TextFile {
        Line* m_textLines{ nullptr };
        char* m_filename{ nullptr };
        unsigned m_noOfLines;
        unsigned m_pageSize;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName)const;
        void setEmpty();
    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile& book);
        TextFile& operator=(const TextFile& book);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__


