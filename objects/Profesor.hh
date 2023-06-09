#ifndef PROFESOR_HH
#define PROFESOR_HH

#include <vector>
#include "Usuario.hh"
#include "Curso.hh"
#include "../data_structures/DTProgresoPromedioCurso.hh"
#include "../data_structures/DTProfesor.hh"

class Profesor : public Usuario{
private:
    string instituto;
    set<Idioma*> idiomas;
    set<Curso*> cursosPropuestos;
public:
    Profesor(string nickname, string password, string name, string description, string instituto);
    string getInstituto();
    vector<string> getNombresIdiomas();
    void agregarCurso(Curso* curso);
    void eliminarCursoProf(Curso* curso);
    set<DTProgresoPromedioCurso> listarEstadisticas();
    void agregarIdiomaProf(Idioma* idiomaProfesor);
    DTProfesor getData();
};

#endif