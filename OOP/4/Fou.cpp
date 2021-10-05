#include "Fou.h"
#include "thr.h"
#include <iostream>

Fou::Fou( ): Thr() {
    colour = "green";
}

Fou::Fou(string str, const Thr &arg): Thr(arg) {
    colour = "yellow";
}

Fou::Fou(const Fou &arg): Thr(arg) {
    colour = arg.colour;
}

Fou::~Fou( ) {
    colour.clear();
}

void Fou::getStrFromFou() {
    std::cout << "String in two: " << s <<std::endl;
}

void Fou::setStrF(string str) {
    colour = str;
}

string Fou::getStrF( ) const {
    return colour;
}

void Fou::print( ) {
    std::cout << "Colour is: " << colour ;
}