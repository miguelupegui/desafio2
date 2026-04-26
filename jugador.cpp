#include "jugador.h"
using namespace std;

Jugador::Jugador() : nombre(""), apellido(""), numero(0), goles(0),
    asistencias(0), minutos(0), amari(0), rojas(0), faltas(0) {}

Jugador::Jugador(string name, string lastName, unsigned short int number) {
    nombre = name; apellido = lastName; numero = number;
    goles = 0; asistencias = 0; minutos = 0;
    amari = 0; rojas = 0; faltas = 0;
}

Jugador::Jugador(const Jugador &otro) {
    nombre = otro.nombre;
    apellido = otro.apellido;
    numero = otro.numero;
    goles = otro.goles;
    asistencias = otro.asistencias;
    minutos = otro.minutos;
    amari = otro.amari;
    rojas = otro.rojas;
    faltas = otro.faltas;
}
// Getters
string Jugador::getNombre() const {
    return nombre;
}
string Jugador::getApellido() const {
    return apellido;
}
short int Jugador::getNumero() const {
    return numero;
}
short int Jugador::getGoles() const {
    return goles;
}
short int Jugador::getAsistencias() const {
    return asistencias;
}
short int Jugador::getFaltas() const {
    return faltas;
}
short int Jugador::getRojas() const {
    return rojas;
}
short int Jugador::getAmarillas() const {
    return amari;
}
// Setters (hay 3 atributos que no cambian durante el torneo, pero sí se asignan al inicio)
void Jugador::setGoles(short _goles) {
    if(_goles > 0) goles += _goles;
}

void Jugador::setAsistencias(short _asistencias) {
    asistencias += _asistencias;
}


