//
// Created by 84000 on 2020/11/24.
//

#ifndef BIGINT_BIGINT_H
#define BIGINT_BIGINT_H
#include <vector>
#include <string>
#include <exception>
#include <ostream>
#define BIGINT_BEGIN namespace BInt {
#define BIGINT_END }

BIGINT_BEGIN

class notAInt : public std::exception {
    const char * what () const throw () override
    {
        return "big int: not a num from '0' to '9'";
    }
};


int toInt(const char& _ch);

class BigInt {
    friend std::ostream &operator << (std::ostream &out, const BigInt &va);
public:
    BigInt();
    explicit BigInt(const std::string& _e);
    BigInt(const BigInt& _oriInt);
    BigInt& operator=(const BigInt& _oriInt);

    //operator
    BigInt operator+(const BigInt& _anotherInt) const;
    BigInt operator+=(const BigInt& _anotherInt) ;
    //BigInt operator-(const BigInt& _anotherInt);

private:
    BigInt& carry();
    bool nonNegative;
    std::vector<int> _ele;
};
BIGINT_END
#endif //BIGINT_BIGINT_H
