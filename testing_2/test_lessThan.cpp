//  String class test program
//
//  Tests: lessThan
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
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("lol");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("lol");
        String  right("\0");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  right("abc");

        // TEST
        bool result = ("abc" < right);

        // VERIFY
        assert(result == false);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  right("abc");

        // TEST
        bool result = ("ab" < right);

        // VERIFY
        assert(result == true);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  right("abc");

        // TEST
        bool result = ('a' < right);

        // VERIFY
        assert(result == true);
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing lessThan" << std::endl;
    return 0;
}

