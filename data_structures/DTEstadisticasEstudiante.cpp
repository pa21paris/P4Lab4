#include "DTEstadisticasEstudiante.hh"

DTEstadisticasEstudiante::DTEstadisticasEstudiante(set<DTProgresoCurso> progresoEstudiante) {
    this->progresoEstudiante = progresoEstudiante;
}

set<DTProgresoCurso> DTEstadisticasEstudiante::getProgresoEstudiante() const{
    return this->progresoEstudiante;
}

bool DTEstadisticasEstudiante::operator<(const DTEstadisticasEstudiante& otro) const{
    return (this->progresoEstudiante < otro.progresoEstudiante);
}