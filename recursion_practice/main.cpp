//Jason Graham
//10/28/2022
//fibonacci sequence
#include <iostream>

//n - how many iterations the program should go
int tail_fib(int n, int n1 = 0, int n2 = 1) {
    if(n1 == 0) std::cout << '0' << std::endl << '1' << std::endl;
    if(n <= 1) {
        return n2; 
    }

    std::cout << n1 + n2 << std::endl;
    return tail_fib(n - 1, n2, n1 + n2);
}

//n - how many iterations the program should go
int fib(int n) {
    if(n <= 1) return n;

    return fib(n - 1) + fib(n - 2);

}

//recursively can't cleanly print out each number in the sequence
//trying to directly print fib() creates a ton of garbage outputs
void fib_printer(int n) {
    for(int i = 0; i <= n; ++i) {
        std::cout << fib(i) << std::endl;
    }
}

int main() {
    std::cout << "How many iterations?" << std::endl;
    int n;
    std::cin >> n;

    std::cout << std::endl;
    tail_fib(n);
    std::cout << std::endl;
    std::cout << "------------------------" <<std::endl;

    fib_printer(n);

}
