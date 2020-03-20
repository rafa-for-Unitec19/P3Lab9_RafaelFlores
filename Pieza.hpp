#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>

using std::string;

class Pieza{
    int posicion[2];

    public:
        Pieza(const int pos[]){
            posicion[0] = pos[0];
            posicion[1] = pos[1];
        };
        virtual bool validarMovimiento() = 0;
};
#endif