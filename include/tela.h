#include <cstdio>
#include "listaSeq.h"
#include "listaEnc.h"
#include "pessoa.h"
#include "sort.h"

#include <iostream>
#include <limits>

using namespace std;

#define SEQ_FILE "./txt/SEQ.txt"
#define ENC_FILE "./txt/ENC.txt"
#define SORT_FILE "./txt/SORT.txt"

class Tela {

    const char* ARQUIVOS[7] = {
        "./txt/NomeRG10.txt",
        "./txt/NomeRG50.txt",
        "./txt/NomeRG100.txt",
        "./txt/NomeRG1K.txt",
        "./txt/NomeRG10K.txt",
        "./txt/NomeRG1M.txt",
        "./txt/NomeRG13M.txt"
    };
    
    const int TAMANHOS[7] = {
        10,
        50,
        100,
        1000,
        10000,
        1000000,
        13000000
    };

    FILE* file;
    ListaSeq sequencial;
    ListaEnc encadeada;
    Sort sort;

public:

    Tela();
    ~Tela();

    bool escolherArquivo();
    void escolherAcao();

    void crud();
    void sorts();
    void salvar();

    void ImprimeListaArquivos();
    void ImprimeOpcoesAcao();
    void ImprimeOpcoesCrud();
    void ImprimeOpcoesSort();
    void ImprimeOpcoesSalvar();
    void clearCin();

    void executar();
};