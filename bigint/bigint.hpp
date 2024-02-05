// Jason Graham
// 9/18/2022
// Bigint
#include <iostream>

//Include Gaurd
#ifndef bigint_hpp
#define bigint_hpp

const int NUM_DIGITS = 200;

class bigint {

    private:
        int digits[NUM_DIGITS];

    public:
        bigint();
        bigint(int);
        bigint(const char[]);

        void debugPrint(std::ostream&) const;

        friend std::ostream& operator<<(std::ostream&, const bigint&);
        friend std::istream& operator>>(std::istream&, bigint&);
        friend bool operator==(const bigint&, const bigint&);

        bigint operator+(const bigint&) const;
        bigint operator*(const bigint&) const;
        int operator[](const int&) const;

        bigint timesDigit(int) const;
        bigint times10(int) const;
        static bigint nfact(int); //extra credit
        int countZeros() const; //extra credit


};

#endif
