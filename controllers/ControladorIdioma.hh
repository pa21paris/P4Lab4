#ifndef CONTROLADORIDIOMA_HH
#define CONTROLADORIDIOMA_HH

#include "IControladorIdioma.hh"

class ControladorIdioma : public IControladorIdioma {
private:
    static ControladorIdioma* instance;
    Usuario* user;
    set<Idioma*> idiomas;
    ControladorIdioma();
public:
    static ControladorIdioma* getInstance();
    Idioma* getIdioma(string nomId);
    set<string> obtenerSuscripcionesDisponibles(string nickname);
    void agregarSuscripciones(set<string> idiomas);
    set<string> listarIdiomas(string nickname);
    void eliminarIdioma(set<string> idiomas);
    void enviarNotificacion(string nombre, string nombreIdioma);
    set<string> obtenerIdiomas();
    void altaIdioma(string nombreIdioma);
};

#endif