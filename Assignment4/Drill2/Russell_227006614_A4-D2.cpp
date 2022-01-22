/*  Author: Ryan Russell
    Date: 10/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 4 Drill 2: learning about the difference in by passing and by reference with functions
*/

#include <iostream>
using namespace std;

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_cr(const int& a, const int& b)
{
    int temp;
    temp = a;
    //a = b; 
    //b = temp;
}

int main()
{
    int x = 7;
    int y = 9;
    swap_v(x,y);
    //swap_r(7,9); //swap_r has to have variables in order for the function to work since the arguments are reference variables
    const int cx = 7;
    const int cy = 9;
    swap_cr(cx,cy); //The whole point of having constants is to have a variable that you do not want to change
                    //Therefore, trying to swap constants will not work because they can not be changed.
    swap_v(7.7,9.9); //swap_r has to have variables in order for the function to work since the arguments are reference variables
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy); //swap_r does not work for doubles because the it only accepts integer arguments
    swap_cr(7.7,9.9); //swap_cr only accepts variables since the arguments must be reference variables
                      //Also cant swap constants since constants cannot be changed
}