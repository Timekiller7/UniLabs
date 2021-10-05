#include "thr.h"
#include "two.h"
#include <iostream>

Thr::Thr( ): Two() {
    debug = true;
}

Thr::Thr(const bool bug, const Two &arg): Two(arg) {
    debug = bug;
}

Thr::Thr(const Thr &arg): Two(arg) {
    debug = arg.debug;
}

Thr::~Thr( ) { }

 void Thr::getStrFromThr() {
    std::cout << "String in two: " << s <<std::endl;
}

void Thr::setBool(bool bug) {
    debug = bug;
}

bool Thr::getBool( ) const {
    return debug;
}

void Thr::print( ) {
    std::cout << "Debug is: " << debug<< std::endl;
}