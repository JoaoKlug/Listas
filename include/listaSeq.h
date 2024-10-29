#pragma once

#include "pessoa.h"
#include<cstdio>

class ListaSeq {

    int tam;
    Pessoa* listaSeq;

    float tempo;
    int n_condicoes;
    int n_atribuicoes;

    public:

    ListaSeq();
    ~ListaSeq();

    void deleteList();

    void setTam(int t);
    int getTam();
    
    void preencher(FILE* file);
    void imprimir();

    void inserirInicio(Pessoa pessoa);
    void inserirFim(Pessoa pessoa);
    void inserir(Pessoa pessoa, int n);

    void removerInicio();
    void removerFim();
    void remover(int n);

    void procurarPessoa(int rg);
    void salvarArquivo(FILE *file);

};


