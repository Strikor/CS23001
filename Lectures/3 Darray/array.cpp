//
//  array.cpp
//  CSII_array
//
//  Created by Teddy Drewek on 10/3/22.
//

#include "array.hpp"


// REQUIRES: n>=0
Darray::Darray(int n){
    cap = n;
    ptr = new int[cap];
}

Darray::~Darray(){
    delete[] ptr;
}

// copy constructor
Darray::Darray(const Darray& actual){
    cap = actual.cap;
    ptr = new int[cap];
    for (int i = 0; i < cap; ++i){
        ptr[i] = actual.ptr[i];
    }
}

// copy assignment (old)
// Darray& Darray::operator=(const Darray& rhs){
//     if (ptr = rhs.ptr) return *this; // a=a
//     delete[] ptr;
//     cap = rhs.cap;
//     ptr = new int[cap];
//     for (int i = 0; i < cap; ++i){
//         ptr[i] = rhs.ptr[i];
//     }
//     return *this;
// }

// copy assignment (new)
Darray& Darray::operator=(Darray rhs){
    swap(rhs);
    return *this;
}


// Constant time swap
// No matter how big the array is, it is always the
// same amount of assignment to swap them
void Darray::swap(Darray& rhs){
    int* tmp = ptr;
    ptr = rhs.ptr;
    rhs.ptr = tmp;
    int capTemp = cap;
    cap = rhs.cap;
    rhs.cap = capTemp;
}

// REQUIRES n >= 0
void Darray::resize(int n){
    int smaller = cap;
    if (n < smaller)
        smaller = n;
    int* tmp = new int[n];
    for (int i = 0; i < smaller; ++i){
        tmp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = tmp;
    cap = n;
}




