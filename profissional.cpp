#include <iomanip>
#include "profissional.hpp"
#include<iostream>
#include<memory>

using std::cin;
using std::cout;

using std::setfill;
using std::setw;


//implementação da classe Profissional

Profissional::Profissional(){
    this->nome = "Null";
}

Profissional::Profissional(int id, string nome, int idade, string genero):id(id), nome(nome), idade(idade), genero(genero){}

Profissional::~Profissional()
{
}

int Profissional::getId(){
    return this->id;
}
void Profissional::setId(int id){
    this->id = id;
}
string Profissional::getNome(){
    return this->nome;
}
void Profissional::setNome(string nome){
    this->nome = nome;
}
int Profissional::getIdade(){
    return this->idade;
}
void Profissional::setIdade(int idade){
    this->idade = idade;
}
string Profissional::getGenero(){
    return this->genero;
}
void Profissional::setGenero(string genero){
    this->genero = genero;
}
ostream& operator<< (ostream& o, Profissional& profissional){
    o << setfill (' ') << setw (10) << profissional.getId() << " | " 
		<< setfill ('.') << setw (50) << profissional.getNome() << " | " 
		<< setfill (' ') << setw (5) << profissional.getIdade()<< " | "
		<< setfill (' ') << setw (10) << profissional.getGenero();
	return o;
}

vector<shared_ptr<Profissional>> Profissional::getProfissional() const{
	return this->profissional;
}

void Profissional::criarProfissional(){
	int cP_id;
    string cP_nome;
    int cP_idade;
    string cP_genero;
    int aux = 1;

    do{
    cout << "Id: ";
    cin >> cP_id;
    cout << "Nome: ";
    cin >> cP_nome;
    cout << "Idade: ";
	cin >> cP_idade;
	cout << "Genero: ";
	cin >> cP_genero;
    
    shared_ptr<Profissional> criado = make_shared<Profissional>(cP_id, cP_nome, cP_idade, cP_genero);

    this->inserirProfissional(criado);

    cout << "[1]Inserir outro, [0]Sair:  ";
    cin >> aux;

    }while(aux == 1);
}

void Profissional::removeProfissional(string nome){
	int y = profissional.size();
     for(int x = 0; x < (y-1); x++){
         if(this->profissional.at(x)->getNome() == nome){
            this->profissional.erase(this->profissional.begin()+x);
         }
     }
}

void Profissional::inserirProfissional(shared_ptr<Profissional> novo){
	this->profissional.push_back(novo);
}

void Profissional::listarProfissional(){
	for(auto& x: this->profissional){
        cout << x->getId() << endl << x->getNome() << endl << x->getIdade() << endl << x->getGenero() << endl;
		cout << endl;
    }
}
