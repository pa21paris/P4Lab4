#include "Curso.hh"

Curso::Curso(string nombre, string descripcion, Dificultades dificultad){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->habilitado = false;
}

Curso::Curso(string nombre, string descripcion, Dificultades dificultad, set<Curso *> cursosPrevios, vector<Leccion *> lecciones){
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
    for(int i=0; i<this->lecciones.size(); i++){
        total += this->lecciones[i]->getTotalE();
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
    float cantEstudiantes=this->getTotalInsc();
    float sumaProgresosCurso=0;
    set<Inscripcion*>::iterator it;
    for(it = this->inscripciones.begin(); it != this->inscripciones.end(); ++it){
        sumaProgresosCurso += (*it)->getProgreso();
    }
    DTProgresoPromedioCurso dtProgresoPromCurso = DTProgresoPromedioCurso(this->convertirADTCurso(), sumaProgresosCurso/cantEstudiantes);
    return dtProgresoPromCurso;
}

void Curso::eliminarCurso(){
    this->profesorCurso->eliminarCursoProf(this);
    for(int i=0; i<this->lecciones.size(); i++){
        this->lecciones[i]->eliminarLeccion();
        delete this->lecciones[i];
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
    if(this->lecciones.size()==0) return nullptr;
    if(leccionActual==nullptr) return this->lecciones.front();    
    int i=0;
    while(i<this->lecciones.size() && this->lecciones[i]!=leccionActual){
        i++;
    }
    if(i==this->lecciones.size()-1) return nullptr;
    i++;
    while (i<this->lecciones.size() && this->lecciones[i]->getEjercicios().size()==0){
        i++;
    };
    return this->lecciones[i];
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

set<DTLeccion> Curso::getDTLecciones() {
    set<DTLeccion> ret;
    for (int i=0; i<this->lecciones.size(); i++) {
        ret.insert((this->lecciones[i])->getDT());
    }
    return ret;
}

Leccion* Curso::getLeccion(int index) {
    return this->lecciones[index-1];
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

void Curso::setIdiomaCurso(Idioma* idioma){
    this->idioma = idioma;
}

vector<DatosLeccion> Curso::getDatosLecciones(){
    vector<DatosLeccion> res;
    for(int i=0; i<this->lecciones.size(); i++){
        res.push_back(lecciones[i]->getDatos());
    }
    return res;
}

set<DTInscripcion> Curso::getDTInscripciones(){
    set<DTInscripcion> res;
    set<Inscripcion*>::iterator it;
    for(it = this->inscripciones.begin(); it != this->inscripciones.end(); ++it){
        res.insert((*it)->getData());
    }
    return res;
}

DTDatosCurso Curso::getDatosCurso(){
    string idioma=this->idioma->getNombre();
    string profesor=this->profesorCurso->getName();
    bool habilitado=this->habilitado;
    vector<DatosLeccion> lecciones=this->getDatosLecciones();
    set<DTInscripcion> inscripciones=this->getDTInscripciones();
    return DTDatosCurso(this->convertirADTCurso(), idioma, profesor, habilitado, lecciones, inscripciones);
}