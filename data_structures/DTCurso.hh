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
    string getNombre() const;
    string getDescripcion() const;
    Dificultades getDificultad() const;
    bool operator==(DTCurso curso) const;
    bool operator<(const DTCurso& otro) const;
};

#endif