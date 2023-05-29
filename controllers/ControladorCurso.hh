#ifndef CONTROLADORCURSO_HH
#define CONTROLADORCURSO_HH

#include "IControladorCurso.hh"

class ControladorCurso : public IControladorCurso {
private:
    set<Curso*> cursos, cursosPrevios;
    set<Leccion*> lecciones;
    ControladorCurso();
public:
    void eliminarCurso();
    set<DTCurso> listarCursos();
    set<string> obtenerNicksDocentes();
    void seleccionUsuario(string nickname);
    void datosCurso(string nombre, string descripcion, Dificultades dificultad);
    void leccionDatos(string tema, string objetivo);
    set<string> idiomasDelDocente();
    void seleccionarCurso(DTCurso curso);
    void seleccionDeIdioma(string nombreIdiomas);
    set<DTCurso> solicitarCursosHabilitados();
    void agregarCursoPrevio(DTCurso curso);
    DTProgresoPromedioCurso listarEstadisticasCurso(DTCurso curso);
    void altaCurso();
    TipoEjercicio obtenerTipo(Ejercicio ejercicio);
    void altaLeccion();
    void agregarEjercicio(TipoEjercicio tipoDeEjercicio, string descripcion);
    void ejercicioDeCompletar(string fraseACompletar, set<string> palabrasFaltantes);
    void ejercicioDeTraduccion(string fraseATraducir, string fraseTraducida);
    void altaEjercicio();
    IControladorCurso* getInstance();
};

#endif