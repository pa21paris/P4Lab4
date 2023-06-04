#ifndef DTPROGRESOCURSO_HH
#define DTPROGRESOCURSO_HH

#include "DTCurso.hh"

class DTProgresoCurso{
private:
    DTCurso curso;
    float progreso;
public:
    DTProgresoCurso(DTCurso curso, float progreso);
    DTCurso getCurso() const;
    float getProgreso() const;
    bool operator<(const DTProgresoCurso& otro) const;
};

#endif