#include "tela.h"

Tela::Tela(){
    file = nullptr;
}

Tela::~Tela(){
    file = nullptr;
}

void Tela::executar(){

   while(escolherArquivo()){
            
      escolherAcao();

      if(sort.getListSort())
        sort.deleteList();
      
      sequencial.deleteList();
      encadeada.deleteList();
   }
}

bool Tela::escolherArquivo(){

    int idxArqv;
    bool flag = true;

    while(flag){

        flag = false;

        ImprimeListaArquivos();
        cin >> idxArqv;
        clearCin();

        if(idxArqv == -1)
            return false;

        if(idxArqv>6 || idxArqv<-1){

            cout << "OPCAO INVALIDA - DIGITE NOVAMENTE" << endl;
            getchar();
            flag = true;
        }
        else if(idxArqv != -1){

            sequencial.setTam(TAMANHOS[idxArqv]);
            encadeada.setTam(TAMANHOS[idxArqv]);

            file = fopen(ARQUIVOS[idxArqv], "r");
            sequencial.preencher(file);
            fclose(file);

            file = fopen(ARQUIVOS[idxArqv], "r");
            encadeada.preencher(file);
            fclose(file);
        }
    }
    return true;
}

void Tela::escolherAcao(){

    int opcao;
    bool flag = true;

    while(flag){

        ImprimeOpcoesAcao();
        cin >>  opcao;
        clearCin();

        switch(opcao){

            case 1:
                crud();
                break;
            case 2:
                sorts();
                break;
            case 3:
                salvar();
                break;
            case -1:
                flag = false;
                break;
            default:
               cout << "OPCAO INVALIDA - DIGITE NOVAMENTE" << endl;
               clearCin();
               getchar();
        }

    }
}

void Tela::crud(){

    int opcao, n, rg;
    bool flag = true;
    Pessoa pessoa;

    while(flag){

        ImprimeOpcoesCrud();
        cin >> opcao;
        clearCin();

        switch (opcao){
            case 1:

               cout << "Nome (10): ";
               cin >> pessoa.nome;
               clearCin();
               cout << "RG (9): ";
               cin >> pessoa.rg;
               clearCin();
               
               sequencial.inserirInicio(pessoa);
               encadeada.inserirInicio(pessoa);           

               break;
            case 2:

               cout << "Nome(10): ";
               cin >> pessoa.nome;
               clearCin();
               cout << "RG(9): ";
               cin >> pessoa.rg;
               clearCin();

               sequencial.inserirFim(pessoa);
               encadeada.inserirFim(pessoa);

               break;
            case 3:

               cout << "Nome(10): "; 
               cin >> pessoa.nome;
               clearCin();
               cout << "RG(9): ";
               cin >> pessoa.rg;
               clearCin();
               cout << "Posicao N - max " << sequencial.getTam()-2 << " : ";
               cin >> n;
               clearCin();

               if( n>sequencial.getTam()-2 || n<0){
                  cout << n << " posicao invalida" << endl;
                  break;
               }

               sequencial.inserir(pessoa, n);
               encadeada.inserir(pessoa, n);

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

               cout << "Posicao N - max " << sequencial.getTam()-2 << " : ";
               cin >> n;
               clearCin();

               if(n>sequencial.getTam()-2 || n<0){
                  cout << n << " posicao invalida" << endl;
                  break;
               }

               sequencial.remover(n);
               encadeada.remover(n);

               break;
            case 7:

               cout << "RG(9): ";
               cin >> rg;
               clearCin();

               sequencial.procurarPessoa(rg);
               encadeada.procurarPessoa(rg);

               break;
            case 8:

               sequencial.imprimir();
               encadeada.imprimir();

               break;
            /*case 9:

               file = fopen(SEQ_FILE, "w");
               sequencial.salvarArquivo(file);
               fclose(file);

               file = fopen(ENC_FILE, "w");
               encadeada.salvarArquivo(file);
               fclose(file);

               break;*/
            case -1:
               flag = false;
               break;
            default:
               cout << "OPCAO INVALIDA - DIGITE NOVAMENTE" << endl;
               clearCin();
               getchar();
        }
    }
}

void Tela::sorts(){

    int opcao;
    bool flag = true;

    if(sort.getListSort()){   
        sort.deleteList();
    }

    sort.preencherList(&encadeada);

    while(flag){

        ImprimeOpcoesSort();
        cin >>  opcao;
        clearCin();

        switch(opcao){

            case 1:
                sort.selectionSort();
                break;
            case 2:
                sort.insertionSort();
                break;
            case 3:
                sort.bubbleSort();
                break;
            case 4:
                sort.shellSort();
                break;
            case 5:
                sort.quickSort();
                break;
            case 6:
                sort.mergeSort();
                break;
            case -1:
                flag = false;
                break;
            default:
                cout << "OPCAO INVALIDA - DIGITE NOVAMENTE" << endl;
                clearCin();
                getchar();
        }
    }
}

void Tela::salvar(){
}

void Tela::ImprimeListaArquivos(){
   
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

void Tela::ImprimeOpcoesAcao(){
    
    getchar();
    system("clear");
    cout <<"---- ESCOLHA UMA ACAO ----"<< endl;
    cout <<"1 - CRUD"<< endl;
    cout <<"2 - SORT"<< endl;
    cout <<"3 - SALVAR"<< endl;
    cout <<"*DIGITE -1 PARA SAIR*"<< endl;
    cout <<"Acao 1-3:";
}

void Tela::ImprimeOpcoesCrud(){
    
    getchar();
    system("clear");
    cout <<"---- MENU CRUD ----"<< endl;
    cout <<"1 - Inserir nó no INICIO"<< endl;
    cout <<"2 - Inserir nó no FIM"<< endl;
    cout <<"3 - Inserir nó na posicao N"<< endl;
    cout <<"4 - Remover nó no INICIO"<< endl;
    cout <<"5 - Remover nó no FIM"<< endl;
    cout <<"6 - Remover nó na posicao N"<< endl;
    cout <<"7 - Procurar um nó com o RG"<< endl;
    cout <<"8 - Mostrar lista na Tela"<< endl;
    //cout <<"9 - Salvar lista em um Arquivo"<< endl;
    cout <<"*DIGITE -1 PARA SAIR*"<< endl;
    cout <<"Opcao 1-9:";
}

void Tela::ImprimeOpcoesSort(){

    getchar();
    system("clear");
    cout <<"---- MENU SORT ----"<< endl;
    cout <<"1 - Selection-Sort"<< endl;
    cout <<"2 - Insertion-Sort"<< endl;
    cout <<"3 - Bubble-Sort"<< endl;
    cout <<"4 - Shell-Sort"<< endl;
    cout <<"5 - Quick-Sort"<< endl;
    cout <<"6 - Merge-Sort"<< endl;
    cout <<"*DIGITE -1 PARA SAIR*"<< endl;
    cout <<"Opcao 1-6:";
}

void Tela::clearCin(){
   cin.clear();
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
}