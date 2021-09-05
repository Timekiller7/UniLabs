#include "matrix.h"
#include <iostream>
/*
*Три конструктора: конструктор умолчания, конструктор с параметрами, конструктор копирования.+
*Для классов, в которых конструктор выделяет память,
  должен быть предусмотрен деструктор.+
*В классах, используемых для хранения, должны быть предусмотрены методы доступа.
*/
int main() {
    size_t row = 2, col = 2;

    matrix mat1;
    matrix mat2(row, col, 2 ,2 ,10 ,10);
   // matrix mCopy(mat2);
    //mCopy.setMatrix();
    mat1.setMatrix();
    mat2.setMatrix();

   mat1.getMatrix();
   mat2.getMatrix();

   std::cout<<"\nAdd: "<<std::endl;
   mat1 + mat2;  // mat 1 = mat1 + mat2
   std::cout<<"\nSub: "<<std::endl;
   mat1 - mat2;  // mat 1 = начальное mat1

 //  mat1.sumRow();
   return 0;
}
