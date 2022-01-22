#include <iostream>
using namespace std;

class Bad_Token{};

struct Token
{
    char kind;
    double value;

    /*Token(char c)
    {
        kind = '0';
        value = 0;
    } 
    Token(char c, double d)
    {
        kind = 'n';
        this->value = d;
    }*/
    Token(char c):
        kind(c), value(0) {}

    Token(char c, double i):
        kind(c), value(i) {}
};

Token get_token()
{ 
    char c;
    int num = 0;

    cin >> c;

    switch(c)
    {
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(c);
        case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            cin.putback(c);
            cin >> num;
            return Token('n', num);

        default:
            throw Bad_Token();
    }
}

double expression();
double term();
double primary();


double expression()
{
    double left = term();
    while(true)
    {
        Token t = get_token();
        switch(t.kind)
        {
            case '+': 
                left += term();
                break;

            case '-': 
                left -= term();
                break;

            default: 
                return left;
        }
    }
}

double term()
{
    double left = primary();
    while(true)
    {
        Token t = get_token();
        switch(t.kind)
        {
            case '*': 
                left *= primary();
                break;

            case '/': 
                left /= primary();
                break;

            default: 
                return left;
        }
    }
}

double primary()
{
    Token t = get_token();
    switch(t.kind)
    {
        case '(':
        {
            double i = expression();
            t = get_token();
            if(t.kind != ')')
            {
                perror("')' expected");
                return i;
            }
        }
        case 'n':
            return t.value;
        default:
            perror("primary expected");
            return 0;
    }
}

int main()
{
    try
    {
        double val = 0;
        while(cin)
        {
            double i = expression();
            cout << i << endl;
        }
    }
    catch(Bad_Token)
    {
        cout << "Error: Bad Token" << endl;
    }
    catch(runtime_error& e)
    {
        cerr << e.what() << endl;
    }
}