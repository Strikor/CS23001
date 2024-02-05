// File: main.cpp
//
// CS 23001 Project 1 bigint
//
// Basics for openning a file for milestone 2
//

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <cassert>
#include "string.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("log_2_small.txt");   // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: log_2_small.txt" << std::endl;
        exit(1);
    }

    String lines[200];
    int i = 0;

    //Until end of file
    while(!in.eof()){
        in >> lines[i];
        //std::cout << line << std::endl;
        ++i;

        //Print out
        //std::cout << line << std::endl;

    }
 
    in.close();

    //Testing
    //Verify
    //std::cout << lines[0] << std::endl;
    assert(lines[0] == "131.123.47.176");
    assert(lines[1] == "-");
    assert(lines[2] == "-"); 
    assert(lines[30] == "4.19.70.66");

    //print all values
    /*for(int j = 0; j < 200; ++j) {
        std::cout << "(" << j << "): " << lines[j] << std::endl;
    }*/

    std::cout << "Done testing input." << std::endl;

    return 0;
}

