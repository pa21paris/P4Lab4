#include "DTUsuario.hh"

DTUsuario::DTUsuario(string nickname, string password, string name, string description) {
    this->nickname = nickname;
    this->password = password;
    this->name = name;
    this->description = description;
}

string DTUsuario::getNickname() const{
    return this->nickname;
}

string DTUsuario::getPassword() const{
    return this->password;
}

string DTUsuario::getName() const{
    return this->name;
}

string DTUsuario::getDescription() const{
    return this->description;
}

bool DTUsuario::operator<(const DTUsuario& otro) const{
    return this->nickname < otro.nickname;
}