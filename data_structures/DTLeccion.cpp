#include "DTLeccion.hh"

DTLeccion::DTLeccion(string tema, string objetivo){
    this->tema = tema;
    this->objetivo = objetivo;
}

string DTLeccion::getTema(){
    return this->tema;
}

string DTLeccion::getObjetivo(){
    return this->objetivo;
}