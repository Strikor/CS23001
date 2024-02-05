//
//  set.cpp
//  CSII_Set
//
//  Created by Teddy Drewek on 9/14/22.
//

#include "set.hpp"
// ------------------------------------------------------------------------------------
bool isValid(int x){
    return (x >= 0) && (x < DOMAIN);
}
// ------------------------------------------------------------------------------------
// set a;
set::set(){
    for (int i = 0; i < DOMAIN; ++i){
        element[i] = false;
    }
}

// delligation
// REQUIRES: 0 <= x < DOMAIN
set::set(int x) : set() {
    if (isValid(x))
        element[x] = true;
}

// REQUIRES: 0 <= x, y < DOMAIN
set::set(int x, int y) : set(){
    if (isValid(x))
        element[x] = true;
    if (isValid(y))
        element[y] = true;
}
// ------------------------------------------------------------------------------------
// set a = {4, 3, 6};
set::set(std::initializer_list<int> lst) : set(){
    for (int i : lst){
        if (isValid(i))
            element[i] = true;
    }
}
// ------------------------------------------------------------------------------------
// cardinality
int set::card() const{
    int result = 0;
    for (int i = 0; i < DOMAIN; ++i){
        if (element[i])
            ++result;
    }
    return result;
}
// ------------------------------------------------------------------------------------
// REQUIRES 0 <= x < DOMAIN
bool set::operator[](int x) const{
    if (isValid(x))
        return element[x];
    else
        return false;
}

// ------------------------------------------------------------------------------------
// c = a + b;  || a.operator+(b)
set set::operator+(const set& rhs) const{
    set result;
    for (int i = 0; i < DOMAIN; ++i){
        result.element[i] = element[i] || rhs.element[i]; // element[i] is "this" or lhs
    }
    return result;
}

set operator+(int lhs, const set& rhs){
    return set(lhs) + rhs;
}

// ------------------------------------------------------------------------------------
// intersection
set set::operator*(const set& rhs) const{
    set result;
    for (int i = 0; i < DOMAIN; ++i){
        result.element[i] = element[i] && rhs.element[i]; // element[i] is "this" or lhs
    }
    return result;
}

set operator*(int lhs, const set& rhs){
    return set(lhs) * rhs;
}
// ------------------------------------------------------------------------------------
// difference
set set::operator-(const set& rhs) const{
    set result;
    for (int i = 0; i < DOMAIN; ++i){
        result.element[i] = element[i] && !rhs.element[i]; // element[i] is "this" or lhs
    }
    return result;
}

set operator-(int lhs, const set& rhs){
    return set(lhs) - rhs;
}

// ------------------------------------------------------------------------------------

bool set::operator==(const set& rhs) const{
    for (int i = 0; i < DOMAIN; ++i){
        if (element[i] != rhs.element[i])
            return false;
    }
    return true;
}

bool operator==(int lhs, const set& rhs){
    return set(lhs) == rhs;
}
// ------------------------------------------------------------------------------------

bool operator!=(const set& lhs, const set& rhs){
    return !((lhs) == rhs);
}

// ------------------------------------------------------------------------------------
bool set::operator<=(const set& rhs) const{
    for (int i = 0; i < DOMAIN; ++i){
        if (element[i] && !rhs.element[i])
            return false;
    }
    return true;
}

bool operator<=(int lhs, const set& rhs) {
    return set(lhs) <= rhs;
}


bool operator>=(const set& lhs, const set& rhs){
    return rhs <= lhs;
}

// ------------------------------------------------------------------------------------
bool operator<(const set& lhs, const set& rhs){
    return lhs <= rhs && lhs != rhs;
}


bool operator>(const set& lhs, const set& rhs){
    return rhs < lhs;
}
// ------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& OUT, const set& rhs){
    bool printComma = false;
    OUT << "{";
    for (int i = 0; i < DOMAIN; ++i){
        if (rhs.element[i]){
            if (printComma)
                OUT << ", ";
                OUT << i;
            printComma = true;
        }
    }
    OUT << "}";
    return OUT;
}
// ------------------------------------------------------------------------------------
