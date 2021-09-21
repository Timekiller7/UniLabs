#ifndef INC_5_2_STACK_H
#define INC_5_2_STACK_H
#include <iostream>

using namespace std;

#include <iomanip>
//Разработать шаблон класса для стека, построенного на основе массива,
//память для которого выделяется в динамической области памяти

template <typename T>
class Stack {
    private:
        T *ptr;
        int size;
        T top;
    public:
        Stack();
        Stack(int s);
        ~Stack();
        void push(const T);
        void pop();
        void show();
};


#endif //INC_5_2_STACK_H
