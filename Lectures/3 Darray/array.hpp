//
//  array.hpp
//  CSII_array
//
//  Created by Teddy Drewek on 10/3/22.
//

// A simple dynamically allocated array.

#ifndef array_hpp
#define array_hpp

#include <iostream>
#include <cassert>

//
// CLASS INV: ptr->int[cap]
//
class Darray {
public:
    Darray() : ptr(0), cap(0) {};
    Darray(int);
    Darray(const Darray&);            // copy constructor
    ~Darray();                        // Destructor
    //Darray& operator=(const Darray&); // old
    Darray& operator=(Darray); // new
    void swap(Darray&);
    
    int capacity() const {return cap;};
    int operator[](int) const;
    int& operator[](int);
    void resize(int);
private:
    int *ptr;
    int cap;
};







#endif /* array_hpp */

