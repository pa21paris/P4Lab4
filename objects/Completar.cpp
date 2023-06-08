#include "Completar.hh"

Completar::Completar(string frase, string descripcion, TipoEjercicio tipoDeEjercicio, vector<string> palabrasFaltantes)
    : Ejercicio(frase, descripcion, tipoDeEjercicio) {
    this->palabrasFaltantes = palabrasFaltantes;
}

bool Completar::resolver(vector<string> palabras) {
    if(palabras.size()!=this->palabrasFaltantes.size()) return false;
    int i=0;
    while(i<palabras.size()){
        if(palabras[i]!=this->palabrasFaltantes[i]) return false;
        i++;
    }
    return true;
}

vector<string> Completar::getPalabrasFaltantes() {
    return palabrasFaltantes;
}