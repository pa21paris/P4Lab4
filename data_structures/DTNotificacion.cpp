#include "DTNotificacion.hh"

DTNotificacion::DTNotificacion(string nombreIdioma, string nombreCurso){
    this->nombreIdioma = nombreIdioma;
    this->nombreCurso = nombreCurso;
}

string DTNotificacion::getNombreIdioma() const{
    return this->nombreIdioma;
}

string DTNotificacion::getNombreCurso() const{
    return this->nombreCurso;
}

bool DTNotificacion::operator<(const DTNotificacion& otro) const{
    return (this->nombreIdioma < otro.nombreIdioma);
}

string DTNotificacion::to_string() const{
    return ("Idioma: " + this->getNombreIdioma() + ", Curso: " + this->getNombreCurso());
}