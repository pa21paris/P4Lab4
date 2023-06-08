#ifndef DTINSCRIPCION_HH
#define DTINSCRIPCION_HH

#include "Date.hh"

class DTInscripcion{
private:
    string nombre;
    Date fechaInscripcion;
public:
    DTInscripcion(string nombre, Date fechaInscripcion);
    string getNombre() const;
    Date getFechaInscripcion() const;
    bool operator<(const DTInscripcion& otro) const;
};

#endif