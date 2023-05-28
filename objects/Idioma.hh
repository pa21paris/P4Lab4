#ifndef IDIOMA_HH
#define IDIOMA_HH

#include <iostream>
#include <set>
#include "Suscripcion.hh"
using namespace std;

class Usuario;

class Idioma{
private:
    string nombre;
    set<Suscripcion *> usuariosSuscriptos;
public:
    Idioma(string nombre);
    string getNombre();
    bool verificarSuscripcion(Usuario* user);
    void agregarSuscripcion(Usuario* user);
    void eliminarSuscripcion(Usuario* user);
    bool enviarNotificacion(DTNotificacion n);
};

#include "Usuario.hh"

#endif