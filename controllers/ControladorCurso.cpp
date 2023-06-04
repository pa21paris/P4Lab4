#include "ControladorCurso.hh"
#include "ControladorUsuario.hh"
#include "ControladorIdioma.hh"
#include "../objects/Completar.hh"
#include "../objects/Traduccion.hh"

ControladorCurso::ControladorCurso() {}

void ControladorCurso::eliminarCurso() {
    if(this->cursoEnProceso != nullptr) this->cursoEnProceso->eliminarCurso();
    delete this->cursoEnProceso;
    this->cursoEnProceso = nullptr;
}

void ControladorCurso::vaciarDatosTemporales() {
    this->cursoEnProceso = nullptr;
    this->profesorSeleccionado = nullptr;
    this->leccionEnCreacion = nullptr;
    this->idiomaSeleccionado = "";
    this->lecciones.clear();
    this->cursosPrevios.clear();
    this->ejercicioEnCreacion = nullptr;
}

Curso* ControladorCurso::findCursoByDTCurso(DTCurso curso) {
    set<Curso*>::iterator it=this->cursos.begin();
    while(it!=this->cursos.end() && (*it)->getNombre()!=curso.getNombre()){
        ++it;        
    }
    if(it!=this->cursos.end()) return *it;
    return nullptr;
}

set<DTCurso> ControladorCurso::listarCursos() {
    set<DTCurso> res;
    set<Curso*>::iterator it;
    for(it = this->cursos.begin(); it != this->cursos.end(); ++it) {
        res.insert((*it)->convertirADTCurso());
    }
    return res;
}

set<string> ControladorCurso::obtenerNicksDocentes() {
    set<string> res;
    ControladorUsuario* cu=ControladorUsuario::getInstance();
    set<DTProfesor> profesores = cu->listarProfesores();
    set<DTProfesor>::iterator it;
    for(it = profesores.begin(); it != profesores.end(); ++it) {
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
    for(it = this->cursos.begin(); it != this->cursos.end(); ++it) {
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

void ControladorCurso::altaCurso() {
    this->cursoEnProceso->setProfesorCurso(this->profesorSeleccionado);
    set<Curso*>::iterator it;
    for(it = this->cursosPrevios.begin(); it != this->cursosPrevios.end(); ++it) {
        this->cursoEnProceso->agregarPrevia(*it);
    }
    set<Leccion*>::iterator it2;
    for(it2 = this->lecciones.begin(); it2 != this->lecciones.end(); ++it2) {
        this->cursoEnProceso->agregarLeccion(*it2);
    }
    ControladorIdioma* ci=ControladorIdioma::getInstance();
    ci->enviarNotificacion(this->cursoEnProceso->getNombre(),this->idiomaSeleccionado);
    ControladorUsuario* cu=ControladorUsuario::getInstance();
    cu->agregarCursoAProfesor(this->profesorSeleccionado,this->cursoEnProceso);
    this->vaciarDatosTemporales();
}

TipoEjercicio ControladorCurso::obtenerTipo(Ejercicio* ejercicio) {
    return ejercicio->getTipo();
}

void ControladorCurso::altaLeccion() {
    this->lecciones.insert(this->leccionEnCreacion);
}

void ControladorCurso::agregarEjercicio(string frase, TipoEjercicio tipoDeEjercicio, string descripcion) {
    this->ejercicioEnCreacion = new Ejercicio(frase, descripcion, tipoDeEjercicio);
}

void ControladorCurso::ejercicioDeCompletar(list<string> palabrasFaltantes) {
    Completar* c = new Completar(
        this->ejercicioEnCreacion->getFrase(),
        this->ejercicioEnCreacion->getDescripcion(),
        this->ejercicioEnCreacion->getTipo(),
        palabrasFaltantes);
    delete this->ejercicioEnCreacion;
    this->ejercicioEnCreacion = c;
}

void ControladorCurso::ejercicioDeTraduccion(string fraseTraducida) {
    Traduccion* t = new Traduccion(
        this->ejercicioEnCreacion->getFrase(),
        this->ejercicioEnCreacion->getDescripcion(),
        this->ejercicioEnCreacion->getTipo(),
        fraseTraducida);
    delete this->ejercicioEnCreacion;
    this->ejercicioEnCreacion = t;
}

void ControladorCurso::altaEjercicio() {
    this->leccionEnCreacion->agregarEjercicio(this->ejercicioEnCreacion);
}

ControladorCurso* ControladorCurso::getInstance(){
    if(ControladorCurso::instance==nullptr) ControladorCurso::instance=new ControladorCurso();
    return ControladorCurso::instance;
}