
#include<cstdio>
#include "listaSeq.h"

#define FILE_PATH "./txt/NomeRG10.txt"

 int main(){

    FILE* file;
    ListaSeq seq;

    file = fopen(FILE_PATH, "r");

    seq.countLines(file);

    file = fopen(FILE_PATH, "r");

    seq.preencherListaSeq(file);

    seq.imprimirListaSeq();

    return 0;
 }
