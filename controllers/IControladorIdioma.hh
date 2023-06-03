#ifndef ICONTROLADORIDIOMA_HH
#define ICONTROLADORIDIOMA_HH

#include "objects/Idioma.hh"

class IControladorIdioma{
public:
    virtual Idioma* getIdioma(string nomid)=0;
    virtual set<string> obtenerSuscripcionesDisponibles(string nickname)=0;
    virtual void agregarSuscripciones(set<string> idiomas)=0;
    virtual set<string> listarIdiomas(string nickname)=0;
    virtual void eliminarIdioma(set<string> idiomas)=0;
    virtual void enviarNotificacion(string nombre, string nombreIdioma)=0;
    virtual set<string> obtenerIdiomas()=0;
    virtual void altaIdioma(string nombreIdioma)=0;
};

#endif