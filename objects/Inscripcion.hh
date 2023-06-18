#ifndef INSCRIPCION_HH
#define INSCRIPCION_HH

#include "../data_structures/Date.hh"
#include "../data_structures/DTProgresoCurso.hh"
#include "../data_structures/DTEjercicio.hh"
#include "Ejercicio.hh"
#include "Curso.hh"

class Estudiante;

class Inscripcion{
private:
    Date fechaInscripcion;
    set<Ejercicio*> ejerciciosPendientes;
    Curso* curso;
    Leccion* leccionActual;
    Estudiante* estudiante;
    int ejericiosRealizados;
    void avanzarLeccion();
public:
    Inscripcion(Date fechaInscripcion, Curso* curso);
    float getProgreso();
    int getTotalEP();
    DTProgresoCurso getDataProgresoEstudiante();
    DTCurso getDTCurso();
    Ejercicio* obtenerEjercicio(DTEjercicio ejercicio);
    vector<DTEjercicio> getEjerciciosPendientes();
    bool resolverTraduccion(Ejercicio* ejercicio, string traduccion);
    bool resolverCompletar(Ejercicio* ejercicio, vector<string> palabras);
    Curso* getCurso();
    DTInscripcion getData();
    void setEstudiante(Estudiante* estudiante);
};

#include "Estudiante.hh"

#endif