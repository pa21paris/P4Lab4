#ifndef COMPLETAR_HH
#define COMPLETAR_HH

#include "Ejercicio.hh"
#include <set>
using namespace std;

class Completar : public Ejercicio {
private:
    set<string> palabrasFaltantes;
public:
    Completar(string frase, string descripcion, set<string> palabrasFaltantes);
    bool resolver(set<string> palabras);
    set<string> getPalabrasFaltantes();
};

#endif