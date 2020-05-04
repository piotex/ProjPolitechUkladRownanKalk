#include "../inc/UkladRownan.hh"


template<class _TYP, int _ROZMIAR>
UkladRownanL<_TYP,_ROZMIAR>::UkladRownanL()
{
    Wektor<_TYP,_ROZMIAR> w;
    MacierzKw<_TYP,_ROZMIAR> m;
    wektor = w;
    macierz = m;
}
template<class _TYP, int _ROZMIAR>
UkladRownanL<_TYP,_ROZMIAR>::UkladRownanL(MacierzKw<_TYP,_ROZMIAR> m, Wektor<_TYP,_ROZMIAR> w):macierz(m),wektor(w){}
template<class _TYP, int _ROZMIAR>
void UkladRownanL<_TYP,_ROZMIAR>::set_Macierz(MacierzKw<_TYP,_ROZMIAR> MM)
{
    macierz = MM;
}
template<class _TYP, int _ROZMIAR>
void UkladRownanL<_TYP,_ROZMIAR>::set_Wektor(Wektor<_TYP,_ROZMIAR> MM)
{
    wektor = MM;
}
template<class TYP, int _ROZMIAR>
const MacierzKw<TYP,_ROZMIAR> UkladRownanL<TYP,_ROZMIAR>::get_Macierz()const{
    return macierz;
}
template<class TYP, int _ROZMIAR>
const Wektor<TYP,_ROZMIAR> UkladRownanL<TYP,_ROZMIAR>::get_Wektor()const{
    return wektor;
}
template<class TYP, int _ROZMIAR>
const Wektor<TYP,_ROZMIAR> UkladRownanL<TYP,_ROZMIAR>::oblicz()const
{
    //metoda Cramera
    TYP Wg = get_Macierz().wyznacznik(Gauss);
    displayMyError( (Wg<COMPARE_VAL && Wg>-COMPARE_VAL) ,"BLAD - Wyznacznik wynosi 0");
    MacierzKw<TYP,_ROZMIAR> copy = get_Macierz();
    Wektor<TYP,_ROZMIAR> ret;
    //std::cout << "\n----------\n" << Wg << "\n----------\n";
    for (int i = 0; i < _ROZMIAR; i++)
    {
        copy.set_Kolumna(i,get_Wektor());

        //std::cout << "\n----------\n"<<copy<<"\n" << copy.wyznacznik(Gauss) << "\n----------\n";

        ret[i] = copy.wyznacznik(Gauss) / Wg;
        copy = get_Macierz();
    }
    return ret;
}
template<class TYP, int _ROZMIAR>
const Wektor<TYP,_ROZMIAR> UkladRownanL<TYP,_ROZMIAR>::get_WektorBledu()const
{
    return get_Macierz() * oblicz() - get_Wektor();
}
template<class TYP, int _ROZMIAR>
std::istream& operator>> (std::istream &strm, UkladRownanL<TYP,_ROZMIAR>& wyr)
{
    MacierzKw<TYP,_ROZMIAR> _m;
    Wektor<TYP,ROZMIAR> _w;
    strm >> _m >> _w;
    _m = _m.transponuj();
    wyr.set_Macierz(_m);
    wyr.set_Wektor(_w);
    return strm;
}
template<class TYP, int _ROZMIAR>
std::ostream& operator<< (std::ostream &strm, const UkladRownanL<TYP,_ROZMIAR> wyr)
{
    MacierzKw<TYP,_ROZMIAR> m = wyr.get_Macierz();
    Wektor<TYP,_ROZMIAR> w = wyr.get_Wektor();
    strm << m << "\r\n" << w;
    return strm;
}

//-------------------------------------------------------------------------------------------------------

