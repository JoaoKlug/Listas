#pragma once

#include "pessoa.h"
#include<cstdio>

class ListaEnc {

    PessoaEnc* pPrimPessoa;

    public:

    ListaEnc();
    ~ListaEnc(); //lebrar de aterrar todos os ponteiros

    void preencher(FILE* file);
    void imprimir();

    void inserirComeco(Pessoa pessoa);
    void inserirFinal(Pessoa pessoa);
    void inserir(Pessoa pessoa, long n);

    void removerComeco();
    void removerFinal();
    void remover(long n);
};