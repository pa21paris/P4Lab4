#include "Idioma.hh"

Idioma::Idioma(string nombre){
    this->nombre = nombre;
}

string Idioma::getNombre(){
    return this->nombre;
}

bool Idioma::verificarSuscripcion(Usuario* user){
    return this->usuariosSuscriptos.find(user) == this->usuariosSuscriptos.end();
}

void Idioma::agregarSuscripcion(Usuario* user){
    this->usuariosSuscriptos.insert(user);
}

void Idioma::eliminarSuscripcion(Usuario* user){
    this->usuariosSuscriptos.erase(user);
}

bool Idioma::enviarNotificacion(DTNotificacion n){
    set<Suscripcion *>::iterator it;
    for(it = this->usuariosSuscriptos.begin(); it != this->usuariosSuscriptos.end(); it++){
        (*it)->enviarNotificacion(n);
    }
    return true;
}