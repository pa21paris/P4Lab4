#include "Usuario.hh"

Usuario::Usuario(string nickname, string password, string name, string description) {
    this->nickname = nickname;
    this->password = password;
    this->name = name;
    this->description = description;
}

string Usuario::getNickname() {
    return this->nickname;
}

string Usuario::getPassword() {
    return this->password;
}

string Usuario::getName() {
    return this->name;
}

string Usuario::getDescription() {
    return this->description;
}

set<DTNotificacion> Usuario::getNotificaciones() {
    set<DTNotificacion> res;
    set<Notificacion*>::iterator it;
    for (it = this->notificaciones.begin(); it != this->notificaciones.end(); it++) {
        res.insert((*it)->leerNotificacion(this));
        this->notificaciones.erase((*it));
    }
    return res;
}

void Usuario::enviarNotificacion(Notificacion* n) {
    this->notificaciones.insert(n);
}