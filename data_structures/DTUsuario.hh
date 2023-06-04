#ifndef DT_USUARIO_HH
#define DT_USUARIO_HH

#include <iostream>
using namespace std;

class DTUsuario {
private:
    string nickname,password,name,description;
public:
    DTUsuario(string nickname, string password, string name, string description);
    string getNickname() const;
    string getPassword() const;
    string getName() const;
    string getDescription() const;
    bool operator<(const DTUsuario& otro) const;
};

#endif