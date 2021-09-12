#include <iostream>
#include "one.h"
#include "two.h"
#include <cstring>
using std::string;
//34
/*
 * float f char* ps
 * string s COne* p
 */
int main() {
    string temp = "working";

    std::cout << "TEST FOR FIRST CLASS: " << std::endl;
    One ob(7,"f");

    One ocopy(ob);        //конструктор копирования
    ocopy.print();
    std::cout  << std::endl;

    One ob2;               //проверка геттеров и тождества
    std::cout << "get char of first object: " << ob.getPs() << std::endl;
    std::cout  << std::endl;

    ob2.print();
    ob = ob2;
    ob.print();

    std::cout  << std::endl << "TEST FOR SECOND CLASS: " << std::endl;
    Two ob3(&ob, temp);
    Two ob4;
    Two copy(ob3);
    copy.print();
    std::cout  << std::endl;

    //по умолчанию в конструкторе One: float = 1,5, char ="t"
    copy = ob4;
    copy.print();
    std::cout  << std::endl;

    copy.getObject();

    return 0;
}
