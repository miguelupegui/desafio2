#include "udeaworldcup.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

UdeAWorldCup::UdeAWorldCup() {
    selecciones = new Equipo*[48];
    grupos = new Grupo*[12];
}

void UdeAWorldCup::ejecutarSimulacion() {
    cout << "--- INICIANDO UDEA WORLD CUP 2026 ---" << endl;
    // 1. Simular Grupos
    // 2. Definir llaves de Octavos
    // 3. Jugar Eliminatorias
}

UdeAWorldCup::~UdeAWorldCup() {
    for(int i=0; i<48; i++) delete selecciones[i];
    delete[] selecciones;

    for(int i=0; i<12; i++) delete grupos[i];
    delete[] grupos;

}

string extraerDato(const string& linea, int& posicionInicial) {
    if (posicionInicial >= linea.length()) return "";

    int fin = linea.find(';', posicionInicial);
    string resultado;

    if (fin == string::npos) {
        resultado = linea.substr(posicionInicial);
        posicionInicial = linea.length();
    } else {
        resultado = linea.substr(posicionInicial, fin - posicionInicial);
        posicionInicial = fin + 1;
    }
    return resultado;
}


void UdeAWorldCup::cargarEquiposDesdeCSV() {
    ifstream archivo("selecciones_clasificadas_mundial.csv");
    string linea;

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        cout << "No se hallo el archivo en: " << endl;
        system("cd");
        return;
    }

    getline(archivo, linea);
    getline(archivo, linea);

    int i = 0;
    while (getline(archivo, linea) && i < 48) {
        int pos = 0;

        string s_rank = extraerDato(linea, pos);
        string s_pais = extraerDato(linea, pos);
        string s_dt   = extraerDato(linea, pos);
        string s_fed  = extraerDato(linea, pos);
        string s_conf = extraerDato(linea, pos);
        string s_gf   = extraerDato(linea, pos);
        string s_gc   = extraerDato(linea, pos);
        string s_pg   = extraerDato(linea, pos);
        string s_pe   = extraerDato(linea, pos);
        string s_pp   = extraerDato(linea, pos);

        int rankVal = stoi(s_rank);
        int pgH = stoi(s_pg);
        int peH = stoi(s_pe);
        int ppH = stoi(s_pp);
        int gfH = stoi(s_gf);
        int gcH = stoi(s_gc);

        Jugador** jugadoresTmp = new Jugador*[26];
        for(int j = 0; j < 26; j++) {
            jugadoresTmp[j] = new Jugador("Nombre" + to_string(j), "Ape", j + 1);
        }

        selecciones[i] = new Equipo(s_pais, s_conf, s_dt, rankVal,
                                    pgH, peH, ppH, gfH, gcH,
                                    jugadoresTmp);
        i++;
    }
    archivo.close();
}
