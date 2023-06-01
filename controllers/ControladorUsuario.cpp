#include "ControladorUsuario.hh"
#include "ControladorIdioma.hh"

ControladorUsuario* ControladorUsuario::getInstance() {
    if(ControladorUsuario::instance == nullptr) ControladorUsuario::instance=new ControladorUsuario();
    return ControladorUsuario::instance;
}

set<DTEstudiante> ControladorUsuario::listarEstudiantes() {
    set<DTEstudiante> res;
    set<Estudiante*>::iterator it;
    for(it=estudiantes.begin(); it!=estudiantes.end(); it++) {
        res.insert((*it)->getData());
    }
    return res;
}

DTEstadisticasEstudiante ControladorUsuario::listarEstadisticasEstudiante(DTEstudiante estudiante) {
    set<Estudiante*>::iterator it=this->estudiantes.begin();
    while(it!=this->estudiantes.end() && (*it)->getNickname()!=estudiante.getNickname()){
        it++;
    }
    if(it!=this->estudiantes.end()) {
        return DTEstadisticasEstudiante((*it)->listarEstadisticas());
    }
    return DTEstadisticasEstudiante(set<DTProgresoCurso>());
}

set<DTProgresoCurso> ControladorUsuario::listarEstadisticas() {
    // TODO
}

set<DTNotificacion> ControladorUsuario::obtenerNotificaciones(string nickname) {
    set<Usuario*>::iterator it=this->usuarios.begin();
    while(it!=this->usuarios.end() && (*it)->getNickname()!=nickname){
        it++;
    }
    if(it!=this->usuarios.end()) {
        return (*it)->getNotificaciones();
    }
    return set<DTNotificacion>();
}

set<DTCurso> ControladorUsuario::listarCursosActivosDeEstudiante(string nickname) {
    set<Estudiante*>::iterator it=this->estudiantes.begin();
    while(it!=this->estudiantes.end() && (*it)->getNickname()!=nickname){
        it++;
    }
    if(it!=this->estudiantes.end()) {
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
    for(it=profesores.begin(); it!=profesores.end(); it++) {
        res.insert((*it)->getData());
    }
    return res;
}