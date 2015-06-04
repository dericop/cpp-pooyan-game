all : pooyan

DIRSRC := ./src

DIRINCLUDE := ./include

DIROBJ := ./obj

DIRBIN := ./bin

ARGS := Arrow.cpp Node.cpp List.cpp Character.cpp

pooyan : Arrow.o Node.o List.o Character.o main.cpp
	g++ $(DIROBJ)$^ -o $(DIRBIN)$@

Arrow.o : Arrow.cpp
	g++ $^ -c

Node.o : Node.cpp
	g++ $^ -c

List.o : List.cpp
	g++ $^ -c

Character.o : Character.cpp
	g++ $^ -c

#List.o : List.cpp
#	g++ $^ -c

sfml-app : Arrow.o Node.o List.o Character.o
	#g++ -c $(ARGS) main.cpp
	g++ $^ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

mainPruebas : Arrow.o Node.o List.o Character.o
	#g++ -c $^ mainPruebas.cpp
	g++ $^ mainPruebas.cpp -o mainPruebas -lsfml-graphics -lsfml-window -lsfml-system

PHONY : clear

clear :
	$(RM) sfml-app mainPruebas