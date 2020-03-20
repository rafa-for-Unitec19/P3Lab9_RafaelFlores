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
        bool validarMovimiento(string coordenada){
            int actual[2] = {getNUmColumn(coordenada.at(1)) - (getNUmColumn(coordenada.at(2)) - '0')};
            int nuevo[2] = {getNUmColumn(coordenada.at(4)) - (getNUmColumn(coordenada.at(5)) - '0')};
            if (std::equal(posicion, posicion + sizeof posicion / sizeof *posicion, actual))
            {
                err = "La posicion que ingreso no concuerda con la Reina";
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
                    setPosicion(nuevo);
                    return true;
                }else{
                    err = "NO se puede mover la reina a esa posicion";
                    return false;
                }
            }
        };
};

const int Reina::FIXED_REINA_BLACK[]{
    0, 3
};

const int Reina::FIXED_REINA_WHITE[]{
    7, 3
};
#endif