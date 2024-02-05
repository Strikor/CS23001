//  String class test program
//
//  Tests: Copy constructor, uses ==
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
        String  str("abc");
        // TEST
        String  cpy(str);

        // VERIFY
        assert(cpy == str);
        assert(str == "abc");
        assert(cpy == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        // TEST
        String  cpy(str);

        // VERIFY
        assert(cpy == str);
        assert(str == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        assert(cpy == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        assert(cpy.length() == 353);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str('\0');
        // TEST
        String  cpy(str);

        // VERIFY
        assert(cpy == str);
        assert(cpy == "");
        assert(str == "");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}

