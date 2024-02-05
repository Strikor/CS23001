//  String test program
//
//  Tests: char array constructor, uses ==
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

        // TEST
        String  str("abcd");

        // VERIFY
        assert(str == "abcd");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("");

        // VERIFY
        assert(str == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("Bella");

        // VERIFY
        assert(str == "Bella");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("Alissa");

        // VERIFY
        assert(str == "Alissa");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(",jxcnalwidnoqiwdoaiwdAWD!@00192;");

        // VERIFY
        assert(str == ",jxcnalwidnoqiwdoaiwdAWD!@00192;");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing char constructor." << std::endl;
    return 0;
}

