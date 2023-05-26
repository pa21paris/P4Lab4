#include "DTCurso.hh"

class DTProgresoCurso{
private:
    DTCurso curso;
    float progreso;
public:
    DTProgresoCurso(DTCurso curso, float progreso);
    DTCurso getCurso();
    float getProgreso();
};