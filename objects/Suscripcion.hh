#ifndef SUSCRIPCION_HH
#define SUSCRIPCION_HH

#include "data_structures/DTNotificacion.hh"

class Suscripcion{
public:
    virtual void enviarNotificacion(DTNotificacion n)=0;
};

#endif