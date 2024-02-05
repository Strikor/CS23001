//
//  string.hpp
//  CSII_IDE
//
//  Created by Teddy Drewek on 9/21/22.
//

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <cassert>

const int STRING_SIZE = 256;


// CLASS INVARIENTS: 0 <= length() <= capacity() &&
//                   capacity() == STRING_SIZE - 1 &&
//                   str[length()] == 0
class String{
public:
    String();
    String(char);
    String(const char[]);
    
    int capacity() const {return STRING_SIZE - 1;};
    int length() const;
    char operator[](int) const;
    char& operator[](int);
    //String operator+(const String&) const;
    String& operator+=(const String&); //cannot be const because it modifies lhs
    String substr(int, int) const;
    int findChar(int, char) const;
    int findChar(char) const;
    
    bool operator==(const String&) const;
    bool operator<(const String&) const;
    
    friend std::ostream& operator<<(std::ostream&, const String&);
    
private:
    char str[STRING_SIZE];
};

// free-functions
std::istream& operator>>(std::istream&, String&);

//String operator+(char, const String&);
//String operator+(const char[], const String&);
String operator+(String, const String&);

bool operator==(const char[], const String&);
bool operator==(char, const String&);
bool operator<(const char[], const String&);
bool operator<(char, const String&);
bool operator!=(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);




#endif // STRING_HPP

