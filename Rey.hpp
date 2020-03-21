#ifndef Rey_H
#define Rey_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Rey : public Pieza
{
public:
    static const int FIXED_REY_WHITE[];
    static const int FIXED_REY_BLACK[];
    const bool isWHITE;
    Rey(const int pos[], bool color) : Pieza(pos), isWHITE(color){};
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
            err = "La posicion que ingreso no concuerda con el rey";
            return false;
        }
        else
        {

            if (nuevo[0] > 7 || nuevo[0] < 0 || nuevo[1] < 0 || nuevo[1] > 7)
            {
                err = "NO se puede mover fuera del tablero";
                return false;
            }
            else if (nuevo[0] > (actual[0] + 1) || nuevo[0] < (actual[0] - 1))
            {
                err = "NO se puede mover mas de un espacio ";
                return false;
            }
            else if (nuevo[1] > (actual[1] + 1) || nuevo[1] < (actual[1] - 1))
            {
                err = "NO se puede mover mas de un espacio ";
                return false;
            }
            else if ((actual[0] - actual[1]) == (nuevo[0] - nuevo[1]))
            {
                setPosicion(nuevo);
                return true;
            }
            else if (((actual[0] - 7) + (actual[1] - 7)) == ((nuevo[0] - 7) + (nuevo[1] - 7)))
            {
                setPosicion(nuevo);
                return true;
            }
        }
    };
    string getSymbol() { return " | R | "; };
};

const int Rey::FIXED_REY_BLACK[] = {
    0, 4};

const int Rey::FIXED_REY_WHITE[] = {
    7, 4};

#endif