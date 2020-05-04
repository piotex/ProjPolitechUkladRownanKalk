#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: workingFile

	./workingFile

workingFile: obj/main.o obj/LiczbaZespolona.o obj/Wektor.o obj/UkladRownan.o obj/MacierzKw.o obj/StatystykaLiczbZespolonych.o  obj/Operacje.o  obj/WyrZespolone.o  obj/Errors.o  obj/BazaTestu.o  #obj/LZtests.o
	g++ -Wall -pedantic -o workingFile obj/*.o     

obj/main.o: src/main.cpp inc/LiczbaZespolona.hh inc/Wektor.hh inc/UkladRownan.hh inc/MacierzKw.hh inc/StatystykaLiczbZespolonych.hh inc/Operacje.hh inc/WyrZespolone.hh inc/Errors.hh inc/BazaTestu.hh #inc/LZtests.hh       
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LiczbaZespolona.o: src/LiczbaZespolona.cpp inc/LiczbaZespolona.hh 
	g++ ${CPPFLAGS} -o obj/LiczbaZespolona.o src/LiczbaZespolona.cpp

obj/UkladRownan.o: src/UkladRownan.cpp inc/UkladRownan.hh src/UkladRownan_temp.cpp
	g++ ${CPPFLAGS} -o obj/UkladRownan.o src/UkladRownan_temp.cpp

obj/MacierzKw.o: src/MacierzKw.cpp inc/MacierzKw.hh src/MacierzKw_temp.cpp
	g++ ${CPPFLAGS} -o obj/MacierzKw.o src/MacierzKw_temp.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh src/Wektor_temp.cpp
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor_temp.cpp

obj/StatystykaLiczbZespolonych.o: src/StatystykaLiczbZespolonych.cpp inc/StatystykaLiczbZespolonych.hh 
	g++ ${CPPFLAGS} -o obj/StatystykaLiczbZespolonych.o src/StatystykaLiczbZespolonych.cpp

obj/Operacje.o: src/Operacje.cpp inc/Operacje.hh  
	g++ ${CPPFLAGS} -o obj/Operacje.o src/Operacje.cpp

obj/WyrZespolone.o: src/WyrZespolone.cpp inc/WyrZespolone.hh 
	g++ ${CPPFLAGS} -o obj/WyrZespolone.o src/WyrZespolone.cpp

obj/Errors.o: src/Errors.cpp inc/Errors.hh  
	g++ ${CPPFLAGS} -o obj/Errors.o src/Errors.cpp

obj/BazaTestu.o: src/BazaTestu.cpp inc/BazaTestu.hh  
	g++ ${CPPFLAGS} -o obj/BazaTestu.o src/BazaTestu.cpp

obj/LZtests.o: src/LZtests.cpp inc/LZtests.hh obj/WyrZespolone.o 
	g++ ${CPPFLAGS} -o obj/LZtests.o src/LZtests.cpp 

clean:
	rm -f obj/*.o workingFile