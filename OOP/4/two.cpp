#include "two.h"
#include "one.h"
#include <cstring>
#include <iostream>


Two::Two( ) {
    One obj;
    p = new One(obj);
    s = "this is a string from constructor for Two";
}

Two::Two(const One *obj, string str) {
    p = new One(*obj);
    s = str;
}

Two::Two(const Two &arg) {
    p = new One(*arg.p);
    s = arg.s;
}

Two::~Two() {
    delete p;
    s.clear();
}

Two &Two::operator=(const Two &arg) {
    if (this == &arg) {
        return *this;
    }
    *p = *arg.p;
    s = arg.s;
    return *this;
}

void Two::setAll(const  One obj, string str ) {
    *p = One(obj);
    s = str;
}

void Two::getObject( ) {
    std::cout << "Float in object: " << p->getF() << std::endl;
    std::cout << "Char in object: " << p->getPs() << std::endl;
}

void Two::getString( ) {
    std::cout << "String: " << s << std::endl;
}

void Two::print() {
    getObject();
    getString();
}