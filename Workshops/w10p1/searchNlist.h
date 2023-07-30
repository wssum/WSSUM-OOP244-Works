#pragma once
/*/////////////////////////////////////////////////////////////////////////

Workshop - #10 (P1)

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
#include<iostream>
#include"Collection.h"

namespace sdds
{
    /*For my template on the search function the types that are able to be used
    * in placement for the template arguments are data types since I used
    * typename. Due to this reason only data types such as int, double or perhaps
    * custome struct types are allowed. Usually for templates the arguments in the
    * "< >" will replace the types of data members when using it in a class, however
    * in thuis case it allows polymorphism to happen as now you can pass certain types
    * of variables to it without having to explicitly name them on the spot by using
    * "< >" beside it and declaring a datat type within the "< >". However, since in my
    * function collector and collectibles must be the same type since I listed both of
    * them as typeA from my templates parameters the first two arguments must always be
    * the same type.
    */
    template<typename typeA, typename typeB>
    bool search(Collection<typeA>& collector, typeA* collectibles, int howMany, const typeB& param)
    {
        int match = 0;
        bool yesOrNo{};

        for (int i = 0; i < howMany; i++)
        {
            if (collectibles[i] == param)
            {
                collector.add(collectibles[i]);
                match++;
            }
        }

        if (match > 0)
        {
            yesOrNo = true;
        }

        return yesOrNo;
    }

    /*For my function below I only have one template argument, typeO
    * and only one parameter is using typeO to have it's data type to
    * be replaced as I am again using typername which will take a data
    * type to replace parameter arg type. Also since theres only one
    * parameter taking my templates argument in placement of it, it allows
    * more flexibility then the search function which requires the first two
    * arguments type to match. The only thing you can't do is pass in raw
    * data such as a number or a character.
    */
    template<typename typeO>
    void listArrayElements(const char* Title, typeO* arg, int howMany)
    {
        std::cout << Title << '\n';
        for (int i = 0; i < howMany; i++)
        {
            std::cout << i + 1 << ": " << arg[i] << std::endl;
        }
    }

}