#include <iostream>
#include <optional>
#include "controllers/Fabrica.hh"
using namespace std;

DTUsuario pedirDatosUsuario(){
    string nickname, contraseña, nombre, descripcion;
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    
    bool registrado = true;
    do{
        cout << "Ingrese el nickname: ";
        getline(cin, nickname);
        if(controladorUsuario->yaRegistrado(nickname))
            cout<< "Nickname ya registrado, intente de nuevo. \n";
        else
            registrado = false; 

    }while(registrado);

    cout << "Ingrese la contraseña: ";
    getline(cin, contraseña);
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    cout << "Ingrese la descripción: ";
    getline(cin, descripcion);
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
    cin.ignore();
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
    cin.ignore();
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
    cin.ignore();
    return selecciones;
}

int menuEstadistica(){	
    cout << "Seleccione una opción:\n";	
    cout << "Obtener estadísticas de :\n";	
    cout << "   1.Estudiante\n";	
    cout << "   2.Profesor\n";	
    cout << "   3.Curso\n";	
    int opcionEst;	
    cin >> opcionEst;
    cin.ignore();
    return opcionEst;	
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
    cin.ignore();
    return selecciones;
}


void createEstudiante(DTUsuario datosUsuario, string paisRes, Date fechaNacimiento){
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    controladorUsuario->ingresarDatosUsuario(
        datosUsuario.getNickname(), datosUsuario.getPassword(), 
        datosUsuario.getName(), datosUsuario.getDescription(), ESTUDIANTE
    );
    controladorUsuario->ingresarDatosEstudiante(paisRes, fechaNacimiento);
    controladorUsuario->confirmarAltaUsuario();
}

void createProfesor(DTUsuario datosUsuario,string instituto, set<string> idiomas){
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    controladorUsuario->ingresarDatosUsuario(
        datosUsuario.getNickname(), datosUsuario.getPassword(), 
        datosUsuario.getName(), datosUsuario.getDescription(), PROFESOR
    );
    controladorUsuario->ingresarInstituto(instituto);
    controladorUsuario->seleccionIdiomas(idiomas);
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
        getline(cin, paisRes);
        cout << "Ingrese la fecha de nacimiento: \n";
        Date fechaNacimiento=pedirDate();
        controladorUsuario->ingresarDatosEstudiante(paisRes, fechaNacimiento);
    }else{
        string instituto;
        cout << "Ingrese el instituto: ";
        getline(cin, instituto);
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
    getline(cin, nombre);
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
    getline(cin, nombre);
    cout << "Ingrese la descripcion: ";
    getline(cin, descripcion);
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
    cin.ignore();
    return DTCurso(nombre, descripcion, (Dificultades)dificultad);
}

void addEjercicioToLeccion(
    string curso, int numeroLeccion, TipoEjercicio tipoEjercicio, 
    string frase, string desc, string traduccion="", vector<string> palabras=vector<string>()){
    IControladorCurso* cc = Fabrica::getIControladorCurso();
    cc->seleccionarCurso(cc->getCurso(curso));
    cc->SeleccionarLeccion(numeroLeccion);
    cc->agregarEjercicio(frase, tipoEjercicio, desc);
    if (tipoEjercicio == COMPLETADO){
        cc->ejercicioDeCompletar(palabras);
    }else{
        cc->ejercicioDeTraduccion(traduccion);
    }
    cc->FinalizarAgregarEjercicio();
}

void addLeccionToCurso(string curso, string tema, string objetivo){
    IControladorCurso* cc = Fabrica::getIControladorCurso();
    cc->seleccionarCurso(cc->getCurso(curso));
    cc->leccionDatos(tema, objetivo);
    cc->altaLeccion();
    cc->agregarLeccion();
}

void createCurso(string profesor, DTCurso datosCurso, string idioma, set<string> cursosPrevios){
    IControladorCurso* cc = Fabrica::getIControladorCurso();
    cc->seleccionUsuario(profesor);
    cc->datosCurso(datosCurso.getNombre(), datosCurso.getDescripcion(), datosCurso.getDificultad());
    cc->seleccionDeIdioma(idioma);
    set<string>::iterator it;
    for(it=cursosPrevios.begin(); it!=cursosPrevios.end(); ++it){
        cc->agregarCursoPrevio(cc->getCurso(*it));
    }
    cc->altaCurso();
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
    cin.ignore();
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
    cin.ignore();
    while (agregarLeccion == 1) {
        string Tema, Objetivo;
        cout << "Ingrese el tema: ";
        getline(cin, Tema);
        cout << "Ingrese el objetivo: ";
        getline(cin, Objetivo);
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
            cin.ignore();
            while (Tipo < 1 && Tipo > 2) {
                cout << "Tipo no valido. Intente de nuevo\n";
            }
            string Frase;
            cout << "Ingrese la frase del ejercicio: ";
            getline(cin, Frase);
            string desc;
            cout << "Ingrese la descripcion: ";
            getline(cin, desc);
            cc->agregarEjercicio(Frase, (TipoEjercicio)Tipo, desc);
            if (Tipo == 1) {
                vector<string> palabras;
                string temp;
                int agregarPalabra;
                do {
                    cout << "Ingrese palabra faltante: ";
                    getline(cin, temp);
                    palabras.push_back(temp);
                    cout << "Desea agregar otra palabra?\n";
                    cout << "1-Si\n";
                    cout << "-Pon otro numero si No\n";
                    cin >> agregarPalabra;
                    cin.ignore();
                } while (agregarPalabra == 1);
                cc->ejercicioDeCompletar(palabras);
            }
            else {
                string FraseTraducida;
                cout << "Ingrese la Traduccion: ";
                getline(cin, FraseTraducida); 
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
        cin.ignore();
    }
    cc->altaCurso();
}

void createInscription(string nickname, string curso){
    IControladorUsuario* cu=Fabrica::getIControladorUsuario();
    IControladorCurso* cc=Fabrica::getIControladorCurso();
    cu->inscribirseCurso(cc->getCurso(curso));
}

void inscripcionCurso(){
    IControladorUsuario* cu=Fabrica::getIControladorUsuario();
    string nickname;
    cout << "Ingrese el nickname: ";
    getline(cin, nickname);
    vector<DTCurso> cursosDisponibles=cu->listarCursosDisponibles(nickname);
    set<int> indiceSeleccionado=pedirSeleccionarIndicesDeLista("Lista de cursos disponibles", cursosDisponibles, false);
    DTCurso cursoSeleccionado=*obtenerListaDeSeleccionadosPorIndices(indiceSeleccionado, cursosDisponibles).begin();
    cu->inscribirseCurso(cursoSeleccionado);
    cout << "Inscripto a curso " << cursoSeleccionado.getNombre();
}

void createSuscription(string nickname, set<string> idiomas){
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    IControladorIdioma* controladorIdioma = Fabrica::getIControladorIdioma();
    controladorIdioma->agregarSuscripciones(idiomas);
}

void sucripcionNotificacion(){
    IControladorUsuario* controladorUsuario = Fabrica::getIControladorUsuario();
    string nickname;
    cout<< "Ingrese su nickname: \n";
    getline(cin, nickname);
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
    getline(cin, nickname);
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
    if(usuarios.empty()){
        cout<< "No hay usuarios registrados. \n"; 
    }
    else{ 
        set<int> usuarioSeleccionado=pedirSeleccionarIndicesDeLista("Lista de usuarios", usuarios, false);
        cu->seleccionarUsuario(*obtenerListaDeSeleccionadosPorIndices(usuarioSeleccionado, usuarios).begin());
        system("clear");
        cout << "Datos del usuario: \n";
        cout << "Nombre: " << cu->getNombreUsuario() << "\n";
        cout << "Descripcion: " << cu->getDescripcionUsuario() << "\n";
        if(cu->getTipoUsuario()==ESTUDIANTE){
            cout << "Pais de residencia: " << cu->getPaisResidenciaUsuario() << "\n";
        }else{
            cout << "Instituto: " << cu->getInstitutoUsuario() << "\n";
            cout << "Idiomas del usuario: \n";
            printVector(cu->getIdiomasUsuario());
        }
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
    if(datosCurso.getHabilitado()){
        cout << "Habilitado: Si \n"; 
    }
    else{
        cout << "Habilitado: No \n"; 
    }
    printVectorDatosLeccion(datosCurso.getLecciones());
    printDTInscripciones(datosCurso.getInscripciones());
}

void consultaCurso(){
    IControladorCurso* cc=Fabrica::getIControladorCurso();
    vector<DTCurso> cursos=cc->listarCursos();
    if(!cursos.empty()){
        set<int> cursoSeleccionado=pedirSeleccionarIndicesDeLista("Lista de cursos", cursos, false);
        DTCurso curso=*obtenerListaDeSeleccionadosPorIndices(cursoSeleccionado, cursos).begin();
        DTDatosCurso datosCurso=cc->getDatosCurso(curso);
        printDatosCurso(datosCurso);
        string continuar;
        cout << "Ingrese algun caracter para continuar:";
        cin >> continuar;
        cin.ignore();
    }else{
        cout << "No existen cursos registrados. \n"; 
    }
}
void consultaEstadisticas(){	
	IControladorUsuario* cu=Fabrica::getIControladorUsuario();	
    IControladorCurso* cc=Fabrica::getIControladorCurso();
    set<int> indiceSeleccionado;	
	int opEst = 0;
    opEst = menuEstadistica();	
    system("clear");
  /*  DTCurso select = *(obtenerListaDeSeleccionadosPorIndices(pedirSeleccionarIndicesDeLista("Lista de cursos no habilitados", cnh, false), cnh)).begin();	
    cc->seleccionarCurso(select);*/	
	switch(opEst){
	case 1:	{
		vector<string> est = cu->getNicksEstudiantes();	
		indiceSeleccionado=pedirSeleccionarIndicesDeLista("Lista de estudiantes", est, false);	
		string estSeleccionado =*(obtenerListaDeSeleccionadosPorIndices(pedirSeleccionarIndicesDeLista("Lista de estudiantes", est, false), est)).begin();	
       	DTEstadisticasEstudiante ee=cu->listarEstadisticasEstudiante(estSeleccionado);	
       	break;	
    }
    case 2:	{
	    vector<string> pr = cc->obtenerNicksDocentes();	
		indiceSeleccionado=pedirSeleccionarIndicesDeLista("Lista de profesores", pr, false);	
		string prSeleccionado =*obtenerListaDeSeleccionadosPorIndices(indiceSeleccionado, pr).begin();	
      	DTEstadisticasProfesor ep = cu->listarEstadisticasProfesor(prSeleccionado);	
       	break;
    }	
    case 3:	{
		vector<DTCurso> cursos = cu->listarCursos();	
		indiceSeleccionado=pedirSeleccionarIndicesDeLista("Lista de cursos", cursos, false);	
		DTCurso cursoSeleccionado=*obtenerListaDeSeleccionadosPorIndices(indiceSeleccionado, cursos).begin();	
       	DTProgresoPromedioCurso ec= cu->listarEstadisticasCurso(cursoSeleccionado);	
       	break;
    }	
    case 0:	
		break;	
	default:	
       	cout << "Opción no valida\n";	
       	break;	
    }
}


void consultaNotificaciones(){
    IControladorUsuario* cu=Fabrica::getIControladorUsuario();    
    bool registrado = true;
    string nickname;

    cout << "Ingrese el nickname del usuario: ";
    getline(cin, nickname);
    if(cu->yaRegistrado(nickname)){
        set<DTNotificacion> notificaciones=cu->obtenerNotificaciones(nickname);
        if(notificaciones.empty()){
            cout << "No hay notificaciones\n";
        }else{
            cout << "Notificaciones del usuario: \n";
            leerNotificaciones(notificaciones);
        }
    }   
    else
        cout<< "Usuario no registrado. \n";
}

void agregarLeccion(){
    IControladorCurso* cc = Fabrica::getIControladorCurso();
    vector<DTCurso> cnh = cc->solicitarCursosNoHabilitados();
    DTCurso select = *(obtenerListaDeSeleccionadosPorIndices(pedirSeleccionarIndicesDeLista("Lista de cursos no habilitados", cnh, false), cnh)).begin();
    cc->seleccionarCurso(select);
    string Tema, Objetivo;
    cout << "Ingrese el tema: ";
    getline(cin, Tema); 
    cout << "Ingrese el objetivo: ";
    getline(cin, Objetivo); 
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
        cin.ignore();
        while (Tipo < 1 && Tipo > 2) {
            cout << "Tipo no valido. Intente de nuevo\n";
        }
        string Frase;
        cout << "Ingrese la frase del ejercicio: ";
        getline(cin, Frase); 
        string desc;
        cout << "Ingrese la descripcion: ";
        getline(cin, desc); 
        cc->agregarEjercicio(Frase, (TipoEjercicio)Tipo, desc);
        if (Tipo == 1) {
            vector<string> palabras;
            string temp;
            int agregarPalabra;
            do {
                cout << "Ingrese palabra faltante: ";
                getline(cin, temp);
                palabras.push_back(temp);
                cout << "Desea agregar otra palabra?\n";
                cout << "1-Si\n";
                cout << "-Pon otro numero si No\n";
                cin >> agregarPalabra;
                cin.ignore();
            } while (agregarPalabra == 1);
            cc->ejercicioDeCompletar(palabras);
        }
        else {
            string FraseTraducida;
            cout << "Ingrese la Traduccion: ";
            getline(cin, FraseTraducida); 
            cc->ejercicioDeTraduccion(FraseTraducida);
        }
        cc->altaEjercicio();
        cout << "Desea agregar otro ejercicio?\n";
        cout << "1-Si\n";
        cout << "-Pon otro numero si No\n";
        cin >> agregarEjercicio;
        cin.ignore();
    }
    cc->agregarLeccion();
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
        cin.ignore();
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
    cin.ignore();
    while (Tipo < 1 && Tipo > 2) {
        cout << "Tipo no valido. Intente de nuevo\n";
    }
    string Frase;
    cout << "Ingrese la frase del ejercicio: ";
    getline(cin, Frase); 
    string desc;
    cout << "Ingrese la descripcion: ";
    getline(cin, desc); 
    cc->agregarEjercicio(Frase, (TipoEjercicio)Tipo, desc);
    if (Tipo == 1) {
        vector<string> palabras;
        string temp;
        int agregarPalabra;
        do {
            cout << "Ingrese palabra faltante: ";
            getline(cin, temp);
            palabras.push_back(temp);
            cout << "Desea agregar otra palabra?\n";
            cout << "1-Si\n";
            cout << "-Pon otro numero si No\n";
            cin >> agregarPalabra;
            cin.ignore();
        } while (agregarPalabra == 1);
        cc->ejercicioDeCompletar(palabras);
    }
    else {
        string FraseTraducida;
        cout << "Ingrese la Traduccion: ";
        getline(cin, FraseTraducida); 
        cc->ejercicioDeTraduccion(FraseTraducida);
    }
    cc->FinalizarAgregarEjercicio();
}

void habilitarCurso(string curso){
    IControladorCurso* cc=Fabrica::getIControladorCurso();
    cc->habilitarCurso(cc->getCurso(curso));
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

void loadIdiomas(){
    string idiomas[3]={"Ingles", "Aleman", "Portugues"};
    for(string i: idiomas){
        createIdioma(i);
    }
}

void loadUsuarios(){
    const int ingles=0;
    const int aleman=1;
    const int portugues=2;
    DTUsuario datosUsuarios[15]={
        DTUsuario("jpidiom", "asdfg123", "Juan Perez", "Soy un apasionado del aprendizaje de idiomas."),
        DTUsuario("marsilva", "qwer456", "Maria Silva", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar."),
        DTUsuario("pero12", "789werty", "Pedro Rodriguez", "Soy un entusiasta del aprendizaje de idiomas."),
        DTUsuario("laugu", "c1v2b3m4", "Laura Gutierrez", "Estoy fascinada por la forma en que las palabras pueden unir a las personas."),
        DTUsuario("carlo22", "tyuipz147", "Carlos Lopez", "Emocionado por adquirir fluidez en diferentes lenguas."),
        DTUsuario("anator", "1qsxc36", "Ana Torres", "Disfruto de la belleza de las diferentes estructuras y sonidos."),
        DTUsuario("luher24", "t7h8y5u6", "Lucia Hernandez", "Emocionada en la riqueza cultural que cada idioma ofrece."),
        DTUsuario("dagon", "1w2e3r4t5", "David Gonzalez", "Aprender nuevas lenguas y sumergirme en diferentes culturas."),
        DTUsuario("carmor", "6yu7i8m9", "Carmen Morales", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas."),
        DTUsuario("jose24", "qwj789p", "Jose Fernandez", "Disfruto del proceso de descubrir nuevas formas de comunicarme."),
        DTUsuario("langMaster", "P4s512", "Marta Grecia", "Soy una profesora apasionada por los idiomas."),
        DTUsuario("linguaPro", "Pess23", "Carlos Petro", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas."),
        DTUsuario("talkExpert", "Secret1", "Laura Perez", "Soy una profesora entusiasta del aprendizaje de idiomas."),
        DTUsuario("lingoSensei", "Secure2", "Franco Lopez", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos."),
        DTUsuario("wordMaestro", "Passw0", "Ana Morales", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas.")
    };
    Date fechasNacimiento[10]={
        Date(15, 7, 1995), Date(28, 2, 1998), Date(10, 11, 1994), Date(22, 4, 1997), Date(3, 9, 1996),
        Date(12, 1, 1999), Date(25, 6, 1993), Date(8, 12, 1997), Date(17, 3, 1995), Date(2, 8, 1998)
    };
    string paisesResidencia[10]={
        "Argentina", "Ecuador", "Peru", "Chile", "Uruguay", 
        "Argentina", "Colombia", "Uruguay", "Chile", "Bolivia"
    };
    string institutos[5]={
        "Instituto de Idiomas Moderno", "Centro Global", "Instituto de Idiomas Vanguardia",
        "Centro de Idiomas", "Instituto de Idiomas Progreso"
    };
    bool idiomasProfesores[5][3]={
        {true, false, true},
        {true, true, true},
        {false, true, false},
        {false, false, true},
        {true, false, false}
    };
    for(int i=0; i<10; i++){
        createEstudiante(datosUsuarios[i], paisesResidencia[i], fechasNacimiento[i]);
    }
    int j = 0; 
    for(int i=10; i<15; i++){
        set<string> idiomas;
        if(idiomasProfesores[j][ingles]) 
            idiomas.insert("Ingles");
        if(idiomasProfesores[j][aleman]) 
            idiomas.insert("Aleman");
        if(idiomasProfesores[j][portugues]) 
            idiomas.insert("Portugues");
        createProfesor(datosUsuarios[i], institutos[j], idiomas);
        j++; 
    }
}

void loadCursos(){
    const int CANTIDAD_CURSOS=6;
    DTCurso cursos[CANTIDAD_CURSOS]={
    DTCurso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", PRINCIPIANTE),
    DTCurso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", PRINCIPIANTE),
    DTCurso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", MEDIO),
    DTCurso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", AVANZADO),
    DTCurso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", MEDIO),
    DTCurso("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", AVANZADO)
    };
    string profesorCursos[CANTIDAD_CURSOS]={
        "langMaster", "langMaster", "linguaPro", "linguaPro", "linguaPro", "lingoSensei"
    };
    string idiomaCursos[CANTIDAD_CURSOS]={
        "Ingles", "Ingles", "Ingles", "Ingles", "Portugues", "Portugues"
    };
    set<string> previasCursos[CANTIDAD_CURSOS]={
        set<string>(), 
        set<string>(), 
        set<string>{cursos[0].getNombre()}, 
        set<string>{cursos[0].getNombre(), cursos[2].getNombre()}, 
        set<string>(), 
        set<string>{cursos[4].getNombre()}
    };
    for(int i=0; i<CANTIDAD_CURSOS; i++){
        createCurso(profesorCursos[i], cursos[i], idiomaCursos[i], previasCursos[i]);
    }
}

void cargarDatosDePrueba(){
    bool cursoHabilitado[6]={
        true, false, true, true, true, false
    };
    loadIdiomas();
    loadUsuarios();
    loadCursos();
}

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
    cout << "   17.Cargar datos de prueba\n";
    cout << "   0.Salir\n";
    cout << "Seleccione el caso de uso a ejecutar: ";
    int opcion;
    cin >> opcion;
    cin.ignore();
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
            cout<< "\n"; 
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
            cout<< "\n"; 
            break;
        case 13:
            consultaIdioma();
            cout<< "\n"; 
            break;
        case 14:
            consultaCurso();
            cout<< "\n"; 
            break;
        case 15:
            consultaEstadisticas();
            cout<< "\n"; 
            break;
        case 16:
            consultaNotificaciones();
            cout<< "\n"; 
            break;
        case 17:
            cargarDatosDePrueba();
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