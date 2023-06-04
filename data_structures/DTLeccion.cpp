#include "DTLeccion.hh"

DTLeccion::DTLeccion(string tema, string objetivo){
    this->tema = tema;
    this->objetivo = objetivo;
}

string DTLeccion::getTema() const{
    return this->tema;
}

string DTLeccion::getObjetivo() const{
    return this->objetivo;
}

bool DTLeccion::operator<(const DTLeccion& otro) const{
    return (this->tema < otro.tema);
}