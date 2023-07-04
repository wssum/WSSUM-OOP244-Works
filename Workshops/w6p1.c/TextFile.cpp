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

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }
    Line::~Line()
    {
        if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
        }
    }

    /*Sets all data members to a safe empty state.*/
    void TextFile::setEmpty()
    {
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;

        m_noOfLines = 0;
    }


    /*Sets a files title to either a new title with 'C_' signalling that its a copy if isCopy paramater is set to true.*/
    void TextFile::setFilename(const char* fname, bool isCopy)
    {
        if (isCopy)
        {
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
        else
        {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
    }


    void TextFile::setNoOfLines()
    {
        ifstream reader(m_filename);//Makes a temporary ifstream object using m_filename.
        char dummy;//A dummy character variable to read in characters.

        /*Checks to see if the file was opened successfully and if so will constantly reiinitializes  the dummy variable
          while checking if the dummy variable is a newline and if so m_noOflines will be incremented.*/
        if (reader.is_open())
        {
            while (reader)
            {
                reader.get(dummy);

                if (dummy == '\n')
                {
                    m_noOfLines++;
                }
            }
            m_noOfLines++;
        }
        else
        {
            delete[] m_filename;
            m_filename = nullptr;
        }

    }

    void TextFile::loadText()
    {
        /*Checks to see if the current filename is valid and if so will start a deep copying of the new resources.*/
        if (m_filename != nullptr)
        {
            delete[] m_textLines;
            m_textLines = nullptr;

            ifstream output(m_filename);//Opens a new file with the current filenames name.
            string line;
             /*Refreshes the number of lines so that it may get the new number of lines for the current object.*/
                m_noOfLines = 0;
                while (getline(output, line))
                {
                    m_noOfLines++;
                }

                /*This whole part below allocates memory and deep copies each new line.*/
                output.clear();
                output.seekg(0);

                m_textLines = new Line[m_noOfLines];

                for (unsigned i = 0; i < m_noOfLines; i++)
                {
                    getline(output, line);
                    m_textLines[i].m_value = new char[strLen(line.c_str()) + 1];
                    strCpy(m_textLines[i].m_value, line.c_str());
                }
            
        }
    }

    /*Saves all content into a new copy of a file.*/
    void TextFile::saveAs(const char* fileName) const
    {
        ofstream outPut(m_filename);
        unsigned i = 0;

        for (i = 0; i < m_noOfLines; i++)
        {
            outPut << m_textLines[i] << endl;
        }
    }

    /*Creates a TextFile object and sets m_pageSize to pageSize parameters arg and sets everything else to a safe empty state.*/
    TextFile::TextFile(unsigned pageSize)
    {
        setEmpty();

        m_pageSize = pageSize;
    }

    /*Creates a TextFile object and sets m_pageSize to pageSize parameters arg and sets everything else to a safe empty state.*/
    TextFile::TextFile(const char* filename, unsigned pageSize)
    {
        setEmpty();

        m_pageSize = pageSize;

        /*Checks to see if filename parameter is a nullptr and if it is not it will allocate the proper amount of memory to store the filename
        to m_filename as well as set the number of lines depending on the file opened.*/
        if (filename != nullptr)
        {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);

            setNoOfLines();

            loadText();

        }
    }


    TextFile::TextFile(const TextFile& book)
    {
        unsigned i = 0;

        setEmpty();

        this->m_pageSize = book.m_pageSize;

        /*Checks to see if  parameter being passed in is valid and if so will allocate all the memory necessary to copy
        the contents over to the newly created object.*/
        if (this != &book)
        {
            setFilename(book.m_filename, true);
            this->m_noOfLines = book.m_noOfLines;
            m_textLines = new Line[m_noOfLines];

            for (i = 0; i < m_noOfLines; i++)
            {
                m_textLines[i].m_value = new char[strLen(book.m_textLines[i].m_value) + 1];
                strCpy(m_textLines[i].m_value, book.m_textLines[i].m_value);
            }
            saveAs(m_filename);//Saves output of the current file.

        }
    }

    TextFile& TextFile:: operator=(const TextFile& book)
    {
        unsigned i = 0;
        /*Checks to see if the current object is the same as the one being passed through the parameters and
          if it's not the object being worked on will have all of its values replaced with the object passed
          in the parameters.*/
        if (this != &book)
        {
            /*Deletes and sets m_text_Lines to a safe empty states.*/
            if (m_textLines != nullptr)
            {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            if (book.m_textLines && book.m_noOfLines > 0)
            {
                /*shallow copies the number of lines which will then determine how much memory to allocate for m_textLines
       data member which is a Line pointer.*/
                m_noOfLines = book.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                /*Goes through a loop determined by how many lines there are and then allocates the necessary amount of memory
                to copy the texts.*/
                for (i = 0; i < m_noOfLines; i++)
                {
                    m_textLines[i].m_value = new char[strLen(book.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, book.m_textLines[i].m_value);
                }
                saveAs(m_filename);//Saves output of the current file.
            }

        }
        return *this;
    }

    TextFile::~TextFile()
    {
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;
    }


    unsigned TextFile::lines()const
    {
        return m_noOfLines;//Returns current objects number of lines.
    }

    const char* TextFile::name()const
    {
        return m_filename;//Returns current objects file name.
    }

    ostream& TextFile::view(ostream& ostr) const
    {
        /*Checks to make sure filename is valid and if so will print out all the content.*/
        if (m_filename != nullptr && m_filename[0] != '\0')
        {
            ostr << m_filename << endl;

            ostr.fill('=');
            ostr.width(strLen(m_filename));
            ostr << '=' << endl;

            unsigned i = 0;
            while (i < m_noOfLines && i < m_pageSize)//prints out number of lines based on pagesize.
            {
                ostr << m_textLines[i] << endl;
                i++;
            }

            if (i < m_noOfLines)//Checks to see if i is less than number of lines and if so a special function will trigger to prompt the user to continue by pressing enter.
            {
                do {
                    ostr << "Hit ENTER to continue...";
                    char get;
                    cin.get(get);

                    for (unsigned k = 0; k < m_pageSize && i < m_noOfLines; k++) {
                        ostr << m_textLines[i] << endl;
                        i++;
                    }
                } while (i < m_noOfLines);
            }
        }

        return ostr;
    }


    istream& TextFile::getFile(istream& istr)
    {
        string name;
        istr >> name;//Using the >> overload operator name gets the content of istr so it can be used to open a ifstream object
        //to write in data.

        /*This whole part below performs a deep copy of all values and also allocates memory for the copy.*/
        m_filename = new char[strLen(name.c_str()) + 1];
        strCpy(m_filename, name.c_str());
        istr.ignore(33000, '\n');

        setNoOfLines();
        loadText();

        return istr;
    }

    const char* TextFile::operator[](unsigned index)const
    {
        /*If the current object is invalid a nullptr will be returned and prevent any further actions thus preventing errors.*/
        if (!this)
        {
            return nullptr;
        }

        /*A safekeep to make sure that is the index passed is more the number of lines a rollback will happen.*/
        if (index >= m_noOfLines)
        {
            int holder = index % m_noOfLines;

            return m_textLines[holder];
        }

        return m_textLines[index];

    }

    /*Checks to see if the m_filename is a nullptr or not and if it isn't a nullptr it returns true.*/
    TextFile::operator bool()const
    {
        if (m_filename != nullptr)
        {
            if (m_textLines != NULL)
            {
                return true;
            }
        }

        return false;

    }


    /*Takes all the ostream content of text and returns it to be displayed.*/
    ostream& operator<<(ostream& ostr, const TextFile& text)
    {
        text.view(ostr);

        return ostr;
    }

    /*Takes all the ostream content of text and returns it to be reassigned to anouther object.*/
    istream& operator>>(istream& istr, TextFile& text)
    {
        text.getFile(istr);

        return istr;
    }



}


