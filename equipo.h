#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include "jugador.h"
using namespace std;


class Equipo
{
private:
    static const short int numJugadores = 26;
    string pais, confed, director; //Confederacion y pais

    //Estadisticas historicas
    short int pG_H, pE_H, pP_H; //Partidos perdi2, gana2 y empata2
    short int gF_H, gC_H;       //Goles a favor, en contra
    //Estadisticas Torneo
    short int pP, pG, pE;     //Partidos perdi2, gana2 y empata2
    short int gF, gC;         //Goles a favor, en contra
    short int puntosFase, ranking; //puntos en Eliminatorias. ranking fifa
    short int faltasE, yellowE, redE;
    Jugador* plantilla[numJugadores] ; //se convocan a 26 jugadores

public:


    Equipo(string _pais, string _confed, string _director, int _ranking,
           int _pgH, int _peH, int _ppH, int _gfH, int _gcH,
           Jugador* _plantilla[]);

    Equipo(const Equipo &otro); //En este contexto, sería raro copiar un equipo pero bueno

    int calcularPuntos() const;
    void mostrarInfo() const;

    // LÓGICA DEL TORNEO
    short int calcularPuntosTorneo() const;
    void registrarResultadoPartido(int golesF, int golesC, int faltas, int amarillas, int rojas);

    // VISUALIZACIÓN
    void mostrarEstadoMundial() const;
    void mostrarHistoricoCompleto() const;

    string getPais() const {
        return pais;
    }

    ~Equipo();
};

#endif // EQUIPO_H
