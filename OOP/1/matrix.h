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
-	сложение матриц,+
-	вычитание матриц,+
-	вывод матрицы на экран дисплея, +
-	ввод элементов матрицы с клавиатуры, +
-	вычисление суммы элементов каждой строки,
-	вычисление суммы элементов каждого столбца.
*/

class matrix {
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
           // for (int j = 0; j <= col; j++)
           //     el[i][j] = 0;
    }

public:
    //конструктор по умолчанию
    matrix() {
        mRow = 2; mCol = 2;
        minRow = 2;                            //по 2 стр и столбца тк в паскале индексы с 1
        minCol = 2;
        maxRow = 10;
        maxCol = 10;
        allocateMemory(2, 2);
    }

    matrix(size_t _mRow, size_t _mCol) {
        minRow = 2;                            //по 2 стр и столбца тк в паскале индексы с 1
        minCol = 2;
        maxRow = 10;
        maxCol = 10;
        allocateMemory(2, 2);
    }

    bool isRightMatrix(size_t row, size_t col) {
        if (row >= minRow && row <= maxRow && col >= minCol && col <= maxCol ){
            return true;
        }
        else {
            return false;
        }
    }

    //конструктор с параметрами
    matrix(size_t row, size_t col, size_t minC, size_t minR, size_t maxC, size_t maxR) {
        minRow = minR;
        minCol = minC;
        maxRow = maxR;
        maxCol = maxC;
        assert(isRightMatrix(row, col) && "Inappropriate row and column for matrix");
        mRow = row; mCol = col;
        allocateMemory(row, col);
    }

    //конструктор копирования
    matrix(const matrix &arg) : mRow(arg.mRow), mCol(arg.mCol) {
        // Примечание: Мы имеем прямой доступ к членам объекта arg, поскольку мы сейчас находимся внутри класса matrix
        el= new double *[mRow];            // выделение памяти для строк, далее - столбцов
        for (size_t i = 1; i <= mRow; i++) {
            el[i] = new double[mCol] {0};
            std::copy(arg.el[i], arg.el[i] + mCol, el[i]); // Копируем очередную строку из arg в текущую
        }
    }

    void setMatrix() // заполнение массива
    {
        for (size_t i = 1; i <= mRow; i++)
            for (size_t j = 1; j <= mCol; j++)
                std::cin >> el[i][j]; // ввод элементов матрицы с клавиатуры
    }

    // Сложение матриц
    void operator+(matrix &arg) {
        if (mRow == arg.mRow && mCol== arg.mCol) { // Сложение возможно, если только размеры матриц равны
            for (size_t i = 1; i <= mRow; i++) {
                for (size_t j = 1; j <= mCol; j++) {
                //    result.el[i][j] += arg.el[i][j];
                //    result.el[i][j]+=el[i][j];
                    el[i][j] += arg.el[i][j];
                  std::cout << el[i][j]<<" ";
                }
                std::cout <<std::endl;
            }
        }
    }
    // Вычитание матриц
    void operator-(matrix &arg) {
        if (mRow == arg.mRow && mCol== arg.mCol) { // Сложение возможно, если только размеры матриц равны
            matrix result; // Копируем данные из *this в result (конструктор копирования)
            for (size_t i = 1; i <= mRow; ++i) {
                for (size_t j = 1; j <= mCol; ++j) {
                    el[i][j] += arg.el[i][j];
                    std::cout << el[i][j]<<" ";
                }
                std::cout <<std::endl;
            }
        }
    }

    void getMatrix()
    {
        for (size_t i = 1; i <= mRow; i++)
            for (size_t j = 1; j <= mCol; j++)
                std::cout << "["<<i<<"]["<<j<<"] = " << el[i][j] <<std::endl;
    }

    // Дружественный оператор для вывода матрицы в выходной поток os (cout, ...)
    friend std::ostream &operator<<(std::ostream &os, const matrix &arg) {
        for (size_t i = 1; i <= arg.mRow; i++) {
          //  os << arg.el[i][1];
            for (size_t j = 1; j <= arg.mCol; j++) {
                os << ' ' << arg.el[i][j];
            }
            os << '\n';
        }
        return os;
    }

    // Деструктор
     ~matrix() {
       for (size_t i = 0; i <= mRow; i++) {
           delete[] el[i];
       }
       delete[] el; // Если el = nullptr, то delete[] не приведет к ошибке
    }

};


#endif //INC_1_MATRIX_H
