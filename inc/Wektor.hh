#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <math.h>
#include "../inc/Rozmiar.hh"
#include<iostream>
#include "LiczbaZespolona.hh"

template<class TYP, int _ROZMIAR>
class Wektor {
  TYP tab[_ROZMIAR];
  int size=_ROZMIAR;

  public: 
    Wektor();
    Wektor(TYP tablica[]);

    const TYP & operator[] (int index) const;
    TYP & operator[] (int index);

    const bool operator == (const Wektor<TYP,_ROZMIAR> & W2) const;
    const bool operator != (const Wektor<TYP,_ROZMIAR> & W2) const;
    const Wektor<TYP,_ROZMIAR> operator +(const Wektor<TYP,_ROZMIAR> & W2) const; //W1 + W2
    const Wektor<TYP,_ROZMIAR> operator -(const Wektor<TYP,_ROZMIAR> & W2) const; //W1 - W2
    
    const Wektor<TYP,_ROZMIAR> operator* (TYP l) const; // W1 * 2
    const Wektor<TYP,_ROZMIAR> operator/ (TYP l) const; // W1 / 2
    
    const double dlugosc() const; //modul
    const TYP operator * (const Wektor<TYP,_ROZMIAR> & W2) const; //skalarnie

    void operator += (const Wektor<TYP,_ROZMIAR> & W2);
    void operator -= (const Wektor<TYP,_ROZMIAR> & W2);

};
template<class TYP, int _ROZMIAR>
std::ostream & operator<<(std::ostream & strm,const Wektor<TYP,_ROZMIAR> & W);
template<class TYP, int _ROZMIAR>
std::istream & operator>>(std::istream & strm,Wektor<TYP,_ROZMIAR> & W);
template<class TYP, int _ROZMIAR>
Wektor<TYP,_ROZMIAR> operator *(TYP l, Wektor<TYP,_ROZMIAR> W2); 

#endif