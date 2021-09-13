#ifndef INC_2_FOU_H
#define INC_2_FOU_H

#include <iostream>
#include <cstring>
#include "thr.h"


class Fou : public Thr {
private:
    string  colour;
public:
    Fou();

    Fou(string str, const Thr &arg);

    Fou(const Fou &arg);

    ~Fou( );

    void getStrFromFou();

    void setStrF(string str);

    string getStrF( ) const;

    virtual void print( );
};



#endif //INC_2_FOU_H
