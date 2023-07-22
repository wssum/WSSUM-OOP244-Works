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

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
    class HtmlText : public Text {
        char* m_title{};
    public:
        void write(std::ostream& os)const;
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& arg);
        HtmlText& operator=(const HtmlText& arg);
        ~HtmlText();
    };
}
#endif // !SDDS_HTMLTEXT_H__