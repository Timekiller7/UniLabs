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
-	сложение матриц, +
-	вычитание матриц, +
-	вывод матрицы на экран дисплея, +
-	ввод элементов матрицы с клавиатуры, +
-	вычисление суммы элементов каждой строки, +
-	вычисление суммы элементов каждого столбца. +
*/

class Matrix {
private:
    size_t maxRow;
    size_t minRow;
    size_t maxCol;
    size_t minCol;
    size_t mRow;        //строка и столбец матрицы (объекта класса)
    size_t mCol;
    double **el= nullptr;                 //element

    void allocateMemory(size_t row, size_t col){
        el = new double *[row + 1];            // выделение памяти для строк, далее - столбцов
        for (size_t i = 0; i <= row; i++)       //row +1 тк по стилю паскаля
            el[i] = new double[col + 1];
    }

public:
    //конструктор по умолчанию
    Matrix() {
        mRow = 2; mCol = 2;
        minRow = 2;                            //по 2 стр и столбца тк в паскале индексы с 1
        minCol = 2;
        maxRow = 10;
        maxCol = 10;
        allocateMemory(2, 2);
    }

    Matrix(size_t _mRow, size_t _mCol) {
        minRow = 2;
        minCol = 2;
        maxRow = 10;
        maxCol = 10;
        allocateMemory(2, 2);
    }

    bool isRightMatrix(size_t row, size_t col) {
        if (row >= minRow && row <= maxRow && col >= minCol && col <= maxCol ) {
            return true;
        }
        else {
            return false;
        }
    }

    //конструктор с параметрами
    Matrix(size_t row, size_t col, size_t minC, size_t minR, size_t maxC, size_t maxR) {
        minRow = minR;
        minCol = minC;
        maxRow = maxR;
        maxCol = maxC;
        assert(isRightMatrix(row, col) && "Inappropriate row and column for matrix");
        mRow = row; mCol = col;
        allocateMemory(row, col);
    }

    //конструктор копирования
    Matrix(const Matrix &arg) : mRow(arg.mRow), mCol(arg.mCol) {
        // Примечание: Мы имеем прямой доступ к членам объекта arg, поскольку мы сейчас находимся внутри класса matrix
        el= new double *[mRow + 1];            // выделение памяти для строк, далее - столбцов
        for (size_t i = 0; i <= mRow; i++) {
            el[i] = new double[mCol + 1];
            std::copy(arg.el[i], arg.el[i] + (mCol + 1), el[i]); // Копируем очередную строку из arg в текущую
        }
    }

    void setMatrix() {
        for (size_t i = 1; i <= mRow; i++)
            for (size_t j = 1; j <= mCol; j++)
                std::cin >> el[i][j];
    }

    Matrix operator+(const Matrix &arg) {
        Matrix result(*this);
        if (mRow == arg.mRow && mCol== arg.mCol) {  // Сложение возможно, если только размеры матриц равны
            for (size_t i = 1; i <= mRow; i++)
                for (size_t j = 1; j <= mCol; j++)
                       result.el[i][j] += arg.el[i][j];
        }
        return result;
    }

    // Вычитание матриц
    void operator-(const Matrix &arg) {
        if (mRow == arg.mRow && mCol == arg.mCol) {
            for (size_t i = 1; i <= mRow; ++i) {
                for (size_t j = 1; j <= mCol; ++j) {
                    el[i][j] -= arg.el[i][j];
                    std::cout << el[i][j]<<" ";
                }
                std::cout << std::endl;
            }
        }
    }

    void sumRow() {
        int sum;
        for (size_t i = 1; i <= mRow; i++){
            sum = 0;
            for (size_t j = 1; j <= mCol; j++){
                sum += el[i][j];
            }
            std::cout << sum << std::endl;
        }
    }

    void sumCol() {
        int sum;
        for (size_t j = 1; j <= mCol; j++) {
            sum = 0;
            for (size_t i = 1; i <= mRow; i++) {
                sum += el[i][j];
            }
            std::cout << sum << " ";
        }
    }

    void getMatrix() {
        for (size_t i = 1; i <= mRow; i++) {
            for (size_t j = 1; j <= mCol; j++){
              //  std::cout << "["<<i<<"]["<<j<<"] = " << el[i][j] <<" ";
                std::cout << el[i][j] <<" ";
            }
            std::cout<<std::endl;
        }
    }

    // Дружественный оператор для вывода матрицы в выходной поток os (cout, ...)
    friend std::ostream &operator<<(std::ostream &os, const Matrix &arg) {
        for (size_t i = 1; i <= arg.mRow; i++) {
          //  os << arg.el[i][1];
            for (size_t j = 1; j <= arg.mCol; j++) {
                os << ' ' << arg.el[i][j];
            }
            os << '\n';
        }
        return os;
    }

    //другое: методы доступа
    void setElement(size_t i, size_t j, double value) {
        if (i >= 1 && i <= mRow && j >= 1 && j <= mCol)
            el[i][j] = value;
        else
            assert("Inappropriate indexes");
    }

    void getElement(size_t i, size_t j) {
        if (i >= 1 && i <= mRow && j >= 1 && j <= mCol)
            std::cout << el[i][j] << std::endl;
        else
            assert("Inappropriate indexes");
    }

    // Деструктор
     ~Matrix() {
       for (size_t i = 0; i <= mRow; i++) {
           delete[] el[i];
       }
       delete[] el; // Если el = nullptr, то delete[] не приведет к ошибке
    }
};


#endif //INC_1_MATRIX_H
