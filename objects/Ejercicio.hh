#ifndef EJERCICIO_HH
#define EJERCICIO_HH

#include <iostream>
#include "../data_structures/TipoEjercicio.hh"
#include "../data_structures/DTEjercicio.hh"
using namespace std;

class Ejercicio {
private:
    string frase;
    string descripcion;
    TipoEjercicio tipoDeEjercicio;
public:
    Ejercicio(string frase, string descripcion, TipoEjercicio tipoDeEjercicio);
    string getFrase();
    string getDescripcion();
    TipoEjercicio getTipo();
    DTEjercicio getData();
};

#endif