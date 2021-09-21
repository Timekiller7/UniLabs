#include "Complex.h"
#include <cstring>
#include <iostream>


template<class T>
 Complex<T>::Complex()
{
    _re = 0;
    _im = 0;
}

template<class T>
Complex<T>::Complex(T re, T im)
{
_re = re;
_im = im;
}

template<class T>
Complex<T>::Complex(const T &arg) : _re(arg._re), _im(arg._im) { }

template<class T>
void Complex<T>::set(T re, T im) {
    _re = re;
    _im = im;
}

/*  Complex operator+(const Complex &arg) {
T result(*this);
result._re += arg._re;
result._im += arg._im;
return result;
}*/
template <class T >
Complex<T>
Complex<T>::operator+( const Complex<T>  &a) {
    _re += a._re;
    _im += a._im;
    return *this;
}

template<class T>
Complex<T>
Complex<T>::operator-(const Complex<T>  &arg) {
    _re -= arg._re;
    _im -= arg._im;
    return *this;
}

template<class T>
Complex<T>
Complex<T>::operator*(const Complex<T>  &arg)  {
    Complex result(*this);
    result._re = _re*arg._re - _im*arg._im;
    result._im = _re*arg._im + _im*arg._re;
    return result;
}

template<class T>
Complex<T>
Complex<T>::operator/(const Complex<T> &arg) {
    Complex result(*this);
    size_t temp = pow(arg._re,2) + pow(arg._im, 2);
    result._re = (_re*arg._re + _im*arg._im)/temp;
    result._im = (_im*arg._re - _re*arg._im)/temp;
    return result;
}

template<class T>
void Complex<T>::get() {
    if (_im > 0) std::cout << _re << " + " << _im <<" i"<< std::endl;
    else if (_im < 0)  std::cout << _re << " - " << -(_im) <<" i"<< std::endl;
    else std::cout << _re << " + " << _im <<" i"<< std::endl;
}