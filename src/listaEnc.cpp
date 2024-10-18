#include "listaEnc.h"

ListaEnc::ListaEnc(){

    pPrimPessoa = nullptr;
    pUltmPessoa = nullptr;

}

ListaEnc::~ListaEnc(){

    
}

void ListaEnc::preencherListaEnc(FILE *file){

    PessoaEnc* pAux;
    pPrimPessoa = new PessoaEnc;

    pAux = new PessoaEnc;

    fscanf(file, "%9[^,] , %d", pPrimPessoa->pessoa.nome, &(pPrimPessoa->pessoa.rg));

    fscanf(file, "%9[^,] , %d", pAux->pessoa.nome, &(pAux->pessoa.rg));


    pPrimPessoa->pPrxP = &(pAux->pessoa);

    pUltmPessoa = pAux;

    pAux = new PessoaEnc;
    while(fscanf(file, "%9[^,] , %d", pAux->pessoa.nome, &(pAux->pessoa.rg)) != EOF){

        pUltmPessoa->pPrxP = &(pAux->pessoa);
        pUltmPessoa = pAux;

        pAux = new PessoaEnc;
    }

    pUltmPessoa->pPrxP = nullptr;
    
}

void ListaEnc::imprimirListaEnc(){

    
}