Name: Ryan Russell
UIN: 227006614
Section: CSCE 121-530
Username: rhrussell
Email: rhrussell@tamu.edu

I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
Ryan Russell	12/1/19

1. Make a Cookie class which represents a Christmas Cookie which has the following included:
- a default constructor: creates a cookie of random type and size which both are pulled from enum
classes CookieType and CookieSize
- constructor that takes in type and size - creates a cookie with a predetermined type and size from 
enum classes CookieType and CookieSize
- get_type(): returns the type of a cookie
- get_size(): returns the size of a cookie
- overloading the == operator: returns true if both cookies have the same type and size and returns false
if otherwise
- overloading the << operator: prints out the contents of a cookie

2. Make an abstract class Basket which uses the Cookie class (holds the cookies of different types
and sizes) which has the following:
- add_cookie(): adding a cookie to the basket
- is_in_basket(const Cookie& c): checks to see if a cookie with a given type and size is in the basket
- remove_any_cookie(): removes and returns a random cookie from the basket
- remove_cookie(const Cookie& c): removes a specific cookie with a given type and size from the basket
- clear_basket(): removes all content from basket
- is_basket_empty(): checks to see if basket is empty and returns true if it is false otherwise
- cookie_total(): returns the total number of cookies in basket
- cookie_size_total(Cookie::CookieSize s): returns the total number of cookies in a basket that
have a specified size
- cookie_type_total(Cookie::CookieType t): returns the total number of cookies in a basket that
have a specified type
- print_cookies(): prints out all the cookies and their contents from a basket in order by size

3. Make a child class Basket_Vector that implements all the functions in the Basket Class with
respect to how a C++ STL vector works

4. Make a child class Basket_LinkedList that implements all the functions in the Basket Class with
respect to how a C++ STL linked list works

5. Add these functions to the classes Basket, Basket_Vector, and Basket_LinkedList and provide
implementation with respect to the data structure of the class
- copy_basket(const Basket& basket): makes a copy of a basket into another basket
- merge_baskets(const Basket& basket1, const Basket& basket2): combines two baskets into a new third
basket without changing the contents of the two original baskets
- intersect_baskets(const Basket& basket1, const Basket& basket2): creates a third basket which contents
includes cookies of the same type and size that are apart of the two baskets without changing the contents
of the two baskets
- difference_baskets(const Basket& basket1, const Basket& basket2): creates a third basket that contains
cookies that are in the first basket but not in the second basket without changing the content of both 
baskets

6a. Created two basket objects and filled them with cookies from an input file
 b. Printed the baskets out and the number of cookies with a specific type and the total number of cookies
in both individual basket
 c. Created a third object that was the union of the two baskets from (a). Printed out that basket and 
the number of cookies with a specific type and the total number of cookies in the basket
 d. Printed the basket that intersects the first and second basket
 e. Printed the basket which is the difference of the first and second basket

Number 6 was repeated a second time so that both Basket_Vector and Basket_LinkedList classes
were used and shown in the main().

For testing out my program, I would write a couple of lines at a time and then test the output
of the function or part of the program I was working on to see if it would for one compile and 
two output anything.