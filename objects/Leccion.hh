#ifndef LECCION_HH
#define LECCION_HH

#include <iostream>
#include "Ejercicio.hh"
#include <set>
using namespace std;

class Leccion {
private:
    string tema, objetivo;
    set<Ejercicio*> ejercicios;
public:
    Leccion(string tema, string objetivo);
    string getTema();
    string getObjetivo();
    int getTotalE();
    void agregarEjercicio(Ejercicio* ejercicio);
    void eliminarLeccion();
    set<Ejercicio*> getEjercicios();
};

#endif