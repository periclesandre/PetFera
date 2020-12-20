#pragma once

#include<vector>
#include "profissional.hpp"
#include<string>
#include<ostream>
#include<memory>



using namespace std;

//Declaração da classe Veterinario

class Veterinario: public Profissional{
private:
    string especialidade;                //especialização em mamíferos, répteis, anfíbios, ou aves
    string formacao;                     //graduação, mestrado, doutorado
    vector<shared_ptr<Veterinario>>veterinario;
public:
    Veterinario();
    Veterinario(int id, string nome, int idade, string genero, string especialidade, string formacao);
    ~Veterinario();
    string getEspecialidade();
    void setEspecialidade(string especialidade);
    string getFormacao();
    void setFormacao(string formacao);
	friend ostream& operator<< (ostream &o, Veterinario& veterinario);
    vector<shared_ptr<Veterinario>>getVeterinario();
    void criarVeterinario();
    void removeVeterinario(string nome);
    void inserirVeterinario(shared_ptr<Veterinario> novo);
    void listarVeterinario();
    void gravaVeterinario();
    void lerVeterinario();
};