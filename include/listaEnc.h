#pragma once

#include "pessoa.h"
#include<cstdio>

class ListaEnc {

    PessoaEnc* pPrimPessoa;
    PessoaEnc* pUltmPessoa;

    public:

    ListaEnc();
    ~ListaEnc(); //lebrar de aterrar todos os ponteiros

    void deleteList();

    void preencher(FILE* file);
    void imprimir();

    void inserirInicio(Pessoa pessoa);
    void inserirFim(Pessoa pessoa);
    void inserir(Pessoa pessoa, int n);

    void removerInicio();
    void removerFim();
    void remover(int n);
};