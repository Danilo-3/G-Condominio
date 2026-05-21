#include "lista_movimento_conta.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

Lista_fracoes::Lista_fracoes() {
    cabeca = nullptr;
    permilagem_total = 0;
}
void guarda_ficheiro(ofstream& ficheires,CNoLista_fracoes *pointer){
    ficheires << "\nidentificacao: " << pointer->Dados.identifica
              << "\nDescricao: " << pointer->Dados.descreve
              << "\nPermilagem: " << pointer->Dados.permila
              <<"\nCodigo do proprietario: " << pointer->Dados.proprietario;

}
void Lista_fracoes::mostra_fracoes_descreve(){
    if(cabeca == nullptr){
  cout << "nao ha fracoes\n";
        return;
    }
    int i = 1;
    CNoLista_fracoes *atual = cabeca;
    ofstream fish("Fracoes.txt");
    while(atual != nullptr){
        cout << i << "." << setw(10) << right << atual->Dados.descreve << endl;
        atual = atual->proximo;
        i++;
        guarda_ficheiro(fish,atual);
    }
    fish.close();
    if(permilagem_total != 1000) cout << "a permilagem total é " << setw(5) << right << permilagem_total << endl;
}
void Lista_fracoes::mostra_fracao(int k) const{
    CNoLista_fracoes *atual = cabeca;
    int i = 1;
    while(i != k) {
        atual = atual->proximo;
        i++;
    }
    cout << "\nIdentificacao:   " << atual->Dados.identifica
         << "\nDescriçao:    " << atual->Dados.descreve
         << "\nPermilagem:    " << atual->Dados.permila
         << "\nProprietario:  " << atual->Dados.proprietario;
}

int Lista_fracoes :: permilagem_tota(){
    return permilagem_total;
}
void Lista_fracoes::insere_fracoes(){
    if(permilagem_total == 1000){cout << "Nao e possivel inserir mais fracoes." << endl; return;}
    CNoLista_fracoes *novo = new CNoLista_fracoes;
    cout << "\nidentificacao:";
    cin>>novo->Dados.identifica;
    cout << "\ndescricao:";
    cin.ignore();
    cin.getline(novo->Dados.descreve, 16);
    do{
        cout << "\npermilagem:";
        cin>>novo->Dados.permila;
        permilagem_total += novo->Dados.permila;
        if(permilagem_total > 1000){
            permilagem_total -= novo->Dados.permila;
            cout << "Insira uma nova permilagem menor que " << 1000-permilagem_total << endl;
        }
    }while(permilagem_total + novo->Dados.permila > 1000);
    cout<<"\ncodigo do proprietario";
    cin>>novo->Dados.proprietario;

    novo->proximo = nullptr;

    if(cabeca == nullptr) {
        cabeca = novo;
    }
    else {
        CNoLista_fracoes *atual=cabeca;
        while(atual->proximo != nullptr)
            atual=atual->proximo;
            atual->proximo=novo;
    }
    cout << "fracao inserida com exito" << endl;

}

void Lista_fracoes::modificar_proprietario() {
    if (cabeca == nullptr) {
        cout << "nao tem fracoes.";
        return;
    }
    mostra_fracoes_descreve();
    char ident[4];
    cout<<"identificacao da fracao a se mudar:";
    cin>>ident;

    CNoLista_fracoes *atual=cabeca;
    bool encontrada=false;
    while(atual != nullptr){
        if(strcmp(atual->Dados.identifica, ident) ==0){
            encontrada=true;
            break;
        }
        atual=atual->proximo;
    }
    if (encontrada==true) {
        cout<<"coloque o nov codigo do proprietario:";
        cin>>atual->Dados.proprietario;
        cout<<"proprietario modificado com exito";
    }
    else{
        cout<<"fracao nao encontrada."<<endl;
    }
}
