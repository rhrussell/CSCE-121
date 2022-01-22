/*  Author: Ryan Russell
    Date: 11/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 7 Problem 4: copies a C style string into memory allocating on the free store
*/


#include <iostream>
using namespace std;

char* strdup(const char* old)
{

    int n = 0;
    while(old[n])
    {
        ++n;
    }
    n += 1;

    const int len = n;

    char* newChar = new char[len];

    for (int i = 0; i < len; ++i)
    {
        newChar[i] = old[i];
    }

    return newChar;
}

int main()
{
    char csold[] = "Hello World!";

    char* csnew = strdup(csold);

    for (int i = 0; i < csnew[i]; ++i)
    {
        cout << csnew[i];
    }

    cout << endl;
}