/*  Author: Ryan Russell
    Date: 11/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 6 Drill 3: reads the data from a file and calculates the mean and median from the data
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Reading
{
    int hour;
    double temperature;
};

int main()
{
    string name = "raw_temps.txt";
    int hour;
    double temperature;
    //string newTemp;
    double temp;
    ifstream ist;
    ist.open(name);
    //file.open("raw_temps.txt");
    vector<Reading> temps;
    for(int i = 0; i < 50; i++)
    {
        ist >> hour >> temperature;
        temps.push_back(Reading{hour, temperature});
    }
    //cout << temps.at(40).hour << " " << temps.at(40).temperature;
    double mean;
    double sum;
    double median;
    double size = temps.size();
    vector<double> tempsMed;
    for(int i = 0; i < temps.size(); i++)
    {
        temp = temps.at(i).temperature;
        sum += temp;
        //cout << temp << endl;
        tempsMed.push_back(temp);
    }
    mean = sum/size;
    sort(tempsMed.begin(), tempsMed.end());
    median = tempsMed.at(size/2);
    cout << "Mean: " << mean << " Median: " << median << endl;
    ist.close();
}