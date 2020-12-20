#include <iomanip>
#include "profissional.hpp"
#include "tratador.hpp"
#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::ios;
using std::setfill;
using std::setw;

//implementação da classe Tratador

Tratador::Tratador(){}

Tratador::Tratador(int id, string nome, int idade, string genero, string habilidade): Profissional(id, nome, idade, genero), habilidade(habilidade){}

Tratador::~Tratador(){}

string Tratador::getHabilidade(){
    return this->habilidade;
}
void Tratador::setHabilidade(string habilidade){
    this->habilidade = habilidade;
}
ostream& 
operator<< (ostream &o, Tratador& tratador){
	o << setfill (' ') << setw (10) << tratador.getId() << " | " 
		<< setfill ('.') << setw (50) << tratador.getNome() << " | " 
		<< setfill (' ') << setw (5) << tratador.getIdade() << " | "
		<< setfill (' ') << setw (10) << tratador.getGenero() << " | " 
		<< setfill (' ') << setw (50) << tratador.getHabilidade();
	return o;
}

vector<shared_ptr<Tratador>> Tratador::getTratador(){
    return this->tratador;
}

void Tratador::criarTratador(){
    int cT_id;
    string cT_nome;
    int cT_idade;
    string cT_genero;
	string cT_habilidade;
    int aux = 1;

    do{
    	cout << "Id: ";
    	cin >> cT_id;
    	cout << "Nome: ";
    	cin >> cT_nome;
    	cout << "Idade: ";
		cin >> cT_idade;
		cout << "Genero: ";
		cin >> cT_genero;
		cout << "Habilidade: ";
		cin >> cT_habilidade;
    
    	shared_ptr<Tratador> criado = make_shared<Tratador>(cT_id, cT_nome, cT_idade, cT_genero, cT_habilidade);

    	this->inserirTratador(criado);

    	cout << "[1]Inserir outro, [0]Sair:  ";
    	cin >> aux;
    }while(aux == 1);

}

void Tratador::inserirTratador(shared_ptr<Tratador> novo){
    this->tratador.push_back(novo);
}

 void Tratador::removeTratador(string nome){
     int y = tratador.size();
     for(int x = 0; x < (y-1); x++){
         if(this->tratador.at(x)->getNome() == nome){
            this->tratador.erase(this->tratador.begin()+x);
         }
     }
 }

void Tratador::listarTratador(){
    for(auto& x: this->tratador){
        cout << x->getId() << endl << x->getNome() << endl << x->getIdade() << endl << x->getGenero() << endl << x->getHabilidade() << endl;
		cout << endl;
    }
}

void Tratador::gravaTratador(){
	fstream arquivo("arqTratador.txt",ios::app);
	for(auto& x: this->tratador){
		arquivo << x->getId() << "-" << x->getNome() << "-" << x->getGenero()
		<< "-" << x->getIdade() << "-" << x->getHabilidade() << endl;
	}
	arquivo.close();
}

void Tratador::lerTratador(){
	fstream arquivo;
	string linha;
	arquivo.open("arqTratador.txt",ios::in);    
    if(arquivo.is_open()){
    	while(getline(arquivo,linha, '-')){
    		cout << linha << endl;
    	}
    }
	arquivo.close();
}