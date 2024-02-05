//  String class test program
//
//  Tests: lessThan, uses ==
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
        String left("ABC");
        String right("abc");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == "ABC");
        assert(right  == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('a');
        String  right('b');

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == "a");
        assert(right  == "b");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('a');
        String  right('a');

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "a");
        assert(right  == "a");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("Bella");
        String  right("Bella");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "Bella");
        assert(right  == "Bella");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("0110001001100001011011000110110001110011");
        String  right("lol");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   == "0110001001100001011011000110110001110011");
        assert(right  == "lol");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right;

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
        assert(left   == "");
        assert(right  == "");
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing lessThan" << std::endl;
    return 0;
}

