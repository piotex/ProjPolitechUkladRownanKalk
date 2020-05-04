#include<iostream>
#include "../inc/LZtests.hh"
#include "../inc/Errors.hh"
#include "../inc/LiczbaZespolona.hh"
#include "../inc/BazaTestu.hh"
#include "../inc/WyrZespolone.hh"
#include "../inc/Wektor.hh"
#include "../inc/MacierzKw.hh"
#include "../inc/StatystykaLiczbZespolonych.hh"


void LZtests::runAll()
{
    dodawanie_LiczbyZespolonej();  
    odejmowanie_LiczbyZespolonej(); 
    mnozenie_LiczbyZespolonej(); 
    dzielenie_LiczbyZespolonej();   
    modulLiczby_Zespolonej();   
    sprzezenie_LiczbyZespolonej();   
    rownosc_LiczbyZespolonej();

    zwiekszLiczbePoprawnych_Statystyka();
    zwiekszLiczbeBlednych_Statystyka();
    zwrocProcentPoprawnych_Statystyka();
    zwrocProcentBlednych_Statystyka();
    reset_Statystyka();

    oblicz_WyrZespolone();

    //inicjacja_Wektor();
    dodawanie_Wektor();  
    odejmowanie_Wektor(); 
    mnozenie_Wektor(); 
    dzielenie_Wektor();   
    dlugosc_Wektor();

    // inicjacja_Macierzy();
    wyznacznik_Macierzy();
    transpozycja_Macierzy();

    std::cout<<"\n\nTest przebiegl pomyslnie\n\n";
}

void LZtests::transpozycja_Macierzy()
{
    Wektor<double,ROZMIAR> w[ROZMIAR];
    Wektor<double,ROZMIAR> wT[ROZMIAR];
    for(int i=0;i<ROZMIAR;i++){
        for(int j=0;j<ROZMIAR;j++){
            w[i][j] = j;
            wT[j][i] = j;
        }
    }
    MacierzKw m2(wT);
    MacierzKw m1(w);
    m1 = m1.transponuj();
    displayMyError(m1 != m2,"transpozycja_Macierzy\n\n");
}

void LZtests::wyznacznik_Macierzy()
{
    Wektor<double,ROZMIAR> w[ROZMIAR] ;
    MacierzKw m(w);
    double wyz = m.wyznacznik(Sarrus);
    displayMyError(wyz != 16,"wyznacznik_Macierzy\n\n");
}

void LZtests::inicjacja_Macierzy()
{
    Wektor<double,ROZMIAR> w[ROZMIAR];
    MacierzKw m(w);
    std::cout << m <<"\n\n";
}

void LZtests::dlugosc_Wektor()
{
    Wektor<double,ROZMIAR> l1;
    for(int i=0;i<ROZMIAR;i++){
        l1[i] = i;
    }
    double ret = l1.dlugosc() ;
    displayMyError(abs(ret - (5.47723)) > (0.00001),"dlugosc_Wektor\n\n");
}
void LZtests::dodawanie_Wektor()
{
    Wektor<double,ROZMIAR> l1; l1[0]=1;l1[1]=1;l1[2]=1;
    Wektor<double,ROZMIAR> l2; l2[0]=-2;l2[1]=2;l2[2]=2;  
    Wektor<double,ROZMIAR> l3; l3[0]=-1;l3[1]=3;l3[2]=3;   
    l2 += l1;
    displayMyError(l2!=l3,"dodawanie_Wektor\n\n");
}
void LZtests::odejmowanie_Wektor()
{
    Wektor<double,ROZMIAR> l4; l4[0]=1;l4[1]=1;l4[2]=1;
    Wektor<double,ROZMIAR> l5; l5[0]=-2;l5[1]=2;l5[2]=2;  
    Wektor<double,ROZMIAR> l6; l6[0]=-3;l6[1]=1;l6[2]=1;   
    l4 = l5-l4;
    displayMyError(l4!=l6,"odejmowanie_Wektor\n\n");
}
void LZtests::mnozenie_Wektor()
{
    Wektor<double,ROZMIAR> l4; l4[0]=1;l4[1]=1;l4[2]=1;
    Wektor<double,ROZMIAR> l5; l5[0]=-2;l5[1]=-2;l5[2]=-2;
    l4 = l4 * -2;
    displayMyError(l4!=l5,"mnozenie_Wektor\n\n");
}
void LZtests::dzielenie_Wektor()
{
    Wektor<double,ROZMIAR> l4; l4[0]=1;l4[1]=1;l4[2]=1;
    Wektor<double,ROZMIAR> l5; l5[0]=-2;l5[1]=-2;l5[2]=-2;
    l5 = l5 / -2;
    displayMyError(l4!=l5,"dzielenie_Wektor\n\n");
}

void LZtests::inicjacja_Wektor()
{
    Wektor<double,ROZMIAR> w;
    std::cout << w <<"initcjacja w tescie\n\n";
}

void LZtests::rownosc_LiczbyZespolonej()
{
    LiczbaZespolona l1(1,1),l2(1,1);
    displayMyError(l1!=l2,"rownosc_LiczbyZespolonej\n\n");
}

void LZtests::dodawanie_LiczbyZespolonej()
{
    LiczbaZespolona l1(1,1),l2(2,2),l3(3,3);
    displayMyError((l1+l2)!=l3,"dodawanie_LiczbyZespolonej\n\n");
}
void LZtests::odejmowanie_LiczbyZespolonej()
{
    LiczbaZespolona l1(1,1),l2(2,2),l3(3,3);
    displayMyError((l3-l2)!=l1,"odejmowanie_LiczbyZespolonej\n\n");
}
void LZtests::mnozenie_LiczbyZespolonej()
{
    LiczbaZespolona l1(2,1),l2(2,2),l3(2,6);
    displayMyError((l1*l2)!=l3,"mnozenie_LiczbyZespolonej\n\n");
}
void LZtests::dzielenie_LiczbyZespolonej()
{
    LiczbaZespolona l1(10,10),l2(2,4),l3(3,-1);
    displayMyError( ((l1/l2)!=l3) ,"dzielenie_LiczbyZespolonej\n\n");
}
void LZtests::modulLiczby_Zespolonej()   
{
    LiczbaZespolona l1(3,4);
    bool prety = l1.modul() != 5;
    displayMyError(prety,"modulLiczby_Zespolonej\n\n");
}
void LZtests::sprzezenie_LiczbyZespolonej()   
{
    LiczbaZespolona l1(3,4),l2(3,-4);
    bool prety = l1.sprzezenie() != l2;
    displayMyError(prety,"sprzezenie_LiczbyZespolonej\n\n");
}

void LZtests::zwiekszLiczbePoprawnych_Statystyka()
{
    Statystyka s;
        s.zwiekszLiczbePoprawnych();    
        s.zwiekszLiczbePoprawnych();    
        s.zwiekszLiczbePoprawnych();    
        s.zwiekszLiczbePoprawnych();    
        s.zwiekszLiczbePoprawnych();    
        int pop = s.zwrocProcentPoprawnych();
    bool prety = pop != 100;
    displayMyError(prety,"zwiekszLiczbePoprawnych_Statystyka\n\n");
}
void LZtests::zwiekszLiczbeBlednych_Statystyka()
{
    Statystyka s;
        s.zwiekszLiczbeBlednych();    
        s.zwiekszLiczbeBlednych();    
        s.zwiekszLiczbeBlednych();    
        s.zwiekszLiczbeBlednych();    
        s.zwiekszLiczbeBlednych();    
        int opo = s.zwrocProcentBlednych();
    bool prety = opo != (100);
    displayMyError(prety,"zwiekszLiczbeBlednych_Statystyka\n\n");
}
void LZtests::zwrocProcentPoprawnych_Statystyka()
{
    Statystyka s;
        s.zwiekszLiczbeBlednych(); 
        s.zwiekszLiczbePoprawnych(); 
        int opo = s.zwrocProcentPoprawnych();
    bool prety = opo != (100/2);
    displayMyError(prety,"zwrocProcentPoprawnych_Statystyka\n\n");
}
void LZtests::zwrocProcentBlednych_Statystyka()
{
    Statystyka s;
    s.zwiekszLiczbeBlednych(); 
    s.zwiekszLiczbeBlednych(); 
    s.zwiekszLiczbeBlednych(); 
    s.zwiekszLiczbePoprawnych(); 
    s.zwiekszLiczbeBlednych(); 
    s.zwiekszLiczbePoprawnych(); 
    s.zwiekszLiczbeBlednych(); 
    s.zwiekszLiczbePoprawnych(); 
    s.zwiekszLiczbeBlednych(); 
    s.zwiekszLiczbePoprawnych(); 
    bool prety = s.zwrocProcentBlednych() != (60);
    displayMyError(prety,"zwrocProcentBlednych_Statystyka\n\n");
}
void LZtests::reset_Statystyka()
{
    Statystyka s;
    s.reset();
    int pop = s.zwrocProcentPoprawnych();
    int bed = s.zwrocProcentBlednych();
    bool prety = (bed != 0 || pop != 0);
    displayMyError(prety,"reset_Statystyka\n\n");
}

void LZtests::oblicz_WyrZespolone()
{
    LiczbaZespolona l1(1,1),l2(2,2);
    WyrZespolone w(l1,Dodaj,l2);
    // std::cout<<w.Oblicz()<<l1+l2;
    bool prety = (l1+l2) != w.Oblicz();
    displayMyError(prety,"oblicz_WyrZespolone-dodaj\n\n");
    w.setOperacja(Odejmij);
    prety = (l1-l2) != w.Oblicz();
    displayMyError(prety,"oblicz_WyrZespolone-Odejmij\n\n");
    w.setOperacja(Mnoz);
    prety = (l1*l2) != w.Oblicz();
    displayMyError(prety,"oblicz_WyrZespolone-Mnoz\n\n");
    w.setOperacja(Dziel);
    prety = (l1/l2) != w.Oblicz();
    displayMyError(prety,"oblicz_WyrZespolone-Dziel\n\n");

}
