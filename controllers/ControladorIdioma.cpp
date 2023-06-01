#include "ControladorIdioma.hh"
#include "ControladorUsuario.hh"

ControladorIdioma* ControladorIdioma::getInstance() {
    if(ControladorIdioma::instance == nullptr){
        ControladorIdioma::instance = new ControladorIdioma();
    }
    return ControladorIdioma::instance;
}

Idioma* ControladorIdioma::getIdioma(string nomId) {
    set<Idioma*>::iterator it=this->idiomas.begin();
    while (it!=this->idiomas.end() && (*it)->getNombre()!=nomId) {
        it++;
    }

    if (it==this->idiomas.end()) return nullptr;
    
    return (*it);
}

set<string> ControladorIdioma::obtenerSuscripcionesDisponibles(string nickname) {
    set<string> res;
    ControladorUsuario* cu = ControladorUsuario::getInstance();
    this->user=cu->getUsuario(nickname);
    set<Idioma*>::iterator it;
    for (it=this->idiomas.begin(); it!=this->idiomas.end(); it++) {
        if(!(*it)->verificarSuscripcion(this->user)){
            res.insert((*it)->getNombre());
        }
    }
    return res;
}

void ControladorIdioma::agregarSuscripciones(set<string> idiomas) {
    set<string>::iterator it;
    for (it=idiomas.begin(); it!=idiomas.end(); it++) {
        this->getIdioma(*it)->agregarSuscripcion(this->user);
    }
}

set<string> ControladorIdioma::listarIdiomas(string nickname) {
    set<string> res;
    ControladorUsuario* cu = ControladorUsuario::getInstance();
    this->user=cu->getUsuario(nickname);
    set<Idioma*>::iterator it;
    for (it=this->idiomas.begin(); it!=this->idiomas.end(); it++) {
        if((*it)->verificarSuscripcion(this->user)){
            res.insert((*it)->getNombre());
        }
    }
    return res;    
}

void ControladorIdioma::eliminarIdioma(set<string> idiomas) {
    set<string>::iterator it;
    for (it=idiomas.begin(); it!=idiomas.end(); it++) {
        this->getIdioma(*it)->eliminarSuscripcion(this->user);
    }
}

void ControladorIdioma::enviarNotificacion(string nombre, string nombreIdioma) {
    set<Idioma*>::iterator it=this->idiomas.begin();
    while(it!=this->idiomas.end() && (*it)->getNombre()!=nombre){
        it++;        
    }
    if(it!=this->idiomas.end()){
        DTNotificacion notificacion(nombre, nombreIdioma);
        (*it)->enviarNotificacion(notificacion);
    }
}