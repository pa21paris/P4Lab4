#include "ControladorUsuario.hh"
#include "ControladorIdioma.hh"
#include "ControladorCurso.hh"

ControladorUsuario* ControladorUsuario::getInstance() {
    if(ControladorUsuario::instance == nullptr) ControladorUsuario::instance=new ControladorUsuario();
    return ControladorUsuario::instance;
}

set<DTEstudiante> ControladorUsuario::listarEstudiantes() {
    set<DTEstudiante> res;
    set<Estudiante*>::iterator it;
    for(it=estudiantes.begin(); it!=estudiantes.end(); ++it) {
        res.insert((*it)->getData());
    }
    return res;
}

DTEstadisticasEstudiante ControladorUsuario::listarEstadisticasEstudiante(DTEstudiante estudiante) {
    set<Estudiante*>::iterator it=this->estudiantes.begin();
    while(it!=this->estudiantes.end() && (*it)->getNickname()!=estudiante.getNickname()){
        ++it;
    }
    if(it!=this->estudiantes.end()) {
        return DTEstadisticasEstudiante((*it)->listarEstadisticas());
    }
    return DTEstadisticasEstudiante(set<DTProgresoCurso>());
}

set<DTNotificacion> ControladorUsuario::obtenerNotificaciones(string nickname) {
    set<Usuario*>::iterator it=this->usuarios.begin();
    while(it!=this->usuarios.end() && (*it)->getNickname()!=nickname){
        ++it;
    }
    if(it!=this->usuarios.end()) {
        return (*it)->getNotificaciones();
    }
    return set<DTNotificacion>();
}

set<DTCurso> ControladorUsuario::listarCursosActivosDeEstudiante(string nickname) {
    set<Estudiante*>::iterator it=this->estudiantes.begin();
    while(it!=this->estudiantes.end() && (*it)->getNickname()!=nickname){
        ++it;
    }
    if(it!=this->estudiantes.end()) {
        this->usuarioEnProceso=(*it);
        return (*it)->getCursosActivos();
    }
    return set<DTCurso>();
}

void ControladorUsuario::ingresarDatosUsuario(string nickname, string contraseña, string nombre, string descripcion, TipoUsuario tipo) {
    this->usuarioEnProceso=new Usuario(nickname, contraseña, nombre, descripcion);
    this->tipoUsuarioEnProceso=tipo;
}

void ControladorUsuario::ingresarDatosEstudiante(string paisRes, Date fechaNacimiento) {
    Usuario* usuarioEnProceso=this->usuarioEnProceso;
    this->usuarioEnProceso=new Estudiante(
        this->usuarioEnProceso->getNickname(), 
        this->usuarioEnProceso->getPassword(), 
        this->usuarioEnProceso->getName(), 
        this->usuarioEnProceso->getDescription(), 
        paisRes, 
        fechaNacimiento
    );
    delete usuarioEnProceso;
}

void ControladorUsuario::ingresarInstituto(string instituto) {
    Usuario* usuarioEnProceso=this->usuarioEnProceso;
    this->usuarioEnProceso=new Profesor(
        this->usuarioEnProceso->getNickname(), 
        this->usuarioEnProceso->getPassword(), 
        this->usuarioEnProceso->getName(), 
        this->usuarioEnProceso->getDescription(), 
        instituto
    );
    delete usuarioEnProceso;
}

set<string> ControladorUsuario::obtenerListaDeIdiomas() {
    ControladorIdioma* ci=ControladorIdioma::getInstance();
    return ci->obtenerIdiomas();
}

set<DTProfesor> ControladorUsuario::listarProfesores() {
    set<DTProfesor> res;
    set<Profesor*>::iterator it;
    for(it=(this->profesores.begin()); it!=(this->profesores.end()); ++it) {
        res.insert((*it)->getData());
    }
    return res;
}

DTEstadisticasProfesor ControladorUsuario::listarEstadisticasProfesor(DTProfesor profesor) {
    set<Profesor*>::iterator it=this->profesores.begin();
    while((it!=(this->profesores.end())) && (((*it)->getNickname())!=(profesor.getNickname()))){
        ++it;
    }
    if(it!=this->profesores.end()) {
        return DTEstadisticasProfesor((*it)->listarEstadisticas());
    }
    return DTEstadisticasProfesor(set<DTProgresoPromedioCurso>());
}

set<DTEjercicio> ControladorUsuario::verEjerciciosPendientes(DTCurso curso) {
    this->inscripcionSeleccionada=((Estudiante*) this->usuarioEnProceso)->getInscripcion(curso);
    return this->inscripcionSeleccionada->getEjerciciosPendientes();
}

set<DTCurso> ControladorUsuario::listarCursos() {
    ControladorCurso* cc=ControladorCurso::getInstance();
    return cc->listarCursos();
}

DTProgresoPromedioCurso ControladorUsuario::listarEstadisticasCurso(DTCurso curso) {
    ControladorCurso* cc=ControladorCurso::getInstance();
    return cc->listarEstadisticasCurso(curso);
}

Profesor* ControladorUsuario::obtenerProfesor(string nickname){
    set<Profesor*>::iterator it=this->profesores.begin();
    while(it!=this->profesores.end() && (*it)->getNickname()!=nickname){
        ++it;
    }
    if(it!=this->profesores.end()) {
        return (*it);
    }
    return nullptr;
}

set<string> ControladorUsuario::getIdiomasProfesor(string nickname) {
    return this->obtenerProfesor(nickname)->getNombresIdiomas();
}

void ControladorUsuario::ingresarSolucionCompletar(list<string> palabras) {
    this->inscripcionSeleccionada->resolverCompletar(this->ejercicioSeleccionado, palabras);
}

void ControladorUsuario::ingresarSolucionTraduccion(string traduccion) {
    this->inscripcionSeleccionada->resolverTraduccion(this->ejercicioSeleccionado, traduccion);
}

Usuario* ControladorUsuario::getUsuario(string nickname){
    set<Usuario*>::iterator it=this->usuarios.begin();
    while(it!=this->usuarios.end() && (*it)->getNickname()!=nickname){
        ++it;
    }
    if(it!=this->usuarios.end()) {
        return (*it);
    }
    return nullptr;
}

void ControladorUsuario::agregarCursoAProfesor(Profesor* p, Curso* c){
    p->agregarCurso(c);
}

void ControladorUsuario::hacerEjercicio(DTEjercicio ejercicio){
    this->ejercicioSeleccionado=this->inscripcionSeleccionada->obtenerEjercicio(ejercicio);
    ControladorCurso* cc=ControladorCurso::getInstance();
    this->tipoEjercicioSeleccionado=cc->obtenerTipo(this->ejercicioSeleccionado);
}

void ControladorUsuario::seleccionIdiomas(set<string> idiomas) {
    this->idiomasSeleccionados=idiomas;
}

void ControladorUsuario::confirmarAltaUsuario() {
    if(this->tipoUsuarioEnProceso==PROFESOR){
        ControladorIdioma* ci=ControladorIdioma::getInstance();
        set<string>::iterator it;
        for(it=this->idiomasSeleccionados.begin(); it!=this->idiomasSeleccionados.end(); ++it) {
            Idioma* idioma=ci->getIdioma(*it);
            ((Profesor*)this->usuarioEnProceso)->agregarIdiomaProf(idioma);
        }
        this->profesores.insert((Profesor*)this->usuarioEnProceso);
    }else{
        this->usuarios.insert((Estudiante*)this->usuarioEnProceso);
    }
    this->usuarios.insert(this->usuarioEnProceso);
}