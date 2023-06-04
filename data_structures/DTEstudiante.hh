#ifndef DT_ESTUDIANTE_HH
#define DT_ESTUDIANTE_HH

#include "DTUsuario.hh"
#include "Date.hh"

class DTEstudiante : public DTUsuario{
private:
    string pais_res;
    Date f_nacimiento;
public:
    DTEstudiante(string nickname, string password, string name, string description, string pais_res, Date f_nacimiento);
    string getPais_res() const;
    Date getF_nacimiento() const;
    bool operator<(const DTEstudiante& otro) const;
};

#endif