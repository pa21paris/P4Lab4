#ifndef ICONTROLADORIDIOMA_HH
#define ICONTROLADORIDIOMA_HH

#include "objects/Idioma.hh"

class IControladorIdioma{
protected:
    static IControladorIdioma* intance;
public:
    virtual IControladorIdioma* getInstance()=0;
    virtual Idioma getIdioma(string nomid)=0;
    virtual set<string> obtenerSuscripcionesDisponibles(string nickname)=0;
    virtual void agregarSuscripciones(set<string> idiomas)=0;
    virtual set<string> listarIdiomas(string nickname)=0;
    virtual void eliminarIdioma(set<string> idiomas)=0;
};

#endif