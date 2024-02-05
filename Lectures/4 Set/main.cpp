//
//  main.cpp
//  CSII_Set
//
//  Created by Teddy Drewek on 9/14/22.
//

#include "set.hpp"

int main() {
    set a, b;
    set c(2);
    set d = {3, 5, 4, 10};
    
    std::cout << d.card() << std::endl;
    
    
    a = b + c;
    a = b + 1;  // c = b.operator+(set(1));
    a = a + 2;
    a = 2 + a;  // does not work (syntax error), unless you make convert int to set free function
    
    return 0;
}
