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
        bool validarMovimiento(string coordenada){
            int actual[2] = {getNUmColumn(coordenada.at(1)) - (getNUmColumn(coordenada.at(2)) - '0')};
            int nuevo[2] = {getNUmColumn(coordenada.at(4)) - (getNUmColumn(coordenada.at(5)) - '0')};
            if (std::equal(posicion, posicion + sizeof posicion / sizeof *posicion, actual))
            {
                err = "La posicion que ingreso no concuerda con la Torre";
                return false;
            }else{
                if(nuevo[0] > 7 || nuevo[0] < 0 || nuevo[1] < 0 || nuevo[1] > 7){
                    err = "NO se puede mover fuera del tablero";
                    return false;
                }else if(((nuevo[0] == actual[0] + 2) || (nuevo[0] == actual[0] + 2)) &&
                            ((nuevo[1] == actual[1] + 1) || (nuevo[1] == actual[1] - 1))){
                    setPosicion(nuevo);
                    return true;
                }else if (((nuevo[1] == actual[1] + 2) || (nuevo[1] == actual[1] + 2)) &&
                            ((nuevo[0] == actual[0] + 1) || (nuevo[0] == actual[0] - 1))){
                    setPosicion(nuevo);
                    return true;
                }else{
                    err = "NO se puede mover el caballo a esa posicion";
                    return false;
                }
            }
        };
};

const int Caballo::FIXED_CABALLO_BLACK[]{
    0, 6
};

const int Caballo::FIXED_CABALLO_WHITE[]{
    7, 1
};
#endif