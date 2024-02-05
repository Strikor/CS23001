//  String class test program
//
//  Tests: split, uses ==
//

#include "string.hpp"
#include <cassert>
#include <vector>
#include <iostream> 
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc ef gh");
        std::vector<String> expected{ "abc", "ef", "gh" };

        // TEST
        std::vector<String> result = str.split(' ');

        // VERIFY
        assert(str    == "abc ef gh");
        assert(result.size() == expected.size());
        for(int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("-a--b-");
        std::vector<String> expected{ "", "a", "", "b", "" };

        // TEST
        std::vector<String> result = str.split('-');

        // VERIFY
        assert(str    == "-a--b-");
        assert(result.size() == expected.size());
        for(int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Howdy Neighbor");
        std::vector<String> expected{"Howdy", "Neighbor"};

        // TEST
        std::vector<String> result = str.split(' ');

        // VERIFY
        assert(str    == "Howdy Neighbor");
        assert(result.size() == expected.size());
        for(int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abcd");
        std::vector<String> expected{"abcd"};

        // TEST
        std::vector<String> result = str.split(' ');

        // VERIFY
        assert(str    == "abcd");
        assert(result.size() == expected.size());
        for(int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("");
        std::vector<String> expected{""};

        // TEST
        std::vector<String> result = str.split(' ');

        // VERIFY
        assert(str    == "");
        assert(result.size() == expected.size());
        for(int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc   ef   gh");
        std::vector<String> expected{ "abc", "", "", "ef", "", "", "gh" };

        // TEST
        std::vector<String> result = str.split(' ');

        // VERIFY
        assert(str    == "abc   ef   gh");
        assert(result.size() == expected.size());
        for(int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing split." << std::endl;
    return 0;
}

