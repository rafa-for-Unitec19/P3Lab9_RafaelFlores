#ifndef CABALLO_H
#define CABALLO_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Caballo : public Pieza
{
public:
    static const int FIXED_CABALLO_WHITE[];
    static const int FIXED_CABALLO_BLACK[];
    const bool isWHITE;
    Caballo(const int pos[], bool color) : Pieza(pos), isWHITE(color){};
    bool validarMovimiento(string coordenada)
    {
        int actual[2], nuevo[2];
        if (isWHITE){
            actual[1] = (getNUmColumn(coordenada.at(1)));
            nuevo[1] = (getNUmColumn(coordenada.at(4)));
            actual[0] = (8 -(coordenada.at(2) - '0'));
            nuevo[0] = (8-(coordenada.at(5) - '0'));
        }else{
            actual[1] = (getNUmColumn(coordenada.at(1)));
            nuevo[1] = (getNUmColumn(coordenada.at(4)));
            actual[0] = ((coordenada.at(2) - '0'));
            nuevo[0] = ((coordenada.at(5) - '0'));
        }
        if (posicion[0] != actual[0] || posicion[1] != actual[1])
        {
            err = "La posicion que ingreso no concuerda con la Torre";
            return false;
        }
        else
        {
            if (nuevo[0] > 7 || nuevo[0] < 0 || nuevo[1] < 0 || nuevo[1] > 7)
            {
                err = "NO se puede mover fuera del tablero";
                return false;
            }
            else if (((nuevo[0] == actual[0] + 2) || (nuevo[0] == actual[0] + 2)) &&
                     ((nuevo[1] == actual[1] + 1) || (nuevo[1] == actual[1] - 1)))
            {
                setPosicion(nuevo);
                return true;
            }
            else if (((nuevo[1] == actual[1] + 2) || (nuevo[1] == actual[1] + 2)) &&
                     ((nuevo[0] == actual[0] + 1) || (nuevo[0] == actual[0] - 1)))
            {
                setPosicion(nuevo);
                return true;
            }
            else
            {
                err = "NO se puede mover el caballo a esa posicion";
                return false;
            }
        }
    };
    string getSymbol() { return " | C | "; };
};

const int Caballo::FIXED_CABALLO_BLACK[] = {
    0, 6};

const int Caballo::FIXED_CABALLO_WHITE[] = {
    7, 1};
#endif