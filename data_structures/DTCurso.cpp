#include "DTCurso.hh"

DTCurso::DTCurso(string nombre, string descripcion, Dificultades dificultad){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
}

string DTCurso::getNombre(){
    return this->nombre;
}

string DTCurso::getDescripcion(){
    return this->descripcion;
}

Dificultades DTCurso::getDificultad(){
    return this->dificultad;
}