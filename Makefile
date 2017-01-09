CFLAGS= -g -std=c++11
LDFLAGS=

all: test

test: test.o Classe_ABR.o
	g++ test.o Classe_ABR.o -o test

test.o: test.cpp Classe_ABR.h
	g++ $(CFLAGS) -c test.cpp -o test.o

Classe_ABR.o: Classe_ABR.cpp Classe_ABR.h
	g++ $(CFLAGS) -c  Classe_ABR.cpp -o Classe_ABR.o
clean:
	rm -f *.o
