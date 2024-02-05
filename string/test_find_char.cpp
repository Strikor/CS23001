//
//Test case for finding character
//

#include "string.hpp"
#include <cassert>
#include <iostream>


int main() {
  
  {
    String str("abcabc");
    int result = str.findch(0,'a');
    assert(str == "abcabc");
    assert(result == 0);
  }

  {
    String str("abcabc");
    int result = str.findch(1,'a');
    assert(str == "abcabc");
    assert(result == 3);
  }

  {
    String str("abcabc");
    int result = str.findch(4,'a');
    assert(str == "abcabc");
    assert(result == -1);
  }

  {
    String str("abcabc");
    int result = str.findch(0, 'z');
    assert(str == "abcabc");
    assert(result == -1);
  }

  std::cout<<"Done testing findchar." <<std::endl;
}