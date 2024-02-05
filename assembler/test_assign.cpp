//  Stack class test program
//
//  Tests: Assign
//  Uses : push & pop
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
        integer_stack.push(1);
        integer_stack.push(2);
        integer_stack.push(3);

        // TEST
        stack<int> result;
        result = integer_stack;

        // VERIFY
        int third = result.pop();
        int second = result.pop();
        int first = result.pop();

        assert(first == 1);
        assert(second == 2);
        assert(third == 3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<double> double_stack;
        double_stack.push(1.1);
        double_stack.push(2.2);
        double_stack.push(3.3);

        // TEST
        stack<double> result;
        result = double_stack;

        // VERIFY
        double third = result.pop();
        double second = result.pop();
        double first = result.pop();

        assert(first == 1.1);
        assert(second == 2.2);
        assert(third == 3.3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> string_stack;
        string_stack.push("abc");
        string_stack.push("def");
        string_stack.push("ghi");

        // TEST
        stack<String> result;
        result = string_stack;

        // VERIFY
        String third = result.pop();
        String second = result.pop();
        String first = result.pop();

        assert(first == "abc");
        assert(second == "def");
        assert(third == "ghi");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> string_stack;
        string_stack.push("abc");

        // TEST
        stack<String> result;
        result = string_stack;

        // VERIFY
        String first = result.pop();

        assert(first == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> string_stack;
        string_stack.push("abc");
        string_stack.push("def");
        string_stack.push("ghi");
        string_stack.push("jkl");
        string_stack.push("mno");
        string_stack.push("pqr");
        string_stack.push("stu");
        string_stack.push("vwx");

        // TEST
        stack<String> result;
        result = string_stack;

        // VERIFY
        String eighth = result.pop();
        String seventh = result.pop();
        String sixth = result.pop();
        String fifth = result.pop();
        String forth = result.pop();
        String third = result.pop();
        String second = result.pop();
        String first = result.pop();

        assert(first == "abc");
        assert(second == "def");
        assert(third == "ghi");
        assert(forth == "jkl");
        assert(fifth == "mno");
        assert(sixth == "pqr");
        assert(seventh == "stu");
        assert(eighth == "vwx");
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Assign." << std::endl;
    return 0;
}

