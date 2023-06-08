#ifndef ICONTROLADORCURSO_HH
#define ICONTROLADORCURSO_HH

#include "../objects/Curso.hh"
#include "../data_structures/TipoEjercicio.hh"
#include "../data_structures/DTCurso.hh"
#include "../data_structures/DTLeccion.hh"
#include "../data_structures/DTDatosCurso.hh"
#include "../objects/Estudiante.hh"

class IControladorCurso{
public:
    virtual void eliminarCurso()=0;
    virtual vector<DTCurso> listarCursos()=0;
    virtual vector<string> obtenerNicksDocentes()=0;
    virtual void seleccionUsuario(string nickname)=0;
    virtual void datosCurso(string nombre, string descripcion, Dificultades dificultad)=0;
    virtual void leccionDatos(string tema, string objetivo)=0;
    virtual vector<string> idiomasDelDocente()=0;
    virtual void seleccionarCurso(DTCurso curso)=0;
    virtual void seleccionDeIdioma(string nombreIdioma)=0;
    virtual vector<DTCurso> solicitarCursosHabilitados()=0;
    virtual vector<DTCurso> solicitarCursosNoHabilitados()=0;
    virtual void agregarCursoPrevio(DTCurso curso)=0;
    virtual void habilitarCurso(DTCurso curso)=0;
    virtual DTProgresoPromedioCurso listarEstadisticasCurso(DTCurso curso)=0;
    virtual void altaCurso()=0;
    virtual TipoEjercicio obtenerTipo(Ejercicio* ejercicio)=0;
    virtual void altaLeccion()=0;
    virtual void agregarEjercicio(string frase, TipoEjercicio tipoDeEjercicio, string descripcion)=0;
    virtual void ejercicioDeCompletar(vector<string> palabrasFaltantes)=0;
    virtual void ejercicioDeTraduccion(string fraseTraducida)=0;
    virtual void altaEjercicio()=0;
    virtual void AgregarLeccion() = 0;
    virtual set<DTLeccion> listarLeccionesCurso() = 0;
    virtual void SeleccionarLeccion(int index) = 0;
    virtual void FinalizarAgregarEjercicio() = 0;
    virtual vector<DTCurso> listarCursosDisponibles(Estudiante* estudiante) = 0;
    virtual void inscribirACurso(Estudiante* estudiante, DTCurso curso) = 0;
    virtual DTDatosCurso getDatosCurso(DTCurso curso) = 0;
};

#endif