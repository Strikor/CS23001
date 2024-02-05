// Jason Graham
// 10/19/2022
// Object_Construction

#include "object_construction.hpp"

int main() {
    //Create a default object
    object_test testDef;

    //Create a copy of the first
    object_test testCpy(testDef);

    //Set the default equal to the copy
    testDef = testCpy;

    //both objects will be deleted by the ending of the function
}
