//
// Created by 84000 on 2020/11/24.
//

#include "BigInt.h"

int BInt::toInt(const char &_ch) {
    if (_ch > 57 || _ch < 48)
        throw BInt::notAInt();
    return _ch - 48;
}

BInt::BigInt::BigInt(const std::string& _e) {
    /*std::string::const_iterator it1 = _e.begin();
    if (*it1 == '-') {
        this->nonNegative = false;
        it1++;
    }
    for (;it1 != _e.end(); it1++)
        this->_ele.push_back(BInt::toInt(*it1));*/
    std::string::const_reverse_iterator it = _e.crbegin();
    for (; it != _e.crend(); it++) {
        if (*it == '-') {
            this->nonNegative = false;
            if ((it + 1) != _e.crend())
                throw notAInt();
            continue;
        }
        this->_ele.push_back(BInt::toInt(*it));
    }

}

std::ostream &BInt::operator<<(std::ostream &out, const BInt::BigInt &va) {
    if (!va.nonNegative)
        out<<'-';
    for (std::vector<int>::const_reverse_iterator it = va._ele.crbegin();
    it != va._ele.crend(); it++ )
        out<<*it;
    return out;
}

BInt::BigInt::BigInt() {
    this->_ele.resize(0);
    this->nonNegative = true;
}

BInt::BigInt::BigInt(const BInt::BigInt &_oriInt) {
    this->nonNegative = _oriInt.nonNegative;
    this->_ele = _oriInt._ele;  //深拷贝？？？？？
}

BInt::BigInt &BInt::BigInt::operator=(const BInt::BigInt &_oriInt) {
    this->nonNegative = _oriInt.nonNegative;
    this->_ele = _oriInt._ele;  //深拷贝？？？？？
    return *this;
}
/*
BInt::BigInt BInt::BigInt::operator+(const BInt::BigInt &_anotherInt) const {
    std::vector<int>::const_iterator it1 = this->_ele.begin(),
                                    it2 = _anotherInt._ele.begin();
    BInt::BigInt res;
    int highBigVa;

    for (; )
}
*/
BInt::BigInt &BInt::BigInt::carry() {
    while (!this->_ele.empty() && !this->_ele.back())
        this->_ele.pop_back();
    if (this->_ele.empty())
        return *this;

    for (int i = 1; i < this->_ele.size(); i++) {
        this->_ele[i] += this->_ele[i - 1] / 10;
        this->_ele[i - 1] %= 10;
    }

    while (this->_ele.back() >= 10) {
        this->_ele.push_back(this->_ele.back() / 10);
        this->_ele[this->_ele.size() - 2] %= 10;
    }

    return *this;
}

BInt::BigInt BInt::BigInt::operator+=(const BInt::BigInt &_anotherInt) {
    if (this->_ele.size() < _anotherInt._ele.size())
        this->_ele.resize(_anotherInt._ele.size());

    for (int i = 0; i < _anotherInt._ele.size(); i++)
        this->_ele[i] += _anotherInt._ele[i];

    return this->carry();
}
