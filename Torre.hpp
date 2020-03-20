#ifndef TORRE_H
#define TORRE_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Torre: public Pieza{
    static const int FIXED_TORRE_WHITE[];
    static const int FIXED_TORRE_BLACK[];
    public:
        Torre(const int pos[]): Pieza(pos){};
        bool validarMovimiento(string cordenada){

        };
};

const int Torre::FIXED_TORRE_BLACK[]{
    0, 7
};

const int Torre::FIXED_TORRE_WHITE[]{
    7, 0
};
#endif