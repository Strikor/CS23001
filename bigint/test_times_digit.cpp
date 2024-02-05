// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 12); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(29761);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 267849); 
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(777);

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0); 
        std::cout << bi << std::endl;
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(987);

        // Test 
        bi = bi.times10(9);

        // Verify
        assert(bi == "987000000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times10(10);

        // Verify
        assert(bi == "0");
    }
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
