#include <iostream>
#include <string.h>
#include "../inc/BazaTestu.hh"


static WyrZespolone  TestLatwy[] =
  { {{2,1}, Dodaj, {1,2}},
    {{1,0}, Odejmij, {0,1}},
    {{3,0}, Mnoz, {0,3}},
    {{4,8}, Dziel, {1,0}},
  };
static WyrZespolone  TestTrudne[] =
  { {{2,1}, Dodaj, {1,2}},
    {{1,0}, Odejmij, {0,1}},
    {{3,0}, Mnoz, {0,3}},
    {{4,8}, Dziel, {1,0}},
  };

BazaTestu::BazaTestu(const char* sNazwaTestu)
{
    IndeksPytania=0;
    if (strcmp(sNazwaTestu,"latwy")) {
        TablicaPytan = TestLatwy;
        IloscPytan = sizeof(TestLatwy)/sizeof(WyrZespolone);
    }
    if (strcmp(sNazwaTestu,"trudny")) {
        TablicaPytan = TestTrudne;
        IloscPytan = sizeof(TestTrudne)/sizeof(WyrZespolone);
    }
    if (!strcmp(sNazwaTestu,"trudny") && !strcmp(sNazwaTestu,"latwy"))
    {
        std::cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << std::endl;
    }
}

bool BazaTestu::PobierzNastpnePytanie(WyrZespolone& Wyrazenie )
{
  if (IndeksPytania >= IloscPytan) return false;

  Wyrazenie = TablicaPytan[IndeksPytania];
  IndeksPytania++;
  return true;
}