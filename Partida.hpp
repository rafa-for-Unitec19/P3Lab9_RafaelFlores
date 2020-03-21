#ifndef PARTIDA_H
#define PARTIDA_H
#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;
using std::ofstream;

class Partida{
    string nombre;
    string pieza;
    vector<string> movimientos;

    public:
        Partida(){};
        void setNombre(string n){nombre = n;};
        void setPieza(string p){pieza = p;};
        void setMovimiento(string m){
            movimientos.push_back(m);
        }
        void guardarArchivo(){
            ofstream salida("bitacoraPartidas.txt");

            salida << nombre << "\n";
            salida << pieza << "\n";
            for (size_t i = 0; i < movimientos.size(); i++)
            {
                salida << movimientos[i]<<"\t";
            }
            salida << "\n---\n";
            salida.close();
        }

};
#endif