#include "Ejercicio.hh"

Ejercicio::Ejercicio(string frase, string descripcion) {
    this->frase = frase;
    this->descripcion = descripcion;
}

string Ejercicio::getFrase() {
    return frase;
}

string Ejercicio::getDescripcion() {
    return descripcion;
}