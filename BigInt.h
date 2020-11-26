//
// Created by 84000 on 2020/11/24.
//

#ifndef BIGINT_BIGINT_H
#define BIGINT_BIGINT_H
#include <vector>
#include <string>
#include <exception>
#include <ostream>
#include <istream>
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
    friend std::istream &operator >> (std::istream &is, BigInt &va);
public:
    BigInt();
    explicit BigInt(const std::string& _e);
    BigInt(const BigInt& _oriInt);
    BigInt& operator=(const BigInt& _oriInt);

    //operator
    BigInt operator+(const BigInt& _anotherInt) const;
    BigInt operator+=(const BigInt& _anotherInt) ;
    BigInt operator-=(const BigInt& _anotherInt) ;
    BigInt operator-(const BigInt& _anotherInt) const;
    bool operator<(const BigInt& _anotherInt) const;
    bool operator>(const BigInt& _anotherInt) const;
    bool operator<=(const BigInt& _anotherInt) const;
    bool operator>=(const BigInt& _anotherInt) const;
    bool operator!=(const BigInt& _anotherInt) const;
    bool operator==(const BigInt& _anotherInt) const;
    //BigInt operator-(const BigInt& _anotherInt);

    //other
    BigInt abs() const;

private:
    BigInt& carryAdd();
    BigInt& carryMin();
    bool nonNegative;
    std::vector<int> _ele;
};
BIGINT_END
#endif //BIGINT_BIGINT_H
