#ifndef CLISTATIPOMOVIMENTO_H
#define CLISTATIPOMOVIMENTO_H
#include "CTipoMovimento.h"

class lista_tipo {
    public:
        CTipoMovimento dados;
        lista_tipo *proximo;
};

class CListaTipoMovimento {
    private:
        lista_tipo * cabeca;
    public:
    CListaTipoMovimento();
    void inserir();
    void mostrarTodos() const;
    void modificar();
    bool procura(unsigned int cod) const;

};
#endif