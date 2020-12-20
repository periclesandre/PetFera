all: animal.cpp anfibio.cpp reptil.cpp ave.cpp mamifero.cpp  profissional.cpp tratador.cpp veterinario.cpp interface.cpp
	g++ -std=c++11 -Wall -pedantic animal.cpp anfibio.cpp reptil.cpp ave.cpp mamifero.cpp  profissional.cpp tratador.cpp veterinario.cpp interface.cpp -o PetFera

run:
	./PetFera

clean:
	rm *PetFera