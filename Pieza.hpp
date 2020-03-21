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
            return col - 97;
        };
        string getError() {return err;};
        void setPosicion(const int pos[]){
            posicion[0] = pos[0];
            posicion[1] = pos[1];
        };
        int getFil(){return posicion[0];};
        int getCol(){return posicion[1];};
        virtual string getSymbol() = 0;
};
#endif