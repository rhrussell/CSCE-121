/*  Author: Ryan Russell
    Date: 11/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 6 Drill 2: creates a file of data in the form of Reading defined type
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Reading
{
    int hour;
    double temperature;
};

int main()
{
    fstream file;
    vector<Reading> temps;
    int hour;
    double temperature;
    string name = "raw_temps.txt";
    file.open(name, fstream::out);
    for(int i = 0; i < 50; i++)
    {
        //cin >> hour >> temperature;
        hour = rand() % 23;
        temperature = rand() % 101;

        if(hour < 0 || 23 < hour)
        {
            perror("hour out of range");
        }
        else
        {
            temps.push_back(Reading{hour,temperature});
        } 
    }

    ofstream ost{name};

    for(int i = 0; i < temps.size(); ++i)
    {
        ost << temps.at(i).hour << " " << temps.at(i).temperature << endl;
    }

    file.close();
}