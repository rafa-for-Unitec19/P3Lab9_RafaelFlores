#ifndef PEON_H
#define PEON_H
#include <iostream>
#include "Pieza.hpp"

using std::string;

class Peon : public Pieza
{
    public:
    static const int FIXED_PEON_WHITE[];
    static const int FIXED_PEON_BLACK[];
    const bool isWHITE;
    Peon(const int pos[], bool color) : Pieza(pos), isWHITE(color){};
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
            err = "La posicion que ingreso no concuerda con el peon";
            return false;
        }
        else
        {
            std::cout << "Entra en la pieza"<< std::endl;
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
            else if (nuevo[0] < posicion[0] && !isWHITE)
            {
                err = "No puedo mover el peon negro hacia atras";
                return false;
            }else if (nuevo[0] > posicion[0] && isWHITE){
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

    string getSymbol(){return " | P | ";};
};

const int Peon::FIXED_PEON_BLACK[] = {
    1, 4};

const int Peon::FIXED_PEON_WHITE[] = {
    6, 4};

#endif