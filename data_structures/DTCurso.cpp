#include "DTCurso.hh"

DTCurso::DTCurso(string nombre, string descripcion, Dificultades dificultad){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
}

string DTCurso::getNombre() const{
    return this->nombre;
}

string DTCurso::getDescripcion() const{
    return this->descripcion;
}

Dificultades DTCurso::getDificultad() const{
    return this->dificultad;
}

bool DTCurso::operator==(DTCurso curso) const{
    return (this->nombre == curso.getNombre() && this->descripcion == curso.getDescripcion() && this->dificultad == curso.getDificultad());
}

bool DTCurso::operator<(const DTCurso& otro) const{
    return (this->nombre < otro.getNombre());
}