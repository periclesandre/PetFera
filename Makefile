#Makefile for "Project PetFera" C++ application
#Created by Péricles Andrade 22/12/2020


PROG = PetFera
CC = g++
CPPFLAGS = -Wall -std=c++11 -I./include

OBJS = animal.o anfibio.o reptil.o ave.o mamifero.o  profissional.o tratador.o veterinario.o interface.o main.o

all : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

debug: CPPFLAGS += -DDEBUG -g -O0
debug: clean all

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp -o $@
animal.o : animal.cpp animal.hpp 
	$(CC) $(CPPFLAGS) -c animal.cpp -o $@
anfibio.o : anfibio.cpp anfibio.hpp 
	$(CC) $(CPPFLAGS) -c anfibio.cpp -o $@
reptil.o : reptil.cpp reptil.hpp 
	$(CC) $(CPPFLAGS) -c reptil.cpp -o $@
ave.o : ave.cpp ave.hpp 
	$(CC) $(CPPFLAGS) -c ave.cpp -o $@
mamifero.o : mamifero.cpp mamifero.hpp 
	$(CC) $(CPPFLAGS) -c mamifero.cpp -o $@
profissional.o : profissional.cpp profissional.hpp 
	$(CC) $(CPPFLAGS) -c profissional.cpp -o $@
tratador.o : tratador.cpp tratador.hpp 
	$(CC) $(CPPFLAGS) -c tratador.cpp -o $@
veterinario.o : veterinario.cpp veterinario.hpp 
	$(CC) $(CPPFLAGS) -c veterinario.cpp -o $@
interface.o : interface.cpp interface.hpp 
	$(CC) $(CPPFLAGS) -c interface.cpp -o $@	
	
clean:
	rm -f core $(PROG) $(OBJS)
	
	
