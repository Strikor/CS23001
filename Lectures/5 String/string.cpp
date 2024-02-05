//
//  string.cpp
//  CSII_IDE
//
//  Created by Teddy Drewek on 9/21/22.
//

#include "string.hpp"

String::String(){
    str[0] = 0;
}

//converts single char to String    String a('x');
String::String(char ch){
    str[0] = ch;
    str[1] = 0;
}

//REQUIRES: s to be null terminating      String a("xyz");
String::String(const char s[]){
    int i = 0;
    while (s[i] != 0){
        if (i >= capacity()) break;
        str[i] = s[i];
        ++i;
    }
    str[i] = 0;
}

//ENSURES:
int String::length() const{
    int len = 0;
    while (str[len] != 0) ++len;
    return len;
}

// REQUIRES: 0 <= i < length()
// Accessor, getter
char String::operator[](int i) const{
    assert(0 <= i);
    assert(i < length());
    return str[i];
}

// REQUIRES: 0 <= i < length()
// Mutator, setter
char& String::operator[](int i){
    assert(0 <= i);
    assert(i < length());
    return str[i];
}

// Concatenation
// a + b
// Given: "ab" + "cd"
// ENSURES: RetVal == "abcd"
/*String String::operator+(const String& rhs) const{
    String result(str);
    int offset = length();
    int i = 0;
    while (rhs.str[i] != 0){
        result.str[offset + i] = rhs.str[i];
        ++i;
    }
    result.str[offset + i] = 0;  // null terminating
    return result;
}
 
String operator+(char lhs, const String* rhs){
    return String(lhs) + rhs;
 }
 */

String& String::operator+=(const String& rhs){
    int offset = length();
    int len = rhs.length();
    int i;
    for (i = 0; i < len; ++i){
        if (offset+i >= capacity()) break;
        str[offset + i] = rhs[i];
    }
    str[offset + i] = 0;
    return *this;
}

String operator+(String lhs, const String& rhs){
    return lhs += rhs;
}


//"abcd".substr(1,2) == "bc"
//REQUIRES: 0 <= start <= end && start <= end < length()
String String::substr(int start, int end) const{
    String result;
    if (start < 0) start = 0;
    if (end >= length()) end = length() - 1;
    if (end < start) return result;
    if (start > end) return result;
    for (int i = start; i <= end; ++i){
        result+= str[i];
    }
    return result;
}

// REQUIRES: 0 <= start < length()
// ENSURES: RetVal == i where str[i] == ch ||
//          RetVal == -1 where str[start,..,length()-1] != ch
int String::findChar(int start, char ch) const{
    if ((start < 0) || (start >= length())) return -1;
    int i = start;
    while (str[i] != 0){
        if (str[i] == ch) return i;
        ++i;
    }
    return -1;
}

int String::findChar(char ch) const{
    int i = 0;
    while (str[i] != 0){
        if (str[i] == ch) return i;
        ++i;
    }
    return -1;
}

// overload <<
std::ostream& operator<<(std::ostream& OUT, const String& rhs){
    OUT << rhs.str;
    return OUT;
}

// overload >>
std::istream& operator>>(std::istream& IN, String& rhs){
    char buffer[STRING_SIZE];
    IN >> buffer;
    rhs = String(buffer);
    return IN;
}

