flags=-O3 -Wall

all: main

main: main.cpp
	g++ $(flags) -o main main.cpp

clean:
	rm *.o main