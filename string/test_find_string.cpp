//
//Test case for findstr()
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main(){
  {
    String str1("abcabcabc");
    String str2("ab");
    int result = str1.findstr(0, str2);
    assert(str1 == "abcabcabc");
    assert(str2 == "ab");
    assert(result == 0);
  }

  {
    String str1("abcabcabc");
    String str2("abcabcabc");
    int result = str1.findstr(0, str2);
    assert(str1 == "abcabcabc");
    assert(str2 == "abcabcabc");

    assert(result == 0);
  }
  {
    String str1("abcabcabc");
    String str2("abcabcabc");
    int result = str1.findstr(1,str2);
    assert(str1 == "abcabcabc");
    assert(str2 == "abcabcabc");
    assert(result == -1);
  }

  {
    String str1("abcabcabc");
    String str2("dd");
    int result = str1.findstr(0, str2);
    assert(str1 == "abcabcabc");
    assert(str2 == "dd");
    assert(result == -1);
  }

  std::cout<< "Done testing findstr." << std::endl;
}