#include <iostream>
#include "equipo.h"

using namespace std;

Equipo::Equipo(string _pais, string _confed, string _director, int _ranking,
               int _pgH, int _peH, int _ppH, int _gfH, int _gcH,
               Jugador* _plantilla[])
    : pais(_pais), confed(_confed), director(_director), ranking(_ranking),
    pG_H(_pgH), pE_H(_peH), pP_H(_ppH), gF_H(_gfH), gC_H(_gcH),
    pP(0), pG(0), pE(0), gF(0), gC(0), faltasE(0), yellowE(0), redE(0)
{
    for (int i = 0; i < numJugadores; i++) {
        plantilla[i] = _plantilla[i];
    }
}

//copia
Equipo::Equipo(const Equipo &otro)
    : pais(otro.pais), confed(otro.confed), director(otro.director),
    pP(otro.pP), pG(otro.pG), pE(otro.pE), gF(otro.gF), gC(otro.gC),
    ranking(otro.ranking), faltasE(otro.faltasE),
    yellowE(otro.yellowE), redE(otro.redE)
{
    for (int i = 0; i < numJugadores; i++) {
        if (otro.plantilla[i] != nullptr) {
            // Creamos una nueva instancia de jugador basada en la original
            plantilla[i] = new Jugador(*(otro.plantilla[i]));
        } else {
            plantilla[i] = nullptr;
        }
    }
}

// Destructor
Equipo::~Equipo() {
    for (int i = 0; i < numJugadores; i++) {
        if (plantilla[i] != nullptr) {
            delete plantilla[i];
            plantilla[i] = nullptr;
        }
    }
}

int Equipo::calcularPuntos() const {
    return (pG * 3) + pE;
}

void Equipo::mostrarInfo() const {
    cout << "=== " << pais << " ===" << endl;
    cout << "Puntos Totales: " << calcularPuntos() << endl;
    cout << "Lista de Jugadores:" << endl;
    for(int i = 0; i < numJugadores; i++) {
        if(plantilla[i] != nullptr) {
            cout << "- " << plantilla[i]->getNombre() << endl;
        }
    }
}
