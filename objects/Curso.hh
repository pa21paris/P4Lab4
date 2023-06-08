#ifndef CURSO_HH
#define CURSO_HH

#include <iostream>
#include <set>
#include <vector>
#include "Leccion.hh"
#include "../data_structures/Dificultades.hh"
#include "../data_structures/DTCurso.hh"
#include "../data_structures/DTProgresoPromedioCurso.hh"
#include "../data_structures/DTDatosCurso.hh"
using namespace std;

class Profesor;
class Inscripcion;

class Idioma;

class Curso{
private:
    string nombre, descripcion;
    Dificultades dificultad;
    set<Curso *> cursosPrevios;
    vector<Leccion *> lecciones;
    Profesor* profesorCurso;
    set<Inscripcion*> inscripciones;
    Idioma* idioma;
    bool habilitado;
    vector<DatosLeccion> getDatosLecciones();
    set<DTInscripcion> getDTInscripciones();
public:
    Curso(string nombre, string descripcion, Dificultades dificultad);
    Curso(string nombre, string descripcion, Dificultades dificultad, set<Curso *> cursosPrevios, vector<Leccion *> lecciones);
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
    void setIdiomaCurso(Idioma* idioma);
    bool estaHabilitado();
    void habilitar();
    set<DTLeccion> getDTLecciones();
    Leccion* getLeccion(int index);
    bool previasCumplidas(set<Curso*> cursosCompletos);
    void addInscripcion(Inscripcion* inscripcion);
    DTDatosCurso getDatosCurso();
};

#include "Profesor.hh"
#include "Inscripcion.hh"

#endif