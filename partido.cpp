#include "partido.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Partido::Partido(Equipo* l, Equipo* v, Fecha f)
    : local(l), visitante(v), fecha(f), golesL(0), golesV(0), jugado(false) {}

void Partido::simular() {
    golesL = rand() % 4;
    golesV = rand() % 3;
    faltas = 15 + (rand() % 10);
    amarillas = rand() % 5;
    rojas = rand() % 2;

    local->registrarResultadoPartido(golesL, golesV, faltas/2, amarillas/2, 0);
    visitante->registrarResultadoPartido(golesV, golesL, faltas/2, amarillas - (amarillas/2), rojas);

    jugado = true;
}

void Partido::mostrarResultado() const {
    cout << "[" << local->getPais() << " " << golesL << " - " << golesV << " " << visitante->getPais() << "] ";
    fecha.mostrar();
    cout << endl;
}

Equipo* Partido::getGanador() const {
    if (golesL > golesV) return local;
    if (golesV > golesL) return visitante;
    return nullptr; // Empate
}
