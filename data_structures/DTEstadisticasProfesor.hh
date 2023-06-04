#ifndef DTESTADISTICASPROFESOR_HH
#define DTESTADISTICASPROFESOR_HH

#include <set>
#include "DTProgresoPromedioCurso.hh"

class DTEstadisticasProfesor {
private:
    set<DTProgresoPromedioCurso> datosCursosPropuestos;
public:
    DTEstadisticasProfesor(set<DTProgresoPromedioCurso> datosCursosPropuestos);
    set<DTProgresoPromedioCurso> getDatosCursosPropuestos() const;
    bool operator<(const DTEstadisticasProfesor& otro) const;
};

#endif