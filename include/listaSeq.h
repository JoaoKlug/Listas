#pragma once

#include "pessoa.h"
#include<cstdio>

class ListaSeq {

    long tam;
    Pessoa* listaSeq;

    public:

    ListaSeq();
    ~ListaSeq(){ delete listaSeq; }

    void setTam(FILE* file);
    void preencher(FILE* file);
    void imprimir();

    void inserirComeco(Pessoa pessoa);
    void inserirFinal(Pessoa pessoa);
    void inserir(Pessoa pessoa, long n);

    void removerComeco();
    void removerFinal();
    void remover(long n);

    

};


