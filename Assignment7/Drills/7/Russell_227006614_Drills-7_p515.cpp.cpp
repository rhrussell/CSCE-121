/*  Author: Ryan Russell
    Date: 11/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 7 Drill 7: focuses on inheritance, virtual functions, and pure virtual functions
*/

#include <iostream>
using namespace std;

class B2
{
    public:
        virtual void pvf() = 0;
};

class D21: public B2
{
    
    string str = "I'm from D21.";

    public:
        void pvf() override
        {
            cout << str << endl;
        }
};

class D22: public B2
{
    int i = 22;

    public:
        void pvf() override
        {
            cout << i << endl;
        }
};

void f(B2& obj)
{
     obj.pvf();
}

int main()
{
    D21 obj;
    f(obj);
    D22 derObj;
    f(derObj);
}