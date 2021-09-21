#ifndef INC_1_COMPLEX_H
#define INC_1_COMPLEX_H

template <class T>
class Complex {
    public:
        T _re;
        T _im;
        Complex();

        explicit Complex(T re, T im);

        //конструктор копирования
        Complex(const T &arg);

        void set(T re, T im);

    Complex  operator+(const Complex &arg);

    Complex  operator-(const Complex &arg);

    Complex  operator*(const Complex &arg);

    Complex  operator/(const Complex &arg);

    void get();

};


#endif //INC_1_COMPLEX_H
