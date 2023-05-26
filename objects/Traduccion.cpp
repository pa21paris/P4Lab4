#include "Traduccion.hh"

Traduccion::Traduccion(string frase, string descripcion, string traduccionCorrecta)
    : Ejercicio(frase, descripcion) {
    this->traduccionCorrecta = traduccionCorrecta;
}

string Traduccion::getTraduccionCorrecta() {
    return this->traduccionCorrecta;
}

void Traduccion::setTraduccionCorrecta(string traduccionCorrecta) {
    this->traduccionCorrecta = traduccionCorrecta;
}