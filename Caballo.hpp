#ifndef CABALLO_H
#define CABALLO_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Caballo: public Pieza{
    static const int FIXED_CABALLO_WHITE[];
    static const int FIXED_CABALLO_BLACK[];
    public:
        Caballo(const int pos[]): Pieza(pos){};
        bool validarMovimiento(string cordenada){

        };
};

const int Caballo::FIXED_CABALLO_BLACK[]{
    0, 6
};

const int Caballo::FIXED_CABALLO_WHITE[]{
    7, 1
};
#endif