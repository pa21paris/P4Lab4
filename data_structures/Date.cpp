#include "Date.hh"

int verifyDay(int day){
    if(day > 0 && day < 32){
        return day;
    }else{
        return 1;
    }
}

int verifyMonth(int mes){
    if(mes > 0 && mes < 13){
        return mes;
    }else{
        return 1;
    }
}

int verifyYear(int year){
    if(year > 0){
        return year;
    }else{
        return 1;
    }
}

Date::Date(int dia, int mes, int ano){
    this->dia = verifyDay(dia);
    this->mes = verifyMonth(mes);
    this->ano = verifyYear(ano);
}

int Date::getDia(){
    return this->dia;
}

int Date::getMes(){
    return this->mes;
}

int Date::getAno(){
    return this->ano;
}

void Date::setDia(int dia){
    this->dia = verifyDay(dia);
}

void Date::setMes(int mes){
    this->mes = verifyMonth(mes);
}

void Date::setAno(int ano){
    this->ano = verifyYear(ano);
}

string Date::toString(){
    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
}