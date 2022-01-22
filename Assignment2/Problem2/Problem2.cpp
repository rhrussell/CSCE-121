/*  Author: Ryan Russell
    Date: 9/9/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 2: Problem 2 - Prints a letter based off inputs that user provides
*/

#include <iostream>
using namespace std;

int main()
{
    string first_name;
    string friend_name;
    char friend_sex = 0;
    int age;

    //cout << "Enter first name: ";
    //cin >> first_name;
    //cout << "Hello, " << first_name << endl;

    cout << "Enter the name of the person you want to write to: ";
    cin >> first_name;
    cout << "Dear " << first_name << "," << endl;

    cout << "   How have you been? Hope all is going well with you." << endl;

    cout << "Enter the name of another friend: ";
    cin >> friend_name;
    cout << "I am doing fine. Have you seen " << friend_name << " lately?" << endl;

    cout << "Enter friend's gender (m for male, f for female): ";
    cin >> friend_sex;

    if(friend_sex == 'm')
    {
        cout << "If you see " << friend_name << " please ask him to call me." << endl;
    }
    if(friend_sex == 'f')
    {
        cout << "If you see " << friend_name << " please ask her to call me." << endl;
    }

    cout << "Enter the age of the recipient: ";
    cin >> age;
    cout << "I hear you just had a birthday and you are " << age << " years old." << endl;
    if(age <= 0 || age >= 110)
    {
        cout << "You're kidding!" << endl;
    }
    if(age < 12)
    {
        cout << "Next year you will be " << age + 1 << "." << endl;
    }
    if(age == 17)
    {
        cout << "Next year you will be able to vote." << endl;
    }
    if(age > 70)
    {
        cout << "I hope you are enjoying retirement." << endl;
    }
    cout << "Yours sincerely," << endl << endl << endl;
    cout << "Ryan Harrison Russell";
}