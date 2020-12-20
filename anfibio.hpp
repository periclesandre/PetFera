#pragma once
#include<iostream>
#include<vector>
#include "animal.hpp"
#include<memory>


using namespace std;

//Declaraçao da classe Anfíbios

class Anfibio: public Animal{
protected:
    string trocapele;              //troca de pele parcial
    string excrecao;               //excrementam ureia
    vector<shared_ptr<Anfibio>>anfibio;
public:
    Anfibio();
    Anfibio(int id, string nome, string genero, int idade, string trocapele, string excrecao);
    virtual ~Anfibio();
    string getTrocapele() const;
    void setTrocapele(string trocapele);
    string getExcrecao() const;
    void setExcrecao(string excrecao);
    vector<shared_ptr<Anfibio>>getAnfibio();
    void criarAnfibio();
    void removeAnfibio(string nome);
    void inserirAnfibio(shared_ptr<Anfibio> novo);
    void listarAnfibio();
    void gravaAnfibio();
    void lerAnfibio();
};