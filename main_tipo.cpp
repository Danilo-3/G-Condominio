#include "CListaTipoMovimento.h"
#include <iostream>

using namespace std;

int main() {
    CListaTipoMovimento lista;
    int opca;

    do {
        cout<<"1. ver todos os tipos\n";
        cout<<"2. inserir tipo\n";
        cout<<"3. modificar tipo\n";
        cout<<"0. sair\n";
        cout<<"opcao: ";
        cin>>opca;

        if(opca == 1)
            listas.mostrarTodos();
        else if(opca == 2)
            listas.inserir();
        else if(opca == 3)
            listas.modificar();
        else if(opca != 0)
            cout << "opcao invalida!\n";

    } while(opca != 0);

    cout << "fechando...\n";
    return 0;
}
