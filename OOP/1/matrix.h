#ifndef INC_1_MATRIX_H
#define INC_1_MATRIX_H
#include <cassert>
#include <iostream>
/*
Необходимо разработать класс, инкапсулирующий динамическую матрицу.
Память для такой матрицы должна выделяться во время выполнения программы.

Cледует создать матрицу, которую можно условно назвать матрицей в стиле языка Паскаль(=> индексы с единицы).
Конструктор такой матрицы должен определять минимальное и максимальное значения индекса для строк и столбцов.
Разрабатываемые классы должны обеспечить выполнения следующих операций:
-	сложение матриц,
-	вычитание матриц,
-	вывод матрицы на экран дисплея,
-	ввод элементов матрицы с клавиатуры,
-	вычисление суммы элементов каждой строки,
-	вычисление суммы элементов каждого столбца.
*/

class matrix {
private:
    size_t maxRow;
    size_t minRow;
    size_t maxCol;
    size_t minCol;
    double **el= nullptr;                 //element

public:
    bool isRightMatrix(size_t row, size_t col) {
        if (row >= minRow && row <= maxRow && col >= minCol && col <= maxCol ){
            return true;
        }
        else {
            return false;
        }
    }

    matrix(size_t row, size_t col) {
        minRow = 2;                            //по 2 стр и столбца тк в паскале индексы с 1
        minCol = 2;
        maxRow = 10;
        maxCol = 10;

        assert(isRightMatrix(row, col) && "Inappropriate row and column for matrix");
        el= new double *[row - 1];            // выделение памяти для строк, далее - столбцов
        for (size_t i = 1; i <= row; i++) {
            el[i] = new double[col] {0};
        }
    }

    void setMatrix(size_t row, size_t col) // заполнение массива
    {
        for (size_t i = 1; i <= row; i++)
            for (size_t j = 1; j <= col; j++)
                std::cin >> el[i][j]; // ввод элементов матрицы с клавиатуры
    }

    void getMatrix(size_t row, size_t col)
    {
        for (size_t i = 1; i <= row; i++)
            for (size_t j = 1; j <= col; j++)
                std::cout << "["<<i<<"]["<<j<<"] = " << el[i][j] <<"\n";
    }

};


#endif //INC_1_MATRIX_H
