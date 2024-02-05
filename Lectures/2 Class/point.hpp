//
//  point.hpp
//  CSII_Class
//
//  Created by Teddy Drewek on 9/7/22.
//

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>



class point {
public:
    point(); //Default constructor
    point(double, double);
    double getx();
    double gety();
    void setx(double);
    void sety(double);
    
    point operator+(point);  //overloading '+' operator
    point operator-(point);  //overloading '-' operator
    
    
    //void print(std::ostream&); don't need if overloaded
private:
    double x, y;
};

std::ostream& operator<<(std::ostream&, point); //free-function




#endif // POINT_HPP
