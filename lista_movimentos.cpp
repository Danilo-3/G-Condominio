#include "lista_movimentos.h"

void guarda_ficheiro(ofstream& ficheiro, no_lista *atual) {

    ficheiro << "\nCodigo do movimento: " << atual->dados.id_movimento
             << "\nData: "     << atual->dados.data
             << "\nValor: " << atual->dados.valor
             <<"\nCodigo do tipo de movimento: " << atual->dados.codigo_tipo_movimento
             <<"\nOrigem do pagamento: " << atual->dados.origem_pagamento
             <<"\nDescricao do movimento: " << atual->dados.descricao_movimento;
}
lista_movimentos::lista_movimentos() {
    cabeca = nullptr;
}
void lista_movimentos :: abertura_do_ano(){
    double aux = saldo_condominio;
    cout << "Insira o valor do orçamento do ano";
    do{
        cin >> saldo_condominio;
    }while(saldo_condominio <= 0);
    saldo_condominio += aux;
}
void lista_movimentos :: tipo_despesas(Condominos& haha){
    if(cabeca == nullptr){
        cout << "Nao há despesas\n";
        return;
    }
    ofstream ficheira("lista_movimento.txt");
    int i = 2;
    no_lista* atual = cabeca;
    while(atual != nullptr){
        if(atual->dados.valor < 0){
                cout << i <<setw(10) << left << '.' << atual->dados.descricao_movimento << endl;
                i++;
        }
        guarda_ficheiro(ficheira,atual);

        atual = atual->proximo;
    }
    ficheira << "\nSaldo_condominio: " << saldo_condominio;
    ficheira.close();
    if(i == 2) {cout << "Nao há despesas" << endl; return;}
    int u;
    cout << "Saldo do Condomínio: " << saldo_condominio;
    cout << "\nEscolha o número adjacente à descricao caso queira saber mais informaçoes sobre essa despesa"
            "\n1.Inserir Despesas"
            "\n0.Sair";
    do{
        cin >> u;
    }while(!(u >= 0 && u <= i-1));
    if(u == 1){
        insere_despesas(haha);
        return;
    }
    if(u == 0) return;
    mostra_despesa(haha,u);
    return;
}
void lista_movimentos :: mostra_despesa(Condominos& haha,const int& u){
    int i = 2,k;
    no_lista* atual = cabeca;
    while(i != u){
        i++;
        atual = atual->proximo;
    }
    cout << "\nCodigo do movimento: " << atual->dados.id_movimento
         << "\nData: "     << setw(4) << atual->dados.ano << "-" << setw(2) << right << setfill('0') <<
        atual->dados.mes << "-" << setw(2) << right <<setfill('0') << atual->dados.dia << endl
        << "\nValor: " << atual->dados.valor
         <<"\nCodigo do tipo de movimento: " << atual->dados.codigo_tipo_movimento
         <<"\nOrigem do pagamento: " << atual->dados.origem_pagamento
         <<"\nDescricao do movimento: " << atual->dados.descricao_movimento;
    cout << "\n1. Modificar despesas"
            "\n0. Sair";
    do{
        cin >> k;
    }while(!(k == 0 || k == 1));
    if(k == 0){
        tipo_despesas(haha);
        return;
    }
    label1:
        cout << "\nQual Dado da despesa quer modificar?"
                "\n5.Valor:"
                "\n4.Codigo do movimento"
                "\n3.Data:"
                "\n2.Codigo do tipo de movimento:"
                "\n1.Descricao do movimento:"
                "\n0.Sair";
        cin >> k;
        switch(k){
        case 0:
            tipo_despesas(haha);
            return;
            break;
        case 1:
            cout << "\nInsira uma nova descrica do movimento: ";
            cin >> atual->dados.descricao_movimento;
            break;
        case 2:
            cout << "\nInsira um novo Codigo do tipo de movimento: ";
            cin >> atual->dados.id_movimento;
            break;
        case 3:
            cout <<"\nInsira um novo ano: ";
            cin >> atual->dados.ano;
            cout << "\nInsira um novo mes: ";
            cin >> atual->dados.mes;
            cout <<"\nInsira um novo dia: ";
            cin >> atual->dados.dia;
            break;
        case 4:
            cout <<"\nInsira um novo Codigo do movimento";
            cin >> atual->dados.codigo_tipo_movimento;
            break;
        case 5:{
            double aux = - atual->dados.valor;
            cout << "\nInsira o novo valor: ";
            cin >> atual->dados.valor;
            atual->dados.valor = -  atual->dados.valor;
            if(atual->dados.origem_pagamento == 0) saldo_condominio += aux + atual->dados.valor;
            else{
                lista_condo* auxs = haha.procura(atual->dados.origem_pagamento);
                auxs->dados.euros += aux + atual->dados.valor;
            }
            break;
              }


        }
    goto label1;
    }

void lista_movimentos ::  insere_despesas(Condominos& haha){
    no_lista* novo = new no_lista;

    cout << "\nInsira o codigo do movimento:";
    cin >> novo->dados.id_movimento;
    cout << "\nA Insira ano ";
    cin >> novo->dados.ano;
    cout << "\nInsira um mes:";
    cin >> novo->dados.mes;
    cout << "\nInsira um dia: ";
    cin >> novo->dados.dia;
    cout << "\nO valor";
    cin >>novo->dados.valor;
    novo->dados.valor = - novo->dados.valor;
    cout << "\nO codigo do tipo de movimento";
    cin >> novo->dados.codigo_tipo_movimento;
    cout << "\nInsira o seu id caso seja um condómino a pagar. Caso contrátrio, insira 0";
    cin >> novo->dados.origem_pagamento;
    if(novo->dados.origem_pagamento == 0) saldo_condominio += novo->dados.valor;
    else{
        lista_condo *aux = haha.procura(novo->dados.origem_pagamento);
        aux->dados.euros += novo->dados.valor;
    }
    cout << "\ndescricao do movimento:";
    cin >> novo->dados.descricao_movimento;
    if(cabeca == nullptr)
        cabeca = novo;
    else{
        no_lista *atual = cabeca;
        if( novo->dados.ano > atual->dados.ano){
        }
        novo->proximo = cabeca->proximo;
    }
    tipo_despesas(haha);
    return;

}
void lista_movimentos :: tipo_receitas(Condominos& haha){
    if(cabeca == nullptr){
        cout << "Nao há receitas\n";
        return;
    }
    int i = 2;
    no_lista* atual = cabeca;
    while(atual != nullptr){
        if(atual->dados.valor > 0)  {
                cout << i <<setw(10) << left << '.' << atual->dados.descricao_movimento << endl;
                i++;
        }
        atual = atual->proximo;
    }
    if(i == 2){ cout << "Nao há receitas" << endl; return;}
    int u;
    cout << "Saldo do Condomínio: " << saldo_condominio;
    cout << "\nEscolha o número adjacente à descricao caso queira saber mais informaçoes sobre essa receita"
            "\n1.Inserir receitas"
            "\n0.Sair";
    do{
        cin >> u;
    }while(!(u >= 0 && u <= i-1));
    if(u == 1){
        insere_receitas(haha);
        return;
    }
    if(u == 0) return;
    mostra_receitas(haha,u);
    return;
}
void lista_movimentos :: mostra_receitas(Condominos& haha,const int& u){
    int i = 2,k;
    no_lista* atual = cabeca;
    while(i != u){
        i++;
        atual = atual->proximo;
    }
    cout << "\nCodigo do movimento: " << atual->dados.id_movimento
         << "\nData: "     << atual->dados.data
         << "\nValor: " << atual->dados.valor
         <<"\nCodigo do tipo de movimento: " << atual->dados.codigo_tipo_movimento
         <<"\nOrigem do pagamento: " << atual->dados.origem_pagamento
         <<"\nDescricao do movimento: " << atual->dados.descricao_movimento;
    cout << "\n1. Modificar Receitas: "
            "\n0. Sair ";
    do{
        cin >> k;
    }while(!(k == 0 || k == 1));
    if(k == 0){
        tipo_receitas(haha);
        return;
    }
label1:
    cout << "\nQual Dado da despesa quer modificar? "
            "\n5.Valor:"
            "\n4.Codigo do movimento: "
            "\n3.Data:"
            "\n2.Codigo do tipo de movimento: "
            "\n1.Descricao do movimento: "
            "\n0.Sair ";
    cin >> k;
    switch(k){
    case 0:
        tipo_receitas(haha);
        return;
        break;
    case 1:
        cout << "\nInsira uma nova descrica do movimento: ";
        cin >> atual->dados.descricao_movimento;
        break;
    case 2:
        cout << "\nInsira um novo Codigo do tipo de movimento: ";
        cin >> atual->dados.id_movimento;
        break;
    case 3:
        cout <<"\nInsira uma nova data: ";
        cin >> atual->dados.data;
        break;
    case 4:
        cout <<"\nInsira um novo Codigo do movimento";
        cin >> atual->dados.codigo_tipo_movimento;
        break;
    case 5:{
        double aux = - atual->dados.valor;
        cout << "\nInsira o novo valor: ";
        cin >> atual->dados.valor;
        if(atual->dados.origem_pagamento == 0) saldo_condominio += aux + atual->dados.valor;
        else{
            lista_condo* auxs = haha.procura(atual->dados.origem_pagamento);
            auxs->dados.euros += aux + atual->dados.valor;
        }
    }
        break;
        goto label1;

    }

}

void lista_movimentos ::  insere_receitas(Condominos& haha){
    no_lista* novo = new no_lista;

    cout << "\nInsira o codigo do movimento:";
    cin >> novo->dados.id_movimento;
    cout << "\nA Data (aaaa-mm-dd)";
    cin >> novo->dados.data;
    cout << "\nO valor";
    cin >>novo->dados.valor;
    cout << "\nO codigo do tipo de movimento";
    cin >> novo->dados.codigo_tipo_movimento;
    cout << "\ndescricao do movimento:";
    cin >> novo->dados.descricao_movimento;

    cout <<"\nInsira o código do destinatário. Caso seja o condomínio,insira 0";
    cin >> novo->dados.origem_pagamento;
    if(novo->dados.origem_pagamento == 0) saldo_condominio += novo->dados.valor;
    else{
        lista_condo *aux = haha.procura(novo->dados.origem_pagamento);
        aux->dados.euros += novo->dados.valor;
    }
    if(cabeca == nullptr)
        cabeca = novo;

    else{
        novo->proximo = cabeca->proximo;
        cabeca->proximo = novo;
    }
    tipo_receitas(haha);
    return;
}
