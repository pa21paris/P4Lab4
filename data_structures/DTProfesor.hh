#ifndef DT_PROFESOR_HH
#define DT_PROFESOR_HH

#include "DTUsuario.hh"

class DTProfesor : public DTUsuario {
private:
    string instituto;
public:	
    DTProfesor(string nickname, string password, string name, string description, string instituto);
    string getInstituto();
};

#endif