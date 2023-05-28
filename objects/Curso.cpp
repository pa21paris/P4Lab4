#include "Curso.hh"

Curso::Curso(string nombre, string descripcion, Dificultades dificultad){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
}

Curso::Curso(string nombre, string descripcion, Dificultades dificultad, set<Curso *> cursosPrevios, set<Leccion *> lecciones){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->cursosPrevios = cursosPrevios;
    this->lecciones = lecciones;
}

void Curso::agregarPrevia(Curso *curso){
    this->cursosPrevios.insert(curso);
}

void Curso::agregarLeccion(Leccion *leccion){
    this->lecciones.insert(leccion);
}

int Curso::getTotalE(){
    int total = 0;
    set<Leccion *>::iterator it;
    for(it = this->lecciones.begin(); it != this->lecciones.end(); it++){
        total += (*it)->getTotalE();
    }
}

DTCurso Curso::convertirADTCurso(){
    DTCurso dtCurso = DTCurso(this->nombre, this->descripcion, this->dificultad);
    return dtCurso;
}

DTProgresoPromedioCurso Curso::getDataProgCurso(){
    // TODO
}

int Curso::getTotalInsc(){
    // TODO
}

void Curso::eliminarCurso(){
    // TODO
}