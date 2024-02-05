// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    //assert(1 == 2); //WRONG. This will fail, of course.
                    //You need to add more test cases here. Remove this assert.

    
    //Add test cases as needed.
    {
      //Setup
      bigint left("66666666666666666666");
      bigint right("33333333333333333333");
      bigint result;

      //Test
      result = left + right;

      //Verify
      assert(left == "66666666666666666666");
      assert(right == "33333333333333333333");
      assert(result == "99999999999999999999");

    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(10);
      bigint right(22);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10);
      assert(right  == 22);
      assert(result == 32);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(100);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 100);
      assert(result == 100);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(40678);
      bigint right(40678);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 40678);
      assert(right  == 40678);
      assert(result == 81356);
    }

    /*{
      //Setup for an output test
      //and yes I know this isn't the location for this but there isn't really an
      //test_output so I just put these here for time being fixing a problem with
      //not printing single digits
      bigint single(9);

      std::cout << single << std::endl;

      bigint dosses(96);

      std::cout << dosses << std::endl;
    }*/

    
    

    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

