#include "CTipoMovimento.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

CTipoMovimento::CTipoMovimento() {
    codigo = 0;
    descricao[0]='\0';
}
unsigned int CTipoMovimento::getCodigo() const {
    return codigo;
}
const char* CTipoMovimento::getDescricao() const {
    return descricao;
}
void CTipoMovimento::setCodigo(unsigned int cod) {
    codigo = cod;
}
void CTipoMovimento::setDescricao(const char* desc) {
    strncpy(descricao, desc, 20);
    descricao[20] = '\0';
}
void CTipoMovimento::mostrar() const {
    cout<<"id:"<<codigo<<"- descricao:"<< descricao<< endl;
}