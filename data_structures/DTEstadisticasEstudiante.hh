#include "DTProgresoCurso.hh"
#include <set>

class DTEstadisticasEstudiante {
private:
    set<DTProgresoCurso> progresoEstudiante;
public:
    DTEstadisticasEstudiante(set<DTProgresoCurso> progresoEstudiante);
    set<DTProgresoCurso> getProgresoEstudiante();
};