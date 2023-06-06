#include "Curso.hh"

Curso::Curso(string nombre, string descripcion, Dificultades dificultad){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->habilitado = false;
}

Curso::Curso(string nombre, string descripcion, Dificultades dificultad, set<Curso *> cursosPrevios, list<Leccion *> lecciones){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->cursosPrevios = cursosPrevios;
    this->lecciones = lecciones;
    this->habilitado = false;
}

void Curso::agregarPrevia(Curso *curso){
    this->cursosPrevios.insert(curso);
}

void Curso::agregarLeccion(Leccion *leccion){
    this->lecciones.push_back(leccion);
}

int Curso::getTotalE(){
    int total = 0;
    list<Leccion *>::iterator it;
    for(it = this->lecciones.begin(); it != this->lecciones.end(); ++it){
        total += (*it)->getTotalE();
    }
    return total;
}

DTCurso Curso::convertirADTCurso(){
    DTCurso dtCurso = DTCurso(this->nombre, this->descripcion, this->dificultad);
    return dtCurso;
}

int Curso::getTotalInsc(){
    return this->inscripciones.size();
}

DTProgresoPromedioCurso Curso::getDataProgCurso(){
    int cantEstudiantes=this->getTotalInsc();
    int sumaProgresosCurso=0;
    set<Inscripcion*>::iterator it;
    for(it = this->inscripciones.begin(); it != this->inscripciones.end(); ++it){
        sumaProgresosCurso += (*it)->getProgreso();
    }
    DTProgresoPromedioCurso dtProgresoPromCurso = DTProgresoPromedioCurso(this->convertirADTCurso(), sumaProgresosCurso/cantEstudiantes);
    return dtProgresoPromCurso;
}

void Curso::eliminarCurso(){
    this->profesorCurso->eliminarCursoProf(this);
    list<Leccion *>::iterator it;
    for(it = this->lecciones.begin(); it != this->lecciones.end(); ++it){
        (*it)->eliminarLeccion();
        delete *it;
    }
}

string Curso::getNombre(){
    return this->nombre;
}

string Curso::getDescripcion(){
    return this->descripcion;
}

Dificultades Curso::getDificultad(){
    return this->dificultad;
}

Leccion* Curso::getLeccionSiguiente(Leccion* leccionActual){
    if(leccionActual==nullptr) return this->lecciones.front();

    list<Leccion *>::iterator it=this->lecciones.begin();
    while(it!=this->lecciones.end() && *it!=leccionActual){
        ++it;
    }

    if((++it)==this->lecciones.end()) return nullptr;

    return *(++it);
}

void Curso::setProfesorCurso(Profesor* profesor){
    this->profesorCurso = profesor;
}

bool Curso::estaHabilitado(){
    return this->habilitado;
}

void Curso::habilitar(){
    this->habilitado = true;
}

list<DTLeccion> Curso::getDTLecciones() {
    list<DTLeccion> ret;
    list<Leccion*>::iterator it;
    for (it = this->lecciones.begin(); it != this->lecciones.end(); ++it) {
        ret.push_back((*it)->getDT());
    }
    return ret;
}

Leccion* Curso::getLeccion(int index) {
    Leccion* ret;
    list<Leccion*>::iterator it;
    int a = 1;
    for (it = this->lecciones.begin(); it != this->lecciones.end(); ++it) {
        if (a == index) {
            ret = *it;
            break;
        }
        a++;
    }
    return ret;
}

bool cumplePrevia(Curso *curso, set<Curso *> cursosCompletos){
    return cursosCompletos.find(curso) != cursosCompletos.end();
}

bool Curso::previasCumplidas(set<Curso *> cursosCompletos){
    if(cursosCompletos.size() != this->cursosPrevios.size()) return false;
    set<Curso *>::iterator it=this->cursosPrevios.begin();
    while (it!=this->cursosPrevios.end() && cumplePrevia(*it, cursosCompletos)){
        ++it;
    }
    if(it==this->cursosPrevios.end()) return true;
    return false;
}

void Curso::addInscripcion(Inscripcion *inscripcion){
    this->inscripciones.insert(inscripcion);
}