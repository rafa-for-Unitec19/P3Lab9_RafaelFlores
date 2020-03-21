#ifndef ALFIL_H
#define ALFIL_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Alfil : public Pieza
{

public:
    static const int FIXED_ALFIL_WHITE[];
    static const int FIXED_ALFIL_BLACK[];
    const bool isWHITE;
    Alfil(const int pos[], bool color) : Pieza(pos), isWHITE(color){};
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
            err = "La posicion que ingreso no concuerda con el alfil";
            return false;
        }
        else
        {
            if (nuevo[0] > 7 || nuevo[0] < 0 || nuevo[1] < 0 || nuevo[1] > 7)
            {
                err = "NO se puede mover fuera del tablero";
                return false;
            }
            else if ((actual[0] - actual[1]) != (nuevo[0] - nuevo[1]))
            {
                setPosicion(nuevo);
                return true;
            }
            else if (((actual[0] - 7) + (actual[1] - 7)) != ((nuevo[0] - 7) + (nuevo[1] - 7)))
            {
                setPosicion(nuevo);
                return true;
            }
            else if ((actual[0] == nuevo[0] && nuevo[1] != actual[1]) ||
                     (actual[1] == nuevo[1] && nuevo[0] != actual[0]))
            {
                err = "NO se puede mover el alfil vertical u horizontalmente";
                return false;
            }
            else
            {
                err = "NO se puede mover el alfil a esa posicion";
                return false;
            }
        }
    };
    string getSymbol() { return " | A | "; };
};

const int Alfil::FIXED_ALFIL_BLACK[] = {
    0, 5};

const int Alfil::FIXED_ALFIL_WHITE[] = {
    7, 2};
#endif