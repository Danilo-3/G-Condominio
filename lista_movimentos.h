#ifndef LISTA_MOVIMENTOS_H
#define LISTA_MOVIMENTOS_H
#include "condominos.h"
#include "lista_movimento_conta.h"
#include "CListaTipoMovimento.h"
typedef struct{
    unsigned int id_movimento,codigo_tipo_movimento,origem_pagamento;
    char data[11],descricao_movimento[31];
    double valor;
}move_contas;

class no_lista{
public:
    move_contas dados;
    no_lista *proximo;
};

class lista_movimentos
{
    void guarda_ficheiro(ofstream& ficheiro,no_lista *ponteiro);
    double saldo_condominio;
    no_lista *cabeca;
public:
    lista_movimentos();
    void tipo_despesas(Condominos& haha);
    void insere_despesas(Condominos&);
    void mostra_despesa(Condominos&,const int&);

    void tipo_receitas(Condominos& haha);
    void insere_receitas(Condominos&);
    void mostra_receitas(Condominos&,const int&);

    void Resumo_do_ano(const Condominos&,const CListaTipoMovimento&);
    void abertura_do_ano(); //valor do orçamento do ano e o saldo inicial da conta

};

#endif // LISTA_MOVIMENTOS_H
