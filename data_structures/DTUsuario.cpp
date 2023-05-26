#include "DTUsuario.hh"

DTUsuario::DTUsuario(string nickname, string password, string name, string description) {
    this->nickname = nickname;
    this->password = password;
    this->name = name;
    this->description = description;
}

string DTUsuario::getNickname() {
    return this->nickname;
}

string DTUsuario::getPassword() {
    return this->password;
}

string DTUsuario::getName() {
    return this->name;
}

string DTUsuario::getDescription() {
    return this->description;
}