#ifndef PROFESOR_HH
#define PROFESOR_HH

#include "Usuario.hh"
#include "Curso.hh"
#include "data_structures/DTProgresoPromedioCurso.hh"

class Profesor : public Usuario{
private:
    string instituto;
    set<Idioma*> idiomas;
    set<Curso*> cursosPropuestos;
public:
    string getInstituto();
    set<string> getNombresIdiomas();
    void agregarCurso(Curso* curso);
    void eliminarCursoProf(Curso* curso);
    set<DTProgresoPromedioCurso> listarEstadisticas();
    void agregarIdiomaProf(Idioma* idiomaProfesor);
};

#endif