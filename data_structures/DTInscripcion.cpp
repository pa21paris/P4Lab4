#include "DTInscripcion.hh"

DTInscripcion::DTInscripcion(string nombre, Date fechaInscripcion): fechaInscripcion(fechaInscripcion){
    this->nombre = nombre;
}

string DTInscripcion::getNombre(){
    return this->nombre;
}

Date DTInscripcion::getFechaInscripcion(){
    return this->fechaInscripcion;
}