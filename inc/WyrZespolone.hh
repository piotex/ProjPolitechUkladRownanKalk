#ifndef WYRZESPOLONE_HH
#define WYRZESPOLONE_HH

#include<iostream>
#include "../inc/LiczbaZespolona.hh"
#include "../inc/Operacje.hh"

class WyrZespolone 
{      
    LiczbaZespolona liczba1;
    LiczbaZespolona liczba2;
    Operacja operacja;
  public:       
    WyrZespolone();
    WyrZespolone(LiczbaZespolona l1, Operacja op, LiczbaZespolona l2);

    const LiczbaZespolona getLiczba1()const;
    const LiczbaZespolona getLiczba2()const;
    const Operacja getOperacja()const;
    void setLiczba1(LiczbaZespolona l);
    void setLiczba2(LiczbaZespolona l);
    void setOperacja(Operacja l);

    const LiczbaZespolona Oblicz ()const;
    const bool operator==(WyrZespolone wyr)const;
    const bool operator!=(WyrZespolone wyr)const;
};

std::istream& operator>> (std::istream &stream, WyrZespolone& wyr);
std::ostream& operator<< (std::ostream &stream, const WyrZespolone wyr);

#endif
