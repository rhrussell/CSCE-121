/*  Author: Ryan Russell
    Date: 11/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 6 Program 1: reads a text file and converts it all lower case
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{   
    string name = "file.txt";
    ifstream text;
    fstream newF;
    char ch;
    string temp;
    string sentence;
    string newSentence;
    //vector<string> sent;
    //vector<string> newSent;

    text.open(name);
    while(!text.eof())
    { 
        text >> temp;
        //sent.push_back(temp);
        sentence += temp;
        sentence += " ";
    }
    for(int i = 0; i < sentence.length(); i++)
    {
        ch = sentence.at(i);
        ch = tolower(ch);
        newSentence += ch;
    }

    //cout << newSentence;
    string newName = "newFile.txt";
    newF.open(newName, fstream::out);
    ofstream ost {newName};

    for(int i = 0; i < newSentence.length(); i++)
    {
        ch = newSentence.at(i);
        ost << ch;
    }

    newF.close();
}