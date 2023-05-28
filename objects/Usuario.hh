#ifndef USUARIO_HH
#define USUARIO_HH

#include <set>
#include "Suscripcion.hh"
#include "Idioma.hh"

class Notificacion;

class Usuario : public Suscripcion {
private:
    string nickname, password, name, description;
    set<Notificacion*> notificaciones;
public:
    Usuario(string nickname, string password, string name, string description);
    string getNickname();
    string getPassword();
    string getName();
    string getDescription();
    void enviarNotificacion(Notificacion* n);
    set<DTNotificacion> getNotificaciones();    
};

#include "Notificacion.hh"

#endif