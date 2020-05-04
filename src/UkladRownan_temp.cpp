#include "UkladRownan.cpp"
#include "../inc/LiczbaZespolona.hh"
#include <math.h>

template class UkladRownanL<double,ROZMIAR>;
template std::istream & operator>>(std::istream &strm, UkladRownanL<double,ROZMIAR> &W);
template std::ostream& operator<< (std::ostream &stream, const UkladRownanL<double,ROZMIAR> wyr);


template class UkladRownanL<LiczbaZespolona,ROZMIAR>;
template std::istream & operator>>(std::istream &strm, UkladRownanL<LiczbaZespolona,ROZMIAR> &W);
template std::ostream& operator<< (std::ostream &stream, const UkladRownanL<LiczbaZespolona,ROZMIAR> wyr);

