#ifndef REINA_H
#define REINA_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Reina : public Pieza
{

public:
    static const int FIXED_REINA_WHITE[];
    static const int FIXED_REINA_BLACK[];
    const bool isWHITE;
    Reina(const int pos[], bool color) : Pieza(pos), isWHITE(color){};
    bool validarMovimiento(string coordenada)
    {
        int actual[2], nuevo[2];
        if (isWHITE)
        {
            actual[1] = (getNUmColumn(coordenada.at(1)));
            nuevo[1] = (getNUmColumn(coordenada.at(4)));
            actual[0] = (8 - (coordenada.at(2) - '0'));
            nuevo[0] = (8 - (coordenada.at(5) - '0'));
        }
        else
        {
            actual[1] = (getNUmColumn(coordenada.at(1)));
            nuevo[1] = (getNUmColumn(coordenada.at(4)));
            actual[0] = ((coordenada.at(2) - '0'));
            nuevo[0] = ((coordenada.at(5) - '0'));
        }
        if (posicion[0] != actual[0] || posicion[1] != actual[1])
        {
            err = "La posicion que ingreso no concuerda con la Reina";
            return false;
        }
        else
        {
            std::cout << "Entra en la pieza" << std::endl;
            std::cout << actual[0] << std::endl;
            std::cout << nuevo[0] << std::endl;
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
                setPosicion(nuevo);
                return true;
            }
            else
            {
                err = "NO se puede mover la reina a esa posicion";
                return false;
            }
        }
    };
    string getSymbol() { return " | Q | "; };
};

const int Reina::FIXED_REINA_BLACK[] = {
    0, 3};

const int Reina::FIXED_REINA_WHITE[] = {
    7, 3};
#endif