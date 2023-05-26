#include "DTProgresoCurso.hh"

DTProgresoCurso::DTProgresoCurso(DTCurso curso, float progreso): curso(curso){
    this->progreso = progreso;
}

DTCurso DTProgresoCurso::getCurso(){
    return this->curso;
}

float DTProgresoCurso::getProgreso(){
    return this->progreso;
}