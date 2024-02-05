//Jason Graham
//11/12/2022
//utilities.cpp

#include "../assembler/utilities.hpp"
#include <vector>
#include <iostream>

String convertPostfix(String infix) {
    std::vector<String> strings = infix.split(' ');
    stack<String> tokenStack;

    int i = 0;

    //Algorithm
    while(strings[i] != ';') {
        if(strings[i] == ')') {
            String right = tokenStack.pop();
            String oper =  tokenStack.pop();
            String left =  tokenStack.pop();
            tokenStack.push(left + ' ' + right + ' ' + oper);
        } else if (strings[i] != '(') {
            tokenStack.push(strings[i]);
        }
        ++i;
    }
    return tokenStack.top();
}

String convertPrefix(String infix) {
    std::vector<String> strings = infix.split(' ');
    stack<String> tokenStack;

    int i = 0;

    //Algorithm
    while(strings[i] != ';') {
        if(strings[i] == ')') {
            String right = tokenStack.pop();
            String oper =  tokenStack.pop();
            String left =  tokenStack.pop();
            tokenStack.push(oper + ' ' + left + ' ' + right);
        } else if (strings[i] != '(') {
            tokenStack.push(strings[i]);
        }
        ++i;
    }
    return tokenStack.top();
}

String convertPostAssembly(String postfix) {
    std::vector<String> tokens = postfix.split(' ');
    stack<String> eval;
    String result;
    
    //Algorithm
    int n = 1; // will keep track of temp variable name
    for(int i = 0; i < (int)tokens.size(); ++i) {
        if(tokens[i] != '+' && tokens[i] != '-' && tokens[i] != '*' && tokens[i] != '/') {
            eval.push(tokens[i]);
        } else {
            String right = eval.pop();
            String left = eval.pop();
            result += evaluate(left, tokens[i], right, n);
            String temp;
            temp += "TMP";
            temp += char(n + 48);
            eval.push(temp);
            ++n;
        }
    }
    return result;

}

//Making an algorithm to evaluate prefix is very easy just have to flip the direction of traversal
String convertPreAssembly(String prefix) {
std::vector<String> tokens = prefix.split(' ');
    stack<String> eval;
    String result;
    
    //The only difference in the Algorithm is the direction of the for loop
    //Algorithm
    int n = 1; // will keep track of temp variable name
    for(int i = (int)tokens.size() - 1; i >= 0; --i) {
        if(tokens[i] != '+' && tokens[i] != '-' && tokens[i] != '*' && tokens[i] != '/') {
            eval.push(tokens[i]);
        } else {
            String left = eval.pop();
            String right = eval.pop();
            result += evaluate(left, tokens[i], right, n);
            String temp;
            temp += "TMP";
            temp += char(n + 48);
            eval.push(temp);
            ++n;
        }
    }
    return result;
}

String evaluate(String left, String opp, String right, int n) {
    //load left, perform opp on right, store
    String opcode;
    String result;

    //Get opperand code
    if(opp == '+') {
        opcode = "AD";
    } else if (opp == '-') {
        opcode = "SB";
    } else if (opp == '*') {
        opcode = "MU";
    } else {
        opcode = "DV";
    }

    //Formatting
    result += "\tLD\t\t" + left + "\n";
    result += "\t" + opcode + "\t\t" + right + "\n";
    result += "\tST\t\tTMP";
    result += char(n + 48);
    result += "\n";

    return result;

}