/*  Author: Ryan Russell
    Date: 9/9/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 2: Problem 3 - Printing off names of TA and PT's
*/

#include <iostream>
using namespace std;

int main()
{
    string my_first_name;
    string my_last_name;
    int section_number = 0;
    string TA_first_name;
    string TA_last_name;
    string PT1_first_name;
    string PT1_last_name;
    string PT2_first_name;
    string PT2_last_name;

    cout << "Enter your first name and last name, and the section number: ";
    cin >> my_first_name >> my_last_name >> section_number;
    
    for(int i = 0; i < 3; i++)
    {
        if(i == 0)
        {
            cout << "Enter your TA's first name and last name: ";
            cin >> TA_first_name >> TA_last_name;
        }
        else if(i == 1)
        {
            cout << "Enter your PT's first name and last name: ";
            cin >> PT1_first_name >> PT1_last_name;
        }
        else
        {
            cout << "Enter your PT's first name and last name: ";
            cin >> PT2_first_name >> PT2_last_name;
        }
        
    }
    cout << my_first_name << " " << my_last_name << " " << section_number << endl;
    cout << section_number << " TA: " << TA_first_name << " " << TA_last_name << endl;
    cout << section_number << " PT: " << PT1_first_name << " " << PT1_last_name << endl;
    cout << section_number << " PT: " << PT2_first_name << " " << PT2_last_name << endl;
}