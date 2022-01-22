#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Reading
{
    int hour;
    string temperature;
};

int main()
{
    string name = "raw_temps.txt";
    int hour;
    string temperature;
    string newTemp;
    double temp;
    ifstream ist;
    ist.open(name);
    //file.open("raw_temps.txt");
    vector<Reading> temps;
    for(int i = 0; i < 50; i++)
    {
        ist >> hour >> temperature;
        if(temperature.at(temperature.length()-1) == 'c')
        {
            newTemp = temperature.substr(0,temperature.length()-1);
            temp = stod(newTemp);
            temp = (temp*1.8) + 32;
            temperature = to_string(temp);
            temperature += "f";
            temps.push_back(Reading{hour, temperature});
        }
        else
        {
            temps.push_back(Reading{hour, temperature});
        }
        
    }
    //cout << temps.at(40).hour << " " << temps.at(40).temperature;
    double mean;
    double sum;
    double median;
    double size = temps.size();
    vector<double> tempsMed;
    for(int i = 0; i < temps.size(); i++)
    {
        newTemp = temps.at(i).temperature;
        newTemp = newTemp.substr(0, newTemp.length()-1);
        //cout << newTemp << endl;
        temp = stod(newTemp);
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