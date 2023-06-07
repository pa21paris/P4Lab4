#include "DTDatosCurso.hh"

DTDatosCurso::DTDatosCurso(
    DTCurso curso, string idioma, string profesor, bool habilitado, 
    vector<DatosLeccion> lecciones, set<DTInscripcion> inscripciones) : curso(curso){
    this->idioma = idioma;
    this->profesor = profesor;
    this->habilitado = habilitado;
    this->lecciones = lecciones;
    this->inscripciones = inscripciones;
}

DTCurso DTDatosCurso::getCurso() {
    return this->curso;
}

string DTDatosCurso::getIdioma() {
    return this->idioma;
}

string DTDatosCurso::getProfesor() {
    return this->profesor;
}

bool DTDatosCurso::getHabilitado() {
    return this->habilitado;
}

vector<DatosLeccion> DTDatosCurso::getLecciones() {
    return this->lecciones;
}

set<DTInscripcion> DTDatosCurso::getInscripciones() {
    return this->inscripciones;
}