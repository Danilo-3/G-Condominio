#include "condominos.h"

Condominos ::   ~Condominos(){
    lista_condo *atual,*proxismo;
    atual = cabeca;
    while(atual != nullptr){
        proxismo = atual->proximo;
        delete atual;
        atual = proxismo;
    }
}
Condominos :: Condominos(){
    cabeca = nullptr;
}
void guarda_ficheiro(ofstream& ficheiro, lista_condo *ponteiro) {

    ficheiro << "id: " << ponteiro->dados.codigo
             << "\nNome: " << ponteiro->dados.nome
             << "\nmorada: " << ponteiro->dados.morada
             <<"\nemail: " << ponteiro->dados.gmail
             <<"\nTelefone: " << ponteiro->dados.telefone
             <<"\nSaldo: " << ponteiro->dados.euros << "€" << endl;
}

void Condominos :: mostra_nomes(){

    if(cabeca == nullptr){
        cout << "A lista de condominos está vazia;" << endl;
        return;
    }
    ofstream ficheiro("lista_condomino.txt");
    int i = 2;
    lista_condo *atual = cabeca;
    while(atual != nullptr){
                 cout   << i << setw(10) << left << "."  <<  atual->dados.nome << endl;
                 guarda_ficheiro(ficheiro,atual);
                 atual = atual->proximo;
                 i++;

        }
    ficheiro.close();
    int u;
    cout <<
        "Escolha o número adjacente ao Nome caso queira saber mais informaçoes sobre esse usuário"
        "\n1. Novo condomino"
        "\n0. Voltar";
    do{
        cin >> u;
    }while(!((u >= 0) || u <= i-1));
    if(u == 0) return;
    if(u == 1){
        pede_dados();
        return;
    }
    mostra_tudo(u);
    return;
}

void Condominos :: mostra_tudo(int k){
    lista_condo *atual = cabeca;
    int i = 2;
    while(i != k){
        i++;
        atual = atual->proximo;
    }
            cout << "Dados associados a esse id:\n"
                << "Nome: " << atual->dados.nome
                 << "\nmorada: " << atual->dados.morada
                 <<"\nemail: " << atual->dados.gmail
                 <<"\nTelefone: " << atual->dados.telefone

                 <<"\nSaldo: " << atual->dados.euros << "€" << endl;
    char m;
    cout << "2. Alterar dados"
            "\n1. Eliminar Condomino"
            "\n0. Voltar";
    do{
             cin >> m;
    }while(!('0' <= m || m <= '2'));
    if(m == '0'){ mostra_nomes(); return;}
    if(m == '1'){ deleta_condomino(atual,k); return;}
    if(m == '2'){ altera_dados(atual,k); return;}
}



void Condominos :: altera_dados(lista_condo *atu, int d){
    char m;
    label:
        cout << "Qual dado pretende alterar?"
            "\n5. ID: " <<  atu->dados.codigo <<
            "\n4. Morada: " << atu->dados.morada <<
            "\n3. email" << atu->dados.gmail <<
            "\n2. Telefone" << atu->dados.telefone <<
            "\n1. euros" << atu->dados.euros <<
            "\n0. Sair\n";
    do{
        cin >>m;
    }while(m > '5' || m < '0');
    if(m == 0){ mostra_tudo(d); return;}
    switch(m){
                case '5':
                    cout <<"Insira um novo id:\n";
                    cin >>atu->dados.codigo;
                    break;
                case '4':
                    cout << "Insira a nova morada:\n";
                    cin >> atu->dados.morada;
                    break;
                case '3':
                    cout << "Insira um nome gmail";
                    cin >> atu->dados.gmail;
                    break;
                case '2':
                    cout << "Insira o novo telefone";
                    cin >> atu->dados.telefone;
                    break;
                case '1':
                    cout << "Insira o novo saldo";
                    cin >> atu->dados.euros;
                    break;
                }
    goto label;

}




void Condominos :: deleta_condomino(lista_condo *k,int d){
    lista_condo *atual = cabeca;
    lista_condo *anterior = nullptr;
    while(atual != nullptr){
        if(atual == k){
            if(anterior == nullptr)
                 cabeca = atual->proximo;
            else
                anterior->proximo = atual->proximo;
            delete atual;
            return;
    }
        anterior = atual;
        atual = atual->proximo;

    }
    mostra_tudo(d);
    return;
}
bool Condominos :: procura(unsigned int codigos) const{
    if(cabeca == nullptr){
        return false;
    }
    lista_condo *atual = cabeca;
    while(atual != nullptr){
        if(atual->dados.codigo == codigos) return true;
        atual = atual->proximo;
        }
    return false;
}
lista_condo* Condominos :: procura(unsigned int codigos){
    lista_condo *atual = cabeca;
    while(atual != nullptr){
        if(atual->dados.codigo == codigos) return atual;
        atual = atual->proximo;
    }
    return nullptr;
}

void Condominos :: pede_dados(){
    lista_condo *novo = new lista_condo;

    do{
        cout << "Insira um id:";
        cin >> novo->dados.codigo;
        if(procura(novo->dados.codigo)) cout << "Esse id já existe" << endl;
    }while(procura(novo->dados.codigo) || novo->dados.codigo == 0);

    cout << "insira o seu nome\n";
    cin >> novo->dados.nome;

    cout << "\nInsira um telefone (utilize apenas numeros):\n";
    cin >> novo->dados.telefone;

    cout << "\ninsira uma morada:\n";
    cin >> novo->dados.morada;
    cout << "\nInsira um email:\n";
    cin >> novo->dados.gmail;

    if(cabeca == nullptr)cabeca = novo;
    else{
        lista_condo *atual = cabeca;
        novo->proximo = atual->proximo;
        atual->proximo = novo;
}
    mostra_nomes();
    return;

}

