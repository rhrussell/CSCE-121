/*  Author: Ryan Russell
    Date: 11/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 7 Drills 1-6: focuses on inheritance, virtual functions, and pure virtual functions
*/

#include <iostream>
using namespace std;

class B1
{
    public:

        virtual void pvf() = 0;

        virtual void vf()
        {
            cout << "B1::vf()" << endl;
        }

        void f()
        {
            cout << "B1::f()" << endl;
        }
};

class D1: public B1
{
    public:
        void pvf()
        {
            cout << "D1::pvf()" << endl;
        }
        void vf() override
        {
            //override;
            cout << "D1::vf()" << endl;
        }

        void f()
        {
            cout << "D1::f()" << endl;
        }
};

class D2: public D1
{
    public:
        void pvf() override
        {
            cout << "D2::pvf()" << endl;
        }
};


int main()
{
    //Drills 1-4

    /*B1 obj;
    D1 derObj;
    B1& refObj = derObj;
    obj.vf();
    obj.f();
    derObj.vf();
    derObj.f();
    refObj.vf();
    refObj.f();
    */

    //Drill 5-6

    D2 derDerObj;
    derDerObj.f();
    derDerObj.vf();
    derDerObj.pvf();
}