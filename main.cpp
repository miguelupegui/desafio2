#include <iostream>
#include <ctime>     // Para time()
#include <cstdlib>   // Para srand()
#include "udeaworldcup.h"

using namespace std;

int main() {
    // 1. Inicializar la semilla para los números aleatorios.
    // Esto garantiza que los resultados de los partidos cambien en cada simulación.
    srand(static_cast<unsigned int>(time(0)));

    cout << "============================================" << endl;
    cout << "       SIMULADOR UdeA WORLD CUP 2026        " << endl;
    cout << "============================================" << endl;

    // 2. Crear la instancia principal del torneo en el Stack (o en el Heap si prefieres)
    // Al crearse, el constructor debería inicializar los arreglos de punteros.
    UdeAWorldCup mundial;

    // 3. Flujo principal del programa
    try {
        cout << "\n[1/3] Cargando datos de selecciones y jugadores..." << endl;
        // Este método abrirá el CSV y creará los 48 objetos Equipo y sus Jugadores
        mundial.cargarEquiposDesdeCSV();

        cout << "[2/3] Configurando grupos y calendario..." << endl;
        // Aquí se reparten los 48 equipos en los 12 grupos (A-L)
        // mundial.configurarTorneo();

        cout << "[3/3] Iniciando simulacion de partidos..." << endl;
        cout << "--------------------------------------------" << endl;

        // Ejecuta Fase de Grupos -> Octavos -> Cuartos -> Semis -> Final
        mundial.ejecutarSimulacion();

        cout << "--------------------------------------------" << endl;
        cout << "Simulacion finalizada con exito." << endl;

        // 4. Mostrar el reporte final (Ganador, Goleador, etc.)
        mundial.mostrarReporteFinal();

    } catch (const exception& e) {
        // Captura de errores críticos (ej. si no encuentra el archivo CSV)
        cerr << "ERROR CRITICO: " << e.what() << endl;
        return 1;
    }

    cout << "\nPresione Enter para salir y liberar memoria..." << endl;
    cin.get();

    // Al salir del main, el destructor de 'mundial' se activará automáticamente
    // liberando todos los Equipos, Jugadores, Grupos y Partidos creados con 'new'.
    return 0;
}
