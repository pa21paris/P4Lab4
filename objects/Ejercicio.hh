#ifndef EJERCICIO_HH
#define EJERCICIO_HH

#include <iostream>
using namespace std;

class Ejercicio {
private:
    string frase;
    string descripcion;
public:
    Ejercicio(string frase, string descripcion);
    string getFrase();
    string getDescripcion();
    void setFrase(string frase);
    void setDescripcion(string descripcion);
};

#endif