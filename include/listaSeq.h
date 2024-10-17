#include "pessoa.h"
#include<cstdio>

class ListaSeq {

    long tam;
    Pessoa* listaP;

    public:

    ListaSeq();
    ~ListaSeq(){ delete listaP; }

    void countLines(FILE* file);
    void preencherListaSeq(FILE* file);
    void imprimirListaSeq();

};


