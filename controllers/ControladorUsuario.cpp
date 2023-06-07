#include "ControladorUsuario.hh"
#include "ControladorIdioma.hh"
#include "ControladorCurso.hh"

ControladorUsuario* ControladorUsuario::instance = nullptr;

ControladorUsuario::ControladorUsuario(){}

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

vector<string> ControladorUsuario::obtenerListaDeIdiomas() {
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

vector<DTCurso> ControladorUsuario::listarCursos() {
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

vector<string> ControladorUsuario::getIdiomasProfesor(string nickname) {
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
        this->estudiantes.insert((Estudiante*)this->usuarioEnProceso);
    }
    this->usuarios.insert(this->usuarioEnProceso);
}

vector<string> ControladorUsuario::consultarNicknameUsuarios(){
    vector<string> res;
    set<Usuario*>::iterator it;
    for(it=this->usuarios.begin(); it!=this->usuarios.end(); ++it) {
        res.push_back((*it)->getNickname());
    }
    return res;
}

void ControladorUsuario::seleccionarUsuario(string nickname) {
    Profesor* p=this->obtenerProfesor(nickname);
    if(p!=nullptr) {
        this->usuarioEnProceso=p;
        this->tipoUsuarioEnProceso=PROFESOR;
    }else{
        this->usuarioEnProceso=this->getUsuario(nickname);
        this->tipoUsuarioEnProceso=ESTUDIANTE;
    }
}

string ControladorUsuario::getDescripcionUsuario() {
    return this->usuarioEnProceso->getDescription();
}

vector<string> ControladorUsuario::getIdiomasUsuario(){
    vector<string> idiomas;
    if(this->tipoUsuarioEnProceso==PROFESOR){
        idiomas=((Profesor*)this->usuarioEnProceso)->getNombresIdiomas();
    }else{
        idiomas=vector<string>();
    }
    this->usuarioEnProceso=nullptr;
    return idiomas;
}

string ControladorUsuario::getInstitutoUsuario() {
    string res="";
    if(this->tipoUsuarioEnProceso==PROFESOR) res=((Profesor*)this->usuarioEnProceso)->getInstituto();
    return res;
}

string ControladorUsuario::getNombreUsuario() {
    return this->usuarioEnProceso->getName();
}

string ControladorUsuario::getPaisResidenciaUsuario() {
    string paisResidencia="";
    if(this->tipoUsuarioEnProceso==ESTUDIANTE){
        paisResidencia=((Estudiante*)this->usuarioEnProceso)->getPaisRes();
    }
    this->usuarioEnProceso=nullptr;
    return paisResidencia;
}

TipoUsuario ControladorUsuario::getTipoUsuario() {
    return this->tipoUsuarioEnProceso;
}

Estudiante* ControladorUsuario::getEstudiante(string nickname){
    set<Estudiante*>::iterator it=this->estudiantes.begin();
    while(it!=this->estudiantes.end() && (*it)->getNickname()!=nickname){
        cout << (*it)->getDescription();
        ++it;
    }
    if(it!=this->estudiantes.end()) return (*it);

    return nullptr;
}

vector<DTCurso> ControladorUsuario::listarCursosDisponibles(string nickname){
    this->usuarioEnProceso=this->getEstudiante(nickname);
    if(this->usuarioEnProceso==nullptr) return vector<DTCurso>();
    ControladorCurso* cc=ControladorCurso::getInstance();
    return cc->listarCursosDisponibles((Estudiante*)this->usuarioEnProceso);    
}

void ControladorUsuario::inscribirseCurso(DTCurso curso){
    ControladorCurso* cc=ControladorCurso::getInstance();
    cc->inscribirACurso((Estudiante*)this->usuarioEnProceso, curso);
    this->usuarioEnProceso=nullptr;
}