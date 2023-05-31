#ifndef COMPLETAR_HH
#define COMPLETAR_HH

#include "Ejercicio.hh"
#include <set>
#include <list>
using namespace std;

class Completar : public Ejercicio {
private:
    list<string> palabrasFaltantes;
public:
    Completar(string frase, string descripcion, list<string> palabrasFaltantes);
    bool resolver(list<string> palabras);
    list<string> getPalabrasFaltantes();
};

#endif