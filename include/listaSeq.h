#pragma once

#include "pessoa.h"
#include<cstdio>

class ListaSeq {

    int tam;
    Pessoa* listaSeq;

    public:

    ListaSeq();
    ~ListaSeq();

    void deleteList();


    void setTam(int t);
    void preencher(FILE* file);
    void imprimir();

    void inserirInicio(Pessoa pessoa);
    void inserirFim(Pessoa pessoa);
    void inserir(Pessoa pessoa, int n);

    void removerInicio();
    void removerFim();
    void remover(int n);

};


