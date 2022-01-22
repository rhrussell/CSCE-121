#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Bad_Token{};

void error(const string& errorMessage)
{
    cerr << errorMessage << endl;
    throw runtime_error(errorMessage);
}

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
        kind('n'), value(i) {}
};

class Token_stream
{
    public:
        Token get();
        void putback(Token);
        Token_stream();
    private:
        bool full;
        Token buffer;
};

Token_stream::Token_stream() : full(false), buffer(0) {}

Token Token_stream::get()
{
    if(full)
    {
        full = false;
        return buffer;
    }

    char c;
    cin >> c;

    switch(c)
    {
        case '(': case ')': case ';': case 'q': case '+': case '-': case '*': case '/':
            return Token(c);
        case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            cin.putback(c);
            double val;
            cin >> val;
            return Token('n', val);
        default:
            cout << "Error Bad Token: " << c << endl;
            throw Bad_Token();
    }
}

void Token_stream:: putback(Token t)
{
    if(full)
    {
        error("putback() into a full buffer");
    }
    buffer = t;
    full = true;
}

Token_stream ts;

double expression();
double term();
double primary();

double expression()
{
    double left = term();
    while(true)
    {
        Token t = ts.get();
        switch(t.kind)
        {
            case '+': 
                cout << "+";
                left += term();
                break;

            case '-': 
                cout << "-";
                left -= term();
                break;

            default: 
                ts.putback(t);
                return left;
        }
    }
}

double term()
{
    double left = primary();
    while(true)
    {
        Token t = ts.get();
        switch(t.kind)
        {
            case '*': 
                cout << "*";
                left *= primary();
                break;

            case '/': 
                cout << "/";
                left /= primary();
                break;

            default: 
                ts.putback(t);
                return left;
        }
    }
}

double primary()
{
    Token t = ts.get();
    switch(t.kind)
    {
        case '(':
        {
            cout << "(";
            double i = expression();
            t = ts.get();
            cout << ")";
            if(t.kind != ')')
            {
                error("')' expected");
            }
            return i;
        }
        case 'n':
            cout << t.value;
            return t.value;
        case 'q': case ';':
            return 0;
        default: 
            error("Primary Expected"); 
    }
}

int main()
{
    try
    {
        double val = 0;
        try
        {
            cout << "Enter an expression: " << endl;  
            while(cin)
            {
                Token t = ts.get();
                if(t.kind == 'q')
                {
                    break;
                }
                else if(t.kind == ';')
                {
                    cout << "=" << val << endl;
                }
                else
                {
                    ts.putback(t);
                }
                
                val = expression();
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
    catch(Bad_Token)
    {
        cout << "Error: Bad Token" << endl;
    }
    catch(runtime_error& e)
    {
        cerr << e.what() << endl;
    }
}