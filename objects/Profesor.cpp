#include "Profesor.hh"

Profesor::Profesor(string nickname, string password, string name, string description, string instituto)
    : Usuario(nickname, password, name, description){
    this->instituto = instituto;
}

string Profesor::getInstituto(){
    return this->instituto;
}

set<string> Profesor::getNombresIdiomas(){
    set<string> nombres;
    set<Idioma*>::iterator it;
    for(it = this->idiomas.begin(); it != this->idiomas.end(); it++){
        nombres.insert((*it)->getNombre());
    }
    return nombres;
}

void Profesor::agregarCurso(Curso* curso){
    this->cursosPropuestos.insert(curso);
}

void Profesor::eliminarCursoProf(Curso* curso){
    this->cursosPropuestos.erase(curso);
}

set<DTProgresoPromedioCurso> Profesor::listarEstadisticas(){
    set<DTProgresoPromedioCurso> estadisticas;
    set<Curso*>::iterator it;
    for(it = this->cursosPropuestos.begin(); it != this->cursosPropuestos.end(); it++){
        estadisticas.insert((*it)->getDataProgCurso());
    }
    return estadisticas;
}

void Profesor::agregarIdiomaProf(Idioma* idiomaProfesor){
    this->idiomas.insert(idiomaProfesor);
}