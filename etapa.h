#ifndef ETAPA_H
#define ETAPA_H

#include "partido.h"

class Etapa {
private:
    string nombreEtapa;
    Partido** partidos; // Arreglo dinámico de punteros
    short int cantidadPartidos;

public:
    Etapa(string nombre, short int numPartidos);
    ~Etapa();
    void setPartido(short int indice, Partido* p);
    void jugarEtapa();
    void obtenerGanadores(Equipo** ganadoresAnfitriones);
};

#endif
