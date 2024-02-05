//  Stack class test program
//
//  Tests: XXX
//

#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> integer_stack;

        // VERIFY
        assert(integer_stack.empty());
        assert(!integer_stack.full());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<double> double_stack;

        // VERIFY
        assert(double_stack.empty());
        assert(!double_stack.full());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> str_stack;

        // VERIFY
        assert(str_stack.empty());
        assert(!str_stack.full());
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Default Constructor." << std::endl;
    return 0;
}

