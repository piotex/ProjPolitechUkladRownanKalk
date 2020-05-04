#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrZespolone.hh"
#include <string.h>
#include<iostream>
#include <stack>

class BazaTestu
{      
    int IloscPytan;
    int IndeksPytania;
    WyrZespolone  *TablicaPytan;
    
    public:            
        BazaTestu(const char* sNazwaTestu);

        bool PobierzNastpnePytanie(WyrZespolone& Wyrazenie );
};

#endif
