#include "DTNotificacion.hh"

DTNotificacion::DTNotificacion(string nombreIdioma, string nombreCurso){
    this->nombreIdioma = nombreIdioma;
    this->nombreCurso = nombreCurso;
}

string DTNotificacion::getNombreIdioma(){
    return this->nombreIdioma;
}

string DTNotificacion::getNombreCurso(){
    return this->nombreCurso;
}