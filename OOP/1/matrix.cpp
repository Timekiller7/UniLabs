#include "matrix.h"
#include <iostream>

int main() {
    size_t row = 3, col = 2;
    matrix mas(row, col);
    mas.setMatrix(row, col);
    mas.getMatrix(row, col);

    return 0;
}
