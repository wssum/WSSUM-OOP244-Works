/*/////////////////////////////////////////////////////////////////////////

Workshop - #MS1

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

// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Utils.h"
#include "Date.h"

namespace sdds {
    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }
    int Date::mdays()const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }
    int Date::systemYear()const {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        return lt.tm_year + 1900;
    }
    void Date::setToToday() {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        m_day = lt.tm_mday;
        m_mon = lt.tm_mon + 1;
        m_year = lt.tm_year + 1900;
        errCode(NO_ERROR);
    }
    int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }
    Date::Date() :m_CUR_YEAR(systemYear()) {
        setToToday();
    }
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }
    const char* Date::dateStatus()const {
        return DATE_ERROR[errCode()];
    }
    int Date::currentYear()const {
        return m_CUR_YEAR;
    }
    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }
    int Date::errCode()const {
        return m_ErrorCode;
    }
    bool Date::bad()const {
        return m_ErrorCode != 0;
    }

    ostream& Date::write(std::ostream& os)const
    {
        if (bad()) //If Date object is bad it date status will be printed
        {
            os << dateStatus();
        }
        else//If its correct then it will be printed in a special date format
        {
            os << m_year << "/";

            if ((m_mon >= 10) && (m_mon <= 12))
            {
                os << m_mon;
            }
            else
            {
                os << setw(2) << setfill('0') << right << m_mon;
            }

            os << "/";

            if (m_day > 9)
            {
                os << m_day;
            }
            else
            {
                os << setw(2) << setfill('0') << right << m_day;
            }
        }

        return os;
    }
    int Date::operator-(Date D1)const
    {
        int yearR = 0, yearL = 0;
        int mmR = 0, mmL = 0;
        int daysR = 0, daysL = 0;
        int days = 0;

        /*This whole section is to convert all of right operands years, months and days to pure days to be validated.*/
        yearR = (D1.m_year * 365) + D1.m_day;
        mmR = daysInMonth(D1.m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.       
        daysR = yearR + mmR;

        /*This whole section is to convert all of left operands years, months and days to pure days to be validated.*/
        yearL = (this->m_year * 365) + this->m_day;
        mmL = daysInMonth(this->m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.     
        daysL = yearL + mmL;

        days = daysL - daysR;
        return days;//Returns values difference between the two dates.
    }

    ostream& operator<<(ostream& os, const Date& RO) {
        return RO.write(os);
    }

    Date::operator bool()const
    {
        return !bad();//Returns a bool to determine whether the object is usable or not.
    }

    istream& Date::read(std::istream& is)
    {

        char delimit = '/';//Dummy delimiter to help deal with delimiters.

        errCode(NO_ERROR);

        is >> m_year >> delimit >> m_mon >> delimit >> m_day;//Reads in a year, month and day with a dummy delimiter to handle delimiters


        if (!is)//Checks to see if cin worked or not, if it did not thenerrCode will be set sin_failed and the buffer will becleared even deeper thanks to the ignore func
        {
            errCode(CIN_FAILED);
            is.clear();
            is.ignore(1000, '\n');
        }
        else
        {
            m_year++;
            validate();//If is worked then values will be validated.
        }

        m_year--;
        is.clear();

        return is;
    }

    bool Date::operator>(Date D1)const
    {
        int yearR = 0, yearL = 0;
        int mmR = 0, mmL = 0;
        int daysR = 0, daysL = 0;

        /*This whole section is to convert all of right operands years, months and days to pure days to be validated.*/
        yearR = (D1.m_year * 365) + D1.m_day;
        mmR = daysInMonth(D1.m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.       
        daysR = yearR + mmR;

        /*This whole section is to convert all of left operands years, months and days to pure days to be validated.*/
        yearL = (this->m_year * 365) + this->m_day;
        mmL = daysInMonth(this->m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.     
        daysL = yearL + mmL;

        return daysL > daysR;//Returns the comparison result.
    }

    bool Date::operator<(Date D1)const
    {
        int yearR = 0, yearL = 0;
        int mmR = 0, mmL = 0;
        int daysR = 0, daysL = 0;

        /*This whole section is to convert all of right operands years, months and days to pure days to be validated.*/
        yearR = (D1.m_year * 365) + D1.m_day;
        mmR = daysInMonth(D1.m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.       
        daysR = yearR + mmR;

        /*This whole section is to convert all of left operands years, months and days to pure days to be validated.*/
        yearL = (this->m_year * 365) + this->m_day;
        mmL = daysInMonth(this->m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.     
        daysL = yearL + mmL;

        return daysL < daysR;//Returns the comparison result.
    }

    bool Date::operator<=(Date D1)const
    {
        int yearR = 0, yearL = 0;
        int mmR = 0, mmL = 0;
        int daysR = 0, daysL = 0;

        /*This whole section is to convert all of right operands years, months and days to pure days to be validated.*/
        yearR = (D1.m_year * 365) + D1.m_day;
        mmR = daysInMonth(D1.m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.       
        daysR = yearR + mmR;

        /*This whole section is to convert all of left operands years, months and days to pure days to be validated.*/
        yearL = (this->m_year * 365) + this->m_day;
        mmL = daysInMonth(this->m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.     
        daysL = yearL + mmL;

        return daysL <= daysR;//Returns the comparison result.
    }

    bool Date::operator>=(Date D1)const
    {
        int yearR = 0, yearL = 0;
        int mmR = 0, mmL = 0;
        int daysR = 0, daysL = 0;

        /*This whole section is to convert all of right operands years, months and days to pure days to be validated.*/
        yearR = (D1.m_year * 365) + D1.m_day;
        mmR = daysInMonth(D1.m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.       
        daysR = yearR + mmR;

        /*This whole section is to convert all of left operands years, months and days to pure days to be validated.*/
        yearL = (this->m_year * 365) + this->m_day;
        mmL = daysInMonth(this->m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.     
        daysL = yearL + mmL;

        return daysL >= daysR;//Returns the comparison result.
    }

    bool Date::operator==(Date D1)const
    {
        int yearR = 0, yearL = 0;
        int mmR = 0, mmL = 0;
        int daysR = 0, daysL = 0;

        /*This whole section is to convert all of right operands years, months and days to pure days to be validated.*/
        yearR = (D1.m_year * 365) + D1.m_day;
        mmR = daysInMonth(D1.m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.       
        daysR = yearR + mmR;

        /*This whole section is to convert all of left operands years, months and days to pure days to be validated.*/
        yearL = (this->m_year * 365) + this->m_day;
        mmL = daysInMonth(this->m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.     
        daysL = yearL + mmL;

        return daysL == daysR;//Returns the comparison result.
    }

    bool Date::operator!=(Date D1)const
    {
        int yearR = 0, yearL = 0;
        int mmR = 0, mmL = 0;
        int daysR = 0, daysL = 0;

        /*This whole section is to convert all of right operands years, months and days to pure days to be validated.*/
        yearR = (D1.m_year * 365) + D1.m_day;
        mmR = daysInMonth(D1.m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.       
        daysR = yearR + mmR;

        /*This whole section is to convert all of left operands years, months and days to pure days to be validated.*/
        yearL = (this->m_year * 365) + this->m_day;
        mmL = daysInMonth(this->m_mon);//Uses a special custom func to get the amount of days in the month leading to said month.     
        daysL = yearL + mmL;

        return daysL != daysR;//Returns the comparison result.
    }

    istream& operator>>(istream& is, Date& RO) {
        return RO.read(is);
    }



}
