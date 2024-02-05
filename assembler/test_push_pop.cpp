//  Stack class test program
//
//  Tests: Push, Pop & getters
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
        
        // TEST
        assert(integer_stack.empty() == true); // .empty() test

        integer_stack.push(1);
        integer_stack.push(2);
        integer_stack.push(3);

        assert(integer_stack.full() == false);  // .full() test
        assert(integer_stack.empty() == false); // .empty() test
        assert(integer_stack.top() == 3);       // .top() test

        int third = integer_stack.pop();
        int second = integer_stack.pop();

        assert(integer_stack.top() == 1);       // .top() test

        int first = integer_stack.pop();

        assert(integer_stack.empty() == true); // .empty() test

        // VERIFY
        assert(first == 1);
        assert(second == 2);
        assert(third == 3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<double> double_stack;

        // TEST
        assert(double_stack.empty() == true); // .empty() test

        double_stack.push(1.1);
        double_stack.push(2.2);
        double_stack.push(3.3);

        assert(double_stack.full() == false);  // .full() test
        assert(double_stack.empty() == false); // .empty() test
        assert(double_stack.top() == 3.3);     // .top() test

        double third = double_stack.pop();
        double second = double_stack.pop();

        assert(double_stack.top() == 1.1);     // .top() test

        double first = double_stack.pop();

        assert(double_stack.empty() == true); // .empty() test

        // VERIFY
        assert(first == 1.1);
        assert(second == 2.2);
        assert(third == 3.3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> string_stack;

        // TEST
        assert(string_stack.empty() == true); // .empty() test

        string_stack.push("abc");
        string_stack.push("def");
        string_stack.push("ghi");

        assert(string_stack.full() == false);  // .full() test
        assert(string_stack.empty() == false); // .empty() test
        assert(string_stack.top() == "ghi");   // .top() test

        String third = string_stack.pop();
        String second = string_stack.pop();

        assert(string_stack.top() == "abc");   // .top() test

        String first = string_stack.pop();

        assert(string_stack.empty() == true); // .empty() test

        // VERIFY
        assert(first == "abc");
        assert(second == "def");
        assert(third == "ghi");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> string_stack;

        // TEST
        assert(string_stack.empty() == true); // .empty() test

        string_stack.push("abc");


        assert(string_stack.full() == false);  // .full() test
        assert(string_stack.empty() == false); // .empty() test
        assert(string_stack.top() == "abc");   // .top() test

        String first = string_stack.pop();

        assert(string_stack.empty() == true); // .empty() test

        // VERIFY
        assert(first == "abc");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> string_stack;

        // TEST
        assert(string_stack.empty() == true); // .empty() test

        string_stack.push("abc");
        string_stack.push("def");
        string_stack.push("ghi");

        assert(string_stack.full() == false);  // .full() test
        assert(string_stack.empty() == false); // .empty() test
        assert(string_stack.top() == "ghi");   // .top() test

        String third1 = string_stack.pop();
        String second1 = string_stack.pop();

        assert(string_stack.top() == "abc");   // .top() test

        string_stack.push("def");
        string_stack.push("ghi");
        string_stack.push("jkl");
        string_stack.push("mno");
        string_stack.push("pqr");
        string_stack.push("stu");
        string_stack.push("vwx");

        String eighth = string_stack.pop();
        String seventh = string_stack.pop();
        String sixth = string_stack.pop();
        String fifth = string_stack.pop();
        String forth = string_stack.pop();
        String third = string_stack.pop();
        String second = string_stack.pop();
        String first = string_stack.pop();

        assert(string_stack.empty() == true); // .empty() test

        // VERIFY
        assert(first == "abc");
        assert(second == "def");
        assert(second1 == "def");
        assert(third == "ghi");
        assert(third1 == "ghi");
        assert(forth == "jkl");
        assert(fifth == "mno");
        assert(sixth == "pqr");
        assert(seventh == "stu");
        assert(eighth == "vwx");
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Push/Pop & Misc. Functions." << std::endl;
    return 0;
}

