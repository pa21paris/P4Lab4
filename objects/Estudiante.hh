#ifndef ESTUDIANTE_HH
#define ESTUDIANTE_HH

#include "Usuario.hh"
#include "data_structures/Date.hh"
#include "data_structures/DTProgresoCurso.hh"
#include "data_structures/DTEstudiante.hh"
#include "Inscripcion.hh"

class Estudiante : public Usuario{
private:
    string paisRes;
    Date fNacimiento;
    set<Inscripcion*> inscripciones;
public:
    Estudiante(string nickname, string password, string name, string description, string paisRes, Date fNacimiento);
    string getPaisRes();
    Date getFechaNacimiento();
    set<DTProgresoCurso> listarEstadisticas();
    set<DTCurso> getCursosActivos();
    Inscripcion* getInscripcion(DTCurso curso);
    DTEstudiante getData();
};

#endif