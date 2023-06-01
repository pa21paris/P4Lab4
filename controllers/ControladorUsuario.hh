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
    TipoUsuario tipoUsuarioEnProceso;
    ControladorUsuario();
public:
    static ControladorUsuario* getInstance();
    set<DTEstudiante> listarEstudiantes();
    DTEstadisticasEstudiante listarEstadisticasEstudiante(DTEstudiante estudiante);
    set<DTProgresoCurso> listarEstadisticas();
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
    void enviarNotificacion(string nombre, string nombreIdiomas);
    Profesor* obtenerProfesor(string nickname);
    set<string> getIdiomasProfesor(string nickname);
    void ingresarSolucionCompletar(set<string> palabras);
    void ingresarSolucionTraduccion(string traduccion);
    Usuario* getUsuario(string nickname);
    void agregarCursoAProfesor(Profesor* p, Curso* c);
};

#endif