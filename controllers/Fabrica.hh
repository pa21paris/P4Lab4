#ifndef FABRICA_HH
#define FABRICA_HH

#include "IControladorCurso.hh"
#include "IControladorIdioma.hh"
#include "IControladorUsuario.hh"
#include "ControladorCurso.hh"
#include "ControladorIdioma.hh"
#include "ControladorUsuario.hh"

class Fabrica {
public:
    static IControladorIdioma* getIControladorIdioma();
    static IControladorCurso* getIControladorCurso();
    static IControladorUsuario* getIControladorUsuario();
};

#endif