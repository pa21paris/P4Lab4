#include "DTProgresoPromedioCurso.hh"

DTProgresoPromedioCurso::DTProgresoPromedioCurso(DTCurso curso, float progCurso): curso(curso){
    this->progCurso = progCurso;
}

DTCurso DTProgresoPromedioCurso::getCurso() const{
    return this->curso;
}

float DTProgresoPromedioCurso::getProgCurso() const{
    return this->progCurso;
}

bool DTProgresoPromedioCurso::operator<(const DTProgresoPromedioCurso& otro) const{
    return (this->progCurso < otro.progCurso);
}