#ifndef PEON_H
#define PEON_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Peon: public Pieza{
    static const int FIXED_PEON_WHITE[];
    static const int FIXED_PEON_BLACK[];
    public:
        Peon(const int pos[]): Pieza(pos){};
        bool validarMovimiento(string cordenada){

        };
};

const int Peon::FIXED_PEON_BLACK[]{
    1, 4
};

const int Peon::FIXED_PEON_WHITE[]{
    6, 4
};

#endif