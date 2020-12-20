#include "animal.hpp"
#include "mamifero.hpp"
#include<iostream>
#include<iomanip>
#include<fstream>



using std::cin;
using std::cout;
using std::ios;
using std::setfill;
using std::setw;

//Implementação da classe Mamíferos

Mamifero::Mamifero(){}

Mamifero::Mamifero(int id, string nome, string genero, int idade, bool amamentando, string dieta, string patas): Animal(id, nome, genero, idade), amamentando(amamentando), dieta(dieta), patas(patas){}


Mamifero::~Mamifero(){}

bool Mamifero::getAmamentando(){
    return this->amamentando;
}
void Mamifero::setAmamentando(bool amamentando){
    this->amamentando = amamentando;
}
string Mamifero::getDieta(){
    return this->dieta;
}
void Mamifero::setDieta(string dieta){
    this->dieta = dieta;
}
string Mamifero::getPatas(){
    return this->patas;
}
void Mamifero::setPatas(string patas){
    this->patas = patas;
}
vector<shared_ptr<Mamifero>> Mamifero::getMamifero(){
	return this->mamifero;
}

void Mamifero::criarMamifero(){
	int cM_id;
    string cM_nome;
    int cM_idade;
    string cM_genero;
	bool cM_amamentando;
	string cM_dieta;
	string cM_patas;
	char letra = 'n';
    int aux = 1;

    do{
    	cout << "Id: ";
    	cin >> cM_id;
    	cout << "Nome: ";
    	cin >> cM_nome;
    	cout << "Idade: ";
		cin >> cM_idade;
		cout << "Genero: ";
		cin >> cM_genero;
		cout << "Amamentando? - S/s(sim) - N/n(não): ";
		cin >> letra;
		if(letra == 'S' || letra == 's'){
        	cM_amamentando = true;
    	}
    	else if (letra == 'N' || letra == 'n')    {
    	    cM_amamentando = false;
    	}
		else{
			cout << "valor incorreto" << endl;
		}
		cout << "Dieta: ";
		cin >> cM_dieta;
		cout << "Posição de andar: ";
		cin >> cM_patas;

	    shared_ptr<Mamifero> criado = make_shared<Mamifero>(cM_id, cM_nome, cM_genero, cM_idade, cM_amamentando, cM_dieta, cM_patas);

    	this->inserirMamifero(criado);

    	cout << "[1]Inserir outro, [0]Sair:  ";
    	cin >> aux;

    }while(aux == 1);
}

void Mamifero::removeMamifero(string nome){
	int y = mamifero.size();
     for(int x = 0; x < (y-1); x++){
         if(this->mamifero.at(x)->getNome() == nome){
            this->mamifero.erase(this->mamifero.begin()+x);
         }
     }
}

void Mamifero::inserirMamifero(shared_ptr<Mamifero> novo){
	this->mamifero.push_back(novo);
}

void Mamifero::listarMamifero(){
	for(auto& x: this->mamifero){
        cout << x->getId() << endl << x->getNome() << endl <<  x->getGenero() << endl << x->getIdade() << endl << x->getDieta() << endl << x->getPatas() << endl;
		if(x->getAmamentando() == 1){
            cout << "Está amamentando" << endl;
        }
        else if (x->getAmamentando()==0){
            cout << "Não está amamentando" << endl;
        }
		cout << endl;
    }
}

void Mamifero::gravaMamifero(){
	fstream arquivo("arqMamifero.txt",ios::in | ios::out | ios::app);
	for(auto& x: this->mamifero){
		arquivo << x->getId() << "-" << x->getNome() << "-" << x->getGenero()
		<< "-" << x->getIdade() << "-" << x->getAmamentando() << "-" << x->getPatas() << "-" << x->getDieta() << endl;
	}
	arquivo.close();
}

void Mamifero::lerMamifero(){
	fstream arquivo;
	string linha;
	arquivo.open("arqMamifero.txt",ios::in);    
    if(arquivo.is_open()){
    	while(getline(arquivo,linha, '-')){
    		cout << linha << endl;
    	}
    }
	arquivo.close();
}