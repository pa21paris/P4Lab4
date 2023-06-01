#ifndef TRADUCCION_HH
#define TRADUCCION_HH

#include "Ejercicio.hh"
#include <iostream>
using namespace std;

class Traduccion: public Ejercicio {
private:
    string traduccionCorrecta;
public:
    Traduccion(string frase, string descripcion, TipoEjercicio tipoDeEjercicio, string traduccionCorrecta);
    string getTraduccionCorrecta();
    bool resolver(string traduccion);
};

#endif