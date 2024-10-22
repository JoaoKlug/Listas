#include "listaEnc.h"

ListaEnc::ListaEnc(){

    pPrimPessoa = nullptr;

}

ListaEnc::~ListaEnc(){

    
}

void ListaEnc::preencher(FILE *file){

    PessoaEnc* pAux;
    PessoaEnc* pUltmPessoa;
    pPrimPessoa = new PessoaEnc;

    pAux = new PessoaEnc;

    
    fscanf(file, "%9[^,] , %d", pPrimPessoa->pessoa.nome, &(pPrimPessoa->pessoa.rg));
    
    fscanf(file, "%9[^,] , %d", pAux->pessoa.nome, &(pAux->pessoa.rg));


    pPrimPessoa->pPrxP = pAux;

    pUltmPessoa = pAux;

    pAux = new PessoaEnc;
    while(fscanf(file, "%9[^,] , %d", pAux->pessoa.nome, &(pAux->pessoa.rg)) != EOF){

        pUltmPessoa->pPrxP = pAux;
        pUltmPessoa = pAux;

        pAux = new PessoaEnc;
    }

    delete pAux;
    
}

void ListaEnc::imprimir(){

    PessoaEnc* pAux;

    pAux = pPrimPessoa;

    while(pAux->pPrxP != nullptr){

        printf("%s - RG: %d \n", pAux->pessoa.nome, pAux->pessoa.rg);
        pAux = pAux->pPrxP;
    }
    
}

void ListaEnc::inserirComeco(Pessoa pessoa){

}
void ListaEnc::inserirFinal(Pessoa pessoa){

}
void ListaEnc::inserir(Pessoa pessoa, long n){

}

void ListaEnc::removerComeco(){

}
void ListaEnc::removerFinal(){

}
void ListaEnc::remover(long n){

}