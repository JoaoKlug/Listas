#include "listaEnc.h"
#include <time.h>

ListaEnc::ListaEnc(){
    pPrimPessoa = nullptr;
    pUltmPessoa = nullptr;
    
    tam = 0;
    tempo = 0;
    n_atribuicoes = 0;
    n_condicoes = 0;
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
        tam = 0;
        tempo = 0;
        n_atribuicoes = 0;
        n_condicoes = 0;
    }
}

void ListaEnc::setTam(int t){
    tam = t;
}

void ListaEnc::preencher(FILE *file){

    PessoaEnc* pAux;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;
    
    pPrimPessoa = new PessoaEnc;
    pAux = new PessoaEnc;
    
    fscanf(file, "%9[^,] , %d\n", pPrimPessoa->pessoa.nome, &(pPrimPessoa->pessoa.rg));
    
    fscanf(file, "%9[^,] , %d\n", pAux->pessoa.nome, &(pAux->pessoa.rg));


    pPrimPessoa->pPrxP = pAux;
    n_atribuicoes++;
    pUltmPessoa = pAux;
    n_atribuicoes++;

    pAux = new PessoaEnc;
    while(fscanf(file, "%9[^,] , %d\n", pAux->pessoa.nome, &(pAux->pessoa.rg)) == 2){ 

        
        pUltmPessoa->pPrxP = pAux;
        n_atribuicoes++;
        pUltmPessoa = pAux;
        n_atribuicoes++;

        n_condicoes++;
        pAux = new PessoaEnc;
    }

    delete pAux;
    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nEncadeada -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void ListaEnc::imprimir(){

    PessoaEnc* pAux;
    int i;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    pAux = pPrimPessoa;
    i = 0;

    printf("\n----- Lista Encadeada -----\n");
    while(pAux != nullptr){

        printf("%s - rg: %d - %d\n", pAux->pessoa.nome, pAux->pessoa.rg, i);
        pAux = pAux->pPrxP;

        n_atribuicoes++;
        n_condicoes++;
        i++;
    }

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nEncadeada -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void ListaEnc::inserirInicio(Pessoa pessoa){

    PessoaEnc* pPessoaNova, *pAux;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    pPessoaNova = new PessoaEnc;
    pPessoaNova->pessoa = pessoa;
    n_atribuicoes++;

    pAux = pPrimPessoa;
    n_atribuicoes++;
    pPrimPessoa = pPessoaNova;
    n_atribuicoes++;
    pPrimPessoa->pPrxP = pAux;
    n_atribuicoes++;

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nEncadeada-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    pPrimPessoa->pessoa.nome, pPrimPessoa->pessoa.rg, tempo, n_condicoes, n_atribuicoes, 0);

    tam++;
}

void ListaEnc::inserirFim(Pessoa pessoa){ 

    PessoaEnc *pPessoaNova;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    pPessoaNova = new PessoaEnc;
    pPessoaNova->pessoa = pessoa;
    n_atribuicoes++;

    pUltmPessoa->pPrxP = pPessoaNova;
    n_atribuicoes++;
    pUltmPessoa = pPessoaNova;
    n_atribuicoes++;

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nEncadeada-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    pUltmPessoa->pessoa.nome, pUltmPessoa->pessoa.rg, tempo, n_condicoes, n_atribuicoes, tam);

    tam++;
}

void ListaEnc::inserir(Pessoa pessoa, int n){ 
    
    PessoaEnc *pPessoaNova , *pAux;
    int i;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    pPessoaNova = new PessoaEnc;
    pPessoaNova->pessoa = pessoa;
    n_atribuicoes++;
    
    pAux = pPrimPessoa;   
    for(i=0;i<n-1;i++){
        pAux = pAux->pPrxP;
        n_atribuicoes++;
        n_condicoes++;
    }
        

    pPessoaNova->pPrxP = pAux->pPrxP;
    n_atribuicoes++;
    pAux->pPrxP = pPessoaNova;
    n_atribuicoes++;

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nEncadeada-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    pPessoaNova->pessoa.nome, pPessoaNova->pessoa.rg, tempo, n_condicoes, n_atribuicoes, n);

    tam++;
}

void ListaEnc::removerInicio(){

    PessoaEnc *pAux;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    pAux = pPrimPessoa;
    n_atribuicoes++;
    pPrimPessoa = pAux->pPrxP;
    n_atribuicoes++;

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nEncadeada-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    pAux->pessoa.nome, pAux->pessoa.rg, tempo, n_condicoes, n_atribuicoes, 0);
    
    tam--;
    delete pAux;
}

void ListaEnc::removerFim(){
    
    PessoaEnc *pAtual, *pAux;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    pAtual = pPrimPessoa;
    while(pAtual->pPrxP != pUltmPessoa){
        pAtual = pAtual->pPrxP;
        n_atribuicoes++;
        n_condicoes++;
    }
        

    pAux = pUltmPessoa;
    n_atribuicoes++;

    pUltmPessoa = pAtual;
    n_atribuicoes++;
    pUltmPessoa->pPrxP = nullptr;

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nEncadeada->Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    pAux->pessoa.nome, pAux->pessoa.rg, tempo, n_condicoes, n_atribuicoes, tam-1);
    
    tam--;
    delete pAux;

}

void ListaEnc::remover(int n){

    PessoaEnc *pAtual, *pAux;
    int i;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    pAtual = pPrimPessoa;
    n_atribuicoes++;
    for(i=0;i<n-1; i++){
        pAtual = pAtual->pPrxP;
        n_atribuicoes++;
        n_condicoes++;
    }
        

    pAux = pAtual->pPrxP;
    n_atribuicoes++;
    pAtual->pPrxP = pAux->pPrxP;
    n_atribuicoes++;

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nEncadeada-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n", 
    pAux->pessoa.nome, pAux->pessoa.rg, tempo, n_condicoes, n_atribuicoes, n);

    tam--;
    delete pAux;
}

void ListaEnc::procurarPessoa(int rg){
    
    PessoaEnc *pAux;
    pAux = pPrimPessoa;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    int i = 0;
    while(pAux != nullptr){
        
        n_condicoes++;
        if(pAux->pessoa.rg == rg)
            break;
        
        pAux = pAux->pPrxP;
        n_atribuicoes++;

        i++;
    }

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
        
    if(pAux != nullptr)
        printf("\nEncadeada-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
        pAux->pessoa.nome, pAux->pessoa.rg, tempo, n_condicoes, n_atribuicoes, i);
    else
        printf("PESSOA NAO ENCONTRADA\n");
}

void ListaEnc::salvarArquivo(FILE *file){
    PessoaEnc *pAux;

    pAux = pPrimPessoa;

    while(pAux != nullptr){
        fprintf(file,"%s %d\n", pAux->pessoa.nome, pAux->pessoa.rg);
        pAux = pAux->pPrxP;
    }

    printf("Encadeada-> SALVA COM SUCESSO\n");
}