//  String class test program
//
//  Tests: subscript, uses ==
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
        String  str("abcdefghijklmnopqrstuvwxyz");

        // TEST
        String result = str[4];

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyz");
        assert(result == 'e');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("0101010101010");

        // TEST
        String result = str[7];

        // VERIFY
        assert(str    == "0101010101010");
        assert(result == "1");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwxyz");

        // TEST
        String result = str[26];

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyz");
        assert(result == "\0");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwxyz");

        // TEST
        String result = str[25];

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyz");
        assert(result == "z");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

