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
    vector<string> obtenerSuscripcionesDisponibles(string nickname);
    void agregarSuscripciones(set<string> idiomas);
    vector<string> listarIdiomas(string nickname);
    void eliminarIdioma(set<string> idiomas);
    void enviarNotificacion(string nombre, string nombreIdioma);
    vector<string> obtenerIdiomas();
    void altaIdioma(string nombreIdioma);
    vector<string> consultarIdiomas();
};

#endif