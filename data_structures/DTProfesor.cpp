#include "DTProfesor.hh"

DTProfesor::DTProfesor(string nickname, string password, string name, string description, string instituto)
    : DTUsuario(nickname, password, name, description){
    this->instituto = instituto;
}

string DTProfesor::getInstituto(){
    return this->instituto;
}