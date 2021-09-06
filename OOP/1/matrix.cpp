#include "matrix.h"
#include <iostream>
/*
*Три конструктора: конструктор умолчания, конструктор с параметрами, конструктор копирования.+
*Для классов, в которых конструктор выделяет память,
  должен быть предусмотрен деструктор.+
*В классах, используемых для хранения, должны быть предусмотрены методы доступа. +
*/
int main() {
    size_t row = 2, col = 2;

    Matrix mat1;
    Matrix mat2(row, col, 2 ,2 ,10 ,10);
    // matrix mCopy(mat2);
    //mCopy.setMatrix();
    mat1.setMatrix();
    mat2.setMatrix();

    //mat1.getMatrix();
    // mat2.getMatrix();

    std::cout<<"\nAdd: "<<std::endl;
    (mat1 + mat2).getMatrix();          //возвращает матрицу (использование конструктора копирования)

    std::cout<<"\nSub: "<<std::endl;
    mat2 - mat1;         //изменяется матрица 2

    std::cout<<"\nSum of elemets in rows: "<<std::endl;
    mat1.sumRow();

    std::cout<<"\nSum of elemets in columns: "<<std::endl;
    mat1.sumCol();

    std::cout<<"\n\nSet/Get element: "<<std::endl;
    mat1.getElement(2, 2);
    mat1.setElement(2, 2, 100);
    mat1.getElement(2, 2);
    return 0;
}
