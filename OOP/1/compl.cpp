#include "complex.h"
#include <cstring>
#include <iostream>

template<typename RealNum, typename ImaginaryNum>
T::Complex()
{
    _re = 0;
    _im = 0;
}

Complex::Complex(T re, T im)
{
_re = re;
_im = im;
}

void Complex::set(T re, T im) {
_re = re;
_im = im;
}

//конструктор копирования
T::Complex(const T &arg) : _re(arg._re), _im(arg._im) { }

/*   Complex operator+(const Complex &arg) {
       T result(*this);
       result._re += arg._re;
       result._im += arg._im;
       return result;
   }*/
template <class T >
Complex<T> operator+(Complex<T> const &a) {
_re += a._re;
_im += a._im;
return *this;
}

Complex  operator-(const Complex &arg) {
    Complex result(*this);
    result._re -= arg._re;
    result._im -= arg._im;
    return result;
}

Complex  operator*(const Complex &arg) {
    Complex result(*this);
    result._re = _re*arg._re - _im*arg._im;
    result._im = _re*arg._im + _im*arg._re;
    return result;
}

Complex  operator/(const Complex &arg) {
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