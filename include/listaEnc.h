#pragma once

#include "pessoa.h"
#include<cstdio>

class ListaEnc {

    PessoaEnc* pPrimPessoa;
    PessoaEnc* pUltmPessoa;

    public:

    ListaEnc();
    ~ListaEnc(); //lebrar de aterrar todos os ponteiros

    void preencherListaEnc(FILE* file);
    void imprimirListaEnc();

};