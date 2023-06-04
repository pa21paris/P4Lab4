#ifndef DATE_HH
#define DATE_HH

#include <iostream>
using namespace std;

class Date{
private:
    int dia, mes, ano;
public:
    Date(int dia, int mes, int ano);
    int getDia();
    int getMes();
    int getAno();
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    string toString();
    bool operator<(const Date& otro) const;
};

#endif