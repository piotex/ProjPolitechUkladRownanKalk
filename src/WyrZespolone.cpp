#include <iostream>
#include "../inc/LiczbaZespolona.hh"
#include "../inc/WyrZespolone.hh"

WyrZespolone::WyrZespolone()
{
    LiczbaZespolona pomoc(0,0);
    liczba1 = pomoc;
    operacja = Dodaj;
    liczba2 = pomoc;
}
WyrZespolone::WyrZespolone(const LiczbaZespolona l1,const Operacja op,const LiczbaZespolona l2):liczba1(l1),liczba2(l2),operacja(op){}

const LiczbaZespolona WyrZespolone::getLiczba1()const{
    return liczba1;
}
const LiczbaZespolona WyrZespolone::getLiczba2()const{
    return liczba2;
}
const Operacja WyrZespolone::getOperacja()const{
    return operacja;
}
void WyrZespolone::setLiczba1(LiczbaZespolona l){
    liczba1 = l;
}
void WyrZespolone::setLiczba2(LiczbaZespolona l){
    liczba2 = l;
}
void WyrZespolone::setOperacja(Operacja l){
    operacja = l;
}

const LiczbaZespolona WyrZespolone::Oblicz()const
{
    LiczbaZespolona Wynik(0,0);
    switch(operacja)
    {
        case Dodaj:
            return liczba1 + liczba2;
        case Odejmij:
            return liczba1 - liczba2;
        case Mnoz:
            return liczba1 * liczba2;
        case Dziel:
            return liczba1 / liczba2;
    }
    return Wynik;
}
std::istream& operator>> (std::istream &strm, WyrZespolone& wyr)
{
    LiczbaZespolona liczba1;
    LiczbaZespolona liczba2;
    Operacja operacja;
    strm >> liczba1 >> operacja >> liczba2;
    wyr.setLiczba1(liczba1);
    wyr.setLiczba2(liczba2);
    wyr.setOperacja(operacja);
    return strm;
}
std::ostream& operator<< (std::ostream &strm, const WyrZespolone wyr)
{
    LiczbaZespolona liczba1 = wyr.getLiczba1();
    LiczbaZespolona liczba2 = wyr.getLiczba2();
    Operacja operacja = wyr.getOperacja();
    strm<<liczba1<<operacja<<liczba2;
    return strm;
}
const bool WyrZespolone::operator==(WyrZespolone wyr)const
{
    return 
        (wyr.liczba1==liczba1 )&& 
        (wyr.liczba2==liczba2)&&
        (wyr.operacja==operacja);
}
const bool WyrZespolone::operator!=(WyrZespolone wyr)const
{
    WyrZespolone w(liczba1,operacja,liczba2);
    return !(wyr == w);
}