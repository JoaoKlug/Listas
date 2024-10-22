
#include<cstdio>
#include "listaSeq.h"
#include "listaEnc.h"

#define FILE_PATH "./txt/NomeRG10.txt"

 int main(){

    FILE* file;
    ListaSeq sequencial;
    ListaEnc encadeada;

    file = fopen(FILE_PATH, "r");
    sequencial.setTam(file);

    file = fopen(FILE_PATH, "r");
    sequencial.preencher(file);

    sequencial.imprimir();
    
    sequencial.remover(4);
    sequencial.removerComeco();
    sequencial.removerFinal();
    
    sequencial.imprimir();

    /*file = fopen(FILE_PATH, "r");
    encadeada.preencher(file);

    encadeada.imprimir();*/

    return 0;
 }
