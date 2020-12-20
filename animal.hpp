#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include "veterinario.hpp"
#include "tratador.hpp"


using namespace std;



//Declaraçao da classe Animal

class Animal{
protected:
    int id;
    string nome;
    string genero;
    int idade;
    vector<shared_ptr<Animal>>animal;
public:
    Animal();
    Animal(int id, string nome, string genero, int idade);
    virtual ~Animal();
    int getId();
    void setId(int id);
    string getNome() const;
    void setNome(string nome);
    string getGenero();
    void setGenero(string genero);
    int getIdade();
    void setIdade(int idade);
    vector<shared_ptr<Animal>>getAnimal();
    vector<shared_ptr<Veterinario>>getVeterinaio;
    vector<shared_ptr<Tratador>>getTratador;
    void criarAnimal();
    void removeAnimal(string nome);
    void inserirAnimal(shared_ptr<Animal> novo);
    void listarAnimal();
};




