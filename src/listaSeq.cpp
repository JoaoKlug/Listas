#include "listaSeq.h"

ListaSeq::ListaSeq(){

    tam = 0;
    listaSeq = nullptr;
}

ListaSeq::~ListaSeq(){
    deleteList();
}

void ListaSeq::deleteList(){

    if(listaSeq != nullptr){
       delete listaSeq;
       tam = 0;
       listaSeq = nullptr;
    }
}

void ListaSeq::setTam(int t){
    tam = t;
 }

void ListaSeq::preencher(FILE* file){

    int i;
    
    listaSeq = new Pessoa[tam];

    i = 0;
    while(fscanf(file, "%9[^,] , %d", listaSeq[i].nome, &listaSeq[i].rg) != EOF)
        i++;
}

void ListaSeq::imprimir(){

    int i;

    printf("\n----- Lista Sequencial -----\n\n");
    for(i = 0; i<tam; i++)
        printf("%s - rg: %d - %d\n", listaSeq[i].nome, listaSeq[i].rg, i);
    
    printf("----------------------------\n");
 }

void ListaSeq::inserirInicio(Pessoa pessoa){

    Pessoa* novaLista, *pAux;
    int i;
    
    novaLista = new Pessoa[tam+1];

    novaLista[0] = pessoa;

    for(i=0; i<tam; i++)
        novaLista[i+1] = listaSeq[i];

    pAux = listaSeq;
    listaSeq = novaLista;
    tam++;

    delete pAux;
}
void ListaSeq::inserirFim(Pessoa pessoa){

    Pessoa* novaLista, *pAux;
    int i;
    
    novaLista = new Pessoa[tam+1];

    novaLista[tam] = pessoa;

    for(i=0; i<tam; i++)
        novaLista[i] = listaSeq[i];

    pAux = listaSeq;
    listaSeq = novaLista;
    tam++;

    delete pAux;

}
void ListaSeq::inserir(Pessoa pessoa, int n){

    Pessoa* novaLista, *pAux;
    int i;
    
    novaLista = new Pessoa[tam+1];

    novaLista[n] = pessoa;

    for(i=0; i<tam; i++){
        if(i<n)
            novaLista[i] = listaSeq[i];
        else
            novaLista[i+1] = listaSeq[i];
    }

    pAux = listaSeq;
    listaSeq = novaLista;
    tam++;

    delete pAux;

}

void ListaSeq::removerInicio(){

    Pessoa* novaLista, *pAux;
    int i;
    
    novaLista = new Pessoa[tam-1];

    for(i=0; i<tam-1; i++)
        novaLista[i] = listaSeq[i+1];

    pAux = listaSeq;
    listaSeq = novaLista;
    tam--;

    delete pAux;

}
void ListaSeq::removerFim(){

    Pessoa *novaLista, *pAux;
    int i;
    
    novaLista = new Pessoa[tam-1];

    for(i=0; i<tam-1; i++)
        novaLista[i] = listaSeq[i];

    pAux = listaSeq;
    listaSeq = novaLista;
    tam--;

    delete pAux;

}
void ListaSeq::remover(int n){

    Pessoa* novaLista, *pAux;
    int i;
    
    novaLista = new Pessoa[(tam-1)];

    for(i=0; i<tam-1; i++){
        if(i<n)
            novaLista[i] = listaSeq[i];
        else
            novaLista[i] = listaSeq[i+1];
    }

    pAux = listaSeq;
    listaSeq = novaLista;
    tam--;

    delete pAux;

}

