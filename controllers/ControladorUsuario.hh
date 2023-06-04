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
public:
    static ControladorUsuario* getInstance();
    set<DTEstudiante> listarEstudiantes();
    DTEstadisticasEstudiante listarEstadisticasEstudiante(DTEstudiante estudiante);
    set<DTNotificacion> obtenerNotificaciones(string nickname);
    set<DTCurso> listarCursosActivosDeEstudiante(string nickname);
    void ingresarDatosUsuario(string nickname, string contraseña, string nombre, string descripcion, TipoUsuario tipo);
    void ingresarDatosEstudiante(string pais_res, Date fechaNacimiento);
    void ingresarInstituto(string instituto);
    set<string> obtenerListaDeIdiomas();
    set<DTProfesor> listarProfesores();
    DTEstadisticasProfesor listarEstadisticasProfesor(DTProfesor profesor);
    set<DTEjercicio> verEjerciciosPendientes(DTCurso curso);
    set<DTCurso> listarCursos();
    DTProgresoPromedioCurso listarEstadisticasCurso(DTCurso curso);
    Profesor* obtenerProfesor(string nickname);
    set<string> getIdiomasProfesor(string nickname);
    void ingresarSolucionCompletar(list<string> palabras);
    void ingresarSolucionTraduccion(string traduccion);
    Usuario* getUsuario(string nickname);
    void agregarCursoAProfesor(Profesor* p, Curso* c);
    void hacerEjercicio(DTEjercicio ejercicio);
    void seleccionIdiomas(set<string> idiomas);
    void confirmarAltaUsuario();
};

#endif