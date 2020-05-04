#include "../inc/StatystykaLiczbZespolonych.hh"

Statystyka::Statystyka()
{
  reset();  
}
void Statystyka::zwiekszLiczbePoprawnych()
{
  LiczbaPoprawnych++;
}
void Statystyka::zwiekszLiczbeBlednych()
{
  LiczbaBlednych++;
}
const double Statystyka::zwrocProcentPoprawnych()const
{
  if (LiczbaPoprawnych == 0 && LiczbaBlednych == 0)
    return 0;  
  return LiczbaPoprawnych*100/(LiczbaPoprawnych+LiczbaBlednych);
}
const double Statystyka::zwrocProcentBlednych()const
{
  if (LiczbaPoprawnych == 0 && LiczbaBlednych == 0)
    return 0;  
  return LiczbaBlednych*100/(LiczbaPoprawnych+LiczbaBlednych);
}
void Statystyka::reset()
{
  LiczbaBlednych=0;
  LiczbaPoprawnych=0;
}

std::ostream& operator<< (std::ostream &stream, Statystyka statystyka)
{
  std::cout << "Procent poprawnych: " << statystyka.zwrocProcentPoprawnych()  << "\r\nProcent blenych: " << statystyka.zwrocProcentBlednych() ;
  return stream;
}
