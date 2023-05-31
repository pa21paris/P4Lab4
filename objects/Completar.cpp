#include "Completar.hh"

Completar::Completar(string frase, string descripcion, list<string> palabrasFaltantes)
    : Ejercicio(frase, descripcion) {
    this->palabrasFaltantes = palabrasFaltantes;
}

bool Completar::resolver(list<string> palabras) {
    if(palabras.size()!=this->palabrasFaltantes.size()){
        return false;
    }
    list<string>::iterator it1,it2;
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

list<string> Completar::getPalabrasFaltantes() {
    return palabrasFaltantes;
}