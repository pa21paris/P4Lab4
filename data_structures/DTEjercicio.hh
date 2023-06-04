#ifndef DTEJERCICIO_HH
#define DTEJERCICIO_HH

#include <iostream>
using namespace std;

class DTEjercicio {
private:
    string frase, descripcion;
public:
    DTEjercicio(string frase, string descripcion);
    string getFrase() const;
    string getDescripcion() const;
    bool operator<(const DTEjercicio& otro) const;
};

#endif