#ifndef CTIPOMOVIMENTO_H
#define CTIPOMOVIMENTO_H

class CTipoMovimento{
private:
    unsigned int codigo;
    char descricao[21];

public:
    CTipoMovimento();
        
    unsigned int getCodigo() const;
    const char * getDescricao() const;

    void setCodigo(unsigned int cod);
    void setDescricao(const char* desc);
    
    void mostrar() const;

};

#endif