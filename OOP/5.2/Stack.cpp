#include "Stack.h"

template <typename T>
Stack<T>::Stack() {
    size = 7;
    ptr = new T[size];
    top = -1;
}

template <typename T>
Stack<T>::Stack(int s) {
    size = s;
    ptr = new T[s];
    top = -1;
}

template <typename T>
Stack<T>::~Stack() {
    delete [] ptr;
}

template <typename T>
void Stack<T>::push(const T value) {
    if (top == size - 1)
        throw false;
    top++;
    ptr[top] = value;
}

template <typename T>
void Stack<T>::pop() {
    if (top == - 1)
        throw "Pop can't be used at the moment";

    ptr[top] = 0;
    top--;
}

template <typename T>
void Stack<T>::show() {
    for (int i = size -1; i >= 0; i--)
        cout << "|" << setw(4) << ptr[i] << setw(4) << "|" << endl;
}