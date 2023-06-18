#include "Inscripcion.hh"
#include "Traduccion.hh"
#include "Completar.hh"

Inscripcion::Inscripcion(Date fechaInscripcion, Curso* curso)
    :fechaInscripcion(fechaInscripcion){
    this->curso = curso;
    this->ejericiosRealizados = 0;
    this->leccionActual=curso->getLeccionSiguiente(nullptr);
    if(this->leccionActual!=nullptr) this->ejerciciosPendientes=this->leccionActual->getEjercicios();
    this->curso->addInscripcion(this);
    this->estudiante=nullptr;
}

int Inscripcion::getTotalEP(){
    return this->ejerciciosPendientes.size();
}

float Inscripcion::getProgreso(){
    int totalEjercicios=this->curso->getTotalE();
    return this->ejericiosRealizados/totalEjercicios;
}

DTProgresoCurso Inscripcion::getDataProgresoEstudiante(){
    return DTProgresoCurso(this->curso->convertirADTCurso(), this->getProgreso());
}

DTCurso Inscripcion::getDTCurso(){
    return this->curso->convertirADTCurso();
}

Ejercicio* Inscripcion::obtenerEjercicio(DTEjercicio ejercicio){
    set<Ejercicio*>::iterator it=this->ejerciciosPendientes.begin();
    bool encontrado=false;
    while (it!=this->ejerciciosPendientes.end() && !encontrado){
        if((*it)->getFrase()==ejercicio.getFrase() && (*it)->getDescripcion()==ejercicio.getDescripcion()){
            encontrado=true;
        }else{
            ++it;
        }
    }
    if (it!=this->ejerciciosPendientes.end()){
        return *it;
    }
    return nullptr;
}

void Inscripcion::avanzarLeccion(){
    this->leccionActual=this->curso->getLeccionSiguiente(this->leccionActual);
    if(this->leccionActual!=nullptr) this->ejerciciosPendientes=this->leccionActual->getEjercicios();
}

bool Inscripcion::resolverTraduccion(Ejercicio* ejercicio, string traduccion){
    Traduccion* t=(Traduccion*)ejercicio;
    bool correcto=t->resolver(traduccion);
    if(correcto){
        this->ejerciciosPendientes.erase(ejercicio);
        this->ejericiosRealizados++;
        if(this->ejerciciosPendientes.empty()) this->avanzarLeccion();
    }
    return correcto;
}

bool Inscripcion::resolverCompletar(Ejercicio* ejercicio, vector<string> palabras){
    Completar* c=(Completar*)ejercicio;
    bool correcto=c->resolver(palabras);
    if(correcto){
        this->ejerciciosPendientes.erase(ejercicio);
        this->ejericiosRealizados++;
        if(this->ejerciciosPendientes.empty()) this->avanzarLeccion();
    }
    return correcto;
}

vector<DTEjercicio> Inscripcion::getEjerciciosPendientes(){
    vector<DTEjercicio> ejerciciosPendientes;
    set<Ejercicio*>::iterator it;
    for(it=this->ejerciciosPendientes.begin(); it!=this->ejerciciosPendientes.end(); ++it){
        ejerciciosPendientes.push_back((*it)->getData());
    }
    return ejerciciosPendientes;
}

Curso* Inscripcion::getCurso(){
    return this->curso;
}

DTInscripcion Inscripcion::getData(){
    return DTInscripcion(this->estudiante->getName(), this->fechaInscripcion);
}

void Inscripcion::setEstudiante(Estudiante* estudiante){
    if(this->estudiante==nullptr) this->estudiante=estudiante;
}