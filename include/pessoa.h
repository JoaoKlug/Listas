#pragma once

typedef struct{
    int rg = -1;
    char nome[10] = "";
} Pessoa;

typedef struct{
    Pessoa pessoa;
    Pessoa* pPrxP = nullptr;
}PessoaEnc;
