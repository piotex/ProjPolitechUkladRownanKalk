#ifndef STATYSTYKALZESP_HH
#define STATYSTYKALZESP_HH

#include<iostream>

class Statystyka {      
    int LiczbaPoprawnych; 
    int LiczbaBlednych; 
  public:            
    Statystyka();

    void zwiekszLiczbePoprawnych();
    void zwiekszLiczbeBlednych();
    const double zwrocProcentPoprawnych()const;
    const double zwrocProcentBlednych()const;
    void reset();
};

std::ostream& operator<< (std::ostream &stream, const Statystyka stat);

#endif