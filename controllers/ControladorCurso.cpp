#include "ControladorCurso.hh"
#include "ControladorUsuario.hh"

ControladorCurso::ControladorCurso() {}

void ControladorCurso::eliminarCurso() {
    if(this->cursoEnProceso != nullptr) this->cursoEnProceso->eliminarCurso();
    delete this->cursoEnProceso;
    this->cursoEnProceso = nullptr;
}

Curso* ControladorCurso::findCursoByDTCurso(DTCurso curso) {
    set<Curso*>::iterator it=this->cursos.begin();
    while(it!=this->cursos.end() && (*it)->getNombre()!=curso.getNombre()){
        it++;        
    }
    if(it!=this->cursos.end()) return *it;
    return nullptr;
}

set<DTCurso> ControladorCurso::listarCursos() {
    set<DTCurso> res;
    set<Curso*>::iterator it;
    for(it = this->cursos.begin(); it != this->cursos.end(); it++) {
        res.insert((*it)->convertirADTCurso());
    }
    return res;
}

set<string> ControladorCurso::obtenerNicksDocentes() {
    set<string> res;
    ControladorUsuario* cu=ControladorUsuario::getInstance();
    set<DTProfesor> profesores = cu->listarProfesores();
    set<DTProfesor>::iterator it;
    for(it = profesores.begin(); it != profesores.end(); it++) {
        res.insert((*it).getNickname());
    }
    return res;
}

void ControladorCurso::seleccionUsuario(string nickname) {
    ControladorUsuario* cu=ControladorUsuario::getInstance();
    this->profesorSeleccionado=cu->obtenerProfesor(nickname);
}

void ControladorCurso::datosCurso(string nombre, string descripcion, Dificultades dificultad) {
    this->cursoEnProceso = new Curso(nombre, descripcion, dificultad);
}

void ControladorCurso::leccionDatos(string tema, string objetivo) {
    this->leccionEnCreacion = new Leccion(tema, objetivo);
}

set<string> ControladorCurso::idiomasDelDocente() {
    ControladorUsuario* cu=ControladorUsuario::getInstance();
    return cu->getIdiomasProfesor(this->profesorSeleccionado->getNickname());
}

void ControladorCurso::seleccionarCurso(DTCurso curso) {
    this->cursoEnProceso=this->findCursoByDTCurso(curso);
}

void ControladorCurso::seleccionDeIdioma(string nombreIdioma) {
    this->idiomaSeleccionado=nombreIdioma;
}

set<DTCurso> ControladorCurso::solicitarCursosHabilitados() {
    set<DTCurso> res;
    set<Curso*>::iterator it;
    for(it = this->cursos.begin(); it != this->cursos.end(); it++) {
        res.insert((*it)->convertirADTCurso());
    }
    return res;
}

void ControladorCurso::agregarCursoPrevio(DTCurso curso) {
    this->cursosPrevios.insert(this->findCursoByDTCurso(curso));
}

DTProgresoPromedioCurso ControladorCurso::listarEstadisticasCurso(DTCurso curso){
    return this->findCursoByDTCurso(curso)->getDataProgCurso();
}