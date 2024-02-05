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
        bi = bi.times10(0);

        // Verify
        assert(bi == 3);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(376);

        // Test 
        bi = bi.times10(1);

        // Verify
        assert(bi == 3760);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times10(6);

        // Verify
        assert(bi == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(66);

        // Test 
        bi = bi.times10(20);

        // Verify
        assert(bi == "6600000000000000000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(20);

        // Test 
        bi = bi.times10(20);

        // Verify
        assert(bi == "2000000000000000000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == 0);
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

