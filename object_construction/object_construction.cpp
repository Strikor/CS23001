// Jason Graham
// 10/19/2022
// Object_Construction

#include <iostream>
#include "object_construction.hpp"

//Default
object_test::object_test() {
    data = 1;
    std::cout << "Called Default Constructor" << std::endl;
}

//Copy
object_test::object_test(const object_test& copy) {
    data = copy.data;
    std::cout << "Called Copy Constructor" << std::endl;
}

//Destructor
object_test::~object_test() {
    std::cout << "Called Destructor" << std::endl;
}

//Assignment
object_test& object_test::operator=(object_test copy) {
    data = copy.data;
    return *this;
    std::cout << "Called Assignment Operator" << std::endl;
}
