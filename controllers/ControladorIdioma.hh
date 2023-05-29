#ifndef CONTROLADORIDIOMA_HH
#define CONTROLADORIDIOMA_HH

#include "IControladorIdioma.hh"

class ControladorIdioma : public IControladorIdioma {
private:
    set<Idioma*> idiomas;
    ControladorIdioma();
public:
    IControladorIdioma* getInstance();
    Idioma getIdioma(string nomid);
    set<string> obtenerSuscripcionesDisponibles(string nickname);
    void agregarSuscripciones(set<string> idiomas);
    set<string> listarIdiomas(string nickname);
    void eliminarIdioma(set<string> idiomas);
};

#endif