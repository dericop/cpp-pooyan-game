all : pooyan

DIRSRC := ./src/

DIRINCLUDE := ./include/

DIROBJ := ./obj/

DIRBIN := ./bin/

DIRSAPP := $(DIRSRC) $(DIRINCLUDE) $(DIROBJ) $(DIRBIN)

ARGS := Arrow.cpp Node.cpp List.cpp Character.cpp

#pooyan : Arrow.o Node.o List.o Character.o main.cpp
#	g++ $(DIROBJ)$^ -o $(DIRBIN)$@

$(DIROBJ)Arrow.o : $(DIRSRC)Arrow.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

$(DIROBJ)Node.o : $(DIRSRC)Node.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

$(DIROBJ)List.o : $(DIRSRC)List.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

$(DIROBJ)Character.o : $(DIRSRC)Character.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

$(DIROBJ)Phantom.o : $(DIRSRC)Phantom.cpp
	g++ $^ -c -o $@ -I $(DIRINCLUDE)

#g++ -c $(ARGS) main.cpp
#	mkdir $(DIRSAPP)
pooyan : $(DIROBJ)Arrow.o $(DIROBJ)Node.o $(DIROBJ)List.o $(DIROBJ)Character.o $(DIROBJ)Phantom.o
	g++ $^ $(DIRSRC)main.cpp -o $(DIRBIN)$@ -I $(DIRINCLUDE) -lsfml-graphics -lsfml-window -lsfml-system -lpthread -lsfml-audio

#g++ -c $^ mainPruebas.cpp
mainPruebas : $(DIROBJ)Arrow.o $(DIROBJ)Node.o $(DIROBJ)List.o $(DIROBJ)Character.o $(DIROBJ)Phantom.o
	g++ $^ $(DIRSRC)mainPruebas.cpp -o $(DIRBIN)$@ -I $(DIRINCLUDE) -I $(DIROBJ) $(DIRBIN)$@ -lsfml-graphics -lsfml-window -lsfml-system -lpthread -lsfml-audio	

PHONY : open clear

open : 
	./bin/pooyan

clear :
	$(RM) $(DIRBIN)*