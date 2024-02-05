//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        10/30/2022
// Author:      Jason Graham
//
// Description: Class implementation for a log entry.
//
// 

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector> 

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  Log follows the format: (Host, - - [Date:Time Timezone] "Request" Status Bytes)
//            Lossy transformation in timezone information to logEntry dataType
//            String with formatting is passed in
// ENSURES:   Format is maintained
//
LogEntry::LogEntry(String s) {
    if(s.length() == 0) return;
    std::vector<String> vec = s.split(' ');
    std::vector<String> req = s.split('\"');

    //Gets bytes
    if(vec.back() != '-') {
        String byts = vec.back();
        //std::cout << byts << std::endl;
        number_of_bytes = 0;
        for(int i = 0; i < byts.length(); ++i) {
        number_of_bytes *= 10;
        number_of_bytes += byts[i] - '0';
        }
    } else {
        number_of_bytes = 0;
    }

    //del 5625
    vec.pop_back();

    //get status
    status = vec.back();

    //get req from it's own split
    req.pop_back();
    request = req.back();

    //remove the request
    req.pop_back();

    //Remove everything from the request on
    vec = req.back().split(' ');
    vec.pop_back();
    vec.pop_back();

    //Gets Date and Time then removes them and the time zone
    time = vec.back();
    date = vec.back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();

    //Gets Host and Done!
    host = vec.back();

}

Date::Date(String s) {
    day = s.substr(1, 2);
    month = s.substr(4, 6);
    year = 0;

    String yr(s.substr(8, 11));

    for(int i = 0; i < yr.length(); ++i) {
        year *= 10;
        year += yr[i] - '0';
    }
}

Time::Time(String s) {
    //131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] "GET /~darci/ HTTP/1.0" 200 5625
    std::vector<String> vec = s.split(':');

    String sec = vec.back();
    second = (sec[0] - '0') * 10 + (sec[1] - '0');
    vec.pop_back();

    String min = vec.back();
    minute = (min[0] - '0') * 10 + (min[1] - '0');
    vec.pop_back();

    String hr = vec.back();
    hour = (hr[0] - '0') * 10 + (hr[1] - '0');
    
}

////////////////////////////////////////////////////////// 
// REQUIRES:  Any given line is less that 511 characters
// ENSURES:   All lines are parsed in a file
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;

    //Run through until end of file is reached
    while(true) {
        char ch[512];
        in.getline(ch, 511);
        if(in.eof()) break;
        result.push_back(LogEntry(String(ch)));

    }

    return result;
}

//Outputs with formatting the logentry
std::ostream& operator<<(std::ostream& out, const LogEntry& rhs) {
    out << rhs.host << " - - [" << rhs.date << ':' << rhs.time << " -400] \"" << rhs.request << "\" " << rhs.status << ' ';
    if(rhs.number_of_bytes != 0) {
        out << rhs.number_of_bytes;
    } else {
        out << '-';
    }

    return out;
}

//Outputs Date
std::ostream& operator<<(std::ostream& out, const Date& rhs) {
    out << rhs.day << '/' << rhs.month << '/' << rhs.year;
    return out;
}

//Outputs time
std::ostream& operator<<(std::ostream& out, const Time& rhs) {
    if(rhs.hour < 10) {
        out << '0' << rhs.hour << ':';
    } else {
        out << rhs.hour << ':';
    }

    if(rhs.minute < 10) {
        out << '0' << rhs.minute << ':';
    } else {
        out << rhs.minute << ':';
    }

    if(rhs.second < 10) {
        out << '0' << rhs.second;
    } else {
        out << rhs.second;
    }

    return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  Propper LogEntry Vector
// ENSURES:   All information is printed
//
void output_all(std::ostream& out, const std::vector<LogEntry> & vec) {
    int s = vec.size();

    for(int i = 0; i < s; ++i) {
        out << vec[i] << std::endl;
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  Propper LogEntry Vector
// ENSURES:   Host information is printed
//
void by_host(std::ostream& out, const std::vector<LogEntry>& vec) {
    int s = vec.size();

    for(int i = 0; i < s; ++i) {
        out << vec[i].getHost() << std::endl;
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  Propper LogEntry Vector
// ENSURES:   Byte total is printed 
//
int byte_count(const std::vector<LogEntry> & vec) {
    int s = vec.size();
    int result = 0;

    for(int i = 0; i < s; ++i) {
        result += vec[i].getBytes();
    }
    
    return result;
}

 
