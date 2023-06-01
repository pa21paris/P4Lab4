#include "Traduccion.hh"

Traduccion::Traduccion(string frase, string descripcion, TipoEjercicio tipoDeEjercicio, string traduccionCorrecta)
    : Ejercicio(frase, descripcion, tipoDeEjercicio) {
    this->traduccionCorrecta = traduccionCorrecta;
}

string Traduccion::getTraduccionCorrecta() {
    return this->traduccionCorrecta;
}

bool Traduccion::resolver(string traduccion) {
    if(traduccion != this->traduccionCorrecta) {
        return false;
    }
    return true;
}