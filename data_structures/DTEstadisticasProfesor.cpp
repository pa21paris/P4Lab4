#include "DTEstadisticasProfesor.hh"

DTEstadisticasProfesor::DTEstadisticasProfesor(set<DTProgresoPromedioCurso> datosCursosPropuestos) {
    this->datosCursosPropuestos = datosCursosPropuestos;
}

set<DTProgresoPromedioCurso> DTEstadisticasProfesor::getDatosCursosPropuestos() const{
    return datosCursosPropuestos;
}

bool DTEstadisticasProfesor::operator<(const DTEstadisticasProfesor& otro) const{
    return (this->datosCursosPropuestos < otro.datosCursosPropuestos);
}

