#include "Notificacion.hh"

Notificacion::Notificacion(string nombreIdioma, string nombreCurso){
    this->nombreIdioma = nombreIdioma;
    this->nombreCurso = nombreCurso;
}

void Notificacion::asociarUsuario(Usuario* id){
    usuarios.insert(id);
}

DTNotificacion Notificacion::getDTNotificacion(){
    return DTNotificacion(this->nombreIdioma, this->nombreCurso);
}

DTNotificacion Notificacion::leerNotificacion(Usuario* user){
    this->usuarios.erase(user);
    return this->getDTNotificacion();
}