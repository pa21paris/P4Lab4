#include "DTInscripcion.hh"

DTInscripcion::DTInscripcion(string nombre, Date fechaInscripcion): fechaInscripcion(fechaInscripcion){
    this->nombre = nombre;
}

string DTInscripcion::getNombre() const{
    return this->nombre;
}

Date DTInscripcion::getFechaInscripcion() const{
    return this->fechaInscripcion;
}

bool DTInscripcion::operator<(const DTInscripcion& otro) const{
    return this->fechaInscripcion < otro.fechaInscripcion;
}