#include "Leccion.hh"

Leccion::Leccion(string tema, string objetivo){
    this->tema = tema;
    this->objetivo = objetivo;
}

void Leccion::agregarEjercicio(Ejercicio* ejercicio){
    ejercicios.insert(ejercicio);
}

void Leccion::eliminarLeccion(){
    set<Ejercicio *>::iterator it;
    for(it = ejercicios.begin(); it != ejercicios.end(); ++it){
        delete *it;
    }
}

string Leccion::getTema(){
    return this->tema;
}

string Leccion::getObjetivo(){
    return this->objetivo;
}

int Leccion::getTotalE(){
    return this->ejercicios.size();
}

set<Ejercicio*> Leccion::getEjercicios(){
    return this->ejercicios;
}

set<DTEjercicio> Leccion::getDTEjercicios(){
    set<DTEjercicio> ejercicios;
    set<Ejercicio*>::iterator it;
    for(it = this->ejercicios.begin(); it != this->ejercicios.end(); ++it){
        ejercicios.insert((*it)->getData());
    }
    return ejercicios;
}

DTLeccion Leccion::getDT() {
    return DTLeccion(this->tema, this->objetivo);
}

DatosLeccion Leccion::getDatos() {
    return DatosLeccion(this->getDT(), this->getDTEjercicios());
}