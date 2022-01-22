/*  Author: Ryan Russell
    Date: 11/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 7 Problem 3: replaces the uppercase characters in a C style string with lowercase equivalents
*/


#include <iostream>
using namespace std;

void to_lower(char* s)
{
    int asc;
    char ch;
    int size = 0;
    
    while (s[size] != '\0') 
    { 
        size++; 
    } 
    //cout << size << endl;

    for(int i = 0; i < size; i++)
    {
        //ch = s[i];
        asc = (int)s[i];
        //cout << ch << endl;
        if(65 <= asc && asc <= 90)
        {
            asc += 32;
            s[i] = (char)asc;
            //s[i] = ch;
        }
    }

    cout << s;
}

int main()
{
    char myString[] = "Hello, World!";
    to_lower(myString);
}