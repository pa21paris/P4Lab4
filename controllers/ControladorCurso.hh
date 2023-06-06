#ifndef CONTROLADORCURSO_HH
#define CONTROLADORCURSO_HH

#include "IControladorCurso.hh"

class ControladorCurso : public IControladorCurso {
private:
    static ControladorCurso* instance;
    set<Curso*> cursos, cursosPrevios;
    set<Leccion*> lecciones;
    Curso* cursoEnProceso;
    Profesor* profesorSeleccionado;
    string idiomaSeleccionado;
    Leccion* leccionEnCreacion;
    Ejercicio* ejercicioEnCreacion;
    ControladorCurso();
    Curso* findCursoByDTCurso(DTCurso curso);
    void vaciarDatosTemporales();
    set<Curso*> getCursosHabilitados();
public:
    void eliminarCurso();
    set<DTCurso> listarCursos();
    set<string> obtenerNicksDocentes();
    void seleccionUsuario(string nickname);
    void datosCurso(string nombre, string descripcion, Dificultades dificultad);
    void leccionDatos(string tema, string objetivo);
    set<string> idiomasDelDocente();
    void seleccionarCurso(DTCurso curso);
    void seleccionDeIdioma(string nombreIdioma);
    set<DTCurso> solicitarCursosHabilitados();
    set<DTCurso> solicitarCursosNoHabilitados();
    void agregarCursoPrevio(DTCurso curso);
    DTProgresoPromedioCurso listarEstadisticasCurso(DTCurso curso);
    void altaCurso();
    TipoEjercicio obtenerTipo(Ejercicio* ejercicio);
    void altaLeccion();
    void agregarEjercicio(string frase, TipoEjercicio tipoDeEjercicio, string descripcion);
    void ejercicioDeCompletar(list<string> palabrasFaltantes);
    void ejercicioDeTraduccion(string fraseTraducida);
    void altaEjercicio();
    static ControladorCurso* getInstance();
    void habilitarCurso(DTCurso curso);
    void AgregarLeccion();
    list<DTLeccion> listarLeccionesCurso();
    void SeleccionarLeccion(int index);
    void FinalizarAgregarEjercicio();
    set<DTCurso> listarCursosDisponibles(Estudiante* estudiante);
    void inscribirACurso(Estudiante* estudiante, DTCurso curso);
};

#endif