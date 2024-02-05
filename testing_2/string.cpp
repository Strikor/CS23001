//File:        string.cpp   
//       
//Version:     1.0
//Date:        9/5/2013 - Current Version Kent State University
//
//Author:      Dr. J. Maletic
//
//Description: -Implementation of simple String class member functions. 
//             


#include "string.hpp"


//////////////////////////////////////////////////////////
// Default Constructor
// ENSURES: str[0] == 0 
//
String::String() { 
      str[0] = 0;
} 


////////////////////////////////////////////////////////// 
// ENSURES: str == s 
// Example:  String("abcd")
//
String::String(const char *s) { 
    int i = 0;
    while (s[i] != 0) {
        str[i] = s[i];
        i++;
        if (i >= DEFAULT_STRING_CAPACITY-1) break;
    }
    str[i] = 0;
} 

//Missed this constructor
String::String(const char ch) {
    str[0] = ch;
    str[1] = '\0';
}

//Missed this operator
std::istream& operator>>(std::istream& in, String& rhs) {
    char ch[256];
    
    in >> ch;
    
    rhs = "";
    
    rhs = String(ch);

    return in;
}

//////////////////////////////////////////////////////////
//Less Than
//
bool String::operator<(const String& rhs)  const {
    int  i = 0;
    
    //Find first non equal characters
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i]))  ++i;
    
    //WRONG - didn't check if both equals 0 for a false case
    if((str[i] == 0) && (rhs.str[i] == 0)) return false; 
    if (str[i] == 0) return true;                           //"aa" < "aaaaa"
    if (str[i] < rhs.str[i]) return true;                   //"aa" < "ab"
    return false;
}


bool operator<(const char *lhs, const String& rhs) {
    return String(lhs) < rhs;
}

bool operator<(const char lhs, const String& rhs) {
    return String(lhs) < rhs;
}
