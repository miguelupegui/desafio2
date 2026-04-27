#ifndef PARTIDO_H
#define PARTIDO_H

#include "equipo.h"
#include "fecha.h"

class Partido {
private:
    Equipo* local;
    Equipo* visitante;
    Fecha fecha;
    short int golesL, golesV;
    short int amarillas, rojas, faltas;
    bool jugado;

public:
    Partido(Equipo* l, Equipo* v, Fecha f);
    void simular();
    void mostrarResultado() const;
    Equipo* getGanador() const;
    Equipo* getLocal() const { return local; }
    Equipo* getVisitante() const { return visitante; }
    bool fueJugado() const { return jugado; }
};

#endif
