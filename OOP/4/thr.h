#ifndef INC_2_THR_H
#define INC_2_THR_H
#include <iostream>
#include <cstring>
#include "two.h"


class Thr : public Two {
    private:
         bool debug;
    public:
        Thr();

        Thr(const bool bug, const Two &arg);

    Thr(const Thr &arg);

        ~Thr( );

        void getStrFromThr();

        void setBool(bool bug);

        bool getBool( ) const;

        virtual void print( );
};


#endif //INC_2_THR_H
