#include "animal.hpp"
#include "ave.hpp"
#include<iostream>
#include<fstream>
#include<iomanip>

using std::cin;
using std::cout;
using std::ios;
using std::setfill;
using std::setw;




//Implementação da classe Ave

Ave::Ave(){}

Ave::Ave(int id, string nome, string genero, int idade, string cor, bool voando): Animal(id, nome, genero, idade), cor(cor), voando(voando){}


Ave::~Ave(){}

string Ave::getCor(){
    return this->cor;
}
void Ave::setCor(string cor){
    this->cor = cor;
}
bool Ave::getVoando(){
    return this->voando;
}
void Ave::setVoando(bool voando){
    this->voando = voando;
}
vector<shared_ptr<Ave>> Ave::getAve(){
	return this->ave;
}

void Ave::criarAve(){
	int cAve_id;
    string cAve_nome;
    int cAve_idade;
    string cAve_genero;
	string cAve_cor;
	bool cAve_voando;
    int aux = 1;
	char letra = 'n';

    do{
    cout << "Id: ";
    cin >> cAve_id;
    cout << "Nome: ";
    cin >> cAve_nome;
    cout << "Idade: ";
	cin >> cAve_idade;
	cout << "Genero: ";
	cin >> cAve_genero;
	cout << "Cor: ";
	cin >> cAve_cor;
	cout << "Apta a voar? - S/s(sim) - N/n(não): ";
	cin >> letra;
	if(letra == 'S' || letra == 's'){
        cAve_voando = true;
    }
    else if (letra == 'N' || letra == 'n')    {
        cAve_voando = false;
    }
	else{
		cout << "valor incorreto" << endl;
	}
	
	

    
    shared_ptr<Ave> criado = make_shared<Ave>(cAve_id, cAve_nome, cAve_genero, cAve_idade, cAve_cor, cAve_voando);

    this->inserirAve(criado);

    cout << "[1]Inserir outro, [0]Sair:  ";
    cin >> aux;

    }while(aux == 1);
}

void Ave::removeAve(string nome){
	int y = ave.size();
     for(int x = 0; x < (y-1); x++){
         if(this->ave.at(x)->getNome() == nome){
            this->ave.erase(this->ave.begin()+x);
         }
     }
}

void Ave::inserirAve(shared_ptr<Ave> novo){
	this->ave.push_back(novo);
}

void Ave::listarAve(){
	for(auto& x: this->ave){
        cout << x->getId() << endl << x->getNome() << endl <<  x->getGenero() << endl << x->getIdade() << endl << x->getCor() << endl;
		if(x->getVoando() == 1){
            cout << "Está voando" << endl;
        }
        else if (x->getVoando()==0){
            cout << "Não está voando" << endl;
        }
		cout << endl;
    }
}

void Ave::gravaAve(){
	fstream arquivo("arqAve.txt",ios::in | ios::out | ios::app);
	for(auto& x: this->ave){
		arquivo << x->getId() << "-" << x->getNome() << "-" << x->getGenero()
		<< "-" << x->getIdade() << "-" << x->getCor() << "-" << x->getVoando() << endl;
	}
	arquivo.close();
}

void Ave::lerAve(){
    fstream arquivo;
	string linha;
	arquivo.open("arqAve.txt",ios::in);    
    if(arquivo.is_open()){
    	while(getline(arquivo,linha, '-')){
    		cout << linha << endl;
    	}
    }
	arquivo.close();
}