#ifndef CCONTROLADORUSUARIO_HH
#define CCONTROLADORUSUARIO_HH

#include "IControladorUsuario.hh"
#include "../objects/Estudiante.hh"

class ControladorUsuario : public IControladorUsuario {
private:
    static ControladorUsuario* instance;
    set<Usuario*> usuarios;
    set<Profesor*> profesores;
    set<Estudiante*> estudiantes;
    Usuario* usuarioEnProceso;
    Inscripcion* inscripcionSeleccionada;
    set<string> idiomasSeleccionados;
    Ejercicio* ejercicioSeleccionado;
    TipoEjercicio tipoEjercicioSeleccionado;
    TipoUsuario tipoUsuarioEnProceso;
    ControladorUsuario();
    Estudiante* getEstudiante(string nickname);
public:
    static ControladorUsuario* getInstance();
    set<DTEstudiante> listarEstudiantes();
    DTEstadisticasEstudiante listarEstadisticasEstudiante(DTEstudiante estudiante);
    set<DTNotificacion> obtenerNotificaciones(string nickname);
    set<DTCurso> listarCursosActivosDeEstudiante(string nickname);
    void ingresarDatosUsuario(string nickname, string contraseña, string nombre, string descripcion, TipoUsuario tipo);
    void ingresarDatosEstudiante(string pais_res, Date fechaNacimiento);
    void ingresarInstituto(string instituto);
    vector<string> obtenerListaDeIdiomas();
    set<DTProfesor> listarProfesores();
    DTEstadisticasProfesor listarEstadisticasProfesor(DTProfesor profesor);
    set<DTEjercicio> verEjerciciosPendientes(DTCurso curso);
    vector<DTCurso> listarCursos();
    DTProgresoPromedioCurso listarEstadisticasCurso(DTCurso curso);
    Profesor* obtenerProfesor(string nickname);
    vector<string> getIdiomasProfesor(string nickname);
    void ingresarSolucionCompletar(vector<string> palabras);
    void ingresarSolucionTraduccion(string traduccion);
    Usuario* getUsuario(string nickname);
    void agregarCursoAProfesor(Profesor* p, Curso* c);
    void hacerEjercicio(DTEjercicio ejercicio);
    void seleccionIdiomas(set<string> idiomas);
    void confirmarAltaUsuario();
    vector<string> consultarNicknameUsuarios();
    void seleccionarUsuario(string nickname);
    string getNombreUsuario();
    string getDescripcionUsuario();
    string getInstitutoUsuario();
    vector<string> getIdiomasUsuario();
    string getPaisResidenciaUsuario();
    TipoUsuario getTipoUsuario();
    vector<DTCurso> listarCursosDisponibles(string nickname);
    void inscribirseCurso(DTCurso curso);
};

#endif