#include "CListaTipoMovimento.h"
#include <iostream>
#include <cstring>

using namespace std;

CListaTipoMovimento::CListaTipoMovimento() {
    cabeca = nullptr;
}
bool CListaTipoMovimento::procura(unsigned int cod) const {
    lista_tipo *atual=cabeca;
    while(atual != nullptr) {
        if(atual->dados.getCodigo() == cod) {
            return true;
        }
        atual = atual->proximo;
    }
        return false;
}

void CListaTipoMovimento::inserir() {
    lista_tipo *novo = new lista_tipo;
    unsigned int cod;
    char desc[21];

    do {
        cout << "codigo do tipo de movimento: ";
        cin >> cod;
        if(procura(cod)) cout << "codigo ja existe" << endl;
    } while(procura(cod) || cod == 0);

    cout << "descricao: ";
    cin.ignore();
    cin.getline(desc, 21);

    novo->dados.setCodigo(cod);
    novo->dados.setDescricao(desc);
    novo->proximo = nullptr;

    if(cabeca == nullptr) {
        cabeca = novo;
    } else {
        lista_tipo *atual = cabeca;
        while(atual->proximo != nullptr)
            atual = atual->proximo;
        atual->proximo = novo;
    }
    cout << "tipo movimento inserido com exito" << endl;
}

void CListaTipoMovimento::mostrarTodos() const {
    lista_tipo *atual = cabeca;
    while(atual != nullptr) {
        atual->dados.mostrar();
        atual = atual->proximo;
    }
}

void CListaTipoMovimento::modificar() {
    unsigned int cod;
    mostrarTodos();
    cout<<"codigo do tipo a se modificar:";
    cin>>cod;
    
    if(!procura(cod)){
        cout << "falha ao encontrar o codigo" << endl;
        return;    
    }

    lista_tipo *atual = cabeca;
    while(atual->dados.getCodigo() !=cod) {
        atual = atual ->proximo;
    }

    char novaDesc[21];
    cout<<"descricao nova:";
    cin.ignore();
    cin.getline(novaDesc, 21);
    atual ->dados.setDescricao(novaDesc);

    cout<<"descricao modificada com exito" << endl;
}
