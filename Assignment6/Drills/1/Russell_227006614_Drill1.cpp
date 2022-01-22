/*  Author: Ryan Russell
    Date: 10/21/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 6: Drill 1 - produces sum of numbers in a file of whitespace-seperated ints
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream file;
    file.open("numbers.dat", ios::in);

    int i;
    int j = 0;
    int sum = 0;
    int data[10];
    
    while(file >> i)
    {
        data[j] = i;
        j++;
    }
    file.close();
    for(int i = 0; i < 10; i++)
    {
        sum += data[i];
    }

    cout << sum;
}