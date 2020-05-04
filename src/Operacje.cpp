#include "../inc/Operacje.hh"

std::istream& operator>> (std::istream &strm, Operacja& op)
{
    char znak = 'x';
    strm >> znak;
    switch(znak)
    {
        case '+': 
            op = Dodaj;
            break;
        case '-': 
            op = Odejmij;
            break;
        case '*': 
            op = Mnoz;
            break;
        case '/': 
            op = Dziel;
            break;
    }
    return strm;
}
std::ostream& operator<< (std::ostream &strm, const Operacja op)
{
    char c = 'x';
    switch(op)
    {
        case Dodaj: 
            c = '+';
            break;
        case Odejmij: 
            c = '-';
            break;
        case Mnoz: 
            c = '*';
            break;
        case Dziel: 
            c = '/';
            break;
    }
  strm<<c;
  return strm;
}