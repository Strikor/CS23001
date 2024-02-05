//
//  set.hpp
//  CSII_Set
//
//  Created by Teddy Drewek on 9/14/22.
//

#ifndef set_hpp
#define set_hpp
#include <iostream>

#include <initializer_list>
const int DOMAIN = 6400;


// CLASS INV: element = {} || element == {0 , ... , DOMAIN-1}
//            
class set{
public:
    set(); // default constructor
    set(int);
    set(int, int);
    set(std::initializer_list<int>);
    
    int card() const; // const method. Method can NOT modify object it is called on
    bool operator[](int) const;
    
    set operator+  (const set&) const; // union
    set operator*  (const set&) const; // intersection
    set operator-  (const set&) const; // difference
    
    bool operator==(const set&) const; // equality
    bool operator<=(const set&) const; // subset
    
    friend std::ostream& operator<<(std::ostream&, const set&); // friend
    
    
    
private:
    bool element[DOMAIN];
};


set operator+(int, const set&); //convert int to set
set operator*(int, const set&);
set operator-(int, const set&);

bool operator== (int, const set&);
bool operator<= (int, const set&);
bool operator!= (const set&, const set&);
bool operator<  (const set&, const set&);
bool operator>= (const set&, const set&); //superset
bool operator>  (const set&, const set&); //proper superset

//std::ostream& operator<<(std::ostream&, const set&); // free function for output







#endif /* set_hpp */
