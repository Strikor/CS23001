// Jason Graham
// 9/18/2022
// Bigint
#include "bigint.hpp"
#include <iostream>

//default constructor
bigint::bigint(){
    for(int i =0; i < NUM_DIGITS; i++){
        digits[i] = 0;
    }

}

//integer constructor
bigint::bigint(int uNum) {
    int temp;

    for (int i = 0; i < NUM_DIGITS; ++i) {
        if (uNum > 9) {
            temp = uNum % 10;
            digits[i] = temp;
            uNum = uNum / 10;

        } else if (uNum <= 9) {
            digits[i] = uNum;
            uNum = uNum / 10;
        } else {
            break;
        }
    }

}

//char[] constructor
bigint::bigint(const char charArr[]) {
    int count = 0;
    int length = 0;


    while (charArr[count] != '\0') { //null character
        count++;
    }
    
    length = count;

    for (int i = 0; i < NUM_DIGITS; ++i) {
        if (i < length) {
            digits[i] = charArr[count - 1] - '0';
            count--;
        } else {
            digits[i] = 0;
        }
    }
}

void bigint::debugPrint(std::ostream& out) const {
    for(int i = NUM_DIGITS - 1; i > 0; i--) {
        out << digits[i] << "|";
    }
}


//EXTRA CREDIT!!!!

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
bigint bigint::nfact(int fact) {
	bigint result("1");

	for (int i = 1; i <= fact; ++i) {
		result = result * i;
	}

	return result;
}

int bigint::countZeros() const {
    int result = 0;

    if(*this == 0) return 0; // if the bigint is 0 anyway skip all the counting
    
    //count the zeros before hitting a normal number
    for (int i = 0; i < NUM_DIGITS; ++i) {
		if (digits[i] == 0) {
			result++;
		} else {
			break;
		}
	}

	return result;
    
}

// END EXTRA CREDIT!!!!!

bigint bigint::timesDigit(int multi) const {
    bigint result;

    //this honestly kindof feels like cheating
    //this method of multiply is only efficient when dealing with
    //small single digit multipliers
    //will have to rethink for overloading operator*
    for(int i = 0; i < multi; ++i) {
        result = result + *this;
    }

    return result;

}

bigint bigint::times10(int n) const {
    bigint result;

    for(int i = NUM_DIGITS - n - 1; i >= 0; --i) {
        result.digits[i + n] = digits[i];
    }

    return result;
}

bigint bigint::operator*(const bigint& multi) const {
    bigint product;
	bigint temp;

	for (int i = 0; i < NUM_DIGITS - 1; ++i) {
		temp = this->timesDigit(multi[i]);
		product = product + temp.times10(i);
	}
	return product;
}

std::ostream& operator<<(std::ostream& out, const bigint& bigintToPrint) {
	int count = 0;

	/*if (count == 500) {
		out << 0;
		return out;
	}*/

    //Fixed Single Digit of 0 not printing
    if(bigintToPrint == 0) { //Null Character
        out << '0';
        return out;
    }

	for (int i = NUM_DIGITS - 1; i >= 0; --i) { // Fixed Single Number not working (i > 0) -> (i >= 0)
		if (bigintToPrint.digits[i] == 0) {
			count++;
		} else {
			for (int j = NUM_DIGITS - (count + 1); j >= 0; --j) {
				out << bigintToPrint.digits[j];
			}
			break;
		}
	}

	return out;
}

std::istream& operator>>(std::istream& in, bigint& bigintOpen) {
    char cn; //CurrentNumber
    int count = 0;
    int temp[NUM_DIGITS];

    while(in >> cn) {
        if(cn == ';') {
            break;
        }

        temp[count] = cn - '0';//'0' offsets the askii value over to the number
        ++count;

    }

    for(int i = 0; i < count; ++i){
        bigintOpen.digits[i] = temp[i];
    }

    return in; //close the input stream

}

bool operator==(const bigint& lhs, const bigint& rhs) {
	for (int i = 0; i < NUM_DIGITS; i++) {
		if (lhs.digits[i] != rhs.digits[i]) {
			return false;
		}
	}
	return true;
}

int bigint::operator[](const int& i) const {
    return digits[i];
}

bigint bigint::operator+(const bigint& bigintToBeAdded) const {
    bigint result;
    int sum = 0;
    bool carry = false;

    for(int i = 0; i < NUM_DIGITS; ++i) {
        sum = digits[i] + bigintToBeAdded.digits[i];
        if(carry) {
            ++sum;
            carry = false;
        }

        if(sum >= 10) {
            carry = true;
            sum -= 10;
        }

        result.digits[i] = sum;
        
    }

    return result;
}
