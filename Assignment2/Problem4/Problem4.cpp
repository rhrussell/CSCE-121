/*  Author: Ryan Russell
    Date: 9/9/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 2: Problem 4 - Using function to guess a number
*/

#include <iostream>
using namespace std;

bool guess_number()
{
    int min = 1;
    int max = 64;
    int middle = 0;
    middle = (max+min)/2;
    string answer = "";
    while(answer != "yes" || answer != "Yes")
    {
        cout << "Is your number " << middle << "? ";
        cin >> answer;
        if(answer == "higher" || answer == "Higher")
        {
            min = middle;
            middle = (max + min)/2;
        }
        else if(answer == "lower" || answer == "Lower")
        {
            max = middle;
            middle = (max + min)/2;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        int num = 0;
        cout << "Enter a number: ";
        cin >> num;
        bool guess = false;

        guess = guess_number();
        if(guess == true)
        {
            cout << "You got it!";
        }
        else
        {
            cout << "Did not get it";
        }
        cout<<endl;
    }
}
