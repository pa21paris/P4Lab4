#ifndef DTNOTIFICACION_HH
#define DTNOTIFICACION_HH

#include <iostream>
using namespace std;

class DTNotificacion{
private:
    string nombreIdioma, nombreCurso;
public:
    DTNotificacion(string nombreIdioma, string nombreCurso);
    string getNombreIdioma() const;
    string getNombreCurso() const;
    bool operator<(const DTNotificacion& otro) const;
    string to_string() const;
};

#endif