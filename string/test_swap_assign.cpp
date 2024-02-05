//  String class test program
//
//  Tests: swap assignment, uses ==
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
        String  left("abc");
        String  right("def");

        // TEST
        left.swap(right);

        // VERIFY
        assert(left   == "def");
        assert(right  == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("def");

        // TEST
        right.swap(left);

        // VERIFY
        assert(left   == "def");
        assert(right  == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("\0");

        // TEST
        left.swap(right);

        // VERIFY
        assert(left   == "");
        assert(right  == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("\0");
        String  right("abc");

        // TEST
        left.swap(right);

        // VERIFY
        assert(left   == "abc");
        assert(right  == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("\0");
        String  right("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");

        // TEST
        left.swap(right);

        // VERIFY
        assert(left   == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        assert(right  == "");
        assert(left.length() == 353);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing swap." << std::endl;
    return 0;
}

