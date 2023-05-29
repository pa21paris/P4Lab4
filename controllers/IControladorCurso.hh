#ifndef ICONTROLADORCURSO_HH
#define ICONTROLADORCURSO_HH

#include "../objects/Curso.hh"
#include "../data_structures/TipoEjercicio.hh"
#include "../data_structures/DTCurso.hh"

class IControladorCurso{
protected:
    static IControladorCurso* intance;
public:
    virtual void eliminarCurso()=0;
    virtual set<DTCurso> listarCursos()=0;
    virtual set<string> obtenerNicksDocentes()=0;
    virtual void seleccionUsuario(string nickname)=0;
    virtual void datosCurso(string nombre, string descripcion, Dificultades dificultad)=0;
    virtual void leccionDatos(string tema, string objetivo)=0;
    virtual set<string> idiomasDelDocente()=0;
    virtual void seleccionarCurso(DTCurso curso)=0;
    virtual void seleccionDeIdioma(string nombreIdiomas)=0;
    virtual set<DTCurso> solicitarCursosHabilitados()=0;
    virtual void agregarCursoPrevio(DTCurso curso)=0;
    virtual DTProgresoPromedioCurso listarEstadisticasCurso(DTCurso curso)=0;
    virtual void altaCurso()=0;
    virtual TipoEjercicio obtenerTipo(Ejercicio ejercicio)=0;
    virtual void altaLeccion()=0;
    virtual void agregarEjercicio(TipoEjercicio tipoDeEjercicio, string descripcion)=0;
    virtual void ejercicioDeCompletar(string fraseACompletar, set<string> palabrasFaltantes)=0;
    virtual void ejercicioDeTraduccion(string fraseATraducir, string fraseTraducida)=0;
    virtual void altaEjercicio()=0;
    virtual IControladorCurso* getInstance()=0;
};

#endif