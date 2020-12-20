#include<iostream>
#include "animal.hpp"
#include "profissional.hpp"
#include "mamifero.hpp"
#include "anfibio.hpp"
#include "reptil.hpp"
#include "ave.hpp"
#include "tratador.hpp"
#include "veterinario.hpp"
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
	
    Tratador* tratador = new Tratador();
    Veterinario* veterinario = new Veterinario();

    Reptil* reptil = new Reptil();
	Anfibio* anfibio = new Anfibio();
	Ave* ave = new Ave();
	Mamifero* mamifero = new Mamifero();

    int x;
    int y;
    string a;


    do{
        
        cout << "[2]Profissionais"<< endl << "[1]Animais" << endl << "[0]Sair"<< endl << ":";
        cin >> x;
        if(x!=0 && x!=1 && x!=2){
            cout << "Digite um valor válido!" << endl;
        }
        else if(x==1 || x==2){
            if(x==2){
                do{
                    cout << "[2]Veterinario" << endl << "[1]Tratador" << endl << "[0]Sair" << endl << ":";
                    cin >> y;
                }while (y!=0 && y!=1 && y!= 2);
                if(y==2){
                    do{
                        cout << "[3]Inserir" << endl << "[2]Excluir" << endl <<"[1]Listar"<< endl << "[0]Sair" << endl << ":";
                        cin >> y;
                    }while(y!=0 && y!=1 && y!= 2 && y!=3);
                    if(y==3){
                        //inserir veterinario
                        veterinario->criarVeterinario();
                        
                    }
                    else if (y==2){
                        //remove veterinario
                        cout << "Qual o nome do veterinario que deseja remover?: ";
                        cin >> a; 
                        veterinario->removeVeterinario(a);
                    }
                    else if (y==1){
                        //listar Veterinarios
                        cout << endl << "Os veterinarios são:" << endl;
                        veterinario->lerVeterinario();
                        veterinario->listarVeterinario();
                        
                    }
                    y=10;
                    
                    
                }
                else if(y==1){
                    do{
                        cout << "[3]Inserir" << endl << "[2]Excluir" << endl <<"[1]Listar"<< endl << "[0]Sair" << endl << ":";
                        cin >> y;
                    }while(y!=0 && y!=1 && y!= 2 && y!=3);
                    if(y==3){
                        //inserir tratador
                        tratador->criarTratador();
                    }
                    else if (y==2){
                        //excluir Tratador
                        cout << "Qual o nome do tratador que deseja remover?: ";
                        cin >> a; 
                        tratador->removeTratador(a);
                    }
                    else if (y==1){
                        //listar Tratador
                        cout << endl << "Os tratadores são:" << endl;
                        tratador->lerTratador();
                        tratador->listarTratador();
                        
                    }
                    
                                      
                }
                
            }
            else if(x==1){
                do{
                    cout << "[4]Anfibio" << endl << "[3]Reptil" << endl << "[2]Ave"<< endl << "[1]Mamífero"<< endl << ":";
                    cin >> y;
                }while(y!=0 && y!=1 && y!= 2 && y!=3 && y!=4);
                if(y==4){
                    do{
                        cout << "[3]Inserir" << endl << "[2]Excluir" << endl <<"[1]Listar"<< endl << "[0]Sair" << endl << ":";
                        cin >> y;
                    }while(y!=0 && y!=1 && y!= 2 && y!=3);
                    if(y==3){
                        //inserir anfibio
                        anfibio->criarAnfibio();
                        
                    }
                    else if (y==2){
                        //excluir anfibio
                        cout << "Qual o nome do anfibio que deseja remover?: ";
                        cin >> a; 
                        anfibio->removeAnfibio(a);
                    }
                    else if(y==1){
                        //listar Anfibios
                        anfibio->lerAnfibio();
                        anfibio->listarAnfibio();
                    }
                    y=10;             // para não entrar em outro if
                    
                }
                else if (y==3){
                    do{
                        cout << "[3]Inserir" << endl << "[2]Excluir" << endl <<"[1]Listar"<< endl << "[0]Sair" << endl << ":";
                        cin >> y;
                    }while(y!=0 && y!=1 && y!= 2 && y!=3);
                    if(y==3){
                        //criar reptil
                        reptil->criarReptil();
                        
                    }
                    else if (y==2){
                        cout << "Qual o nome do reptil que deseja remover?: ";
                        cin >> a; 
                        reptil->removeReptil(a);
                    }
                    else if (y==1) {
                        //listar Repteis
                        reptil->lerReptil();
                        reptil->listarReptil();
                    }

                    y=10;                //impedir que retorne aos if's        
                  
                    
                }
                else if (y==2){
                    do{
                        cout << "[3]Inserir" << endl << "[2]Excluir" << endl <<"[1]Listar"<< endl << "[0]Sair" << endl << ":";
                        cin >> y;
                    }while(y!=0 && y!=1 && y!= 2 && y!=3);
                    if(y==3){
                        //cria ave
                        ave->criarAve();
                        
                    }
                    else if (y==2){
                        //remove ave
                        cout << "Qual o nome da ave que deseja remover?: ";
                        cin >> a; 
                        ave->removeAve(a);
                    }
                    else if (y==1){
                        //listar Aves;
                        ave->lerAve();
                        ave->listarAve();
                    }
                    y=10;
                }
                else if (y==1){
                    do{
                        cout << "[3]Inserir" << endl << "[2]Excluir" << endl <<"[1]Listar"<< endl << "[0]Sair" << endl << ":";
                        cin >> y;
                    }while(y!=0 && y!=1 && y!= 2 && y!=3);
                    if(y==3){
                        //insere mamífero
                        mamifero->criarMamifero();
                        
                    }
                    else if (y==2){
                        //remove mamífero
                        cout << "Qual o nome do mamífero que deseja remover?: ";
                        cin >> a; 
                        mamifero->removeMamifero(a);
                    }
                    else if (y==1){
                        //listar Mamiferos
                        mamifero->lerMamifero();
                        mamifero->listarMamifero();
                    }

                    y=10;
                    
                    
                }                
                
            }

        }
        

    }while(x!=0);

    tratador->gravaTratador();
    veterinario->gravaVeterinario();
    mamifero->gravaMamifero();
    ave->gravaAve();
    reptil->gravaReptil();
    anfibio->gravaAnfibio();

    return 0;
}