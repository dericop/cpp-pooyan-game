all : pooyan

DIRSRC := ./src/

DIRINCLUDE := ./include/

DIROBJ := ./obj/

DIRBIN := ./bin/

DIRSAPP := $(DIRSRC) $(DIRINCLUDE) $(DIROBJ) $(DIRBIN)

ARGS := Arrow.cpp Node.cpp List.cpp Character.cpp

#pooyan : Arrow.o Node.o List.o Character.o main.cpp
#	g++ $(DIROBJ)$^ -o $(DIRBIN)$@

Arrow.o : $(DIRSRC)Arrow.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

Node.o : $(DIRSRC)Node.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

List.o : $(DIRSRC)List.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

Character.o : $(DIRSRC)Character.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

Phantom.o : $(DIRSRC)Phantom.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

#g++ -c $(ARGS) main.cpp
#	mkdir $(DIRSAPP)
pooyan : Phantom.o Arrow.o Node.o List.o Character.o
	g++ $^ $(DIRSRC)main.cpp -I $(DIRINCLUDE) -I $(DIROBJ) -o $(DIRBIN)$@ -lsfml-graphics -lsfml-window -lsfml-system -lpthread -lsfml-audio

#g++ -c $^ mainPruebas.cpp
mainPruebas : $(DIROBJ)Phantom.o $(DIROBJ)Arrow.o $(DIROBJ)Node.o $(DIROBJ)List.o $(DIROBJ)Character.o
	g++ $^ $(DIRSRC)main.cpp -I $(DIRINCLUDE) -o $(DIRBIN)$@ -lsfml-graphics -lsfml-window -lsfml-system -lpthread -lsfml-audio

PHONY : open clear

open : 
	./bin/pooyan

clear :
	$(RM) $(DIRBIN)*