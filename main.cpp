#include <iostream>
#include <optional>
#include "controllers/Fabrica.hh"
using namespace std;

DTUsuario pedirDatosUsuario(){
    string nickname, contraseña, nombre, descripcion;
    cout << "Ingrese el nickname: ";
    cin >> nickname;
    cout << "Ingrese la contraseña: ";
    cin >> contraseña;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese la descripcion: ";
    cin >> descripcion;
    return DTUsuario(nickname, contraseña, nombre, descripcion);
}

Date pedirDate(){
    int dia, mes, anio;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
    return Date(dia, mes, anio);
}

optional<TipoUsuario> pedirTipoUsuario(){
    int tipoUsuario;
    cout << "Tipos de usuario: \n";
    cout << "1.Estudiante\n";
    cout << "2.Profesor\n";
    cout << "Ingrese su opcion: ";
    cin >> tipoUsuario;
    if(tipoUsuario!=1 && tipoUsuario!=2){
        cout << "Tipo de usuario no valido\n\n";
        return {};
    }
    return (TipoUsuario)tipoUsuario;
}

template <typename T>
set<T> obtenerListaDeSeleccionadosPorIndices(set<int> selecciones, set<T> lista){
    set<T> res;
    typename set<T>::iterator it;
    int index=0;
    for(it=lista.begin(); it!=lista.end(); ++it){
        if(selecciones.find(index)!=selecciones.end()){
            res.insert(*it);
        }
        index++;
    }
    return res;    
}

template <typename T>
void printSet(set<T> setAImprimir){
    typename set<T>::iterator it;
    for(it=setAImprimir.begin(); it!=setAImprimir.end(); ++it){
        cout << *it << "\n";
    }
}

set<string> pedirSeleccionDeLista(string nombreSeccion, set<string> lista, bool masDeUno){
    set<int> selecciones;
    cout << nombreSeccion << ":\n";
    set<string>::iterator it;
    int index=1;
    for(it=lista.begin(); it!=lista.end(); ++it){
        cout << index << ". " << *it << "\n";
        index++;
    }
    if(masDeUno) cout << "0. Salir\n";
    int opcion;
    do{
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        if(opcion>0 && opcion<=lista.size()){
            selecciones.insert(opcion-1);
            cout << "Seleccionado\n";
        }
    } while (masDeUno && opcion!=0);
    return obtenerListaDeSeleccionadosPorIndices(selecciones, lista);
}

void altaUsuario(){
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    DTUsuario datosUsuario = pedirDatosUsuario();
    optional<TipoUsuario> tipoUsuario;
    do{
        tipoUsuario = pedirTipoUsuario();
    } while (!tipoUsuario);
    controladorUsuario->ingresarDatosUsuario(
        datosUsuario.getNickname(), datosUsuario.getPassword(), 
        datosUsuario.getName(), datosUsuario.getDescription(), tipoUsuario.value()
    );
    if(tipoUsuario.value()==ESTUDIANTE){
        string paisRes;
        cout << "Ingrese el pais de residencia: ";
        cin >> paisRes;
        cout << "Ingrese la fecha de nacimiento: ";
        Date fechaNacimiento=pedirDate();
        controladorUsuario->ingresarDatosEstudiante(paisRes, fechaNacimiento);
    }else{
        string instituto;
        cout << "Ingrese el instituto: ";
        cin >> instituto;
        controladorUsuario->ingresarInstituto(instituto);
        set<string> idiomas=controladorUsuario->obtenerListaDeIdiomas();
        set<string> seleccionados=pedirSeleccionDeLista("Lista de idiomas", idiomas, true);
        controladorUsuario->seleccionIdiomas(seleccionados);
    }
    controladorUsuario->confirmarAltaUsuario();
}
void altaIdioma(){
    string nombre;
    cout << "Ingrese el nombre del idioma: ";
    cin >> nombre;
    IControladorIdioma* controladorIdioma = Fabrica::getIControladorIdioma();
    controladorIdioma->altaIdioma(nombre);
}

void altaCurso(){}
void eliminarCurso(){}
void inscripcionCurso(){}
void sucripcionNotificacion(){}
void eliminarSuscripciones(){}
void consultaUsuario(){
    IControladorUsuario* cu=Fabrica::getIControladorUsuario();
    set<string> usuarios=cu->consultarNicknameUsuarios();
    string usuarioSeleccionado=*pedirSeleccionDeLista("Lista de usuarios", usuarios, false).begin();
    cu->seleccionarUsuario(usuarioSeleccionado);
    cout << cu->getNombreUsuario();
    cout << cu->getDescripcionUsuario();
    if(cu->getTipoUsuario()==ESTUDIANTE){
        cout << cu->getPaisResidenciaUsuario();
    }else{
        cout << cu->getInstitutoUsuario();
        cout << "Idiomas usuario: \n";
        printSet(cu->getIdiomasUsuario());
    }
}
void consultaIdioma(){}
void consultaCurso(){}
void consultaEstadisticas(){}
void consultaNotificaciones(){}
void agregarLeccion(){}
void agregarEjercicio(){}
void habilitarCurso(){}
void realizarEjercicio(){}

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
    int op=0;
    // int op = mostrarMenuYObtenerOpcion();
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