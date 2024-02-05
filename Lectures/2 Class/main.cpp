//
//  main.cpp
//  CSII_Class
//
//  Created by Teddy Drewek on 9/7/22.
//

#include "point.hpp"

int main(){
    point a; //default constructor called (0,0)
    point b(3.0, 5.0); //initialized constructor
    point c(2.6, 7.9);
    point d(3.0, 4.0);
    
    std::cout << "hello" << std::endl;
    
    c = d + b;
    //c.print(std::cout);  don't need if overloaded
    
    std::cout << "c = " << c << std::endl;
    std::cout << "a = " << a << std::endl;
    a.setx(6.3);
    a.sety(7.8);
    
    std::cout << "a = " << a << std::endl;
    
    
}
