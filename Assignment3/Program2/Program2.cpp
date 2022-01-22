/*  Author: Ryan Russell
    Date: 9/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 3: Program 2 -  writing a function that will print out pyramid of numbers
*/

#include <iostream>
using namespace std;

void print_pyramid(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int k = n; k >= i; k--)
        {
            cout << "   ";
        }
    
        for(int k = i; k >= 1; --k)
        {
            if(k >= 10)
            {
                cout << k << " ";
            }

            else if(1 < k < 10)
            {
                cout << k << "  ";
            }

        }

        for(int k = 2; k <= i; ++k)
        {
            if(k >= 10)
            {
                cout << k << " ";
            }
            else if(1 < k < 10)
            {
                cout << k << "  ";
            }
        }

        cout << endl;
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        int num = 0;
        cout << "Enter a number: ";
        cin >> num;
        print_pyramid(num);
    }
}