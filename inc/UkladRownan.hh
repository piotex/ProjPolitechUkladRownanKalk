#ifndef UKLAD_ROWNAN_L
#define UKLAD_ROWNAN_L

#include <math.h>
#include "Wektor.hh"
#include "MacierzKw.hh"

template<class _TYP, int _ROZMIAR>
class UkladRownanL {
  MacierzKw<_TYP,_ROZMIAR> macierz;
  Wektor<_TYP,_ROZMIAR> wektor;
public:
  UkladRownanL();
  UkladRownanL(MacierzKw<_TYP,_ROZMIAR> m, Wektor<_TYP,_ROZMIAR> w);

  const Wektor<_TYP,_ROZMIAR> oblicz()const;
  const Wektor<_TYP,_ROZMIAR> get_WektorBledu()const;

  const MacierzKw<_TYP,_ROZMIAR> get_Macierz()const;
  const Wektor<_TYP,_ROZMIAR> get_Wektor()const;
  void set_Macierz(MacierzKw<_TYP,_ROZMIAR> m);
  void set_Wektor(Wektor<_TYP,_ROZMIAR> w);
};
template<class _TYP, int _ROZMIAR>
std::istream& operator>> (std::istream &stream, UkladRownanL<_TYP,_ROZMIAR>& wyr);
template<class _TYP, int _ROZMIAR>
std::ostream& operator<< (std::ostream &stream, const UkladRownanL<_TYP,_ROZMIAR> wyr);


#endif