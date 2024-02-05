//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream> 
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String lhs("abc");
        String rhs("abc");

        // VERIFY
        assert(lhs == rhs);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String lhs("abc");
        String rhs("def");

        // VERIFY
        assert(!(lhs == rhs));
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String lhs("010");
        String rhs("010");

        // VERIFY
        assert(lhs == rhs);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String s("abc");


        // VERIFY
        assert(s == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  s("A");

        // VERIFY
        assert(s == 'A');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  s("0");

        // VERIFY
        assert(s == '0');
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing equals." << std::endl;
    return 0;
}

