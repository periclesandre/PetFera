#pragma once
#include<iostream>
#include<vector>
#include "animal.hpp"
#include<memory>

//Declaraçao da classe Reptil

class Reptil: public Animal{
protected:
    string ecdise;               //troca completa de pele
    string tipopele;             //escama, placa dermica, casco
    vector<shared_ptr<Reptil>>reptil;
public:
    Reptil();
    Reptil(int id, string nome, string genero, int idade, string ecdise, string tipopele);
    virtual ~Reptil();
    string getEcdise();
    void setEcdise(string ecdise);
    string getTipopele();
    void setTipopele(string tipopele);
    vector<shared_ptr<Reptil>>getReptil();
    void criarReptil();
    void removeReptil(string nome);
    void inserirReptil(shared_ptr<Reptil> novo);
    void listarReptil();
    void gravaReptil();
    void lerReptil();
};