//
//  profile.cpp
//
//  Created by Jonathan Maletic.
//  Copyright 2022 Kent State University. All rights reserved.
//  Fall  2022
//  Modified by: Jason Graham
//

#include "profile.hpp"

// Prints out the profile.
//
// TODO: Very basic, need to make it print neat columns with headings
// 
std::ostream& operator<< (std::ostream& out, const profile& p) {
    out << "\n----------------------------------------------" << std::endl;
    out << "File: " << p.filename << std::endl;
    out << "Line/Function\t\t|Executed" << std::endl;
    for(std::map<std::string, int>::const_iterator i = p.stmt.begin(); i != p.stmt.end(); ++i) {
        if(i->first.size() < 8) {
            out << i->first << "\t\t\t " << i->second << std::endl;
        } else if (i->first.size() < 16){
            out << i->first << "\t\t " << i->second << std::endl;
        } else if (i->first.size() < 24){
            out << i->first << "\t " << i->second << std::endl;
        } else {
            out << i->first << " " << i->second << std::endl;
        }
                
    }
    return out;
}



// REQUIRES:  n >= 0
// ENSURES: Returns a text version of a positive integer long
//
std::string intToString(long n) {
    assert(n >= 0);
    std::string result;
    
    if (n == 0) return "0";
    while (n > 0) {
        result = char(int('0') + (n % 10)) + result;
        n = n / 10;
    }  
    return result;
}
