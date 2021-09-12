#ifndef INC_2_ONE_H
#define INC_2_ONE_H
#include <cstring>

class One {
private:
    float f;
    char *ps;

public:
    One();

    One(float f, const char *str);

    One(const One &one);

    ~One();

    One &operator=(const One &arg);

    float getF();

    char getPs();

    void print();
};


#endif //INC_2_ONE_H
