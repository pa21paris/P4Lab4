#ifndef COMPLETAR_HH
#define COMPLETAR_HH

#include "Ejercicio.hh"
#include <vector>
using namespace std;

class Completar : public Ejercicio {
private:
    vector<string> palabrasFaltantes;
public:
    Completar(string frase, string descripcion, TipoEjercicio tipoDeEjercicio, vector<string> palabrasFaltantes);
    bool resolver(vector<string> palabras);
    vector<string> getPalabrasFaltantes();
};

#endif