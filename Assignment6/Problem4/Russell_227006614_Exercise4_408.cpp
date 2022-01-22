/*  Author: Ryan Russell
    Date: 11/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 6 Program 4: converts octal and hexidecimal numbers into decimal
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    string number = "";
    string newnum;
    string temp;
    int size;
    int num;
    int total = 0;

    
    while(number != "q")   
    {
        cout << "Enter a number" << endl;
        cin >> number;
        if(number.at(0) == '0')
        {
            if(number.at(1) == 'x')
            {
                newnum = number.substr(2);
                size = newnum.size();
                for(int i = 0; i < size; i++)
                {
                    temp = newnum.at(i);
                    num = stoi(temp);
                    total += num * pow(16, size - i - 1);
                }
                cout << number << " hexidecimal " << "converts to " << total << " decimal" << endl;
            }
            else
            {
                newnum = number.substr(1);
                size = newnum.size();
                for(int i = 0; i < size; i++)
                {
                    temp = newnum.at(i);
                    num = stoi(temp);
                    total += num * pow(8, size - i - 1);
                }
                cout << number << " octal " << "converts to " << total << " decimal" << endl;
            }
        }
        else if(number == "q")
        {
            break;
        }
        else
        {
            cout << number << " decimal " << "converts to " << number << " decimal" << endl;
        }

        total = 0;
    }
}