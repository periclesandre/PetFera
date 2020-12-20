#include "anfibio.hpp"
#include "animal.hpp"
#include<iostream>
#include <fstream>



using namespace std;

//Implementação da classe Anfibio

Anfibio::Anfibio(){}

Anfibio::Anfibio(int id, string nome, string genero, int idade, string trocapele, string excrecao): Animal(id, nome, genero, idade), trocapele(trocapele), excrecao(excrecao){}

Anfibio::~Anfibio()
{
}

string Anfibio::getTrocapele() const{
    return this->trocapele;
}
void Anfibio::setTrocapele(string trocapele){
    this->trocapele = trocapele;
}
string Anfibio::getExcrecao() const{
    return this->excrecao;
}
void Anfibio::setExcrecao(string excrecao){
    this->excrecao = excrecao;
}

vector<shared_ptr<Anfibio>> Anfibio::getAnfibio(){
	return this->anfibio;
}

void Anfibio::criarAnfibio(){
	int cAnf_id;
    string cAnf_nome;
    int cAnf_idade;
    string cAnf_genero;
	string cAnf_trocapele;
	string cAnf_excrecao;
    int aux = 1;

    do{
    cout << "Id: ";
    cin >> cAnf_id;
    cout << "Nome: ";
    cin >> cAnf_nome;
    cout << "Idade: ";
	cin >> cAnf_idade;
	cout << "Genero: ";
	cin >> cAnf_genero;
	cout << "Troca de pele: ";
	cin >> cAnf_trocapele;
	cout << "Tipo de excreção: ";
	cin >> cAnf_excrecao;
    
    shared_ptr<Anfibio> criado = make_shared<Anfibio>(cAnf_id, cAnf_nome, cAnf_genero, cAnf_idade, cAnf_trocapele, cAnf_excrecao);

    this->inserirAnfibio(criado);

    cout << "[1]Inserir outro, [0]Sair:  ";
    cin >> aux;

    }while(aux == 1);
}

void Anfibio::removeAnfibio(string nome){
	int y = anfibio.size();
     for(int x = 0; x < (y-1); x++){
         if(this->anfibio.at(x)->getNome() == nome){
            this->anfibio.erase(this->anfibio.begin()+x);
         }
     }
}

void Anfibio::inserirAnfibio(shared_ptr<Anfibio> novo){
	this->anfibio.push_back(novo);
}

void Anfibio::listarAnfibio(){
	for(auto& x: this->anfibio){
        cout << x->getId() << endl << x->getNome() << endl <<  x->getGenero() << endl << x->getIdade() << endl << x->getTrocapele() << endl << x->getExcrecao() << endl;
		cout << endl;
    }
}

void Anfibio::gravaAnfibio(){
    fstream arquivo("arqAnfibio.txt",ios::in | ios::out | ios::app);
	for(auto& x: this->anfibio){
		arquivo << x->getId() << "-" << x->getNome() << "-" << x->getGenero()
		<< "-" << x->getIdade() << "-" << x->getTrocapele() << "-" << x->getExcrecao() << endl;
	}
	arquivo.close();
}

void Anfibio::lerAnfibio(){
    fstream arquivo;
	string linha;
	arquivo.open("arqAnfibio.txt",ios::in);    
    if(arquivo.is_open()){
    	while(getline(arquivo,linha, '-')){
    		cout << linha << endl;
    	}
    }
	arquivo.close();
}