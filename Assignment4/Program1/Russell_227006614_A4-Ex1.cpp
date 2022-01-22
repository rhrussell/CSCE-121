/*  Author: Ryan Russell
    Date: 10/4/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 4 Program 1: learning how to implement the fibnacci sequence for different variable types
*/

#include <iostream>
using namespace std;

int fibonacciInt(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacciInt(n-1) + fibonacciInt(n-2);
    }
}

long fibonacciLong(int n)
{
    if(n == 0 || n == 1)
    {
        return (long)n;
    }
    else
    {
        return (long)fibonacciLong(n-1) + (long)fibonacciLong(n-2);
    }
}

long long fibonacciLongLong(int n)
{
    if(n == 0 || n == 1)
    {
        return (long long)n;
    }
    else
    {
        return (long long)fibonacciLongLong(n-1) + (long long)fibonacciLongLong(n-2);
    }
}

int main()
{
    int counter = 0;
    do
    {
        fibonacciInt(counter);
        counter++;
    } while (fibonacciInt(counter) >= 0);
    cout << "Largest Number: " << fibonacciInt(counter-1) << endl;
    cout << "Amount of Fibonacci Numbers that fit in type int: " << counter << endl;

    long counterLong = 0L;
    do
    {
        fibonacciLong(counterLong);
        counterLong++;
    } while (fibonacciLong(counterLong) >= 0);
    cout << "Largest Number: " << fibonacciLong(counterLong-1) << endl;
    cout << "Amount of Fibonacci Numbers that fit in type long: " << counterLong << endl;

    long long counterLongLong = 0LL;
    do
    {
        fibonacciLongLong(counterLongLong);
        counterLongLong++;
    } while (fibonacciLongLong(counterLongLong) >= 0);
    cout << "Largest Number: " << fibonacciLongLong(counterLongLong-1) << endl;
    cout << "Amount of Fibonacci Numbers that fit in type long long: " << counterLongLong << endl;
}