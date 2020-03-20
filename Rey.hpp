#ifndef Rey_H
#define Rey_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Rey: public Pieza{
    static const int FIXED_REY_WHITE[];
    static const int FIXED_REY_BLACK[];
    public:
        Rey(const int pos[]): Pieza(pos){};
        bool validarMovimiento(string coordenada){
            int actual[2] = {getNUmColumn(coordenada.at(1)) - (getNUmColumn(coordenada.at(2)) - '0')};
            int nuevo[2] = {getNUmColumn(coordenada.at(4)) - (getNUmColumn(coordenada.at(5)) - '0')};
            if (std::equal(posicion, posicion + sizeof posicion / sizeof *posicion, actual))
            {
                err = "La posicion que ingreso no concuerda con el rey";
                return false;
            }else{
                if(nuevo[0] > 7 || nuevo[0] < 0 || nuevo[1] < 0 || nuevo[1] > 7){
                    err = "NO se puede mover fuera del tablero";
                    return false;
                }
                else if (nuevo[0] > (actual[0]+1) || nuevo[0] < (actual[0]-1) ){
                    err = "NO se puede mover mas de un espacio ";
                    return false;
                }else if(nuevo[1] > (actual[1]+1) || nuevo[1] < (actual[1]-1) ){
                    err = "NO se puede mover mas de un espacio ";
                    return false;
                }else if((actual[0] - actual[1]) == (nuevo[0] - nuevo[1])){
                    setPosicion(nuevo);
                    return true;
                }else if (((actual[0] - 7) + (actual[1] - 7)) == ((nuevo[0] - 7) + (nuevo[1] - 7))){
                    setPosicion(nuevo);
                    return true;
                }
            }
        };
};

const int Rey::FIXED_REY_BLACK[]{
    0, 4
};

const int Rey::FIXED_REY_WHITE[]{
    7, 4
};

#endif