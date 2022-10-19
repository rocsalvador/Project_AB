flags=-O3 -Wall

all: task1 suffixtree main
	g++ $(flags) -o project main.o task1.o suffixtree.o

main: main.cpp
	g++ $(flags) -c main.cpp

task1: task1.cpp
	g++ $(flags) -c task1.cpp

suffixtree: suffixtree.cpp
	g++ $(flags) -c suffixtree.cpp

clean:
	rm *.o project
