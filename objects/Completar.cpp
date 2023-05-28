#include "Completar.hh"

Completar::Completar(string frase, string descripcion, set<string> palabrasFaltantes)
    : Ejercicio(frase, descripcion) {
    this->palabrasFaltantes = palabrasFaltantes;
}

bool Completar::resolver(set<string> palabras) {
    if(palabras.size()!=this->palabrasFaltantes.size()){
        return false;
    }
    set<string>::iterator it1,it2;
    it1=palabras.begin();
    it2=this->palabrasFaltantes.begin();
    while(it1!=palabras.end() && it2!=this->palabrasFaltantes.end()){
        if(*it1!=*it2){
            return false;
        }
        it1++;
        it2++;
    }
    return true;
}

set<string> Completar::getPalabrasFaltantes() {
    return palabrasFaltantes;
}