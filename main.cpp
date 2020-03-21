#include <iostream>
#include <vector>
#include "Pieza.hpp"
#include "Peon.hpp"
#include "Rey.hpp"
#include "Reina.hpp"
#include "Alfil.hpp"
#include "Torre.hpp"
#include "Caballo.hpp"
#include "Partida.hpp"

using namespace std;

string tablero[8][8];
vector<Pieza *> piezasEnPartida;
vector<Partida> partidas;
const string piezas[] = {"Rey", "Reina", "Alfil", "Caballo", "Torre", "Peon"};

void borrarTablero()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            tablero[i][j] = "";
        }
    }
}

void imprimirTablero()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            cout << tablero[i][j];
        }
        cout << "\n";
    }
}

int menu()
{
    int op;
    cout << "Ingrese la opcion que mas desee:"
         << "\n\t1. Jugar Partida"
         << "\n\t2. Recrear Partida"
         << "\n\t3. Salir" << endl;
    cin >> op;
    return op;
}

int menuPiezas()
{
    while (true)
    {
        int op;
        cout << "Ingrese la pieza a utilizar:"
             << "\n\t1. Reina"
             << "\n\t2. Alfil"
             << "\n\t3. Caballo"
             << "\n\t4. Torre"
             << "\n\t5. Peon" << endl;
        cin >> op;
        if (op > 0 && op < 6)
        {
            return op;
        }
        else
        {
            cout << "Debe seleccionar una opcion valida";
        }
    }
}

void crearPieza(int ind, bool color)
{
    switch (ind)
    {
    case 0:
    {
        if (color)
        {
            piezasEnPartida.push_back(new Rey(Rey::FIXED_REY_WHITE, color));
        }
        else
        {
            piezasEnPartida.push_back(new Rey(Rey::FIXED_REY_BLACK, color));
        }
        break;
    }
    case 1:
    {
        if (color)
        {
            piezasEnPartida.push_back(new Reina(Reina::FIXED_REINA_WHITE, color));
        }
        else
        {
            piezasEnPartida.push_back(new Reina(Reina::FIXED_REINA_BLACK, color));
        }
        break;
    }
    case 2:
    {
        if (color)
        {
            piezasEnPartida.push_back(new Alfil(Alfil::FIXED_ALFIL_WHITE, color));
        }
        else
        {
            piezasEnPartida.push_back(new Alfil(Alfil::FIXED_ALFIL_BLACK, color));
        }
        break;
    }
    case 3:
    {
        if (color)
        {
            piezasEnPartida.push_back(new Caballo(Caballo::FIXED_CABALLO_WHITE, color));
        }
        else
        {
            piezasEnPartida.push_back(new Caballo(Caballo::FIXED_CABALLO_BLACK, color));
        }
        break;
    }
    case 4:
    {
        if (color)
        {
            piezasEnPartida.push_back(new Torre(Torre::FIXED_TORRE_WHITE, color));
        }
        else
        {
            piezasEnPartida.push_back(new Torre(Torre::FIXED_TORRE_BLACK, color));
        }
        break;
    }
    case 5:
    {
        if (color)
        {
            piezasEnPartida.push_back(new Peon(Peon::FIXED_PEON_WHITE, color));
        }
        else
        {
            piezasEnPartida.push_back(new Peon(Peon::FIXED_PEON_BLACK, color));
        }
        break;
    }
    }
}

void generarPartida()
{
    Partida temp;
    cout << "Ingrese el nombre de la partida" << endl;
    string nombre;
    cin.ignore();
    getline(cin, nombre);
    temp.setNombre(nombre);
    int indice = menuPiezas();
    temp.setPieza(piezas[indice]);
    crearPieza(0, true);
    crearPieza(0, false);
    crearPieza(indice, true);
    crearPieza(indice, false);
    partidas.push_back(temp);
}

void borrarVectorPiezas()
{
    for (int i = 0; i < piezasEnPartida.size(); i++)
    {
        delete piezasEnPartida[i];
    }
    piezasEnPartida.clear();
}

bool validarJugada(string jugada, int pieza1, int pieza2)
{
    if (piezasEnPartida[pieza1]->validarMovimiento(jugada))
    {
        cout << "Entra A" << endl;
        partidas[partidas.size() - 1].setMovimiento(jugada);

        return true;
    }
    else if (piezasEnPartida[pieza2]->validarMovimiento(jugada))
    {
        cout << "Entra B" << endl;
        partidas[partidas.size() - 1].setMovimiento(jugada);

        return true;
    }
    else
    {
        cout << "Entra C" << endl;
        cout << piezasEnPartida[pieza1]->getError() << endl;
        cout << piezasEnPartida[pieza2]->getError() << endl;

        return false;
    }
}

void crearTablero()
{
    borrarTablero();
    tablero[piezasEnPartida[0]->getFil()][piezasEnPartida[0]->getCol()] = piezasEnPartida[0]->getSymbol();
    tablero[piezasEnPartida[1]->getFil()][piezasEnPartida[1]->getCol()] = piezasEnPartida[1]->getSymbol();
    tablero[piezasEnPartida[2]->getFil()][piezasEnPartida[2]->getCol()] = piezasEnPartida[2]->getSymbol();
    tablero[piezasEnPartida[3]->getFil()][piezasEnPartida[3]->getCol()] = piezasEnPartida[3]->getSymbol();
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (tablero[i][j] == "")
            {
                tablero[i][j] = " | . | ";
            }
        }
    }
    imprimirTablero();
}

void selector()
{
    bool flag = true;
    while (flag)
    {
        switch (menu())
        {
        case 1:
        {
            cout << "Jugar partida" << endl;
            generarPartida();
            cout << "Comenzando partida, para terminar escriba SALIDA" << endl;
            bool change = true;
            string entrada;
            crearTablero();
            while (true)
            {
                if (change)
                {
                    cout << "Ingrese la jugada de las blancas [actual, nuevo]" << endl;
                    cin >> entrada;
                    if (entrada == "SALIDA")
                    {
                        break;
                    }
                    else
                    {

                        if (validarJugada(entrada, 0, 2))
                        {

                        }
                        else
                        {
                            cout << "Pierde Turno" << endl;
                        }
                        change = false;
                        crearTablero();
                    }
                }
                else
                {
                    cout << "Ingrese la jugada de las negras [actual, nuevo]" << endl;
                    cin >> entrada;
                    if (entrada == "SALIDA")
                    {
                        break;
                    }
                    else
                    {
                        if (validarJugada(entrada, 0, 2))
                        {
                        }
                        else
                        {
                            cout << "Pierde Turno" << endl;
                        }
                        change = false;
                        crearTablero();
                    }
                }
            }
            break;
        }
        case 2:
            cout << "Recrear partida" << endl;
            break;
        case 3:
            flag = false;
            borrarVectorPiezas();
            break;
        default:
            cout << "Opcion invalida!!!" << endl;
            break;
        }
    }
}

int main()
{
    selector();
    return 0;
}