#include "animal.hpp"
#include "veterinario.hpp"
#include "tratador.hpp"
#include<iostream>



using namespace std;

//Implementação da classe Animal
Animal::Animal(){
    this->nome = "Null";
}

Animal::Animal(int id, string nome, string genero, int idade):id(id), nome(nome), genero(genero), idade(idade){}

Animal::~Animal(){}

int Animal::getId(){
	return this->id;
}

void Animal::setId(int id){
	this->id = id;
}

string Animal::getNome() const{
    return this->nome;
}
void Animal::setNome(string nome){
    this->nome = nome;
}

string Animal::getGenero(){
    return this->genero;
}
void Animal::setGenero(string genero){
    this->genero = genero;
}
int Animal::getIdade(){
    return this->idade;
}
void Animal::setIdade(int idade){
    this->idade = idade;
}

vector<shared_ptr<Animal>> Animal::getAnimal(){
	return this->animal;
}

void Animal::criarAnimal(){
	int cA_id;
    string cA_nome;
	string cA_genero;
    int cA_idade;
    int aux = 1;

    do{
		cout << "ID: ";
		cin >> cA_id;
    	cout << "Nome: ";
    	cin >> cA_nome;
    	cout << "Idade: ";
		cin >> cA_idade;
		cout << "Genero: ";
		cin >> cA_genero;
    
    	shared_ptr<Animal> criado = make_shared<Animal>(cA_id, cA_nome, cA_genero ,cA_idade);

    	this->inserirAnimal(criado);

    	cout << "[1]Inserir outro, [0]Sair:  ";
    	cin >> aux;

    }while(aux == 1);
}

void Animal::removeAnimal(string nome){
	int y = animal.size();
     for(int x = 0; x < (y-1); x++){
         if(this->animal.at(x)->getNome() == nome){
            this->animal.erase(this->animal.begin()+x);
         }
     }
}

void Animal::inserirAnimal(shared_ptr<Animal> novo){
	this->animal.push_back(novo);
}

void Animal::listarAnimal(){
	for(auto& x: this->animal){
        cout << x->getId() << endl << x->getNome() << endl <<  x->getGenero() << endl << x->getIdade() <<endl;
		cout << endl;
    }
}






