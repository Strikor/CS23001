#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-1.txt");      // Open a file
    if(!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }

    //Until end of file
    while(!in.eof()){
        //Read two bigints
        bigint num1 = 0;
        bigint num2 = 0;
        bigint result = 0;
        char ch;

        while(true) {
            in.get(ch);
            
            if(in.eof()) return 0;

            //ch is either a ; or a num
            if(ch == ';') break;

            int digit = ch - int('0');
            if(digit >= 0 && digit < 10) {
                num1 = num1.times10(1);
                num1 = num1 + digit;
            }
            

        }

         

        while(true) {
            in.get(ch);

            //ch is either a ; or a num
            if(ch == ';') break;

            int digit = ch - int('0');
            if(digit >= 0 && digit < 10) {
                num2 = num2.times10(1);
                num2 = num2 + digit;
            }

        } 

        //Print them out
        std::cout << (num1) << std::endl;
        std::cout << std::endl;
        std::cout << (num2) << std::endl;
        
        //Add them together
        result = num1 + num2;
        //Print out results
        std::cout << result << std::endl;
        std::cout << std::endl;

    }
 
    in.close();                  // Close file/input stream
    return 0;
}