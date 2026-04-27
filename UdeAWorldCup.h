#ifndef UDEAWORLDCUP_H
#define UDEAWORLDCUP_H

#include "equipo.h"
#include "grupo.h"
#include "etapa.h"

class UdeAWorldCup {
private:
    Equipo** selecciones; //48 equipos
    Grupo** grupos; //12 grupos
    Etapa* fases[4]; //R16, R8, Semi, Final

public:
    UdeAWorldCup();
    ~UdeAWorldCup();
    void ejecutarSimulacion();
    void mostrarReporteFinal();
    void cargarEquiposDesdeCSV();
    void cargarJugadoresDesdeCSV();
};

#endif
