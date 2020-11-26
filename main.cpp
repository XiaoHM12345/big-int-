#include <iostream>
#include "BigInt.h"

void test1()
{
    BInt::BigInt a("123");
    BInt::BigInt b("456");
    BInt::BigInt c("-124");
    BInt::BigInt d("-456");
    BInt::BigInt e = a;
    if (a > b)
        std::cout<<a<<"<"<<b<<" true"<<std::endl;
    if (b > a)
        std::cout<<b<<"<"<<a<<" true"<<std::endl;
    if (c > d)
        std::cout<<c<<"<"<<d<<" true"<<std::endl;
    if (d == c)
        std::cout<<d<<"!="<<c<<" true"<<std::endl;
    if (a != e)
        std::cout<<a<<"=="<<e<<" true"<<std::endl;
}

int main() {
    BInt::BigInt a("1234");
    BInt::BigInt b("-11341");
    BInt::BigInt c("9999");
    BInt::BigInt d(b);

    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
    std::cout<<d<<std::endl;
    b = b - a;
    std::cin>>b;
    std::cout<<b<<std::endl;
    //test1();
    return 0;
}
