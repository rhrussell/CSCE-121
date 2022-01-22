Name: Ryan Russell
UIN: 227006614
Section: CSCE-121-530
Username: rhrussell
Email: rhrussell@tamu.edu

I certify that I have listed all the sources that I used to develop the solutions
and code to the submitted work.
On my honor as an Aggie, I have neither given nor received any
unauthorized help on this academic work.

Ryan Russell	10/17/2019

Demo: This program focused on developing the actual structure Token to be used
in later programs. It prints the value and the kind of each individual token in
the input.

Part 1: This program adds more to the program we wrote for in the demo part of
the assignment. This part of the program adds three seperate functions that deal
with three seperate groups of tokens. It also throws an exception Bad_Token whenever
an invalid token is used.

This version of the calculator program is wrong because it only prints out the 
first digit of the expression. It can be fixed by creating a place where all the
tokens are stored and then used when needed.

Part 2: This program takes off where Part 1 left off and corrects the mistakes
the previous program had. This program adds a place where all the tokens are stored
and creates a function which puts them there.

The token buffer was created with the help of the C++ library. We need to use the 
putback() function in the token stream to evaluate the expression correctly because
it makes sure all the tokens are in one place so that when the expression is done,
the expression can be fully evaluated.