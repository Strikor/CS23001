//
//  point.cpp
//  CSII_Class
//
//  Created by Teddy Drewek on 9/7/22.
//

#include "point.hpp"

// default constructor
point::point(){
    x = 0.0;
    y = 0.0;
}
// initialized constructor
point::point(double nx, double ny){
    x = nx;
    y = ny;
}

double point::getx(){
    return x;
}

double point::gety(){
    return y;
}

void point::setx(double nx){
    x = nx;
}

void point::sety(double ny){
    y = ny;
}

point point::operator+(point rhs){
    point result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    return result;
}

point point::operator-(point rhs){
    point result;
    result.x = x - rhs.x;
    result.y = y - rhs.y;
    return result;
}

/*void point::print(std::ostream& out){
    out << "(" << x << ", " << y << ")" << std::endl;
} don't need if overloaded
 */

std::ostream& operator<<(std::ostream& out, point rhs){
    out << "(" << rhs.getx() << ", " << rhs.gety() << ")" << std::endl;
    return out;
}


