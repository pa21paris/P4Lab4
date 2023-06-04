#ifndef DTESTADISTICASESTUDIANTE_HH
#define DTESTADISTICASESTUDIANTE_HH

#include "DTProgresoCurso.hh"
#include <set>

class DTEstadisticasEstudiante {
private:
    set<DTProgresoCurso> progresoEstudiante;
public:
    DTEstadisticasEstudiante(set<DTProgresoCurso> progresoEstudiante);
    set<DTProgresoCurso> getProgresoEstudiante() const;
    bool operator<(const DTEstadisticasEstudiante& otro) const;
};

#endif