#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

enum CookieType {macadamia_nut_chocolate, walnut_chocolate_chunk, blackberry_galettes, white_chocolate_raspberry};
enum CookieSize {small, medium, large};

CookieType convertType(const string &str)
{
    if(str == "macadamia_nut_chocolate")
    {
        return macadamia_nut_chocolate;
    }
    else if(str == "walnut_chocolate_chunk")
    {
        return walnut_chocolate_chunk;
    }
    else if(str == "blackberry_galettes")
    {
        return blackberry_galettes;
    }
    else
    {
        return white_chocolate_raspberry;
    }   
}

CookieSize convertSize(const string &str)
{
    if(str == "small")
    {
        return small;
    }
    else if(str == "medium")
    {
        return medium;
    }
    else
    {
        return large;
    }
}

class Cookie
{
    public:
        Cookie()
        {
            type = CookieType(rand() % 4);
            size = CookieSize(rand() % 3);
        }

        Cookie(CookieType t, CookieSize s)
        {
            type = t;
            size = s;
        }
        
        CookieType get_type() const
        {
            return type;
        }

        CookieSize get_size() const
        {   
            return size;
        }

        bool operator==(const Cookie& c) const
        {
            if((c.type == this->type) && (c.size == this->size))
            {
                return true;
            }
            else
            {
                return false;
            }
        }     

    private:
        CookieType type;
        CookieSize size;
};

ostream& operator<<(ostream& os, const Cookie& cook)
{
    os << "(";

    switch(cook.get_type())
    {
        case 0:
            os << "macadamia_nut_chocolate";
            break;

        case 1:
            os << "walnut_chocolate_chunk";
            break;

        case 2:
            os << "blackberry_galettes";
            break;

        case 3:
            os << "white_chocolate_raspberry";
            break;
    }

    os << ", ";

    switch(cook.get_size())
    {
        case 0:
            os << "small";
            break;

        case 1:
            os << "medium";
            break;
                
        case 2:
            os << "large";
            break;
    }

    os << ")";

    return os;
}

class Basket
{
    public:
        virtual void add_cookie(const Cookie& c) = 0;
        virtual bool is_in_basket(const Cookie& c) const = 0;
        virtual Cookie remove_any_cookie() = 0;
        virtual void remove_cookie(const Cookie& c) = 0;
        virtual void clear_basket() = 0;
        virtual bool is_basket_empty() const = 0;
        virtual int cookie_total() const = 0;
        virtual int cookie_size_total(CookieSize s) const = 0;
        virtual int cookie_type_total(CookieType t) const = 0;
        virtual void print_cookies() const = 0;
        virtual vector<Cookie> get_vector() const = 0;
        virtual list<Cookie> get_list() const = 0;
        virtual void copy_basket(const Basket& basket) = 0;
        virtual void merge_baskets(const Basket& basket1, const Basket& basket2) = 0;
        virtual void intersect_baskets(const Basket& basket1, const Basket& basket2) = 0;
        virtual void difference_baskets(const Basket& basket1, const Basket& basket2) = 0;
};

class Basket_Vector : public Basket
{
    vector<Cookie> vec;
    list<Cookie> listCookies;

    public:        
        Basket_Vector(vector<Cookie> v)
        {
            vec = v;
        }

        void add_cookie(const Cookie& c)
        {
            vec.push_back(c);
        }

        bool is_in_basket(const Cookie& c) const
        {
            for(int i = 0; i < vec.size(); i++)
            {
                if(vec.at(i) == c)
                {
                    return true;
                }
            }
            return false;
        }

        Cookie remove_any_cookie()
        {
            int num;
            num = rand() % vec.size();
            CookieType type = vec.at(num).get_type();
            CookieSize size = vec.at(num).get_size();
            Cookie new_cookie(type, size);
            vec.erase(vec.begin() + num);

            return new_cookie;
        }

        void remove_cookie(const Cookie& c)
        {
            for(int i = 0; i < vec.size(); i++)
            {
                if(vec.at(i) == c)
                {
                    vec.erase(vec.begin() + i);
                }
            }
        }

        void clear_basket()
        {
            vec.clear();
        }

        bool is_basket_empty() const
        {
            if(vec.size() == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int cookie_total() const
        {
            int total;
            total = vec.size();
            return total;
        }

        int cookie_size_total(CookieSize s) const
        {
            int total = 0;

            for(int i = 0; i < vec.size(); i++)
            {
                if(vec[i].get_size() == s)
                {
                    total+=1;
                }
            }

            return total;
        }

        int cookie_type_total(CookieType t) const
        {
            int total = 0;
            for(int i = 0; i < vec.size(); i++)
            {
                if(vec[i].get_type() == t)
                {
                    total+=1;
                }
            }

            return total;
        }

        void print_cookies() const
        {
            if(vec.size() == 0)
            {
                cout << "This basket is empty!" << endl;
            }
            else
            {
                int i = 0;
                for(Cookie const &cook : vec)
                {
                    if(cook.get_size() == small)
                    {
                        cout << "Cookie " << i + 1 << " : " << cook << endl;
                        i++;
                    }
                }
                for(Cookie const &cook : vec)
                {
                    if(cook.get_size() == medium)
                    {
                        cout << "Cookie " << i + 1 << " : " << cook << endl;
                        i++;
                    }
                }
                for(Cookie const &cook : vec)
                {
                    if(cook.get_size() == large)
                    {
                        cout << "Cookie " << i + 1 << " : " << cook << endl;
                        i++;
                    }
                }
            }
        }

        vector<Cookie> get_vector() const
        {
            return vec;
        }

        list<Cookie> get_list() const
        {
            return listCookies;
        }

        /*
        Purpose: copies a full Basket_Vector object into an empty Basket_Vector object
        Arguments: basket is a Basket reference(in this case it is a Basket_Vector object)
        Precondition: argument basket must be of Basket_Vector
        PostCondition: basket object using the method is a copy of the argument basket*/
        void copy_basket(const Basket& basket)
        {
            vector<Cookie> v1;
            CookieType type;
             CookieSize size;
            v1 = basket.get_vector();
            this->clear_basket();
            int i = 0;
            while(i < v1.size())
            {
                type = v1.at(i).get_type();
                size = v1.at(i).get_size();
                Cookie cook(type, size);
                this->add_cookie(cook);
                i++;
            }
        }

        /*
        Purpose: combines two Basket_Vectors into a new Basket_Vector object
        Arguments: basket1 and basket2 are both Basket references(in this case both are Basket_Vector objects)
        Precondition: arguments basket1 and basket2 must be of Basket_Vector
        Postcondition: basket object using the method is the combination of the arguments basket1 and basket2*/
        void merge_baskets(const Basket& basket1, const Basket& basket2)
        {
            vector<Cookie> v1;
            vector<Cookie> v2;
            vector<Cookie> v3;
            v1 = basket1.get_vector();
            v2 = basket2.get_vector();
            this->clear_basket();
            int i = 0;
            while(i < v1.size())
            {
                CookieType type;
                CookieSize size;
                type = v1[i].get_type();
                size = v1[i].get_size();
                Cookie cook (type,size);
                this->add_cookie(cook);
                i++;
            }
            int j = 0;
            while(j < v2.size())
            {
                CookieType type;
                CookieSize size;
                type = v2[j].get_type();
                size = v2[j].get_size();
                Cookie cook (type,size);
                this->add_cookie(cook);
                j++;
            }
        }

        /*
        Purpose: creates a third Basket_Vector that contain cookies that are both in basket1 and basket2
        Arguments: basket1 and basket2 are both Basket references(in this case they are both Basket_Vector objects)
        Precondition: basket1 and basket2 must be both of Basket_Vector
        Postcondition: basket object using the method is the basket full of cookies both in basket1 and basket2*/
        void intersect_baskets(const Basket& basket1, const Basket& basket2)
        {
            vector<Cookie> v1;
            vector<Cookie> v2;
            CookieType type1;
            CookieSize size1;
            CookieType type2;
            CookieSize size2;
            v1 = basket1.get_vector();
            v2 = basket2.get_vector();
            this->clear_basket();
            for(int i = 0; i < v1.size(); i++)
            {
                type1 = v1[i].get_type();
                size1 = v1[i].get_size();
                Cookie cook1(type1,size1);
                
                if(basket2.is_in_basket(cook1) && basket1.is_in_basket(cook1))
                {
                    this->add_cookie(cook1);
                }
            }
        }

        /*
        Purpose: creates a third Basket_Vector that contain cookies that are in basket1 but not in basket2
        Arguments: basket1 and basket2 are both Basket references(in this case they are both Basket_Vector objects)
        Precondition: basket1 and basket2 must be both of Basket_Vector
        Postcondition: basket object using the method is the basket full of cookies that are in basket1 but not basket2*/
        void difference_baskets(const Basket& basket1, const Basket& basket2)
        {
            vector<Cookie> v1;
            vector<Cookie> v2;
            CookieType type1;
            CookieSize size1;
            CookieType type2;
            CookieSize size2;
            v1 = basket1.get_vector();
            v2 = basket2.get_vector();
            this->clear_basket();
            for(int i = 0; i < v1.size(); i++)
            {
                type1 = v1[i].get_type();
                size1 = v1[i].get_size();
                Cookie cook1(type1,size1);
                
                if(!(basket2.is_in_basket(cook1)))
                {
                    this->add_cookie(cook1);
                }
            }
        }
};

class Basket_LinkedList : public Basket
{
    list<Cookie> listCookies;
    list<Cookie>::iterator itr;
    list<Cookie>::iterator itrNext;
    vector<Cookie> vec;

    public:
        void add_cookie(const Cookie& c)
        {
            listCookies.push_back(c);
        }

        bool is_in_basket(const Cookie& c) const
        {
            bool result;
            result = (find(listCookies.begin(), listCookies.end(), c) != listCookies.end());
            return result;
        }

        Cookie remove_any_cookie()
        {
            int num;
            num = rand() % listCookies.size();
            itr = listCookies.begin();
            itrNext = next(itr, num - 1);
            Cookie cook = *itrNext;
            CookieType type =  cook.get_type();
            CookieSize size = cook.get_size();
            Cookie new_cookie(type, size);
            listCookies.erase(itrNext);

            return new_cookie;
        }

        void remove_cookie(const Cookie& c)
        {
            for(int i = 0; i < listCookies.size(); i++)
            {
                itr = listCookies.begin();
                itrNext = next(itr, i - 1);
                Cookie cook = *itrNext;
                if(cook == c)
                {
                    listCookies.erase(itrNext);
                }
            }
        }

        void clear_basket()
        {
            listCookies.clear();
        }

        bool is_basket_empty() const
        {
            if(listCookies.size() == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int cookie_total() const
        {
            int total;
            total = listCookies.size();
            return total;
        }

        int cookie_size_total(CookieSize s) const
        {
            int total = 0;

            for(list<Cookie>::const_iterator itrConst = listCookies.begin(); itrConst != listCookies.end(); ++itrConst)
            {
                Cookie cook = *itrConst;
                if(cook.get_size() == s)
                {
                    total += 1;
                }
            }

            return total;
        }

        int cookie_type_total(CookieType t) const
        {
            int total = 0;

            for(list<Cookie>::const_iterator itrConst = listCookies.begin(); itrConst != listCookies.end(); ++itrConst)
            {
                Cookie cook = *itrConst;
                if(cook.get_type() == t)
                {
                    total += 1;
                }
            }

            return total;
        }

        void print_cookies() const
        {
            if(listCookies.size() == 0)
            {
                cout << "This basket is empty" << endl;
            }
            else
            {
                int i = 0;
                for(Cookie const &cook : listCookies)
                {
                    if(cook.get_size() == small)
                    {
                        cout << "Cookie " << i + 1 << " : " << cook << endl;
                        i++;
                    }
                }
                for(Cookie const &cook : listCookies)
                {
                    if(cook.get_size() == medium)
                    {
                        cout << "Cookie " << i + 1 << " : " << cook << endl;
                        i++;
                    }
                }
                for(Cookie const &cook : listCookies)
                {
                    if(cook.get_size() == large)
                    {
                        cout << "Cookie " << i + 1 << " : " << cook << endl;
                        i++;
                    }
                }
            }
        }

        vector<Cookie> get_vector() const
        {
            return vec;
        }

        list<Cookie> get_list() const
        {
            return listCookies;
        }

        /*
        Purpose: copies a full Basket_LinkedList object into an empty Basket_LinkedList object
        Arguments: basket is Basket reference(in this case it is a Basket_LinkedList object)
        Precondition: argument basket must be of Basket_LinkedList
        PostCondition: basket object using the method is a copy of the argument basket*/
        void copy_basket(const Basket& basket)
        {
            list<Cookie> l1;
            l1 = basket.get_list();
            this->clear_basket();
            for(int i = 0; i < l1.size(); i++)
            {
                itr = l1.begin();
                itrNext = next(itr, i);
                Cookie cook = *itrNext;
                this->add_cookie(cook);
            }
        }

        /*
        Purpose: combines two Basket_LinkedList into a new Basket_LinkedList object
        Arguments: basket1 and basket2 are both Basket references(in this case both are Basket_LinkedList objects)
        Precondition: arguments basket1 and basket2 must be of Basket_LinkedList
        Postcondition: basket object using the method is the combination of the arguments basket1 and basket2*/
        void merge_baskets(const Basket& basket1, const Basket& basket2)
        {
            list<Cookie> l1;
            list<Cookie> l2;
            l1 = basket1.get_list();
            l2 = basket2.get_list();
            this->clear_basket();
            for(int i = 0; i < l1.size(); i++)
            {
                itr = l1.begin();
                itrNext = next(itr, i);
                Cookie cook = *itrNext;
                this->add_cookie(cook);
            }

            for(int i = 0; i < l2.size(); i++)
            {
                itr = l2.begin();
                itrNext = next(itr, i);
                Cookie cook = *itrNext;
                this->add_cookie(cook);
            }
        }

        /*
        Purpose: creates a third Basket_LinkedList that contain cookies that are both in basket1 and basket2
        Arguments: basket1 and basket2 are both Basket references(in this case they are both Basket_LinkedList objects)
        Precondition: basket1 and basket2 must be both of Basket_LinkedList
        Postcondition: basket object using the method is the basket full of cookies both in basket1 and basket2*/
        void intersect_baskets(const Basket& basket1, const Basket& basket2)
        {
            list<Cookie> l1;
            list<Cookie> l2;
            list<Cookie>::iterator itr;
            list<Cookie>::iterator itrNext;

            l1 = basket1.get_list();
            l2 = basket2.get_list();
            this->clear_basket();
            for(int i = 0; i < l1.size(); i++)
            {
                itr = l1.begin();
                itrNext = next(itr, i);
                Cookie cook = *itrNext;
                if(basket2.is_in_basket(cook) && basket1.is_in_basket(cook))
                {
                    this->add_cookie(cook);
                }
            }
        }

        /*
        Purpose: creates a third Basket_LinkedList that contain cookies that are in basket1 but not in basket2
        Arguments: basket1 and basket2 are both Basket references(in this case they are both Basket_LinkedList objects)
        Precondition: basket1 and basket2 must be both of Basket_LinkedList
        Postcondition: basket object using the method is the basket full of cookies in basket1 but not basket2*/
        void difference_baskets(const Basket& basket1, const Basket& basket2)
        {
            list<Cookie> l1;
            list<Cookie> l2;
            list<Cookie>::iterator itr1;
            list<Cookie>::iterator itr1Next;
            list<Cookie>::iterator itr2;
            list<Cookie>::iterator itr2Next;
            l1 = basket1.get_list();
            l2 = basket2.get_list();
            this->clear_basket();
            for(int i = 0; i < l1.size(); i++)
            {
                itr1 = l1.begin();
                itr1Next = next(itr1, i);
                Cookie cook1 = *itr1Next;
              
                if(!(basket2.is_in_basket(cook1)))
                {
                    this->add_cookie(cook1);
                }
            }
        }
};

int main()
{
    //Vector Implementation
    
    ifstream file;
    string name;
    string typeStr;
    string sizeStr;
    string blank;
    CookieType type;
    CookieSize size;
    int num;
    num = 0;

    name = "baskets.txt";
    file.open(name);

    vector<Cookie> v1;
    vector<Cookie> v2;
    vector<Cookie> v3;
    Basket_Vector vec1(v1);
    Basket_Vector vec2(v2);
    Basket_Vector vec3(v3);

    for(int i = 0; i < 15; i++)
    {
            file >> typeStr;
            file >> sizeStr;
            type = convertType(typeStr);
            size = convertSize(sizeStr);
            Cookie cook(type, size);
            vec1.add_cookie(cook);
    }
    cout << "Vector Implementation" << endl;
    cout << endl;
    cout << "Basket 1:" << endl;
    vec1.print_cookies();
    
    getline(file, blank);
    cout << endl;

    for(int i = 0; i < 15; i++)
    {
            file >> typeStr;
            file >> sizeStr;
            type = convertType(typeStr);
            size = convertSize(sizeStr);
            Cookie cook(type, size);
            vec2.add_cookie(cook);
    }
    cout << "Basket 2:" << endl;
    vec2.print_cookies();
    cout << endl;

    num = vec1.cookie_type_total(walnut_chocolate_chunk);
    cout << "Total Number of Walnut Chocolate Chunk Cookies in Basket 1: " << num << endl;
    num = vec2.cookie_type_total(walnut_chocolate_chunk);
    cout << "Total Number of Walnut Chocolate Chunk Cookies in Basket 2: " << num << endl;
    num = vec1.cookie_size_total(medium);
    cout << "Total Number of Medium Cookies in Basket 1: " << num << endl;
    num = vec2.cookie_size_total(medium);
    cout << "Total Number of Medium Cookies in Basket 2: " << num << endl;
    num = vec1.cookie_total();
    cout << "Total Number of Cookies in Basket 1: " << num << endl;
    num = vec2.cookie_total();
    cout << "Total Number of Cookies in Basket 2: " << num << endl;
    cout << endl;

    cout << "Basket 3 (Basket 1 and 2 Combined): " << endl;
    vec3.merge_baskets(vec1, vec2);
    vec3.print_cookies();
    cout << endl;
    num = vec3.cookie_type_total(walnut_chocolate_chunk);
    cout << "Total Number of Walnut Chocolate Chunk Cookies in Basket 3: " << num << endl;
    num = vec3.cookie_size_total(medium);
    cout << "Total Number of Medium Cookies in Basket 3: " << num << endl;
    num = vec3.cookie_total();
    cout << "Total Number of Cookies in Basket 3: " << num << endl;
    cout << endl;
    vec3.clear_basket();

    vec3.intersect_baskets(vec1,vec2);
    cout << "Intersection of Basket 1 and Basket 2" << endl;
    vec3.print_cookies();
    cout << endl;
    vec3.clear_basket();

    vec3.difference_baskets(vec1, vec2);
    cout << "Difference of Basket 1 and Basket 2" << endl;
    vec3.print_cookies();
    cout << endl;

    //Linked List Implementation
    Basket_LinkedList list1;
    Basket_LinkedList list2;
    Basket_LinkedList list3;

    getline(file, blank);
    cout << "Linked List Implementation" << endl;
    cout << endl;

    for(int i = 0; i < 15; i++)
    {
        file >> typeStr;
        file >> sizeStr;
        type = convertType(typeStr);
        size = convertSize(sizeStr);
        Cookie cook(type, size);
        list1.add_cookie(cook);
    }
    cout << "Basket 1:" << endl;
    list1.print_cookies();
    
    getline(file, blank);
    cout << endl;

    for(int i = 0; i < 15; i++)
    {
            file >> typeStr;
            file >> sizeStr;
            type = convertType(typeStr);
            size = convertSize(sizeStr);
            Cookie cook(type, size);
            list2.add_cookie(cook);
    }
    cout << "Basket 2:" << endl;
    list2.print_cookies();
    cout << endl;

    num = list1.cookie_type_total(walnut_chocolate_chunk);
    cout << "Total Number of Walnut Chocolate Chunk Cookies in Basket 1: " << num << endl;
    num = list2.cookie_type_total(walnut_chocolate_chunk);
    cout << "Total Number of Walnut Chocolate Chunk Cookies in Basket 2: " << num << endl;
    num = list1.cookie_size_total(medium);
    cout << "Total Number of Medium Cookies in Basket 1: " << num << endl;
    num = list2.cookie_size_total(medium);
    cout << "Total Number of Medium Cookies in Basket 2: " << num << endl;
    num = list1.cookie_total();
    cout << "Total Number of Cookies in Basket 1: " << num << endl;
    num = list2.cookie_total();
    cout << "Total Number of Cookies in Basket 2: " << num << endl;
    cout << endl;

    cout << "Basket 3 (Basket 1 and 2 Combined: " << endl;
    list3.merge_baskets(list1, list2);
    list3.print_cookies();
    cout << endl;
    num = list3.cookie_type_total(walnut_chocolate_chunk);
    cout << "Total Number of Walnut Chocolate Chunk Cookies in Basket 3: " << num << endl;
    num = list3.cookie_size_total(medium);
    cout << "Total Number of Medium Cookies in Basket 3: " << num << endl;
    num = list3.cookie_total();
    cout << "Total Number of Cookies in Basket 3: " << num << endl;
    cout << endl;
    list3.clear_basket();

    list3.intersect_baskets(list1,list2);
    cout << "Intersection of Basket 1 and Basket 2" << endl;
    list3.print_cookies();
    cout << endl;
    list3.clear_basket();

    list3.difference_baskets(list1, list2);
    cout << "Difference of Basket 1 and Basket 2" << endl;
    list3.print_cookies();
    cout << endl;
}