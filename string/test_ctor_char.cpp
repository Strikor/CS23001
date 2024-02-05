//  String test program
//
//  Tests: char constructor, uses ==
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
        String  str('0');

        // VERIFY
        assert(str == '0');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
        assert(str == 'a');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('A');

        // VERIFY
        assert(str == 'A');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('\0');

        // VERIFY
        assert(str == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('K');

        // VERIFY
        assert(str == 'K');
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing char constructor." << std::endl;
    return 0;
}

