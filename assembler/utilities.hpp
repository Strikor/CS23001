#ifndef CS2_UTILITIES_HPP_
#define CS2_UTILITIES_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: utilities.hpp
//
// Programmer: Jason Graham
// Date:       Fall 2022
//

#include "stack.hpp"
#include "../string/string.hpp"

//Milestone 2
String convertPostfix(String);

//Milestone 3
String convertPostAssembly(String);
String evaluate(String, String, String, int);

//Challenge
String convertPrefix(String);
String convertPreAssembly(String);

#endif
