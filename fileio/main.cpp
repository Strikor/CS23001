#include <iostream>
#include <fstream>
#include <string>

void untilSpace() {
    std::ifstream infile("fileio-text.txt");

    std::string output;

    do {
        char ch;
        infile.get(ch);

        if(ch == ' ') break;

        output = output + ch;

    } while(true);

    std::cout << output << std::endl;
    infile.close();

}

void addTwoFString() {
    std::ifstream infile("fileio-data-1.txt");
    
    int num1 = 0;
    int num2 = 0;

    do{
        char ch;
        infile.get(ch);

        //ch is either a ; or a num
        if(ch == ';') break;

        int digit = ch - int('0');
        num1 = num1 * 10 + digit;

    } while(true);

    infile.get();

    do{
        char ch;
        infile.get(ch);

        //ch is either a ; or a num
        if(ch == ';') break;

        int digit = ch - int('0');
        num2 = num2 * 10 + digit;

    } while(true);

    //std::cout << num1 << std::endl;
    //std::cout << num2 << std::endl;
    //int out = num1 + num2;

    std::cout << (num1 + num2) << std::endl;
    infile.close();

}

int main() {
    untilSpace();

    addTwoFString();

}
