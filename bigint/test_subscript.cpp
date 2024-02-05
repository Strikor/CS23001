// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }

    {
        // Setup
        bigint bi("0123456789");

        // Test 
        int digit1 = bi[0];
        int digit2 = bi[1];
        int digit3 = bi[2];
        int digit4 = bi[3];
        int digit5 = bi[4];
        int digit6 = bi[5];
        int digit7 = bi[6];
        int digit8 = bi[7];
        int digit9 = bi[8];
        int digit0 = bi[9];

        // Verify
        assert(bi     == "0123456789");
        assert(digit1 == 9);
        assert(digit2 == 8);
        assert(digit3 == 7);
        assert(digit4 == 6);
        assert(digit5 == 5);
        assert(digit6 == 4);
        assert(digit7 == 3);
        assert(digit8 == 2);
        assert(digit9 == 1);
        assert(digit0 == 0);
    }

    {
        // Setup
        bigint bi(0);

        // Test 
        int digit1 = bi[0];
        int digit2 = bi[1];
        int digit3 = bi[2];
        int digit4 = bi[3];
        int digit5 = bi[4];
        int digit6 = bi[5];
        int digit7 = bi[6];
        int digit8 = bi[7];
        int digit9 = bi[8];
        int digit0 = bi[9];

        // Verify
        assert(bi     == 0);
        assert(digit1 == 0);
        assert(digit2 == 0);
        assert(digit3 == 0);
        assert(digit4 == 0);
        assert(digit5 == 0);
        assert(digit6 == 0);
        assert(digit7 == 0);
        assert(digit8 == 0);
        assert(digit9 == 0);
        assert(digit0 == 0);
    }
    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

