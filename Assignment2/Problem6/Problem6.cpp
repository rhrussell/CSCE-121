/*  Author: Ryan Russell
    Date: 9/9/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 2: Problem 6 - Printing a number pyramid
*/

#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    
    for(int i = 1; i <= num; i++)
    {
        for(int k = num; k >= i; k--)
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
/*cout << "         1";
cout << "       2 1 2";
cout << "     3 2 1 2 3";
cout << "   4 3 2 1 2 3 4";
cout << " 5 4 3 2 1 2 3 4 5";*/