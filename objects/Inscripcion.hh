#ifndef INSCRIPCION_HH
#define INSCRIPCION_HH

#include "data_structures/Date.hh"
#include "data_structures/DTProgresoCurso.hh"
#include "data_structures/DTEjercicio.hh"
#include "Ejercicio.hh"
#include "Curso.hh"

class Inscripcion{
private:
    Date fechaInscripcion;
    set<Ejercicio*> ejerciciosPendientes;
    Curso* curso;
public:
    float getProgreso();
    DTProgresoCurso getDataProgresoEstudiante();
    int getTotalEP();
    DTCurso getDTCurso();
    Ejercicio* obtenerEjercicio(DTEjercicio ejercicio);
    void resolverTraduccion(Ejercicio* ejercicio, string traduccion);
    void resolverCompletar(Ejercicio* ejercicio, set<string> palabras);
};

#endif