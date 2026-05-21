#ifndef LISTA_MOVIMENTO_CONTA_H
#define LISTA_MOVIMENTO_CONTA_H
#include <iostream>
#include <iomanip>
using namespace std;
typedef struct{
    char identifica[4];
    char descreve[16];
    double permila;
    int proprietario;
}fracoes;

class CNoLista_fracoes{
public:
    fracoes Dados;
    CNoLista_fracoes *proximo;
};

class Lista_fracoes{
    void guarda_ficheiro(ofstream& ficheires,CNoLista_fracoes *pointer);
    CNoLista_fracoes *cabeca;
    int  permilagem_total;

public:
    int permilagem_tota();
    Lista_fracoes();
    void mostra_fracoes_descreve() ;
    void procura_fracao(int codigo) const;
    void mostra_fracao(int k) const;
    void insere_fracoes();
    void modificar_proprietario();
    int procura_fracao(int codigo);
};
#endif // LISTA_MOVIMENTO_CONTA_H
