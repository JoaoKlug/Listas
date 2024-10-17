#include "listaSeq.h"

ListaSeq:: ListaSeq(){

    tam = 0;
    listaP = nullptr;
}

void ListaSeq:: countLines(FILE* file){

    long lines;
    char ch;

    lines = 0;
    while((ch = fgetc(file))!= EOF){
        if(ch == '\n')
            lines++;
    }

    tam = lines;
 }

void ListaSeq:: preencherListaSeq(FILE* file){

    listaP = new Pessoa[tam];

    int i;

    i = 0;
    while(fscanf(file, "%9[^,] , %d", listaP[i].nome, &listaP[i].rg) != EOF)
        i++;

}

void ListaSeq:: imprimirListaSeq(){

     int i;
     for(i = 0; i<tam; i++)
        printf("%s  %d \n", listaP[i].nome, listaP[i].rg);
 }

