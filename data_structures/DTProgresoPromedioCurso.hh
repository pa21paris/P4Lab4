#include "DTCurso.hh"

class DTProgresoPromedioCurso{
private:
    DTCurso curso;
    float progCurso;
public:
    DTProgresoPromedioCurso(DTCurso curso, float progreso);
    DTCurso getCurso();
    float getProgCurso();
};