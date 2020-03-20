#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>

using std::string;

class Pieza{
    protected:
        int posicion[2];
        string err;

    public:
        Pieza(const int pos[]){
            setPosicion(pos);
        };
        virtual bool validarMovimiento(string) = 0;
        int getNUmColumn(char col){
            return 97 - col;
        };
        string getError(string err) {return err;};
        void setPosicion(const int pos[]){
            posicion[0] = pos[0];
            posicion[1] = pos[1];
        };
};
#endif