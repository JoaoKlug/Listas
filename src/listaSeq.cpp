#include "listaSeq.h"

ListaSeq::ListaSeq(){

    tam = 0;
    listaSeq = nullptr;
}

void ListaSeq::setTam(FILE* file){

    long lines;
    char ch;

    lines = 0;
    while((ch = fgetc(file))!= EOF){
        if(ch == '\n')
            lines++;
    }

    tam = lines;
 }

void ListaSeq::preencher(FILE* file){

    listaSeq = new Pessoa[tam];

    long i;

    i = 0;
    while(fscanf(file, "%9[^,] , %d", listaSeq[i].nome, &listaSeq[i].rg) != EOF)
        i++;

}

void ListaSeq::imprimir(){

     long i;
     for(i = 0; i<tam; i++)
        printf("\n%ld %s %d\n", i ,listaSeq[i].nome, listaSeq[i].rg);
    
     printf("\n--------------------------------------\n");
 }

void ListaSeq::inserirComeco(Pessoa pessoa){

    Pessoa* novaLista, *pAux;
    long i;
    
    novaLista = new Pessoa[tam+1];

    novaLista[0] = pessoa;

    for(i=0; i<tam; i++)
        novaLista[i+1] = listaSeq[i];

    pAux = listaSeq;
    listaSeq = novaLista;
    tam++;

    delete pAux;
}
void ListaSeq::inserirFinal(Pessoa pessoa){

    Pessoa* novaLista, *pAux;
    long i;
    
    novaLista = new Pessoa[tam+1];

    novaLista[tam] = pessoa;

    for(i=0; i<tam; i++)
        novaLista[i] = listaSeq[i];

    pAux = listaSeq;
    listaSeq = novaLista;
    tam++;

    delete pAux;

}
void ListaSeq::inserir(Pessoa pessoa, long n){

    Pessoa* novaLista, *pAux;
    long i;
    
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

void ListaSeq::removerComeco(){

    Pessoa* novaLista, *pAux;
    long i;
    
    novaLista = new Pessoa[tam-1];

    for(i=0; i<tam-1; i++)
        novaLista[i] = listaSeq[i+1];

    pAux = listaSeq;
    listaSeq = novaLista;
    tam--;

    delete pAux;

}
void ListaSeq::removerFinal(){

    Pessoa *novaLista, *pAux;
    long i;
    
    novaLista = new Pessoa[tam-1];

    for(i=0; i<tam-1; i++)
        novaLista[i] = listaSeq[i];

    pAux = listaSeq;
    listaSeq = novaLista;
    tam--;

    delete pAux;

}
void ListaSeq::remover(long n){

    Pessoa* novaLista, *pAux;
    long i;
    
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

