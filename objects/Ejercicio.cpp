#include "Ejercicio.hh"

Ejercicio::Ejercicio(string frase, string descripcion, TipoEjercicio tipoDeEjercicio) {
    this->frase = frase;
    this->descripcion = descripcion;
    this->tipoDeEjercicio = tipoDeEjercicio;
}

string Ejercicio::getFrase() {
    return frase;
}

string Ejercicio::getDescripcion() {
    return descripcion;
}

TipoEjercicio Ejercicio::getTipo() {
    return this->tipoDeEjercicio;
}