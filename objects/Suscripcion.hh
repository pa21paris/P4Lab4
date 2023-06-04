#ifndef SUSCRIPCION_HH
#define SUSCRIPCION_HH

class Notificacion;

class Suscripcion{
public:
    virtual void enviarNotificacion(Notificacion* n)=0;
};

#include "Notificacion.hh"

#endif