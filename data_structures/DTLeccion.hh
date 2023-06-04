#ifndef DTLECCION_HH
#define DTLECCION_HH

#include <iostream>
using namespace std;

class DTLeccion{
private:
    string tema, objetivo;
public:
    DTLeccion(string tema, string objetivo);
    string getTema() const;
    string getObjetivo() const;
    bool operator<(const DTLeccion& otro) const;
};

#endif