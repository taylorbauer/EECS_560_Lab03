Lab3: main.o QuadraticProbingHashTable.o Restauraunt.o Menu.o DoubleHashTable.o
	g++ -std=c++11 main.o QuadraticProbingHashTable.o Restauraunt.o Menu.o DoubleHashTable.o -o Lab3
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
QuadraticProbingHashTable.o: QuadraticProbingHashTable.cpp QuadraticProbingHashTable.h
	g++ -std=c++11 -c QuadraticProbingHashTable.cpp
DoubleHashTable.o: DoubleHashTable.cpp DoubleHashTable.h
	g++ -std=c++11 -c DoubleHashTable.cpp
Restauraunt.o: Restauraunt.cpp
	g++ -std=c++11 -c Restauraunt.cpp
Menu.o: Menu.cpp
	g++ -std=c++11 -c Menu.cpp
clean:
	rm -f test *.o