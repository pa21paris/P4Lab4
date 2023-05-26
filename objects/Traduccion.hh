#ifndef TRADUCCION_HH
#define TRADUCCION_HH

#include "Ejercicio.hh"
#include <iostream>
using namespace std;

class Traduccion: public Ejercicio {
private:
    string traduccionCorrecta;
public:
    Traduccion(string frase, string descripcion, string traduccionCorrecta);
    string getTraduccionCorrecta();
    void setTraduccionCorrecta(string traduccionCorrecta);
};

#endif