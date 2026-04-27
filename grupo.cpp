#include "grupo.h"
#include <iostream>

using namespace std;

Grupo::Grupo(char _nombre, Equipo* e1, Equipo* e2, Equipo* e3, Equipo* e4)
    : nombre(_nombre), partidosGenerados(0) {
    participantes[0] = e1;
    participantes[1] = e2;
    participantes[2] = e3;
    participantes[3] = e4;

    for(int i = 0; i < 6; i++) enfrentamientos[i] = nullptr;
}

Grupo::~Grupo() {
    for(int i = 0; i < 6; i++) {
        if(enfrentamientos[i] != nullptr) delete enfrentamientos[i];
    }
}

void Grupo::simularJornadas() {
    // Simulamos los 6 partidos del grupo
    for(int i = 0; i < 6; i++) {
        if(enfrentamientos[i] != nullptr) {
            enfrentamientos[i]->simular();
        }
    }
}

void Grupo::obtenerClasificados(Equipo* clasificados[2]) {
    // Ordenamiento Burbuja para la tabla de posiciones
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3 - i; j++) {
            // Criterio: Puntos del torneo, luego diferencia de goles del torneo
            int ptsJ = participantes[j]->calcularPuntosTorneo();
            int ptsJ1 = participantes[j+1]->calcularPuntosTorneo();

            if(ptsJ < ptsJ1) {
                Equipo* temp = participantes[j];
                participantes[j] = participantes[j+1];
                participantes[j+1] = temp;
            }
        }
    }
    clasificados[0] = participantes[0];
    clasificados[1] = participantes[1];
}

void Grupo::mostrarTabla() {
    cout << "\n--- TABLA GRUPO " << nombre << " ---" << endl;
    for(int i = 0; i < 4; i++) {
        cout << i+1 << ". " << participantes[i]->getPais()
        << " Pts: " << participantes[i]->calcularPuntosTorneo() << endl;
    }
}
