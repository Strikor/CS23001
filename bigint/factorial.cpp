#include <iostream> 
#include <cassert>
#include "bigint.hpp"

int main () {
/*
    Finding the factorial is the easy part the hard part
    is finding the number of trailing zeros. Finding a trailing
    zero without using code can be done by counting the number
    of the multiples of 5 and 2 contained within the factorial,
    As whenever multiplying by 5's and 2's we create a zero.
    For instance with the factorial of 10 (10!), we have 2
    multiples of 5, 5 & 10. Then we also have 5 multiples of 2,
    2, 4, 6, 8, 10. Using these multiples we can make 2 pairs
    of 2-5 combos meaning our factorial will have 2 trailing
    zeros: 10! = 3628800

    nfact() & countZeros() are both methods for the assignment
*/

    //get the factorial of 100
    bigint fact(bigint::nfact(100));
    std::cout << fact << std::endl;

    //countZeros() simply counts how many zeros it hits by moving
    //up through the array unill it hits a non-zero number then gives
    //that as an output.
    int zeros = fact.countZeros();
    std::cout << zeros << std::endl;
}