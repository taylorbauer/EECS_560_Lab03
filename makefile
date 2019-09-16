Lab2: main.o QuadraticProbingHashTable.o Restauraunt.o Menu.o
	g++ -std=c++11 main.o QuadraticProbingHashTable.o Restauraunt.o Menu.o -o Lab2
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
QuadraticProbingHashTable.o: QuadraticProbingHashTable.cpp QuadraticProbingHashTable.h
	g++ -std=c++11 -c QuadraticProbingHashTable.cpp
Restauraunt.o: Restauraunt.cpp
	g++ -std=c++11 -c Restauraunt.cpp
Menu.o: Menu.cpp
	g++ -std=c++11 -c Menu.cpp
clean:
	rm -f test *.o