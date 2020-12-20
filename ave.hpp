#pragma once
#include<iostream>
#include<vector>
#include "animal.hpp"
#include<memory>

//Declaraçao da classe Répteis

class Ave: public Animal{
protected:
    string cor;
    bool voando;
    vector<shared_ptr<Ave>>ave;
public:
    Ave();
    Ave(int id, string nome, string genero, int idade, string cor, bool voando);
    virtual ~Ave();
    string getCor();
    void setCor(string cor);
    bool getVoando();
    void setVoando(bool voando);
    vector<shared_ptr<Ave>>getAve();
    void criarAve();
    void removeAve(string nome);
    void inserirAve(shared_ptr<Ave> novo);
    void listarAve();
    void gravaAve();
    void lerAve();
};