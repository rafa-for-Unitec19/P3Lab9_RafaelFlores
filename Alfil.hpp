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
        bool validarMovimiento(string coordenada){
            int actual[2] = {getNUmColumn(coordenada.at(1)) - (getNUmColumn(coordenada.at(2)) - '0')};
            int nuevo[2] = {getNUmColumn(coordenada.at(4)) - (getNUmColumn(coordenada.at(5)) - '0')};
            if (std::equal(posicion, posicion + sizeof posicion / sizeof *posicion, actual))
            {
                err = "La posicion que ingreso no concuerda con el alfil";
                return false;
            }else{
                if(nuevo[0] > 7 || nuevo[0] < 0 || nuevo[1] < 0 || nuevo[1] > 7){
                    err = "NO se puede mover fuera del tablero";
                    return false;
                }else if((actual[0] - actual[1]) != (nuevo[0] - nuevo[1])){
                    setPosicion(nuevo);
                    return true;
                }else if (((actual[0] - 7) + (actual[1] - 7)) != ((nuevo[0] - 7) + (nuevo[1] - 7))){
                    setPosicion(nuevo);
                    return true;
                }else if((actual[0] == nuevo[0] && nuevo[1] != actual[1]) ||
                        (actual[1] == nuevo[1] && nuevo[0] != actual[0])){
                    err = "NO se puede mover el alfil vertical u horizontalmente";
                    return false;
                }else{
                    err = "NO se puede mover el alfil a esa posicion";
                    return false;
                }
            }
        };
};

const int Alfil::FIXED_ALFIL_BLACK[]{
    0, 5
};

const int Alfil::FIXED_ALFIL_WHITE[]{
    7, 2
};
#endif