#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador
{
private:
    // los nombres y apellidos serán nombreN y apellidoN, siendo N el # de la camiseta
    string const nombre, apellido;

    unsigned short int const numero;
    unsigned short int goles, asistencias, faltas, rojas, amari, minutos;

public:
    // Constructor
    Jugador();
    Jugador(string name, string lastName, unsigned short int number);
    Jugador(const Jugador &otro); //contructor de copia

    string getNombre() const; //Los getters no generan ningun cambio
    string getApellido() const; //Por eso son metodos constantes
    short int getNumero() const;
    short int getGoles() const;
    short int getAsistencias() const;
    short int getFaltas() const;
    short int getRojas() const;
    short int getAmarillas() const;

    void setNumero(short newNumber); //Los setters no generan ningún retorno
    void setGoles(short newGol);     //Por eso son de tipo void
    void setAsistencias(short newAsist);
    void setFaltas(short newFalta);
    void setRojas(short newRoja);
    void setAmarillas(short newAmari);

   //Donde vivirá mi jugador? Los datos comoo nombre donde los guardo?
    //En un archivo, lo dice el problema
};

#endif // JUGADOR_H
