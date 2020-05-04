#ifndef LZTESTS_HH
#define LZTESTS_HH

class LZtests
{      
    public:      
        void runAll();

        void dodawanie_LiczbyZespolonej();  
        void odejmowanie_LiczbyZespolonej(); 
        void mnozenie_LiczbyZespolonej(); 
        void dzielenie_LiczbyZespolonej();   
        void modulLiczby_Zespolonej();   
        void sprzezenie_LiczbyZespolonej();   
        void rownosc_LiczbyZespolonej();

        void zwiekszLiczbePoprawnych_Statystyka();
        void zwiekszLiczbeBlednych_Statystyka();
        void zwrocProcentPoprawnych_Statystyka();
        void zwrocProcentBlednych_Statystyka();
        void reset_Statystyka();

        void oblicz_WyrZespolone();

        void inicjacja_Wektor();
        void dodawanie_Wektor();  
        void odejmowanie_Wektor(); 
        void mnozenie_Wektor(); 
        void dzielenie_Wektor();   
        void dlugosc_Wektor();  
         
        void inicjacja_Macierzy();   
        void wyznacznik_Macierzy();   
        void transpozycja_Macierzy();  

};

#endif
