#ifndef CURSO_HH
#define CURSO_HH

#include <iostream>
#include <set>
#include <list>
#include "Leccion.hh"
#include "../data_structures/Dificultades.hh"
#include "../data_structures/DTCurso.hh"
#include "../data_structures/DTProgresoPromedioCurso.hh"
using namespace std;

class Profesor;
class Inscripcion;

class Curso{
private:
    string nombre, descripcion;
    Dificultades dificultad;
    set<Curso *> cursosPrevios;
    list<Leccion *> lecciones;
    Profesor* profesorCurso;
    set<Inscripcion*> inscripciones;
    bool habilitado;
public:
    Curso(string nombre, string descripcion, Dificultades dificultad);
    Curso(string nombre, string descripcion, Dificultades dificultad, set<Curso *> cursosPrevios, list<Leccion *> lecciones);
    void agregarPrevia(Curso *curso);
    void agregarLeccion(Leccion *leccion);
    int getTotalE();
    DTCurso convertirADTCurso();
    DTProgresoPromedioCurso getDataProgCurso();
    int getTotalInsc();
    void eliminarCurso();
    string getNombre();
    string getDescripcion();
    Dificultades getDificultad();
    Leccion* getLeccionSiguiente(Leccion* leccionActual);
    void setProfesorCurso(Profesor* profesor);
    bool estaHabilitado();
    void habilitar();
    list<DTLeccion> getDTLecciones();
    Leccion* getLeccion(int index);
    bool previasCumplidas(set<Curso*> cursosCompletos);
    void addInscripcion(Inscripcion* inscripcion);
};

#include "Profesor.hh"
#include "Inscripcion.hh"

#endif