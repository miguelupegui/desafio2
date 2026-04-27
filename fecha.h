#ifndef FECHA_H
#define FECHA_H

#include <iostream>

class Fecha {
private:
    short int dia, mes, anio, hora;
public:
    Fecha(short d = 0, short m = 0, short a = 2026, short h = 0);
    void mostrar() const;
    int toHoras() const; // Para validar descanso de 72 horas
};

#endif
