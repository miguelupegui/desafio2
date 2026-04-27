#include "fecha.h"
using namespace std;

Fecha::Fecha(short d, short m, short a, short h) : dia(d), mes(m), anio(a), hora(h) {}

void Fecha::mostrar() const {
    cout << dia << "/" << mes << "/" << anio << " - " << hora << ":00";
}

int Fecha::toHoras() const {
    return (mes * 30 * 24) + (dia * 24) + hora;
}
