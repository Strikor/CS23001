// String Test Program
// 
// Tests:  default constructor, uses ==
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main () {
    // Setup

    // Test 
    String s;

    // Verify
    assert(s == "");

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}

