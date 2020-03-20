#ifndef PEON_H
#define PEON_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Peon : public Pieza
{
    static const int FIXED_PEON_WHITE[];
    static const int FIXED_PEON_BLACK[];
    static const bool WHITE = true;
    static const bool BLACK = false;

public:
    Peon(const int pos[]) : Pieza(pos){};
    bool validarMovimiento(string coordenada, bool color)
    {
        int actual[2] = {getNUmColumn(coordenada.at(1)) - (getNUmColumn(coordenada.at(2)) - '0')};
        int nuevo[2] = {getNUmColumn(coordenada.at(4)) - (getNUmColumn(coordenada.at(5)) - '0')};
        if (std::equal(posicion, posicion + sizeof posicion / sizeof *posicion, actual))
        {
            err = "La posicion que ingreso no concuerda con el peon";
            return false;
        }
        else
        {
            if(nuevo[0] > 7 || nuevo[0] < 0 || nuevo[1] < 0 || nuevo[1] > 7){
                    err = "NO se puede mover fuera del tablero";
                    return false;
            }else if (nuevo[1] != actual[1]){
                err = "No puede Mover el peon horizontalmente";
                return false;
            }
            else if (nuevo[0] > (actual[0] + 2) || nuevo[0] < (actual[0] - 2))
            {
                err + "No se puede mover mas de 2 espacios"; 
                return false;
            }
            else if (nuevo[0] < posicion[0] && !color)
            {
                err = "No puedo mover el peon negro hacia atras";
                return false;
            }else if (nuevo[0] > posicion[0] && color){
                err = "No puedo mover el peon blanco hacia atras";
                return false;
            }else if (nuevo[0] == (actual[0] + 2) || nuevo[0] == (actual[0] - 2)){
                    if (actual[0] == FIXED_PEON_BLACK[0] && ((nuevo[0] - 2) == FIXED_PEON_BLACK[0]))
                    {
                        setPosicion(nuevo);
                        return true;
                    }
                    else if (actual[0] == FIXED_PEON_WHITE[0] && ((nuevo[0] + 2) == FIXED_PEON_WHITE[0]))
                    {
                        setPosicion(nuevo);
                        return true;
                    }
            }
            else if (nuevo[0] == (actual[0] + 1)){
                setPosicion(nuevo);
                return true;
            }
        }
    };
};

const int Peon::FIXED_PEON_BLACK[]{
    1, 4};

const int Peon::FIXED_PEON_WHITE[]{
    6, 4};

#endif