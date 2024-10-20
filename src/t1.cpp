
#include<cstdio>
#include "listaSeq.h"
#include "listaEnc.h"

#define FILE_PATH "./txt/NomeRG10.txt"

 int main(){

    FILE* file;
    ListaSeq seq;
    ListaEnc enc;

    file = fopen(FILE_PATH, "r");
    seq.countLines(file);

    file = fopen(FILE_PATH, "r");
    seq.preencherListaSeq(file);

    file = fopen(FILE_PATH, "r");
    enc.preencherListaEnc(file);

    seq.imprimirListaSeq();
    enc.imprimirListaEnc();

    return 0;
 }
