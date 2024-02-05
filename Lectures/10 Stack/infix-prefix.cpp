#include "stack.hpp"
#include <iostream>
#include <string>
typedef std::string String;

// expr = must be valid fully paranthesised infix expression
String infix_to_postfix(const char expr[]) {
    stack<String> S;
    int i = 0;
    String lhs, rhs, op, temp = " ";
    while (expr[i] != 0){
        if (expr[i] == ')'){
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(lhs + rhs + op); 
        }else if (expr[i] != '('){
            temp[0] = expr[i];
            S.push(expr[i]);
        }
        ++i;
    }
    return S.pop();
}

String infix_to_prefix(const char expr[]) {
    stack<String> S;
    int i = 0;
    String lhs, rhs, op, temp = " ";
    while (expr[i] != 0){
        if (expr[i] == ')'){
            rhs = S.pop();
            op = S.pop();
            lhs = S.pop();
            S.push(lhs + rhs + op); 
        }else if (expr[i] != '('){
            temp[0] = expr[i];
            S.push(expr[i]);
        }
        ++i;
    }
    return S.pop();
}