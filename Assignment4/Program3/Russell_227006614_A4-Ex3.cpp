/*  Author: Ryan Russell
    Date: 10/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 4 Program 3: reversing the order of vectors using a regular function and recursion
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> a)
{
    vector<int> b;
    for(int i = a.size()-1; i >= 0; i--)
    {
        b.push_back(a.at(i));
    }
    
    return b;
}

void reverseRecur(vector<int> &a, int first, int end)
{
    if(first <= end)
    {
        int temp = a.at(first);;
        a.at(first) = a.at(end);
        a.at(end) = temp;
        reverseRecur(a, first + 1, end - 1);
    } 
}

int main()
{
    vector<int> orig = {1, 2, 3, 4, 5, 6};
    vector<int> rev;
    rev = reverse(orig);
    for(int i = 0; i < rev.size(); i++)
    {
        cout << rev[i] << " ";
    }
    cout << endl;
    int first = 0;
    int end = orig.size() - 1;
    reverseRecur(orig, first, end);
    for(int i = 0; i < orig.size(); i++)
    {
        cout << orig[i] << " ";
    }
}