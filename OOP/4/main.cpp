#include <iostream>
#include "one.h"
#include "two.h"
#include "thr.h"
#include "fou.h"
#include <cstring>
using std::string;
//34
/*
 * float f char* ps
 * string s COne* p
 */

void printAll(Two **y, size_t n) {            //base классом Two объединены
    for (int i = 0; i < n; i++) {
        y[i]->print(), std::cout << std::endl;   //функция у каждого класса вызывается, не у одного Two
    }
}

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
    copy.setAll(ob, "another test: in three and four");

    std::cout  << std::endl << "TEST FOR THIRD CLASS: " << std::endl;

    Thr ob5(true, copy);
    std::cout  <<ob5.getBool() << std::endl;
    ob5.setBool(false);
   
    std::cout  <<ob5.getBool() << std::endl;
    Thr copy2(ob5);
    std::cout << "copy2" << std::endl;
   // std::cout << copy2.getBool() << std::endl;
    copy2.getObject();
    copy2.getBool();
    copy2.print();
    ob5.getObject();             //примеры наследования
    ob5.getBool();
    ob5.print();
    ob5.getStrFromThr();    //тк protected переменная в классе Two => получаем доступ

    std::cout  << std::endl << "TEST FOR FOURTH CLASS: " << std::endl;
    Fou ob6;
    Two *x[3] ;
    x[0] = &ob4;
    x[1] = &ob5;
    x[2] = &ob6;
    printAll(x, 3);

    ob5.print();
    ob6.print();
    ob6.getStrFromFou();
    return 0;
}
