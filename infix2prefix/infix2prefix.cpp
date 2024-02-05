// Jason Graham
// 11/18/2022
// copy of prefix code
// This is just a copy of my working code from milestone 3/challenge

#include "../assembler/stack.hpp"
#include "../string/string.hpp"
#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {

    if (argc != 2) {      // Error if there are not 2 things on the command line
        std::cerr << "Error" << std::endl;
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        exit(1);         // Exit with error
    }

    std::ifstream in(argv[1]);     // Open file, quit if open fails
    if (!in) {
        std::cerr << "Error: Can not open " << argv[1] << std::endl;
        exit(2);
    }

    // Process the input_file
    std::vector<String> prefix;
    std::vector<String> infix;
    while(true) {
        char ch[512];
        in.getline(ch, 511);
        if(in.eof()) break;
        prefix.push_back(convertPrefix(String(ch)));
        infix.push_back(String(ch));
    }

    in.close();

    //Print Postfix Expressions
    if(argc == 2) { // No output file given
        for(int i = 0; i < (int)prefix.size(); ++i) {
            std::cout << "Infix Expression: " << infix[i].split(';')[0] << std::endl
            << "Prefix Expression: " << prefix[i] << std::endl << std::endl
            << convertPreAssembly(prefix[i]) << std::endl;
            
        }

    }

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