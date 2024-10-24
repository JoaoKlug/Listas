
#include<cstdio>
#include "listaSeq.h"
#include "listaEnc.h"
#include "pessoa.h"
#include <iostream>
using namespace std;

#define FILE_PATH "./txt/NomeRG10.txt"

static const char* ARQUIVOS[7] =
{
   "./txt/NomeRG10.txt",
   "./txt/NomeRG50.txt",
   "./txt/NomeRG100.txt",
   "./txt/NomeRG1K.txt",
   "./txt/NomeRG10K.txt",
   "./txt/NomeRG1M.txt",
   "./txt/NomeRG13M.txt"
};

static int TAMANHOS[7]= 
{
   10,
   50,
   100,
   1000,
   10000,
   1000000,
   13000000
};

void ImprimeListaArquivos();
void ImprimeOpcoes();

int main(){

   FILE* file;
   ListaSeq sequencial;
   ListaEnc encadeada;
   Pessoa pessoa;
   int idxArqv, opcao, n, rg;


   idxArqv = -2;
   opcao = 10;

   while(idxArqv !=-1 ){

      ImprimeListaArquivos();
      cin >> idxArqv;

      if(idxArqv>6 || idxArqv<-1){
         cout << "OPCAO INVALIDA - DIGITE NOVAMENTE" << endl;
         fflush (stdin) ;
         getchar();
      }
      else if(idxArqv != -1){
         sequencial.setTam(TAMANHOS[idxArqv]);

         file = fopen(ARQUIVOS[idxArqv], "r");
         sequencial.preencher(file);

         file = fopen(ARQUIVOS[idxArqv], "r");
         encadeada.preencher(file);

         opcao = 0;
      }
         

      while(opcao != 10){

         ImprimeOpcoes();
         cin >> opcao;

         switch (opcao){
            case 1:

               cout << "Nome (10): ";
               cin >> pessoa.nome;
               cout << "RG (9): ";
               cin >> pessoa.rg;

               sequencial.inserirInicio(pessoa);
               encadeada.inserirInicio(pessoa);

               break;
            case 2:

               cout << "Nome(10): ";
               cin >> pessoa.nome;
               cout << "RG(9): ";
               cin >> pessoa.rg;

               
               encadeada.inserirFim(pessoa);
               sequencial.inserirFim(pessoa);

               fflush (stdin);
               getchar();

               break;
            case 3:

               cout << "Nome(10): "; 
               cin >> pessoa.nome;
               cout << "RG(9): ";
               cin >> pessoa.rg;
               cout << "Posicao N - max " << TAMANHOS[idxArqv]-1 << " :" <<endl;
               cin >> n;

               sequencial.inserir(pessoa,n);
               encadeada.inserir(pessoa,n);

               break;
            case 4:

               sequencial.removerInicio();
               encadeada.removerInicio();
               
               break;
            case 5:

               sequencial.removerFim();
               encadeada.removerFim();

               break;
            case 6:

               cout << "Posicao N - max " << TAMANHOS[idxArqv]-1 << " :" <<endl;
               cin >> n;

               sequencial.remover(n);
               encadeada.remover(n);

               break;
            case 7:

               cout << "RG(9): " << endl;
               cin >> rg;

               break;
            case 8:

               sequencial.imprimir();
               fflush (stdin) ;
               getchar();

               encadeada.imprimir();

               fflush (stdin) ;
               getchar();
               break;
            case 9:

               //fwrite
               break;
            default:
               cout << "OPCAO INVALIDA - DIGITE NOVAMENTE" << endl;
               fflush (stdin) ;
               getchar();
         }
      }

      sequencial.deleteList();
      encadeada.deleteList();
   }

   return 0;
}


void ImprimeListaArquivos(){

   system("clear");
   cout <<"---- ESCOLHA UM ARQUIVO ----"<< endl;
   cout <<"0 - Arquivo com 10 dados"<< endl;
   cout <<"1 - Arquivo com 50 dados"<< endl;
   cout <<"2 - Arquivo com 100 dados"<< endl;
   cout <<"3 - Arquivo com 1k dados"<< endl;
   cout <<"4 - Arquivo com 10k dados"<< endl;
   cout <<"5 - Arquivo com 1M dados"<< endl;
   cout <<"6 - Arquivo com 13M dados"<< endl;
   cout <<"*DIGITE -1 PARA SAIR*"<< endl;
   cout <<"Arquivo 0-6:";
}

void ImprimeOpcoes(){

   system("clear");
   cout <<"---- MENU OPCOES ----"<< endl;
   cout <<"1 - Inserir nó no INICIO"<< endl;
   cout <<"2 - Inserir nó no FIM"<< endl;
   cout <<"3 - Inserir nó na posicao N"<< endl;
   cout <<"4 - Remover nó no INICIO"<< endl;
   cout <<"5 - Remover nó no FIM"<< endl;
   cout <<"6 - Remover nó na posicao N"<< endl;
   cout <<"7 - Procurar um nó com o RG"<< endl;
   cout <<"8 - Mostrar lista na Tela"<< endl;
   cout <<"9 - Salvar lista em um Arquivo"<< endl;
   cout <<"10 - Ler outro Arquivo"<< endl;
   cout <<"Opcao (1-10):";
}
