#include <iostream>
#include <vector>
using namespace std;

struct Token
{
    char kind;
    int value;

    Token(char ch): kind(ch), value(0) {}
    Token(char ch, int value): kind('n'), value(value) {}
};

int main()
{
    vector<Token> vec;
    //cout << t.kind << endl;
    //cout << t.value << endl;

    do
    {
        char ch;
        int value;
        cin >> ch;
        //cin >> value;
        if(isdigit(ch))
        {
            value = ch - 48;
            Token t(ch, value);
            vec.push_back(t);
        }
        else
        {
            Token t(ch);
            vec.push_back(t);
        }

        if(ch == 'q')
        {
            break;
        }  
    }
    while(cin);

    for(int i = 0; i < vec.size(); i++)
    {
        Token t = vec.at(i);
        cout << "kind: " << t.kind << endl;
        if(t.kind == 'n')
        {
            cout << "value: " << t.value << endl;
        }     
    }
}