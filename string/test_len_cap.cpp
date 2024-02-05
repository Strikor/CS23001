//  String class test program
//
//  Tests lencap, uses ==
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
        String  str("a");

        // TEST
        int result = str.length();

        // VERIFY
        assert(str    == "a");
        assert(result == 1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
        int result = str.length();

        // VERIFY
        assert(str    == "abc");
        assert(result == 3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwxyz");

        // TEST
        int result = str.length();

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyz");
        assert(result == 26);
    }

    std::cout << "Done testing Length." << std::endl;

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("a");

        // TEST
        int result = str.capacity();

        // VERIFY
        assert(str    == "a");
        assert(result == str.length());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");

        // TEST
        int result = str.capacity();

        // VERIFY
        assert(str    == "abc");
        assert(result == str.length());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwxyz");

        // TEST
        int result = str.capacity();

        // VERIFY
        assert(str    == "abcdefghijklmnopqrstuvwxyz");
        assert(result == str.length());
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing capacity." << std::endl;
    return 0;
}

