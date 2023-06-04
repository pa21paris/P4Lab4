#ifndef DTPROGRESOPROMEDIOCURSO_HH
#define DTPROGRESOPROMEDIOCURSO_HH

#include "DTCurso.hh"

class DTProgresoPromedioCurso{
private:
    DTCurso curso;
    float progCurso;
public:
    DTProgresoPromedioCurso(DTCurso curso, float progreso);
    DTCurso getCurso() const;
    float getProgCurso() const;
    bool operator<(const DTProgresoPromedioCurso& otro) const;
};

#endif