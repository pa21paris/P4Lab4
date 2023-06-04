#include "DTProgresoCurso.hh"

DTProgresoCurso::DTProgresoCurso(DTCurso curso, float progreso): curso(curso){
    this->progreso = progreso;
}

DTCurso DTProgresoCurso::getCurso() const{
    return this->curso;
}

float DTProgresoCurso::getProgreso() const{
    return this->progreso;
}

bool DTProgresoCurso::operator<(const DTProgresoCurso& otro) const{
    return (this->progreso < otro.progreso);
}