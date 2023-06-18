#ifndef ICONTROLADORUSUARIO_HH
#define ICONTROLADORUSUARIO_HH

#include "../data_structures/DTEstadisticasProfesor.hh"
#include "../data_structures/DTProfesor.hh"
#include "../data_structures/DTEstadisticasEstudiante.hh"
#include "../data_structures/DTEstudiante.hh"
#include "../objects/Profesor.hh"

enum TipoUsuario{
    ESTUDIANTE,
    PROFESOR
};

class IControladorUsuario {
public:
    virtual set<DTEstudiante> listarEstudiantes()=0;
    virtual vector<string> getNicksEstudiantes()=0;    
    virtual DTEstadisticasEstudiante listarEstadisticasEstudiante(string estudiante)=0;
    virtual set<DTNotificacion> obtenerNotificaciones(string nickname)=0;
    virtual vector<DTCurso> listarCursosActivosDeEstudiante(string nickname)=0;
    virtual void ingresarDatosUsuario(string nickname, string contraseña, string nombre, string descripcion, TipoUsuario tipo)=0;
    virtual void ingresarDatosEstudiante(string pais_res, Date fechaNacimiento)=0;
    virtual void ingresarInstituto(string instituto)=0;
    virtual vector<string> obtenerListaDeIdiomas()=0;
    virtual set<DTProfesor> listarProfesores()=0;
    virtual DTEstadisticasProfesor listarEstadisticasProfesor(string profesor)=0;
    virtual vector<DTEjercicio> verEjerciciosPendientes(DTCurso curso)=0;
    virtual vector<DTCurso> listarCursos()=0;
    virtual DTProgresoPromedioCurso listarEstadisticasCurso(DTCurso curso)=0;
    virtual Profesor* obtenerProfesor(string nickname)=0;
    virtual vector<string> getIdiomasProfesor(string nickname)=0;
    virtual bool ingresarSolucionCompletar(vector<string> palabras)=0;
    virtual bool ingresarSolucionTraduccion(string traduccion)=0;
    virtual Usuario* getUsuario(string nickname)=0;
    virtual void agregarCursoAProfesor(Profesor* p, Curso* c)=0;
    virtual TipoEjercicio hacerEjercicio(DTEjercicio ejercicio)=0;
    virtual void seleccionIdiomas(set<string> idiomas)=0;
    virtual void confirmarAltaUsuario()=0;
    virtual vector<string> consultarNicknameUsuarios()=0;
    virtual void seleccionarUsuario(string nickname)=0;
    virtual string getNombreUsuario()=0;
    virtual string getDescripcionUsuario()=0;
    virtual string getInstitutoUsuario()=0;
    virtual vector<string> getIdiomasUsuario()=0;
    virtual string getPaisResidenciaUsuario()=0;
    virtual TipoUsuario getTipoUsuario()=0;
    virtual vector<DTCurso> listarCursosDisponibles(string nickname)=0;
    virtual void inscribirseCurso(DTCurso curso)=0;
    virtual bool yaRegistrado(string nickname)=0;

};

#endif