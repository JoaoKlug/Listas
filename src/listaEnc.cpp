#include "listaEnc.h"

ListaEnc::ListaEnc(){

    pPrimPessoa = nullptr;

}

ListaEnc::~ListaEnc(){

    
}

void ListaEnc::preencherListaEnc(FILE *file){

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

void ListaEnc::imprimirListaEnc(){

    
    
}