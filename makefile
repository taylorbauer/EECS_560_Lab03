Lab2: main.o
	g++ -std=c++11 main.o -o Lab2
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm -f test *.o