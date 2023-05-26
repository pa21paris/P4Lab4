#include "DTProgresoPromedioCurso.hh"

DTProgresoPromedioCurso::DTProgresoPromedioCurso(DTCurso curso, float progCurso): curso(curso){
    this->progCurso = progCurso;
}

DTCurso DTProgresoPromedioCurso::getCurso(){
    return this->curso;
}

float DTProgresoPromedioCurso::getProgCurso(){
    return this->progCurso;
}