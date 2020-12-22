#include<iostream>
#include "animal.hpp"
#include "profissional.hpp"
#include "mamifero.hpp"
#include "anfibio.hpp"
#include "reptil.hpp"
#include "ave.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <vector>
#include <string>
#include<ostream>
#include<memory>

using std::vector;

class Interface {
public:
	Interface();
	~Interface();
	
	void testar();
	friend ostream& operator<< (ostream& o, Interface& interface);
private:
	vector<Profissional*> profissional;
	vector<Veterinario*> veterinario;
	vector<Tratador*> tratador;
	vector<Animal*> animal;
	vector<Mamifero*> mamifero;
	vector<Reptil*> reptil;
	vector<Ave*> ave;
	vector<Anfibio*> anfibio;
};


