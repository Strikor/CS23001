//Jason Graham
//11/12/2022
//prefix.cpp

#include "utilities.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    if (argc != 2 && argc != 3) {      // Error if there are not 2 things on the command line
        std::cerr << "Error" << std::endl;
        std::cerr << "Usage: " << argv[0] << " input_file [output_file]" << std::endl;
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

    } else { // Output file
        std::ofstream out(argv[2]); //"std::ios_base::app" as the second arg opens "out" to append to a file
        if(!out){
            std::cout << "Error: Can not open " << argv[2] << "\n";
            exit(3);
        }

        for(int i = 0; i < (int)prefix.size(); ++i) {
            out << "Infix Expression: " << infix[i].split(';')[0] << std::endl
            << "Prefix Expression: " << prefix[i] << std::endl << std::endl
            << convertPreAssembly(prefix[i]) << std::endl;

            //Makes output look nice by removing extra endl at end of file
            if(i + 1 < (int)prefix.size()) out << std::endl;
            
        }

        out.close();


    }

}