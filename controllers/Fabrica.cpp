#include "Fabrica.hh"

IControladorCurso* Fabrica::getIControladorCurso() {
    return ControladorCurso::getInstance();
}

IControladorIdioma* Fabrica::getIControladorIdioma() {
    return ControladorIdioma::getInstance();
}

IControladorUsuario* Fabrica::getIControladorUsuario() {
    return ControladorUsuario::getInstance();
}