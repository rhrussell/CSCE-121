/*  Author: Ryan Russell
    Date: 11/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 6 Program 7: replaces punctuation with whitespace and replaces with contractions with the full words
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string line;
    string newNewLine;
    string newLine;
    char ch;
    int len;

    cout << "Enter a string" << endl;
    getline(cin, line);
    len = line.size();

    for(int i = 0; i < len; i++)
    {
        ch = line.at(i);
        if(ch == '.'  || ch == ';' || ch == ',' ||  ch == '?' || ch == ':' || ch == '/' || ch == '!')
        {
            newLine += " ";
        }
        else if(ch == '-')
        {
            if(0 < i < len - 1)
            {
                if(!isalpha(line.at(i-1)) && !isalpha(line.at(i+1)))
                {
                    newLine += " ";
                }
                else
                {
                    newLine += "-";
                } 
            }
            else
            {
                newLine += " ";
            }   
        }
        else if(isupper(ch))
        {
            newLine += tolower(ch);
        }
        else
        {
            newLine += ch;
        }
    }
    //cout << newLine << endl;

    istringstream iss (newLine);
    vector<string> words;
    do
    {
        string word;
        iss >> word;

        words.push_back(word);
    } while (iss);
    
    for(int i = 0; i < words.size(); i++)
    {
        //cout << words.at(i) << endl;
        if(words.at(i) == "don't")
        {
            newNewLine += "do not";
        }
        else if(words.at(i) == "can't")
        {
            newNewLine += "can not";
        }
        else if(words.at(i) == "aren't")
        {
            newNewLine += "are not";
        }
        else if(words.at(i) == "didn't")
        {
            newNewLine += "did not";
        }
        else if(words.at(i) == "hadn't")
        {
            newNewLine += "had not";
        }
        else if (words.at(i) == "won't")
        {
            newNewLine += "will not";
        }
        
        else
        {
            newNewLine += words.at(i);
        }
        
        newNewLine += " ";
    }

    cout << newNewLine << endl;
}