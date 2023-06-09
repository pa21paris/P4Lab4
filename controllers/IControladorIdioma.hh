#ifndef ICONTROLADORIDIOMA_HH
#define ICONTROLADORIDIOMA_HH

#include "../objects/Idioma.hh"
#include "vector"

class IControladorIdioma{
public:
    virtual Idioma* getIdioma(string nomid)=0;
    virtual vector<string> obtenerSuscripcionesDisponibles(string nickname)=0;
    virtual void agregarSuscripciones(set<string> idiomas)=0;
    virtual vector<string> listarIdiomas(string nickname)=0;
    virtual void eliminarIdioma(set<string> idiomas)=0;
    virtual void enviarNotificacion(string nombre, string nombreIdioma)=0;
    virtual vector<string> obtenerIdiomas()=0;
    virtual void altaIdioma(string nombreIdioma)=0;
    virtual vector<string> consultarIdiomas()=0;
};

#endif