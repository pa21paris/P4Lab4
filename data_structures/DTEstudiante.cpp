#include "DTEstudiante.hh"

DTEstudiante::DTEstudiante(string nickname, string password, string name, string description, string pais_res, Date f_nacimiento)
    : DTUsuario(nickname, password, name, description), f_nacimiento(f_nacimiento) {
    this->pais_res = pais_res;
}

string DTEstudiante::getPais_res() const{
    return this->pais_res;
}

Date DTEstudiante::getF_nacimiento() const{
    return this->f_nacimiento;
}

bool DTEstudiante::operator<(const DTEstudiante& otro) const {
    return (this->f_nacimiento < otro.f_nacimiento);
}