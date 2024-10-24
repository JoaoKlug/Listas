#include "listaEnc.h"

ListaEnc::ListaEnc(){
    pPrimPessoa = nullptr;
    pUltmPessoa = nullptr;
}

ListaEnc::~ListaEnc(){
    deleteList();
}

void ListaEnc::deleteList(){

    PessoaEnc *pAux, *pAtual;

    if(pPrimPessoa != nullptr && pUltmPessoa != nullptr)
    {
        pAux = pPrimPessoa;
        
        while(pAux != nullptr){

            pAtual = pAux;
            pAux = pAux->pPrxP;

            delete pAtual;
        }

        pPrimPessoa = nullptr;
        pUltmPessoa = nullptr;
    }
}

void ListaEnc::preencher(FILE *file){

    PessoaEnc* pAux;
    
    pPrimPessoa = new PessoaEnc;
    pAux = new PessoaEnc;
    
    fscanf(file, "%9[^,] , %d", pPrimPessoa->pessoa.nome, &(pPrimPessoa->pessoa.rg));
    
    fscanf(file, "%9[^,] , %d", pAux->pessoa.nome, &(pAux->pessoa.rg));


    pPrimPessoa->pPrxP = pAux;
    pUltmPessoa = pAux;

    pAux = new PessoaEnc;
    while(fscanf(file, "%9[^,] , %d", pAux->pessoa.nome, &(pAux->pessoa.rg)) == 2){ 

        pUltmPessoa->pPrxP = pAux;
        pUltmPessoa = pAux;

        pAux = new PessoaEnc;
    }

    delete pAux;
}

void ListaEnc::imprimir(){

    PessoaEnc* pAux;
    int i;


    pAux = pPrimPessoa;
    i = 0;

    printf("\n----- Lista Encadeada -----\n");
    while(pAux != nullptr){

        printf("%s - rg: %d - %d\n", pAux->pessoa.nome, pAux->pessoa.rg, i);
        pAux = pAux->pPrxP;
        i++;
    }
    printf("---------------------------\n");

}

void ListaEnc::inserirInicio(Pessoa pessoa){

    PessoaEnc* pPessoaNova, *pAux;

    pPessoaNova = new PessoaEnc;
    pPessoaNova->pessoa = pessoa;

    pAux = pPrimPessoa;
    pPrimPessoa = pPessoaNova;
    pPrimPessoa->pPrxP = pAux;
}
void ListaEnc::inserirFim(Pessoa pessoa){ 

    PessoaEnc *pPessoaNova;

    pPessoaNova = new PessoaEnc;
    pPessoaNova->pessoa = pessoa;

    pUltmPessoa->pPrxP = pPessoaNova;
    pUltmPessoa = pPessoaNova;

}
void ListaEnc::inserir(Pessoa pessoa, int n){ // n != incio e fim
    
    PessoaEnc *pPessoaNova , *pAux;
    int i;

    pPessoaNova = new PessoaEnc;
    pPessoaNova->pessoa = pessoa;
    
    pAux = pPrimPessoa;   
    for(i=0;i<n;i++)
        pAux = pAux->pPrxP;

    pPessoaNova->pPrxP = pAux->pPrxP;
    pAux->pPrxP = pPessoaNova;

}

void ListaEnc::removerInicio(){

    PessoaEnc *pAux;

    pAux = pPrimPessoa;

    pPrimPessoa = pAux->pPrxP;

    delete pAux;

}
void ListaEnc::removerFim(){
    
    PessoaEnc *pAtual, *pAux;

    pAtual = pPrimPessoa;
    while(pAtual->pPrxP != pUltmPessoa)
        pAtual = pAtual->pPrxP;

    pAux = pUltmPessoa;
    pUltmPessoa = pAtual;
    pUltmPessoa->pPrxP = nullptr;

    delete pAux;

}
void ListaEnc::remover(int n){

    PessoaEnc *pAtual, *pAux;
    int i;

    pAtual = pPrimPessoa;
    for(i=0;i<n-1; i++)
        pAtual = pAtual->pPrxP;

    pAux = pAtual->pPrxP;
    pAtual->pPrxP = pAux->pPrxP;

    delete pAux;
}