flags=-O3 -Wall

all: task-1 suffixtr main
	g++ $(flags) -o main main.o task-1.o suffixtree.o

main: main.cpp
	g++ $(flags) -c main.cpp

task-1: task-1.cpp
	g++ $(flags) -c task-1.cpp

suffixtr: suffixtree.cpp
	g++ $(flags) -c suffixtree.cpp

clean:
	rm *.o main