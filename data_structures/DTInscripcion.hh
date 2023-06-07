#ifndef DTINSCRIPCION_HH
#define DTINSCRIPCION_HH

#include "Date.hh"

class DTInscripcion{
private:
    string nombre;
    Date fechaInscripcion;
public:
    DTInscripcion(string nombre, Date fechaInscripcion);
    string getNombre();
    Date getFechaInscripcion();
};

#endif