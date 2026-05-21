TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CListaTipoMovimento.cpp \
        CTipoMovimento.cpp \
        condominos.cpp \
        executavel_condomino.cpp \
        lista_movimento_conta.cpp \
        lista_movimentos.cpp \
        main_listamovimento.cpp \
        main_tipo.cpp

HEADERS += \
    CListaTipoMovimento.h \
    CTipoMovimento.h \
    condominos.h \
    lista_movimento_conta.h \
    lista_movimentos.h
