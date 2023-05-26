#ifndef DT_CURSO_HH
#define DT_CURSO_HH

#include <iostream>
#include "Dificultades.hh"
using namespace std;

class DTCurso{
private:
    string nombre, descripcion;
    Dificultades dificultad;
public:
    DTCurso(string nombre, string descripcion, Dificultades dificultad);
    string getNombre();
    string getDescripcion();
    Dificultades getDificultad();
};

#endif