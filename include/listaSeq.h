#pragma once

#include "pessoa.h"
#include<cstdio>

class ListaSeq {

    long tam;
    Pessoa* listaSeq;

    public:

    ListaSeq();
    ~ListaSeq(){ delete listaSeq; }

    void countLines(FILE* file);
    void preencherListaSeq(FILE* file);
    void imprimirListaSeq();

};


