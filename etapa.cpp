#include "etapa.h"
#include <iostream>

using namespace std;

Etapa::Etapa(string nombre, short int numPartidos)
    : nombreEtapa(nombre), cantidadPartidos(numPartidos) {
    partidos = new Partido*[cantidadPartidos];
    for(int i = 0; i < cantidadPartidos; i++) {
        partidos[i] = nullptr;
    }
}

Etapa::~Etapa() {
    for(int i = 0; i < cantidadPartidos; i++) {
        if(partidos[i] != nullptr) delete partidos[i];
    }
    delete[] partidos;
}

void Etapa::setPartido(short int indice, Partido* p) {
    if(indice >= 0 && indice < cantidadPartidos) partidos[indice] = p;
}

void Etapa::jugarEtapa() {
    cout << "\n>>> FASE: " << nombreEtapa << " <<<" << endl;
    for(int i = 0; i < cantidadPartidos; i++) {
        if(partidos[i] != nullptr) {
            partidos[i]->simular();
            partidos[i]->mostrarResultado();
        }
    }
}

void Etapa::obtenerGanadores(Equipo** ganadores) {
    for(int i = 0; i < cantidadPartidos; i++) {
        ganadores[i] = partidos[i]->getGanador();
    }
}
void Equipo::registrarResultadoPartido(int golesF, int golesC, int faltas, int amarillas, int rojas) {
    gF += golesF; gC += golesC;
    faltasE += faltas; yellowE += amarillas; redE += rojas;
    if (golesF > golesC) pG++;
    else if (golesF < golesC) pP++;
    else pE++;
}

short int Equipo::calcularPuntosTorneo() const {
    return (pG * 3) + pE;
}

void Equipo::mostrarEstadoMundial() const {
    cout << "Pais: " << pais << " | Puntos: " << calcularPuntosTorneo() << endl;
}
