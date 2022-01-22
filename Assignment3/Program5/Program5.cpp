/*  Author: Ryan Russell
    Date: 9/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 3: Program 5 -  getting a number from birthdate and learning how to throw errors based on conditions
*/

#include <iostream>
#include <string>
using namespace std;

class InvalidInput{};

void birthdate(int month, int day, int year)
{
    if((year < 1000) || (1 > day) || (day > 31) || (1 > month) || (12 < month) || cin.fail())
    {
       throw InvalidInput();
    }
}

int main()
{
    int month = 0;
    int day = 0;
    int year = 0;
    //bool valid = false;
    cout << "Enter birthdate(month day year): " << endl;
    cin >> month >> day >> year;

    /*do
    {
        try
        {
            birthdate(month, day, year);
            valid = true;
        }
        catch(InvalidInput)
        {
            cout << "Wrong Format. Enter the birthdate again. " << endl;
            valid = false;
        }   
    } while (valid == false);*/
    try
    {
        birthdate(month, day, year);
    }
    catch(InvalidInput)
    {
        cout << "Wrong Format. Enter the birthdate again. " << endl;
    }

    int num = 0;
    int sum = 0;
    string mm = "";
    string dd = "";
    string yyyy = "";
    string mmddyyyy = "";
    mm = to_string(month);
    dd = to_string(day);
    yyyy = to_string(year);
    mmddyyyy = mm + dd + yyyy;

    while(num < 1 || num >= 10)
    { 
        for(int i = 0; i < mmddyyyy.length(); i++)
        {
            char n = mmddyyyy.at(i);
            sum += (int)n - 48;
            //cout << sum;
        }
        num = sum;
        //cout << num;
        if(num >= 10)
        {
           mmddyyyy = to_string(sum); 
           sum = 0;
        }
    }   
    cout << num << endl;
    if(num == 1)
    {
        cout << "The Leader: original thinker, creative, confident, honest" << endl;
    }
    else if(num == 2)
    {
        cout << "The Mediator: diplomatic, adaptability, credibility, self-control" << endl;
    }
    else if(num == 3)
    {
        cout << "The Communicator: expressibe, considerate, passionate, respect" << endl;
    }
    else if(num == 4)
    {
        cout << "The Teacher: trustworthy, listener, approachable, caring" << endl;
    }
    else if(num == 5)
    {
        cout << "The Freedom Seeker: adventurous, independent, optimistic, committed" << endl;
    }
    else if(num == 6)
    {
        cout << "The Nurturer: family-oriented, emotional, avoid confrontation, expressive" << endl;
    }
    else if(num == 7)
    {
        cout << "The Seeker: analytic, driven, patient, perseverant" << endl;
    }
    else if(num == 8)
    {
        cout << "The Power House: authoritative, realistic, loyal, assertive" << endl;
    }
    else if(num == 9)
    {
        cout << "The Humanitarian: charitable, goal-oriented, decisive, open-minded" << endl;
    }
}