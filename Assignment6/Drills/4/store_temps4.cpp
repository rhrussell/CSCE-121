/*  Author: Ryan Russell
    Date: 11/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 6 Drill 4: converts celsius readings to fahrenheit while doing the same things from the previous programs.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

struct Reading
{
    int hour;
    string temperature;
};

int main()
{
    fstream file;
    vector<Reading> temps;
    int hour;
    double temp;
    string temperature;
    string name = "raw_temps.txt";
    file.open(name, fstream::out);
    for(int i = 0; i < 50; i++)
    {
        //cin >> hour >> temperature;
        hour = rand() % 24;
        temp = rand() % 101;
        temperature = to_string(temp);
        if(i % 5 == 0)
        {
            temperature += "f";
        }
        else
        {
            temperature += "c";
        }
        
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