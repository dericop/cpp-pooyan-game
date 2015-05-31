all : mainPruebas

mainPruebas : Balloon.cpp Arrow.cpp Node.cpp List.cpp Character.cpp 
	g++ $^ mainPruebas.cpp -o $@

PHONY : clear

clear : 
	$(RM) mainPruebas