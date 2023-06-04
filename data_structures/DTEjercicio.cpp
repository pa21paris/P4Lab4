#include "DTEjercicio.hh"

DTEjercicio::DTEjercicio(string frase, string descripcion) {
    this->frase = frase;
    this->descripcion = descripcion;
}

string DTEjercicio::getFrase() const{
    return this->frase;
}

string DTEjercicio::getDescripcion() const{
    return this->descripcion;
}

bool DTEjercicio::operator<(const DTEjercicio& otro) const {
    return (this->frase < otro.frase);
}