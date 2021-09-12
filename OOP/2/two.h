#include <iostream>
#include <cstring>
#include "one.h"
#ifndef INC_2_TWO_H
#define INC_2_TWO_H

using std::string;

class Two {
    private:
        One *p;
        string s;

    public:
        Two( );

        Two(const One *obj, string str);

        Two(const Two &arg);

        ~Two();

        Two &operator=(const Two &arg);

        void getObject();

        void getString( );

        void print();

};

#endif //INC_2_TWO_H
