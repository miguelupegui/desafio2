#ifndef GRUPO_H
#define GRUPO_H

#include "equipo.h"
#include "partido.h"

class Grupo {
private:
    char nombre;
    Equipo* participantes[4];
    Partido* enfrentamientos[6];
    short int partidosGenerados;

public:
    Grupo(char _nombre, Equipo* e1, Equipo* e2, Equipo* e3, Equipo* e4);
    ~Grupo();
    void organizarCalendario(Fecha inicio);
    void simularJornadas();
    void mostrarTabla();
    void obtenerClasificados(Equipo* clasificados[2]); // Devuelve los 2 mejores
};

#endif
