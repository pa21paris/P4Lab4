#include <iostream>
using namespace std;

class DTLeccion{
private:
    string tema, objetivo;
public:
    DTLeccion(string tema, string objetivo);
    string getTema();
    string getObjetivo();
};