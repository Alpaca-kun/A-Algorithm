compilar: Prototipo.o 
	g++ -std=c++11 Prototipo.cpp

Prototipo.o: Prototipo.cpp
	g++ -std=c++11 -c Prototipo.cpp
