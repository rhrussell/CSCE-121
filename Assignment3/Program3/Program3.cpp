/*  Author: Ryan Russell
    Date: 9/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 3: Program 3 -  working with functions that have the same purpose but have different return types
*/

#include <iostream>
using namespace std;

int minInt(int a, int b)
{
    if(a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int minChar(char a, char b)
{
    int aNum = int(a);
    int bNum = int(b);

    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <typename T>
T minObj(T a, T b)
{
    if(a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    cout << "The larger for integer for 10 and 15 is: " << minInt(10,15) << endl;
    cout << "The larger for integer for 12345 and 12344 is: " << minInt(12345, 12344) << endl;
    cout << "The larger for character for A and c is: " << minChar('A', 'c') << endl;
    cout << "The larger for double for 1.75 and 1.80 is: " << minObj(1.75, 1.80) << endl;
    cout << "The larger for float for 1077.72 and 1999.34 is: " << minObj(1077.72f, 1999.34f) << endl;
}