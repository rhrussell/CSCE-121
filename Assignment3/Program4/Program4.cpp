/*  Author: Ryan Russell
    Date: 9/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 3: Program 4 - using a function and switch statement to show how many roots are in a quadratic function
*/

#include <iostream>
using namespace std;

int compute_roots(double a, double b, double c, double& x1, double& x2)
{
    //double x1 = (-b + (b^2-4*a*c)^(1/2))/(2*a);
    //double x2 = (-b - (b^2-4*a*c)^(1/2))/(2*a);

    if(a == 0 && b != 0)
    {
        return 0;
    }

    else if(a == 0 && b == 0 && c != 0)
    {
        return 0;
    }

    else if(a == 0 && b == 0 && c == 0)
    {
        return 3;
    }

    else if(a != 0)
    {
        double disc = b*b-4*a*c;
        if(disc >= 0)
        {
            if(disc == 0)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            return 4;
        }
    }
}

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double X1 = 0;
    double X2 = 0;
    //double& x1 = X1;
    //double& x2 = X2;

    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "Enter c: " << endl;
    cin >> c;

    
    int nroots = 0;
    nroots = compute_roots(a, b, c, X1, X2);
    
    switch(nroots)
    {
        case 0:
            cout << "No Roots." << endl;
            break;
        case 1:
            cout << "One Root." << endl;
            break;
        case 2:
            cout << "Two Real Roots." << endl;
            break;
        case 3:
            cout << "Infinite Number of Roots." << endl;
            break;
        case 4:
            cout << "No Real Roots." << endl;
            break;
    }
}