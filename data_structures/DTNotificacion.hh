#include <iostream>
using namespace std;

class DTNotificacion{
private:
    string nombreIdioma, nombreCurso;
public:
    DTNotificacion(string nombreIdioma, string nombreCurso);
    string getNombreIdioma();
    string getNombreCurso();
};