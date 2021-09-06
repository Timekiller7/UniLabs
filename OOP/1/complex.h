#ifndef INC_1_COMPLEX_H
#define INC_1_COMPLEX_H
#include <cassert>
#include <iostream>
/*
 Реализация должна содержать два поля,
 определяющие соответственно действительную и мнимую часть комплексного числа

 -	сложение, +
-	вычитание, +
-	умножение, +
-	деление, +
-	вывод комплексного числа на экран дисплея. +
 */

class Complex {
   private:
        double _re, _im;
   public:
        Complex()
        {
            _re = 0;
            _im = 0;
        }

        Complex(double re, double im)
        {
            _re = re;
            _im = im;
        }

        void set(double re, double im) {
            _re = re;
            _im = im;
        }

        //конструктор копирования
        Complex(const Complex &arg) : _re(arg._re), _im(arg._im) { }

        Complex operator+(const Complex &arg) {
            Complex result(*this);
            result._re += arg._re;
            result._im += arg._im;
            return result;
        }

        Complex operator-(const Complex &arg) {
            Complex result(*this);
            result._re -= arg._re;
            result._im -= arg._im;
            return result;
        }

        Complex operator*(const Complex &arg) {
            Complex result(*this);
            result._re = _re*arg._re - _im*arg._im;
            result._im = _re*arg._im + _im*arg._re;
            return result;
        }

        Complex operator/(const Complex &arg) {
            Complex result(*this);
            size_t temp = pow(arg._re,2) + pow(arg._im, 2);
            result._re = (_re*arg._re + _im*arg._im)/temp;
            result._im = (_im*arg._re - _re*arg._im)/temp;
            return result;
        }

        void get() {
            if (_im > 0) std::cout << _re << " + " << _im <<" i"<< std::endl;
            else if (_im < 0)  std::cout << _re << " - " << -(_im) <<" i"<< std::endl;
            else std::cout << _re << " + " << _im <<" i"<< std::endl;
        }
};

#endif //INC_1_COMPLEX_H
