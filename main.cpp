#include <iostream>
#include "BigInt.h"

int main() {
    BInt::BigInt a("1234");
    BInt::BigInt b("-2345");
    BInt::BigInt c("9999");
    BInt::BigInt d(b);

    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
    std::cout<<d<<std::endl;
    a += c;
    std::cout<<a<<std::endl;
    return 0;
}
