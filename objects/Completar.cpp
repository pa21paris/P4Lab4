#include "Completar.hh"

Completar::Completar(string frase, string descripcion, set<string> palabrasFaltantes)
    : Ejercicio(frase, descripcion) {
    this->palabrasFaltantes = palabrasFaltantes;
}

void Completar::resolver(set<string> palabras) {}

set<string> Completar::getPalabrasFaltantes() {
    return palabrasFaltantes;
}

void Completar::setPalabrasFaltantes(set<string> palabrasFaltantes) {
    this->palabrasFaltantes = palabrasFaltantes;
}