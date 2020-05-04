#include<iostream>
#include <fstream>
#include "../inc/Errors.hh"
#include "../inc/LiczbaZespolona.hh"
#include "../inc/BazaTestu.hh"
#include "../inc/WyrZespolone.hh"
#include "../inc/Wektor.hh"
#include "../inc/MacierzKw.hh"
#include "../inc/StatystykaLiczbZespolonych.hh"
#include "../inc/UkladRownan.hh"

int main(int argc, char **argv)
{
  UkladRownanL<LiczbaZespolona,ROZMIAR> ukladRownan;
  Wektor<LiczbaZespolona,ROZMIAR> wektorWynik;
  Wektor<LiczbaZespolona,ROZMIAR> wektorBledow;
  // UkladRownanL<double,ROZMIAR> ukladRownan;
  // Wektor<double,ROZMIAR> wektorWynik;
  // Wektor<double,ROZMIAR> wektorBledow;

  std::ifstream plik("dane.dat");
  plik >> ukladRownan;

  std::cout << "Macierz:\n" 
            << ukladRownan.get_Macierz() 
            << "\nWektor:\n" 
            << ukladRownan.get_Wektor() 
            << "\nRozwiazanie:\n" 
            << ukladRownan.oblicz() 
            <<"\n"<<"\nWektor bledu:\n"
            <<ukladRownan.get_WektorBledu()
            <<"\nDlugosc wektora bledu:\n"
            <<ukladRownan.get_WektorBledu().dlugosc()
            <<"\n\n\n";

}

