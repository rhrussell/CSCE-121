/*  Author: Ryan Russell
    Date: 10/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 4 Program 2: using recursion to convert decimal numbers to octal form
*/

#include <iostream>
using namespace std;

int decimal_to_octal(int decimal)
{
    if(decimal < 0)
    {
        cout << "Must be a non-negative integer" << endl;
    }

    else if(decimal == 0)
    {
        cout << 0;
        return decimal;
    }

    else
    {
        return (decimal % 8 + 10 * decimal_to_octal(decimal/8));
    }
}

int main()
{
    cout << decimal_to_octal(56);
}