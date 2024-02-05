// bigint Test Program
//
// Tests:  factorial
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint fact(bigint::nfact(100));

        // Test/Verify
        assert(fact.countZeros() == 24);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint fact(bigint::nfact(0));

        // Test/Verify
        assert(fact.countZeros() == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint fact(bigint::nfact(10));

        // Test/Verify
        assert(fact.countZeros() == 2);
    }


    std::cout << "Done with testing factorial." << std::endl;
    return 0;
}

