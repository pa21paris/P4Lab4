#ifndef LECCION_HH
#define LECCION_HH

#include <iostream>
#include "Ejercicio.hh"
#include <set>
#include "../data_structures/DTLeccion.hh"
#include "../data_structures/DatosLeccion.hh"
using namespace std;

class Leccion {
private:
    string tema, objetivo;
    set<Ejercicio*> ejercicios;
    set<DTEjercicio> getDTEjercicios();
public:
    Leccion(string tema, string objetivo);
    string getTema();
    string getObjetivo();
    int getTotalE();
    void agregarEjercicio(Ejercicio* ejercicio);
    void eliminarLeccion();
    set<Ejercicio*> getEjercicios();
    DTLeccion getDT();
    DatosLeccion getDatos();
};

#endif