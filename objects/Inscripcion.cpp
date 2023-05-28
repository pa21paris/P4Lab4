#include "Inscripcion.hh"
#include "Traduccion.hh"
#include "Completar.hh"

Inscripcion::Inscripcion(Date fechaInscripcion, Curso* curso)
    :fechaInscripcion(fechaInscripcion){
    this->curso = curso;
}

int Inscripcion::getTotalEP(){
    return this->ejerciciosPendientes.size();
}

float Inscripcion::getProgreso(){
    int totalEjercicios=this->curso->getTotalE();
    int ejerciciosPendientes=this->getTotalEP();
    return (totalEjercicios-ejerciciosPendientes)/totalEjercicios;
}

DTProgresoCurso Inscripcion::getDataProgresoEstudiante(){
    return DTProgresoCurso(this->curso->convertirADTCurso(), this->getProgreso());
}

DTCurso Inscripcion::getDTCurso(){
    this->curso->convertirADTCurso();
}

Ejercicio* Inscripcion::obtenerEjercicio(DTEjercicio ejercicio){
    set<Ejercicio*>::iterator it=this->ejerciciosPendientes.begin();
    bool encontrado=false;
    while (it!=this->ejerciciosPendientes.end() && !encontrado){
        if((*it)->getFrase()==ejercicio.getFrase() && (*it)->getDescripcion()==ejercicio.getDescripcion()){
            encontrado=true;
        }else{
            it++;
        }
    }
    if (it!=this->ejerciciosPendientes.end()){
        return *it;
    }
    return nullptr;
}

void Inscripcion::resolverTraduccion(Ejercicio* ejercicio, string traduccion){
    Traduccion* t=(Traduccion*)ejercicio;
    if(t->resolver(traduccion)){
        this->ejerciciosPendientes.erase(ejercicio);
    }
}

void Inscripcion::resolverCompletar(Ejercicio* ejercicio, set<string> palabras){
    Completar* c=(Completar*)ejercicio;
    if(c->resolver(palabras)){
        this->ejerciciosPendientes.erase(ejercicio);
    }
}