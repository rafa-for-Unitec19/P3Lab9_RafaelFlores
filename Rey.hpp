#ifndef Rey_H
#define Rey_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Rey: public Pieza{
    static const int FIXED_REY_WHITE[];
    static const int FIXED_REY_BLACK[];
    public:
        Rey(const int pos[]): Pieza(pos){};
        bool validarMovimiento(string cordenada){

        };
};

const int Rey::FIXED_REY_BLACK[]{
    0, 4
};

const int Rey::FIXED_REY_WHITE[]{
    7, 4
};

#endif