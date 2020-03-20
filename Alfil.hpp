#ifndef ALFIL_H
#define ALFIL_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Alfil: public Pieza{
    static const int FIXED_ALFIL_WHITE[];
    static const int FIXED_ALFIL_BLACK[];
    public:
        Alfil(const int pos[]): Pieza(pos){};
        bool validarMovimiento(string cordenada){

        };
};

const int Alfil::FIXED_ALFIL_BLACK[]{
    0, 5
};

const int Alfil::FIXED_ALFIL_WHITE[]{
    7, 2
};
#endif