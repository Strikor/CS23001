// Jason Graham
// 10/9/2022
// String
#include <iostream>
#include <vector>
#include "string.hpp"

//Empty string
String::String(){ 
    str = new char[1];
    stringSize = 1;
    str[0] = 0;
} 

//String('x')
String::String(char ch) {
    if(ch != '\0') {
        str = new char[2];
        stringSize = 2;
        str[0] = ch;
        str[1] = 0;
    } else { //Starts with null char
        str = new char[1];
        stringSize = 1;
        str[0] = 0;
    }
    
}

//String("abcd")
//Assume null-term
String::String(const char ch[]) {
    int i = 0;

    while(ch[i] != 0) ++i;

    str = new char[i + 1];
    stringSize = i + 1;
    i = 0;

    while(ch[i] != 0){
        str[i] = ch[i];
        ++i;  
    }

    str[i] = 0;

}

//Copy constructor
String::String(const String& strTC) {
    str = new char[strTC.capacity() + 1];
    stringSize = strTC.capacity() + 1;

    for(int i = 0; i < stringSize; ++i) {
        str[i] = strTC[i];
    }
}

//Custom size constructor
String::String(int size) {
    str = new char[size];
    stringSize = size;
}

//Copy constructor with custom size
String::String(const String& strTC, int size) {
    str = new char[size];
    stringSize = size;

    int length = strTC.length();

    for(int i = 0; i <= length; ++i) {
        str[i] = strTC[i];
    }

}

//Destructor
String::~String() {
    delete[] str;
}

void String::swap(String& rhs){

  char *temp = str;
  int tempSize = stringSize;

  str=rhs.str;
  stringSize = rhs.stringSize;

  rhs.str = temp;
  rhs.stringSize = tempSize;
}

String& String::operator=(String rhs){
  swap(rhs);
  return *this;
}

//Max chars that can be stored
int String::capacity() const{
    return stringSize - 1;

}

//Number of char in string
int String::length() const{
    /*int count = 0;

    //This line was giving a strange error with 
    //"invalid conditional jumps based on an unitialized value". No clue, replaced with capacity() code
    while(str[count] != 0) ++count;

    return count;*/
    return stringSize - 1;

}

//Accessor/Modifier
char& String::operator[](int i) {
    int len = length();
    if(i >= 0 && i <= len) return str[i];
    return str[len + 1];

}

//Accessor
char String::operator[](int i) const{
    int len = length();
    if(i >= 0 && i <= len) return str[i];
    return 0;

}

//Concatenation
String& String::operator+=(const String& rhs) {
    int offset = length();
    int i = 0;

    String result(*this, stringSize + rhs.length());

    while(rhs.str[i] != '\0'){
        result[offset+i] = rhs.str[i];
        ++i;
    }
    
    result[offset+i] = 0;

    swap(result);
    return *this;
}

bool String::operator==(const String& rhs) const{
    int i = 0;
    while((str[i] != '\0')){
        if(str[i] != rhs[i]){
            return false;

        }

        ++i;
    }

    return str[i] == rhs.str[i];
}

bool String::operator<(const String& rhs) const{
    int i = 0;
    while(str[i] != 0 && rhs.str[i] != 0 && str[i] == rhs.str[i]) ++i;

    if((str[i] == 0) && (rhs.str[i] == 0)) return false;
    if(str[i] == 0) return true;
    if(str[i] < rhs.str[i]) return true;
    return false;

}

//operators

String operator+(String lhs, const String& rhs) {
    return(lhs+=rhs);
}

bool operator==(const char lhs[], const String& rhs) {
    return(String(lhs)==rhs);
}

bool operator==(char lhs, const String& rhs) {
    return(String(lhs)==rhs);
}

bool operator<(const char lhs[], const String& rhs) {
    return(String(lhs) < rhs);
}

bool operator<(char lhs, const String& rhs) {
    return(String(lhs) < rhs);
}

bool operator<=(const String& lhs, const String& rhs) {
    return(lhs < rhs || lhs == rhs);
}

bool operator!=(const String& lhs, const String& rhs) {
    return(!(lhs == rhs));
}

bool operator>=(const String& lhs, const String& rhs) {
    return(!(lhs < rhs));
}

bool operator>(const String& lhs, const String& rhs) {
    return(rhs < lhs);
}

//End operators

//Sub from staring to ending positions
String String::substr(int start, int end) const{
    String result;
    if(start < 0) start = 0;
    if(end < start) return String();
    if(end > length()) end = length();
    if(start > end) return String();

    for(int i = start; i <= end; ++i) {
        result += str[i];
    }

    return result;
}

//Location of charater starting at a position
int String::findch(int start, char ch) const{
    int len = length();
    for(int i = start; i <= len; ++i) {
        if(str[i] == ch) return i;
    }
    return -1;
}

//Location of string starting at a position
int String::findstr(int start, const String& chArr) const{
    int chLen = chArr.length();
    int loc = findch(start, chArr[0]);
    bool broken = false;
    
    while(loc != -1){
        for(int i = 1; i < chLen; ++i) {
            if(str[loc + i] != chArr[i]) {
                broken = true;
                break;
            }
        }
        if(!broken) {
            return loc;
        }

        broken = false;
        start = loc + 1;
        loc = findch(start, chArr[0]);
    }

    return -1;

}

//Milestone 3
std::vector<String> String::split(char delim) const {
    std::vector<String> output;
    int start = 0;
    int chPos = findch(start, delim);

    while(chPos != -1) {
        output.push_back(substr(start, chPos - 1));
        start = chPos + 1;
        chPos = findch(start, delim);
    }

    output.push_back(substr(start, length()));

    return output;

}

std::istream& operator>>(std::istream& in, String& rhs) {
    char ch[256];
    
    in >> ch;
    
    rhs = "";
    for(int i = 0; i < 256 && ch[i] != '\0'; ++i) {
        rhs += ch[i];
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}
