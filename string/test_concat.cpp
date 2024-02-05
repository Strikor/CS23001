//  String class test program
//
//  Tests: concat, uses == 
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
        String  left("abcd");
        String  right("efg");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abcdefg");
        assert(left   == "abcd");
        assert(right  == "efg");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("efg");
        String result("");

        // TEST
        result += (left + right);

        // VERIFY
        assert(result == "abcdefg");
        assert(left   == "abcd");
        assert(right  == "efg");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("efg");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "abcdefg");
        assert(left   == "abcd");
        assert(right  == "efg");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("0000");
        String  right("1111");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(result == "00001111");
        assert(left   == "0000");
        assert(right  == "1111");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("efg");

        // TEST
        left += right;

        // VERIFY
        assert(left   == "abcdefg");
        assert(right  == "efg");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("efg");

        // TEST
        right += (left + right);

        // VERIFY
        assert(left   == "abcd");
        assert(right  == "efgabcdefg");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRST");
        String  right("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(left   == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRST");
        assert(left.length() == 128);
        assert(right  == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        assert(right.length() == 225);

        assert(result == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        assert(result.length() == 353);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("\0");

        // TEST
        String result = left + right;

        // VERIFY
        assert(result == "abcd");
        assert(left   == "abcd");
        assert(right  == "\0");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcd");
        String  right("\0");

        // TEST
        String result = left + right;

        // VERIFY
        assert(result == "abcd");
        assert(left   == "abcd");
        assert(right  == "\0");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("abcd");

        // TEST
        String result = left + right;

        // VERIFY
        assert(result == "abcd");
        assert(left   == "\0");
        assert(right  == "abcd");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        String  right("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");

        // TEST
        String result = (left + right);

        // VERIFY
        assert(left   == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        assert(left.length() == 353);
        assert(right  == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation");
        assert(right.length() == 353);

        assert(result == "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocationabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSThis will not be added to the string because it goes out of bounds but not with dynamic allocation\0");
        assert(result.length() == 706);
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing concat" << std::endl;
    return 0;
}