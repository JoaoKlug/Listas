#pragma once

#include "pessoa.h"
#include<cstdio>

class ListaEnc {

    int tam;
    PessoaEnc* pPrimPessoa;
    PessoaEnc* pUltmPessoa;

    float tempo;
    int n_condicoes;
    int n_atribuicoes;

    public:

    ListaEnc();
    ~ListaEnc(); //lebrar de aterrar todos os ponteiros

    void deleteList();

    void setTam(int t);
    void setPtrTempo(float *tmp);
    void setPtrCondicoes(int *nc);
    void setPtrAtribuicoes(int *na);

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