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
    return (TipoUsuario)(tipoUsuario-1);
}

void menuTipoEjercicio(){
    cout << "Tipo de ejercicio: \n";
    cout << "1.Completado\n";
    cout << "2.Traduccion\n";
    cout << "Ingrese su opcion: ";
}

template <typename T>
set<T> obtenerListaDeSeleccionadosPorIndices(set<int> selecciones, vector<T> lista){
    set<T> res;
    set<int>::iterator it;
    for(it=selecciones.begin(); it!=selecciones.end(); ++it){
        res.insert(lista[*it]);
    }
    return res;    
}

template <typename T>
void printVector(vector<T> setAImprimir){
    for(int i=0; i<setAImprimir.size(); i++){
        cout << setAImprimir[i] << "\n";
    }
}

set<int> pedirSeleccionarIndicesDeLista(string nombreSeccion, vector<string> lista, bool masDeUno){
    const int SALIR = 0;
    set<int> selecciones;
    cout << nombreSeccion << ":\n";
    for(int i=0; i<lista.size(); i++){
        cout << i+1 << ". " << lista[i] << "\n";
    }
    if(masDeUno) cout << "0. Salir\n";
    int opcion;
    do{
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        if(opcion>0 && opcion<=lista.size()){
            selecciones.insert(opcion-1);
            cout << "Seleccionado\n";
        }else if(opcion!=SALIR){
            cout << "Opcion invalida.\n";
        }
    } while ((masDeUno && opcion!=SALIR));
    return selecciones;
}

set<int> pedirSeleccionarIndicesDeLista(string nombreSeccion, vector<DTCurso> lista, bool masDeUno){
    set<int> selecciones;
    cout << nombreSeccion << ":\n";
    for(int i=0; i<lista.size(); i++){
        cout << i+1 << ". " << lista[i].getNombre() << "\n";
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
        else if (opcion != 0) {
            cout << "Opcion invalida.\n";
        }
    } while ((masDeUno && opcion != 0));
    return selecciones;
}


void createUsuario(
    DTUsuario datosUsuario, TipoUsuario tipoUsuario, string paisRes="", 
    Date fechaNacimiento=Date(1,1,1), string instituto="", set<string> idiomas=set<string>()){
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    controladorUsuario->ingresarDatosUsuario(
        datosUsuario.getNickname(), datosUsuario.getPassword(), 
        datosUsuario.getName(), datosUsuario.getDescription(), tipoUsuario
    );
    if(tipoUsuario==ESTUDIANTE){
        controladorUsuario->ingresarDatosEstudiante(paisRes, fechaNacimiento);
    }else{
        controladorUsuario->ingresarInstituto(instituto);
        controladorUsuario->seleccionIdiomas(idiomas);
    }
    controladorUsuario->confirmarAltaUsuario();
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
        cout << "Ingrese la fecha de nacimiento: \n";
        Date fechaNacimiento=pedirDate();
        controladorUsuario->ingresarDatosEstudiante(paisRes, fechaNacimiento);
    }else{
        string instituto;
        cout << "Ingrese el instituto: ";
        cin >> instituto;
        controladorUsuario->ingresarInstituto(instituto);
        vector<string> idiomas=controladorUsuario->obtenerListaDeIdiomas();
        set<int> seleccionados=pedirSeleccionarIndicesDeLista("Lista de idiomas", idiomas, true);
        controladorUsuario->seleccionIdiomas(obtenerListaDeSeleccionadosPorIndices(seleccionados, idiomas));
    }
    controladorUsuario->confirmarAltaUsuario();
    cout << "Usuario \"" << datosUsuario.getNickname() << "\" agregado\n";
}

void createIdioma(string idioma){
    IControladorIdioma* controladorIdioma = Fabrica::getIControladorIdioma();
    controladorIdioma->altaIdioma(idioma);
}

void altaIdioma(){
    string nombre;
    cout << "Ingrese el nombre del idioma: ";
    cin >> nombre;
    createIdioma(nombre);
    cout << "Idioma \"" << nombre << "\" agregado\n";
}

void leerNotificaciones(set<DTNotificacion> notificaciones){
    set<DTNotificacion>::iterator it;
    for(it=notificaciones.begin(); it!=notificaciones.end(); ++it){
        cout << (*it).to_string() << "\n";
    }
}

void eliminarCurso() {
    IControladorCurso* cc = Fabrica::getIControladorCurso();
    vector<DTCurso> listaCursos = cc->listarCursos();
    cc->seleccionarCurso(*(obtenerListaDeSeleccionadosPorIndices(pedirSeleccionarIndicesDeLista("Lista de Cursos", listaCursos, false), listaCursos)).begin());
    cc->eliminarCurso();
}

DTCurso pedirDatosCurso(){
    string nombre, descripcion;
    int dificultad;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese la descripcion: ";
    cin >> descripcion;
    cout << "Dificultades: \n";
    cout << "1.Principiante\n";
    cout << "2.Medio\n";
    cout << "3.Avanzado\n";
    cout << "Ingrese su opcion: ";
    cin >> dificultad;
    while (dificultad < 1 && dificultad > 3) {
        cout << "Dificultad no valida. Intente de nuevo\n";
        cin >> dificultad;
    }
    return DTCurso(nombre, descripcion, (Dificultades)dificultad);
}

void altaCurso() {
    IControladorCurso* cc = Fabrica::getIControladorCurso();
    vector<string> nicksDocentes = cc->obtenerNicksDocentes();
    set<string> seleccionado = obtenerListaDeSeleccionadosPorIndices(pedirSeleccionarIndicesDeLista("Lista de docentes", nicksDocentes, false), nicksDocentes);
    cc->seleccionUsuario(*seleccionado.begin());
    DTCurso datosCurso=pedirDatosCurso();
    cc->datosCurso(datosCurso.getNombre(), datosCurso.getDescripcion(), datosCurso.getDificultad());
    vector<string> Idiomas = cc->idiomasDelDocente();
    set<string> seleccionado2 = obtenerListaDeSeleccionadosPorIndices(pedirSeleccionarIndicesDeLista("Lista de idiomas del docente", Idiomas, false), Idiomas);
    cc->seleccionDeIdioma(*seleccionado2.begin());
    int agregarCurso;
    cout << "Desea agregar cursos previos?\n";
    cout << "1-Si\n";
    cout << "-Pon otro numero si No\n";
    cin >> agregarCurso;
    vector<DTCurso> cursosPreviosDisponibles;
    if (agregarCurso == 1) cursosPreviosDisponibles = cc->solicitarCursosHabilitados();
    while (agregarCurso == 1) {
        set<int> cursoSeleccionado=pedirSeleccionarIndicesDeLista("Lista de cursos habilitados", cursosPreviosDisponibles, false);
        DTCurso select = *(obtenerListaDeSeleccionadosPorIndices(cursoSeleccionado, cursosPreviosDisponibles)).begin();
        cc->agregarCursoPrevio(select);
        cursosPreviosDisponibles.erase(cursosPreviosDisponibles.begin()+(*cursoSeleccionado.begin()));
        cout << "Desea agregar mas cursos previos?\n";
        cout << "1-Si\n";
        cout << "-Pon otro numero si No\n";
        cin >> agregarCurso;
    }
    int agregarLeccion;
    cout << "Desea agregar una leccion?\n";
    cout << "1-Si\n";
    cout << "-Pon otro numero si No\n";
    cin >> agregarLeccion;
    while (agregarLeccion == 1) {
        string Tema, Objetivo;
        cout << "Ingrese el tema: ";
        cin >> Tema;
        cout << "Ingrese el objetivo: ";
        cin >> Objetivo;
        cc->leccionDatos(Tema, Objetivo);
        cc->altaLeccion();
        int agregarEjercicio;
        cout << "Desea agregar un ejercicio?\n";
        cout << "1-Si\n";
        cout << "-Pon otro numero si No\n";
        cin >> agregarEjercicio;
        while (agregarEjercicio == 1) {
            int Tipo;
            menuTipoEjercicio();
            cin >> Tipo;
            while (Tipo < 1 && Tipo > 2) {
                cout << "Tipo no valido. Intente de nuevo\n";
            }
            string Frase;
            cout << "Ingrese la frase del ejercicio: ";
            cin >> Frase;
            string desc;
            cout << "Ingrese la descripcion: ";
            cin >> desc;
            cc->agregarEjercicio(Frase, (TipoEjercicio)Tipo, desc);
            if (Tipo == 1) {
                vector<string> palabras;
                string temp;
                int agregarPalabra;
                do {
                    cout << "Ingrese palabra faltante: ";
                    cin >> temp;
                    palabras.push_back(temp);
                    cout << "Desea agregar otra palabra?\n";
                    cout << "1-Si\n";
                    cout << "-Pon otro numero si No\n";
                    cin >> agregarPalabra;
                } while (agregarPalabra == 1);
                cc->ejercicioDeCompletar(palabras);
            }
            else {
                string FraseTraducida;
                cout << "Ingrese la Traduccion: ";
                cin >> FraseTraducida;
                cc->ejercicioDeTraduccion(FraseTraducida);
            }
            cc->altaEjercicio();
            cout << "Desea agregar otro ejercicio?\n";
            cout << "1-Si\n";
            cout << "-Pon otro numero si No\n";
            cin >> agregarEjercicio;
        }
        cout << "Desea agregar otra leccion?\n";
        cout << "1-Si\n";
        cout << "-Pon otro numero si No\n";
        cin >> agregarLeccion;
    }
    cc->altaCurso();
}


void inscripcionCurso(){
    IControladorUsuario* cu=Fabrica::getIControladorUsuario();
    string nickname;
    cout << "Ingrese el nickname: ";
    cin >> nickname;
    vector<DTCurso> cursosDisponibles=cu->listarCursosDisponibles(nickname);
    set<int> indiceSeleccionado=pedirSeleccionarIndicesDeLista("Lista de cursos disponibles", cursosDisponibles, false);
    DTCurso cursoSeleccionado=*obtenerListaDeSeleccionadosPorIndices(indiceSeleccionado, cursosDisponibles).begin();
    cu->inscribirseCurso(cursoSeleccionado);
    cout << "Inscripto a curso " << cursoSeleccionado.getNombre();
}

void sucripcionNotificacion(){
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    string nickname;
    cout<< "Ingrese su nickname: \n";
    cin>> nickname;
    IControladorIdioma* controladorIdioma = Fabrica::getIControladorIdioma();
    vector<string> idiomas=controladorIdioma->obtenerSuscripcionesDisponibles(nickname);
    if(idiomas.size()==0){
        cout<< "No hay idiomas disponibles para el usuario ingresado. \n";
    }else{
        bool masDeUno = (idiomas.size() > 1) ? true : false;
        set<int> seleccionados = pedirSeleccionarIndicesDeLista("Lista de idiomas a los que no esta suscrito", idiomas, masDeUno); 
        controladorIdioma->agregarSuscripciones(obtenerListaDeSeleccionadosPorIndices(seleccionados, idiomas));
        cout<< "Se ha suscrito correctamente. \n";
    }
}

void eliminarSuscripciones(){
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    string nickname;
    cout<< "Ingrese su nickname: \n";
    cin>> nickname;
    IControladorIdioma* controladorIdioma = Fabrica::getIControladorIdioma();
    vector<string> idiomas = controladorIdioma->listarIdiomas(nickname);
    if(idiomas.size()==0)
        cout<< "No hay idiomas disponibles para el usuario ingresado. \n";
    else{
        bool masDeUno = (idiomas.size() > 1) ? true : false;
        set<int> seleccionados = pedirSeleccionarIndicesDeLista("Lista de idiomas a los que esta suscrito", idiomas, masDeUno); 
        controladorIdioma->eliminarIdioma(obtenerListaDeSeleccionadosPorIndices(seleccionados, idiomas));
        cout<< "Se han eliminado las suscripciones correctamente. \n";
    }
}

void consultaUsuario(){
    IControladorUsuario* cu=Fabrica::getIControladorUsuario();
    vector<string> usuarios=cu->consultarNicknameUsuarios();
    set<int> usuarioSeleccionado=pedirSeleccionarIndicesDeLista("Lista de usuarios", usuarios, false);
    cu->seleccionarUsuario(*obtenerListaDeSeleccionadosPorIndices(usuarioSeleccionado, usuarios).begin());
    system("clear");
    cout << "Datos del usuario: \n";
    cout << cu->getNombreUsuario() << "\n";
    cout << cu->getDescripcionUsuario() << "\n";
    if(cu->getTipoUsuario()==ESTUDIANTE){
        cout << cu->getPaisResidenciaUsuario() << "\n";
    }else{
        cout << cu->getInstitutoUsuario() << "\n";
        cout << "Idiomas usuario: \n";
        printVector(cu->getIdiomasUsuario());
    }
}
void consultaIdioma(){
    IControladorIdioma* ci=Fabrica::getIControladorIdioma();
    printVector(ci->consultarIdiomas());
}

string dificultadToString(Dificultades dificultad){
    string dificultadesString[3]={"PRINCIPIANTE", "MEDIO", "AVANZADO"};
    return dificultadesString[dificultad];
}

void printDatosLeccion(DatosLeccion datosLeccion){
    cout << "Tema: " << datosLeccion.leccion.getTema() << "\n";
    cout << "Objetivo: " << datosLeccion.leccion.getObjetivo() << "\n";
    set<DTEjercicio>::iterator it;
    for (it = datosLeccion.ejercicios.begin(); it != datosLeccion.ejercicios.end(); it++) {
        cout << "Problema: " << it->getFrase() << "\n";
        cout << "Descripcion: " << it->getDescripcion() << "\n";
    }
}

void printVectorDatosLeccion(vector<DatosLeccion> lecciones){
    for (int i = 0; i < lecciones.size(); i++) {
        cout << "Leccion " << i+1 << ":\n";
        printDatosLeccion(lecciones[i]);
    }
}

void printDTInscripciones(set<DTInscripcion> inscripciones){
    set<DTInscripcion>::iterator it;
    for (it = inscripciones.begin(); it != inscripciones.end(); it++) {
        cout << "Inscripcion: " << it->getNombre() << ", fecha de inscripcion: " << it->getFechaInscripcion().toString() << "\n";
    }
}

void printDatosCurso(DTDatosCurso datosCurso){
    DTCurso curso=datosCurso.getCurso();
    cout << "Nombre del curso: " << curso.getNombre() << "\n";
    cout << "Descripcion: " << curso.getDescripcion() << "\n";
    cout << "Dificultad: " << dificultadToString(curso.getDificultad()) << "\n";
    cout << "Idioma: " << datosCurso.getIdioma() << "\n";
    cout << "Profesor: " << datosCurso.getProfesor() << "\n";
    cout << "Habilitado: " << datosCurso.getHabilitado() << "\n";
    printVectorDatosLeccion(datosCurso.getLecciones());
    printDTInscripciones(datosCurso.getInscripciones());
}

void consultaCurso(){
    IControladorCurso* cc=Fabrica::getIControladorCurso();
    vector<DTCurso> cursos=cc->listarCursos();
    set<int> cursoSeleccionado=pedirSeleccionarIndicesDeLista("Lista de cursos", cursos, false);
    DTCurso curso=*obtenerListaDeSeleccionadosPorIndices(cursoSeleccionado, cursos).begin();
    DTDatosCurso datosCurso=cc->getDatosCurso(curso);
    printDatosCurso(datosCurso);
    string continuar;
    cout << "Ingrese algun caracter para continuar:";
    cin >> continuar;
}
void consultaEstadisticas(){}
void consultaNotificaciones(){
    IControladorUsuario* cu=Fabrica::getIControladorUsuario();
    string nickname;
    cout << "Ingrese el nickname del usuario: ";
    cin >> nickname;
    set<DTNotificacion> notificaciones=cu->obtenerNotificaciones(nickname);
    if(notificaciones.empty()){
        cout << "No hay notificaciones\n";
    }else{
        cout << "Notificaciones del usuario: \n";
        leerNotificaciones(notificaciones);
    }
}
void agregarLeccion(){
    IControladorCurso* cc = Fabrica::getIControladorCurso();
    vector<DTCurso> cnh = cc->solicitarCursosNoHabilitados();
    DTCurso select = *(obtenerListaDeSeleccionadosPorIndices(pedirSeleccionarIndicesDeLista("Lista de cursos no habilitados", cnh, false), cnh)).begin();
    cc->seleccionarCurso(select);
    string Tema, Objetivo;
    cout << "Ingrese el tema: ";
    cin >> Tema;
    cout << "Ingrese el objetivo: ";
    cin >> Objetivo;
    cc->leccionDatos(Tema, Objetivo);
    cc->altaLeccion();
    int agregarEjercicio;
    cout << "Desea agregar un ejercicio?\n";
    cout << "1-Si\n";
    cout << "-Pon otro numero si No\n";
    cin >> agregarEjercicio;
    while (agregarEjercicio == 1) {
        int Tipo;
        menuTipoEjercicio();
        cin >> Tipo;
        while (Tipo < 1 && Tipo > 2) {
            cout << "Tipo no valido. Intente de nuevo\n";
        }
        string Frase;
        cout << "Ingrese la frase del ejercicio: ";
        cin >> Frase;
        string desc;
        cout << "Ingrese la descripcion: ";
        cin >> desc;
        cc->agregarEjercicio(Frase, (TipoEjercicio)Tipo, desc);
        if (Tipo == 1) {
            vector<string> palabras;
            string temp;
            int agregarPalabra;
            do {
                cout << "Ingrese palabra faltante: ";
                cin >> temp;
                palabras.push_back(temp);
                cout << "Desea agregar otra palabra?\n";
                cout << "1-Si\n";
                cout << "-Pon otro numero si No\n";
                cin >> agregarPalabra;
            } while (agregarPalabra == 1);
            cc->ejercicioDeCompletar(palabras);
        }
        else {
            string FraseTraducida;
            cout << "Ingrese la Traduccion: ";
            cin >> FraseTraducida;
            cc->ejercicioDeTraduccion(FraseTraducida);
        }
        cc->altaEjercicio();
        cout << "Desea agregar otro ejercicio?\n";
        cout << "1-Si\n";
        cout << "-Pon otro numero si No\n";
        cin >> agregarEjercicio;
    }
    cc->AgregarLeccion();
}
void agregarEjercicio(){
    IControladorCurso* cc = Fabrica::getIControladorCurso();
    vector<DTCurso> cnh = cc->solicitarCursosNoHabilitados();
    DTCurso select = *(obtenerListaDeSeleccionadosPorIndices(pedirSeleccionarIndicesDeLista("Lista de cursos no habilitados", cnh, false), cnh)).begin();
    cc->seleccionarCurso(select);
    set<DTLeccion> lecs = cc->listarLeccionesCurso();
    //muestro lecciones en pantalla
    cout << "Lista de lecciones disponibles:\n";
    set<DTLeccion>::iterator it;
    int index = 1;
    for (it = lecs.begin(); it != lecs.end(); ++it) {
        cout << index << ". " << (*it).getTema() << ", " << (*it).getObjetivo() << "\n";
        index++;
    }
    int opcion;
    bool invalido;
    do {
        invalido = false;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        if (opcion > 0 && opcion <= lecs.size()) {
            cout << "Seleccionado\n";
        }
        else {
            cout << "Opcion invalida.\n";
            invalido = true;
        }
    } while (invalido);
    cc->SeleccionarLeccion(opcion);
    //termino eleccion de leccion
    //agrego ejercicio
    int Tipo;
    menuTipoEjercicio();
    cin >> Tipo;
    while (Tipo < 1 && Tipo > 2) {
        cout << "Tipo no valido. Intente de nuevo\n";
    }
    string Frase;
    cout << "Ingrese la frase del ejercicio: ";
    cin >> Frase;
    string desc;
    cout << "Ingrese la descripcion: ";
    cin >> desc;
    cc->agregarEjercicio(Frase, (TipoEjercicio)Tipo, desc);
    if (Tipo == 1) {
        vector<string> palabras;
        string temp;
        int agregarPalabra;
        do {
            cout << "Ingrese palabra faltante: ";
            cin >> temp;
            palabras.push_back(temp);
            cout << "Desea agregar otra palabra?\n";
            cout << "1-Si\n";
            cout << "-Pon otro numero si No\n";
            cin >> agregarPalabra;
        } while (agregarPalabra == 1);
        cc->ejercicioDeCompletar(palabras);
    }
    else {
        string FraseTraducida;
        cout << "Ingrese la Traduccion: ";
        cin >> FraseTraducida;
        cc->ejercicioDeTraduccion(FraseTraducida);
    }
    cc->FinalizarAgregarEjercicio();
}
void habilitarCurso(){
    IControladorCurso* cc=Fabrica::getIControladorCurso();
    vector<DTCurso> cursosNoHabilitados=cc->solicitarCursosNoHabilitados();
    set<int> cursoSeleccionado=pedirSeleccionarIndicesDeLista("Cursos no habilitados", cursosNoHabilitados, false);
    system("clear");
    cc->habilitarCurso(*obtenerListaDeSeleccionadosPorIndices(cursoSeleccionado, cursosNoHabilitados).begin());
    cout << "Curso habilitado\n";
}
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
    int op;
    // op=0;
    do{
        op = mostrarMenuYObtenerOpcion();
        system("clear");
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
    } while (op!=0);
}