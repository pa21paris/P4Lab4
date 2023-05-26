#include <set>
#include "DTProgresoPromedioCurso.hh"

class DTEstadisticasProfesor {
private:
    set<DTProgresoPromedioCurso> datosCursosPropuestos;
public:
    DTEstadisticasProfesor(set<DTProgresoPromedioCurso> datosCursosPropuestos);
    set<DTProgresoPromedioCurso> getDatosCursosPropuestos(); 
};