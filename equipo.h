#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include "jugador.h"
using namespace std;


class Equipo
{
private:
    //Aca vienen los atributos
    static const int numJugadores = 26;
    string confed, pais, director; //Confederacion y pais
    int pP, pG, pE;     //Partidos perdi2, gana2 y empata2
    int gF, gC;         //Goles a favor, en contra
    int ranking, puntos; //puntaje en el torneo y ranking fifa
    int faltasE, yellowE, redE;
    Jugador* plantilla[numJugadores] ; //se convocan a 26 jugadores

public:

    Equipo(); //Contructor por defecto



};

#endif // EQUIPO_H
