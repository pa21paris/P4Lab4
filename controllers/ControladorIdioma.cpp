#include "ControladorIdioma.hh"
#include "ControladorUsuario.hh"

ControladorIdioma* ControladorIdioma::instance = nullptr;

ControladorIdioma::ControladorIdioma(){}

ControladorIdioma* ControladorIdioma::getInstance() {
    if(ControladorIdioma::instance == nullptr){
        ControladorIdioma::instance = new ControladorIdioma();
    }
    return ControladorIdioma::instance;
}

Idioma* ControladorIdioma::getIdioma(string nomId) {
    set<Idioma*>::iterator it=this->idiomas.begin();
    while (it!=this->idiomas.end() && (*it)->getNombre()!=nomId) {
        ++it;
    }

    if (it==this->idiomas.end()) return nullptr;
    
    return (*it);
}

vector<string> ControladorIdioma::obtenerSuscripcionesDisponibles(string nickname) {
    vector<string> res;
    ControladorUsuario* cu = ControladorUsuario::getInstance();
    this->user=cu->getUsuario(nickname);
    if(this->user==nullptr) return res;
    set<Idioma*>::iterator it;
    for (it=this->idiomas.begin(); it!=this->idiomas.end(); ++it) {
        if(!(*it)->verificarSuscripcion(this->user)){
            res.push_back((*it)->getNombre());
        }
    }
    return res;
}

void ControladorIdioma::agregarSuscripciones(set<string> idiomas) {
    set<string>::iterator it;
    for (it=idiomas.begin(); it!=idiomas.end(); ++it) {
        this->getIdioma(*it)->agregarSuscripcion(this->user);
    }
}

set<string> ControladorIdioma::listarIdiomas(string nickname) {
    set<string> res;
    ControladorUsuario* cu = ControladorUsuario::getInstance();
    this->user=cu->getUsuario(nickname);
    set<Idioma*>::iterator it;
    for (it=this->idiomas.begin(); it!=this->idiomas.end(); ++it) {
        if((*it)->verificarSuscripcion(this->user)){
            res.insert((*it)->getNombre());
        }
    }
    return res;    
}

void ControladorIdioma::eliminarIdioma(set<string> idiomas) {
    set<string>::iterator it;
    for (it=idiomas.begin(); it!=idiomas.end(); ++it) {
        this->getIdioma(*it)->eliminarSuscripcion(this->user);
    }
}

void ControladorIdioma::enviarNotificacion(string nombre, string nombreIdioma) {
    Idioma* idioma=this->getIdioma(nombreIdioma);
    if(idioma!=nullptr){
        Notificacion* notificacion = new Notificacion(nombre, nombreIdioma);
        idioma->enviarNotificacion(notificacion);
    }
}

vector<string> ControladorIdioma::obtenerIdiomas() {
    vector<string> res;
    set<Idioma*>::iterator it;
    for (it=this->idiomas.begin(); it!=this->idiomas.end(); ++it) {
        res.push_back((*it)->getNombre());
    }
    return res;
}

void ControladorIdioma::altaIdioma(string nombreIdioma) {
    this->idiomas.insert(new Idioma(nombreIdioma));
}

vector<string> ControladorIdioma::consultarIdiomas() {
    vector<string> res;
    set<Idioma*>::iterator it;
    for (it=this->idiomas.begin(); it!=this->idiomas.end(); ++it) {
        res.push_back((*it)->getNombre());
    }
    return res;
}