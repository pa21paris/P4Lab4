#ifndef DATOS_LECCION_HH
#define DATOS_LECCION_HH

#include "DTLeccion.hh"
#include "DTEjercicio.hh"
#include <set>

struct DatosLeccion{
    DTLeccion leccion;
    set<DTEjercicio> ejercicios;
    DatosLeccion(DTLeccion leccion, set<DTEjercicio> ejercicios):leccion(leccion){
        this->ejercicios = ejercicios;
    }
};

#endif