#ifndef CONDOMINOS_H
#define CONDOMINOS_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "lista_movimento_conta.h"
using namespace std;

typedef struct{

    unsigned int codigo;
    string nome,morada,gmail;
    int telefone;
    double euros; //valor do condómino
}condomino;

class lista_condo{
public:
    condomino dados;
    lista_condo *proximo;
};


class Condominos{
    void guarda_ficheiro(ofstream& ficheiro,lista_condo *ponteiro);
    lista_condo *cabeca;
public:

    Condominos();
    ~Condominos();
    void deleta_condomino(lista_condo *k,int);
    void pede_dados(); //Quando a pessoa quiser adicionar um condomino
    void mostra_tudo(int k) ;
    void mostra_nomes() ;
    void altera_dados(lista_condo *atu, int );
    bool procura(unsigned int codigos) const;
    lista_condo* procura(unsigned int codigos) ;
};

#endif // CONDOMINOS_H
