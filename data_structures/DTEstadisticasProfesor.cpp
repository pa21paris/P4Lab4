#include "DTEstadisticasProfesor.hh"

DTEstadisticasProfesor::DTEstadisticasProfesor(set<DTProgresoPromedioCurso> datosCursosPropuestos) {
    this->datosCursosPropuestos = datosCursosPropuestos;
}

set<DTProgresoPromedioCurso> DTEstadisticasProfesor::getDatosCursosPropuestos() {
    return datosCursosPropuestos;
}

