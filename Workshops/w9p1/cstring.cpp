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


#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <cstdio>
#include "cstring.h"

namespace sdds {
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		int i = 0;
		char null = '\0';
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = null;
	}

	void strnCpy(char* des, const char* src, int len)
	{
		int i = 0;

		for (i = 0; i < len; i++)
		{
			des[i] = src[i];
		}
	}

	int strCmp(const char* s1, const char* s2)
	{
		int i = 0, a = 0, b = 0;
		for (i = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] == s2[i])
			{
				a++; //a is counter for 1st string
				b++; //b is counter for second
			}

			if (s1[i] != s2[i])
			{
				if (s1[i] > s2[i]) //compares ascii value to determine what happens to a 
				{
					a++;
				}
				else
				{
					a--;
				}

			}


		}

		if (a == b) //depending on the value of a, s1 is either equal to s2 so itll return 0 or 1 if the ascii value is more than s2
		{
			return 0;
		}
		else if (a > b)
		{
			return 1;
		}

		return -1;//if didnt pass any test than the ascii value is lower
	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i = 0, a = 0, b = 0;
		for (i = 0; i < len; i++)
		{
			if (s1[i] == s2[i])
			{
				a++; //a is counter for 1st string
				b++; //b is counter for second
			}

			if (s1[i] != s2[i])
			{
				if (s1[i] > s2[i]) //compares ascii value to determine what happens to a 
				{
					a++;
				}
				else
				{
					a--;
				}

			}


		}

		if (a == b) //depending on the value of a, s1 is either equal to s2 so itll return 0 or 1 if the ascii value is more than s2
		{
			return 0;
		}
		else if (a > b)
		{
			return 1;
		}

		return -1;//if didnt pass any test than the ascii value is lower

	}

	int strLen(const char* s)
	{
		int i = 0, c = 0;
		for (i = 0; s[i] != 0; i++)
		{
			c++; //counter for s
		}
		return c;
	}
	const char* strStr(const char* str1, const char* str2)
	{
		int i = 0, str1Count = 0, str2Count = 0;
		int d = 0, match = 0, e = 0, holder = 0, a = 0;

		str1Count = static_cast<int>(strLen(str1));
		str2Count = static_cast<int>(strLen(str2));

		for (i = 0; i < str1Count; i++)
		{
			match = 0;
			if (str1[i] == str2[0])
			{

				d = i;//will hold the position to start matching str2
				for (e = 0; e < str2Count; e++)//e is the iterator for str2, required for the inner for loop
				{
					if (str1[d] == str2[e])
					{
						match++;//using match to see if the letters all match. If so then the value of str2 and match will be the same
					}
					d++;
				}
				if (match == str2Count)
				{
					if (holder == 0)
					{
						holder = match;
						if (a == 0)
						{
							a = i; //will hold the value of the first occurence of the first char in str2 so if everything goes well this will be used to present the address to return
						}
					}


				}
			}
		}


		if (holder == str2Count)
		{
			return &str1[a];
		}

		return nullptr;
	}


	void strCat(char* des, const char* src)
	{
		int i = 0, srcLen = 0, desLen = 0;

		desLen = static_cast<int>(strLen(des));
		srcLen = static_cast<int>(strLen(src));


		for (i = 0; src[i] != '\0'; i++)
		{
			des[desLen] = src[i];//using deslen as the element for des, will start the concat process at the very end
			desLen++;
			if (i == srcLen - 1)//using this statement will determine the end of the string, which will ultimately help put a null terminator to stop any unwanted behaviours
			{
				des[desLen] = '\0';
			}
		}

	}
}









