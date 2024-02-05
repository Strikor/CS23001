//  String class test program
//
//  Tests: substring, uses ==
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
        String  str("Howdy Neighbor");

        // TEST
        String result = str.substr(0,4);

        // VERIFY
        assert(str    == "Howdy Neighbor");
        assert(result == "Howdy");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Howdy Neighbor");

        // TEST
        String result = str.substr(5,13);

        // VERIFY
        assert(str    == "Howdy Neighbor");
        assert(result == " Neighbor");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Howdy Neighbor");

        // TEST
        String result = str.substr(5,400);

        // VERIFY
        assert(str    == "Howdy Neighbor");
        assert(result == " Neighbor");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Howdy Neighbor");

        // TEST
        String result = str.substr(-400,400);

        // VERIFY
        assert(str    == "Howdy Neighbor");
        assert(result == "Howdy Neighbor");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Howdy Neighbor");

        // TEST
        String result = str.substr(400,-400);

        // VERIFY
        assert(str    == "Howdy Neighbor");
        assert(result == "");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing substring." << std::endl;
    return 0;
}

