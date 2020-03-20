#ifndef REINA_H
#define REINA_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Reina: public Pieza{
    static const int FIXED_REINA_WHITE[];
    static const int FIXED_REINA_BLACK[];
    public:
        Reina(const int pos[]): Pieza(pos){};
        bool validarMovimiento(string cordenada){

        };
};

const int Reina::FIXED_REINA_BLACK[]{
    0, 3
};

const int Reina::FIXED_REINA_WHITE[]{
    7, 3
};
#endif