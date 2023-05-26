#include "DTEjercicio.hh"

DTEjercicio::DTEjercicio(string frase, string descripcion) {
    this->frase = frase;
    this->descripcion = descripcion;
}

string DTEjercicio::getFrase() {
    return this->frase;
}

string DTEjercicio::getDescripcion() {
    return this->descripcion;
}