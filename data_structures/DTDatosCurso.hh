#ifndef DT_DATOS_CURSO_HH
#define DT_DATOS_CURSO_HH

#include "DTCurso.hh"
#include "DTLeccion.hh"
#include "DTEjercicio.hh"
#include "DTInscripcion.hh"
#include <vector>
#include <set>

struct DatosLeccion{
    DTLeccion leccion;
    vector<DTEjercicio> ejercicios;
};

class DTDatosCurso{
private:
    DTCurso curso;
    string idioma, profesor;
    bool habilitado;
    vector<DatosLeccion> lecciones;
    set<DTInscripcion> inscripciones;
public:
    DTDatosCurso(
        DTCurso curso, string idioma, string profesor, bool habilitado, 
        vector<DatosLeccion> lecciones, set<DTInscripcion> inscripciones
    );
    DTCurso getCurso();
    string getIdioma();
    string getProfesor();
    bool getHabilitado();
    vector<DatosLeccion> getLecciones();
    set<DTInscripcion> getInscripciones();
};

#endif