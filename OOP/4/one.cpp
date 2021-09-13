#include "one.h"
#include <cstring>
#include <iostream>
// #include  <memory>

One::One() {
    f = 1.5;
    ps = new char[1];
    memcpy(ps, "t", 1);
}

One::One(float ff, const char *str) {
    f = ff;
    size_t len = strlen(str) + 1;
    ps = new char[len];
    memcpy(ps, str, len);
}

One::One(const One &arg) {
    f = arg.f;
    size_t len = strlen(arg.ps) + 1;
    ps = new char[len];
    memcpy(ps, arg.ps, len);
}

One::~One() {
    delete ps;
}

One &One::operator=(const One &arg) {
    if (this == &arg) {
        return *this;
    }
    delete ps;
    size_t len = strlen(arg.ps) + 1;
    ps = new char[len];
    memcpy(ps, arg.ps, len);
    f = arg.f;
    return *this;
}

void One::setChar(const char *str) {
    memcpy(ps, str, 1);
}

void One::setFloat(float num) {
    f = num;
}

float One::getF() {
    return f;
}

char One::getPs() {
    return *ps;
}

void One::print() {
    std::cout << "float: " << f << std::endl;
    std::cout << "char: " << *ps << std::endl;
}