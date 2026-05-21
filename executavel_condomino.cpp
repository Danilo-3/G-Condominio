#include "lista_movimentos.h"

int main(){
    Condominos A;
    lista_movimentos B;
    Lista_fracoes listas;
    CListaTipoMovimento lista;
    int op;

inicio:
        cout << "Pressione 1 para iniciar o programa gestao de condomínio\n"
                "Trabalho Realizado por: \nDanilo Lima Brito\n"
                "Kaíke Aléssio Olímpio de Souza\n"
                "Data de realizacao: 20/05/2026\n";
        cin >> op;

        loop:
            cout << "1. Fraçoes"
                "\n2.Condóminos"
                "\n3.Tipo de Despesas"
                "\n4.Abertura do ano"
                "\n5.Receita"
                "\n6.Despesa\n"
                "7.Resumo do ano\n"
                "8. Sair\n";
            do{
                cin >> op;
            }while(!(op >= 1 && op <= 8));
            if(op == 8) goto inicio;
            switch(op){
                case 1:
                do{
                    cout<<"1. ver todas as fracoes\n";
                    cout<<"2. inserir fracao\n";
                    cout<<"3. modificar proprietario\n";
                    cout<<"0. sair\n";
                    cout<<"opcao: ";
                    cin>>op;

                    if(op == 1)
                        listas.mostra_fracoes_descreve();
                    else if(op == 2)
                        listas.insere_fracoes();
                    else if(op == 3)
                        listas.modificar_proprietario();
                    else if(op != 0)
                        cout << "opcao invalida!\n";

                } while(op != 0);
                break;
                case 2:
                    A.mostra_nomes();
                    break;
                case 3:
                    do {
                        cout<<"1. ver todos os tipos\n";
                        cout<<"2. inserir tipo\n";
                        cout<<"3. modificar tipo\n";
                        cout<<"0. sair\n";
                        cout<<"opcao: ";
                        cin>>op;

                        if(op == 1)
                            lista.mostrarTodos();
                        else if(op == 2)
                            lista.inserir();
                        else if(op == 3)
                            lista.modificar();
                        else if(op != 0)
                            cout << "opcao invalida!\n";

                    } while(op != 0);
                    break;
                }
                if(listas.permilagem_tota() != 1000){
                    cout << "Nao e possivel acessar essas opcoes por a permilagem total é diferente de mil" << endl;
                    goto loop;
                }
                switch (op){
                case 6:
                    B.tipo_despesas(A);
                    break;
                case 5:
                    B.tipo_receitas(A);
                    break;
                goto loop;
                }
    return 0;
}

