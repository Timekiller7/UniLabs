#include <iostream>
#include "one.h"
#include "two.h"
//34
/*
 * float f char* ps
 * string s COne* p
 */
int main() {
    One ob(7,"f");
    One ob2;
    std::cout << "get char: " << ob.getPs() << std::endl;
    ob2.print();
    ob = ob2;
    ob.print();


    return 0;
}
