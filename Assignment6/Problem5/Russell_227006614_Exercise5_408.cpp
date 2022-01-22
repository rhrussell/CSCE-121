/*  Author: Ryan Russell
    Date: 11/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 6 Program 5: outputs the character classification of each character in a string
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    char ch;
    int len;

    cout << "Enter a string" << endl;
    getline(cin, line);
    //cout << line << endl;
    len = line.size();
    //cout << len << endl;

    for(int i = 0; i < len; i++)
    {
        ch = line.at(i);
        cout << ch << " - ";
        if(isspace(ch))
        {
            cout << "Whitespace ";
        }
        if(isalpha(ch))
        {
            cout << "Letter ";
        }
        if(isdigit(ch))
        {
            cout << "Digit ";
        }
        if(isxdigit(ch))
        {
            cout << "Hexadecimal Digit ";
        }
        if(isupper(ch))
        {
            cout << "Uppercase Letter ";
        }
        if(islower(ch))
        {
            cout << "Lowercase Letter ";
        }
        if(isalnum(ch))
        {
            cout << "Alphanumeric ";
        }
        if(iscntrl(ch))
        {
            cout << "Control Character ";
        }
        cout << endl;   
    }
}