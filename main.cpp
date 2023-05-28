#include <iostream>
#include "objects/Ejercicio.hh"
#include "objects/Traduccion.hh"
using namespace std;

void altaUsuario(){};
void altaIdioma(){};
void altaCurso(){};
void eliminarCurso(){};
void inscripcionCurso(){};
void sucripcionNotificacion(){};
void eliminarSuscripciones(){};
void consultaUsuario(){};
void consultaIdioma(){};
void consultaCurso(){};
void consultaEstadisticas(){};
void consultaNotificaciones(){};
void agregarLeccion(){};
void agregarEjercicio(){};
void habilitarCurso(){};
void realizarEjercicio(){};

int mostrarMenuYObtenerOpcion(){
    cout << "Seleccione una opción:\n";
    cout << "Grupo altas y bajas:\n";
    cout << "   1.Alta de usuario\n";
    cout << "   2.Alta de idioma\n";
    cout << "   3.Alta de curso\n";
    cout << "   4.Eliminar curso\n";
    cout << "   5.Inscripcion a curso\n";
    cout << "   6.Suscripcion a notificación\n";
    cout << "   7.Eliminar suscripciones\n";
    cout << "Grupo modificacion:\n";
    cout << "   8.Agregar lección\n";
    cout << "   9.Agregar ejercicio\n";
    cout << "   10.Habilitar curso\n";
    cout << "   11.Realizar ejercicio\n";
    cout << "Grupo consulta:\n";
    cout << "   12.Consulta de usuario\n";
    cout << "   13.Consultar idiomas\n";
    cout << "   14.Consultar curso\n";
    cout << "   15.Consultar estadisticas\n";
    cout << "   16.Consulta de notificaciones\n";
    cout << "Otras:\n";
    cout << "   0.Salir\n";
    cout << "Seleccione el caso de uso a ejecutar: ";
    int opcion;
    cin >> opcion;
    return opcion;
}

int main() {
    // int op=0;
    int op = mostrarMenuYObtenerOpcion();
    switch (op){
    case 1:
        altaUsuario();
        break;
    case 2:
        altaIdioma();
        break;
    case 3:
        altaCurso();
        break;
    case 4:
        eliminarCurso();
        break;
    case 5:
        inscripcionCurso();
        break;
    case 6:
        sucripcionNotificacion();
        break;
    case 7:
        eliminarSuscripciones();
        break;
    case 8:
        agregarLeccion();
        break;
    case 9:
        agregarEjercicio();
        break;
    case 10:
        habilitarCurso();
        break;
    case 11:
        realizarEjercicio();
        break;
    case 12:
        consultaUsuario();
        break;
    case 13:
        consultaIdioma();
        break;
    case 14:
        consultaCurso();
        break;
    case 15:
        consultaEstadisticas();
        break;
    case 16:
        consultaNotificaciones();
        break;
    case 0:
        cout << "Gracias por usar la aplicación\n";
        break;
    default:
        cout << "Opción no valida\n";
        break;
    }
}