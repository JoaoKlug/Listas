#include "listaSeq.h"
#include <time.h>

ListaSeq::ListaSeq(){
    
    tam = 0;
    tempo = 0;
    n_atribuicoes = 0;
    n_condicoes = 0;
    listaSeq = nullptr;
}

ListaSeq::~ListaSeq(){
    deleteList();
}

void ListaSeq::deleteList(){

    if(listaSeq != nullptr){
       delete listaSeq;

       tam = 0;
       n_atribuicoes = 0;
       n_condicoes = 0;
       tempo = 0;
       listaSeq = nullptr;
    }
}

int ListaSeq::getTam(){
    return tam;
}

void ListaSeq::setTam(int t){
    tam = t;
}

void ListaSeq::preencher(FILE* file){

    clock_t t_1, t_2;
    int i;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    listaSeq = new Pessoa[tam];
    i = 0;
    while(fscanf(file, "%9[^,] , %d\n", listaSeq[i].nome, &listaSeq[i].rg) == 2){
        i++;
        n_condicoes++;
    }

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nSequencial -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void ListaSeq::imprimir(){

    clock_t t_1, t_2;
    int i;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    printf("\n----- Lista Sequencial -----\n\n");
    for(i = 0; i<tam; i++){
        printf("%s - rg: %d - %d\n", listaSeq[i].nome, listaSeq[i].rg, i);
        n_condicoes++;
    }

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nSequencial -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void ListaSeq::inserirInicio(Pessoa pessoa){

    Pessoa* novaLista, *pAux;
    clock_t t_1, t_2;
    int i;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;
    
    novaLista = new Pessoa[tam+1];

    novaLista[0] = pessoa;
    n_atribuicoes++;

    for(i=0; i<tam; i++){
        novaLista[i+1] = listaSeq[i];
        n_atribuicoes++;
        n_condicoes++;
    }
    pAux = listaSeq;
    n_atribuicoes++;

    listaSeq = novaLista;
    n_atribuicoes++;
    
    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC; 
    printf("\nSequencial-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    listaSeq[0].nome, listaSeq[0].rg, tempo, n_condicoes, n_atribuicoes, 0);

    tam++;
    delete pAux;
}

void ListaSeq::inserirFim(Pessoa pessoa){

    Pessoa* novaLista, *pAux;
    clock_t t_1, t_2;
    int i;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;
    
    novaLista = new Pessoa[tam+1];

    novaLista[tam] = pessoa;
    n_atribuicoes++;

    for(i=0; i<tam; i++){
        novaLista[i] = listaSeq[i];
        n_atribuicoes++;
        n_condicoes++;
    }
    pAux = listaSeq;
    n_atribuicoes++;

    listaSeq = novaLista;
    n_atribuicoes++;
   
    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nSequencial-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    listaSeq[tam].nome, listaSeq[tam].rg, tempo, n_condicoes, n_atribuicoes, tam);

    tam++;
    delete pAux;
}

void ListaSeq::inserir(Pessoa pessoa, int n){

    Pessoa* novaLista, *pAux;
    clock_t t_1, t_2;
    int i;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;
    
    novaLista = new Pessoa[tam+1];

    novaLista[n] = pessoa;
    n_atribuicoes++;

    for(i=0; i<tam; i++){
        n_atribuicoes++;
        n_condicoes++;
        if(i<n)
            novaLista[i] = listaSeq[i];
        else
            novaLista[i+1] = listaSeq[i];
        n_condicoes++;
    }
    pAux = listaSeq;
    n_atribuicoes++;

    listaSeq = novaLista;
    n_atribuicoes++;

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nSequencial-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    listaSeq[n].nome, listaSeq[n].rg, tempo, n_condicoes, n_atribuicoes, n);

    tam++;
    delete pAux;
}

void ListaSeq::removerInicio(){

    Pessoa* novaLista, *pAux;
    clock_t t_1, t_2;
    int i;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    novaLista = new Pessoa[tam-1];

    for(i=0; i<tam-1; i++){
        novaLista[i] = listaSeq[i+1];
        n_atribuicoes++;
        n_condicoes++;
    }
    pAux = listaSeq;
    n_atribuicoes++;

    listaSeq = novaLista;
    n_atribuicoes++;
    
    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nSequencial-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    pAux[0].nome, pAux[0].rg, tempo, n_condicoes, n_atribuicoes, 0);

    tam--;
    delete pAux;
}

void ListaSeq::removerFim(){

    Pessoa *novaLista, *pAux;
    clock_t t_1, t_2;
    int i;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;
    
    novaLista = new Pessoa[tam-1];

    for(i=0; i<tam-1; i++){
        novaLista[i] = listaSeq[i];
        n_atribuicoes++;
        n_condicoes++;
    }
    pAux = listaSeq;
    n_atribuicoes++;

    listaSeq = novaLista;
    n_atribuicoes++;

    

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nSequencial-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    pAux[tam-1].nome, pAux[tam-1].rg, tempo, n_condicoes, n_atribuicoes, tam-1);

    tam--;
    delete pAux;
}

void ListaSeq::remover(int n){

    Pessoa* novaLista, *pAux;
    clock_t t_1, t_2;
    int i;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;
    
    novaLista = new Pessoa[tam-1];

    for(i=0; i<tam-1; i++){
        n_condicoes++;
        n_atribuicoes++;
        if(i<n)
            novaLista[i] = listaSeq[i];
        else
            novaLista[i] = listaSeq[i+1];
        n_condicoes++;
    }

    pAux = listaSeq;
    n_atribuicoes++;

    listaSeq = novaLista;
    n_atribuicoes++;
    
    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    printf("\nSequencial-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
    pAux[n].nome, pAux[n].rg, tempo, n_condicoes, n_atribuicoes, n);

    tam--;
    delete pAux;
}

void ListaSeq::procurarPessoa(int rg){

    int i;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    for(i=0;i<tam;i++){
        n_condicoes++;
        if(listaSeq[i].rg == rg)
            break;
    }


    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;

    if(i==tam)
        printf("PESSOA NAO ENCONTRADA\n");
    else
        printf("\nSequencial-> Nome: %s | Rg: %d | Tempo: %fs | Condicoes: %d | Atribuicoes: %d | Posicao: %d\n",
        listaSeq[i].nome, listaSeq[i].rg, tempo, n_condicoes, n_atribuicoes, i);
}

void ListaSeq::salvarArquivo(FILE *file){
    
    int i;

    for(i=0; i<tam; i++)
        fprintf(file,"%s %d\n",listaSeq[i].nome,listaSeq[i].rg);
    
    printf("Sequencial-> SALVA COM SUCESSO\n");

}