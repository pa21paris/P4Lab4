#ifndef NOTIFICACION_HH
#define NOTIFICACION_HH

#include "Usuario.hh"

class Notificacion{
private:
    string nombreIdioma, nombreCurso;
    set<Usuario*> usuarios;
    DTNotificacion getDTNotificacion();
public:
    Notificacion(string nombreIdioma, string nombreCurso);
    void asociarUsuario(Usuario* id);
    DTNotificacion leerNotificacion(Usuario* user);
};

#endif