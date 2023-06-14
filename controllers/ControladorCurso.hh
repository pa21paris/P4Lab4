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
    DTCurso getCurso(string nombreCurso);
    void eliminarCurso();
    vector<DTCurso> listarCursos();
    vector<string> obtenerNicksDocentes();
    void seleccionUsuario(string nickname);
    void datosCurso(string nombre, string descripcion, Dificultades dificultad);
    void leccionDatos(string tema, string objetivo);
    vector<string> idiomasDelDocente();
    void seleccionarCurso(DTCurso curso);
    void seleccionDeIdioma(string nombreIdioma);
    vector<DTCurso> solicitarCursosHabilitados();
    vector<DTCurso> solicitarCursosNoHabilitados();
    void agregarCursoPrevio(DTCurso curso);
    DTProgresoPromedioCurso listarEstadisticasCurso(DTCurso curso);
    void altaCurso();
    TipoEjercicio obtenerTipo(Ejercicio* ejercicio);
    void altaLeccion();
    void agregarEjercicio(string frase, TipoEjercicio tipoDeEjercicio, string descripcion);
    void ejercicioDeCompletar(vector<string> palabrasFaltantes);
    void ejercicioDeTraduccion(string fraseTraducida);
    void altaEjercicio();
    static ControladorCurso* getInstance();
    void habilitarCurso(DTCurso curso);
    void agregarLeccion();
    set<DTLeccion> listarLeccionesCurso();
    void SeleccionarLeccion(int index);
    void FinalizarAgregarEjercicio();
    vector<DTCurso> listarCursosDisponibles(Estudiante* estudiante);
    void inscribirACurso(Estudiante* estudiante, DTCurso curso);
    DTDatosCurso getDatosCurso(DTCurso curso);
};

#endif