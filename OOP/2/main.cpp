#include <iostream>
#include "one.h"
#include "two.h"
#include "thr.h"
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
    ob2.setChar("s");
    ob2.setFloat(3.7);
    ob = ob2;
    ob.print();

    std::cout  << std::endl << "TEST FOR SECOND CLASS: " << std::endl;
    Two ob3(&ob, temp);
    Two ob4;
    Two copy(ob3);
    copy.print();
    std::cout  << std::endl;

    //по умолчанию в конструкторе One: float = 1,5, char ="t"
    copy = ob4;      //меняется только string, тк  новый объект класса One по конструктору
    copy.print();
    std::cout  << std::endl;

    copy.getObject();
    copy.setAll(ob, "another test");

    std::cout  << std::endl << "TEST FOR THIRD CLASS: " << std::endl;

    Thr ob5(true, copy);
    std::cout  <<ob5.getBool() << std::endl;
    ob5.setBool(false);
    std::cout  <<ob5.getBool() << std::endl;
    ob5.getObject();             //примеры наследования
    ob5.getStrFromThr();    //тк protected переменная в классе Two => получаем доступ

    return 0;
}
