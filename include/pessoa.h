#pragma once

typedef struct{
    int rg = -1;
    char nome[10] = "";
} Pessoa;

struct PessoaEnc{
    Pessoa pessoa;
    PessoaEnc* pPrxP = nullptr;
};
