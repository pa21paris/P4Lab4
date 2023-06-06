#include "Estudiante.hh"
#include <ctime>

Estudiante::Estudiante(string nickname, string password, string name, string description, string paisRes, Date fNacimiento)
    : Usuario(nickname, password, name, description), fNacimiento(fNacimiento){
    this->paisRes = paisRes;
}

string Estudiante::getPaisRes() {
    return paisRes;
}

Date Estudiante::getFechaNacimiento() {
    return fNacimiento;
}

set<DTProgresoCurso> Estudiante::listarEstadisticas() {
    set<DTProgresoCurso> estadisticas;
    set<Inscripcion*>::iterator it;
    for (it = inscripciones.begin(); it != inscripciones.end(); ++it) {
        estadisticas.insert((*it)->getDataProgresoEstudiante());
    }
    return estadisticas;
}

set<DTCurso> Estudiante::getCursosActivos() {
    set<DTCurso> cursosActivos;
    set<Inscripcion*>::iterator it;
    for (it = inscripciones.begin(); it != inscripciones.end(); ++it) {
        cursosActivos.insert((*it)->getDTCurso());
    }
    return cursosActivos;
}

Inscripcion* Estudiante::getInscripcion(DTCurso curso) {
    set<Inscripcion*>::iterator it=inscripciones.begin();
    bool encontrado = false;
    while (it != inscripciones.end() && !encontrado) {
        if ((*it)->getDTCurso() == curso) {
            encontrado = true;
        } else {
            ++it;
        }
    }
    if(encontrado) return *it;
    return nullptr; 
}

DTEstudiante Estudiante::getData() {
    return DTEstudiante(
        this->getNickname(),
        this->getPassword(),
        this->getName(),
        this->getDescription(), 
        this->getPaisRes(), 
        this->getFechaNacimiento());
}

set<Curso*> Estudiante::getCursosCompletos(){
    set<Inscripcion*>::iterator it;
    set<Curso*> cursosCompletos;
    for (it = inscripciones.begin(); it != inscripciones.end(); ++it) {
        if((*it)->getDataProgresoEstudiante().getProgreso()==1) cursosCompletos.insert((*it)->getCurso());
    }
    return cursosCompletos;
}

Date getCurrentDate(){
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime); 
    int anio = 1900 + local_time->tm_year;
    int mes = 1 + local_time->tm_mon;
    int dia = local_time->tm_mday;
    return Date(dia, mes, anio);
}

void Estudiante::inscribirseACurso(Curso* curso) {
    this->inscripciones.insert(new Inscripcion(getCurrentDate(), curso));
}