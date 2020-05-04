#ifndef OPERACJELZESP_HH
#define OPERACJELZESP_HH

#include<iostream>

enum Operacja
{ 
    Dodaj, 
    Odejmij, 
    Mnoz, 
    Dziel
};

std::istream& operator>> (std::istream &strm, Operacja& op);
std::ostream& operator<< (std::ostream &strm, const Operacja op);

#endif