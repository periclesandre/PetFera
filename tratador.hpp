#pragma once
#include "profissional.hpp"

#include<vector>

#include<string>
#include<ostream>
#include<memory>



using namespace std;

//Declaração da classe Tratador

class Tratador: public Profissional{
private:
    string habilidade;               //alimentador, lavador, limpador (limpa os excrementos)
    vector<shared_ptr<Tratador>>tratador;
public:
    Tratador();
    Tratador(int id, string nome, int idade, string genero, string habilidade);
    ~Tratador();
    string getHabilidade();
    void setHabilidade(string habilidade);
	friend ostream& operator<< (ostream &o, Tratador& tratador);
    vector<shared_ptr<Tratador>>getTratador();
    void criarTratador();
    void removeTratador(string nome);
    void inserirTratador(shared_ptr<Tratador> novo);
    void listarTratador();
    void gravaTratador();
    void lerTratador();    
};
