#include "sort.h"
#include <cstdio>

Sort::Sort(){
    tam = 0;
    listSort = nullptr;
}

Sort::~Sort(){
    
    deleteList();
}

void Sort::preencherList(ListaEnc* pL){
    
    PessoaEnc* pAux;

    if(pL){

        tam = pL->getTam();
        pAux = pL->getPPrimPessoa();

        listSort = new Pessoa*[tam];

        for(int i = 0; i<tam; i++){

            if(pAux){
                listSort[i] = &(pAux->pessoa);
                pAux = pAux->pPrxP;
            }
            
        }
    }
}

void Sort::deleteList(){

    if(listSort){

        delete[] listSort;
        listSort = nullptr;
    }
}

Pessoa** Sort::getListSort()const{
    return listSort;
}

void Sort::selectionSort(){

    int i, j, menor;
    Pessoa* pAux;
    
    if(listSort == nullptr)
        return;
    
    for(i=0;i<tam;i++){

        menor = i;
        for(j=i+1; j<tam; j++){
            
            if(listSort[j]->rg < listSort[menor]->rg)
                menor = j;
        }
        
        if(menor != i){

            pAux = listSort[i];
            listSort[i] = listSort[menor];
            listSort[menor] = pAux;
        }

        pAux = nullptr;
    }

    imprimir();
}

void Sort::insertionSort(){
    
    int i, j;

    Pessoa *pAux;

    for(i=1;i<tam;i++){

        pAux = listSort[i];

        for(j = i - 1; j >= 0 && listSort[j]->rg > pAux->rg ; j--){
                
            listSort[j+1] = listSort[j]; // passa pra frente
        }

        listSort[j+1] = pAux; //coloca no lugar certo

    }
    imprimir();
}

void Sort::bubbleSort(){

}

void Sort::shellSort(){

}

void Sort::quickSort(){

}

void Sort::mergeSort(){

    int i, j, k,tamAux;
    int esquerda, meio, direita, tamEsq, tamDir;
    Pessoa **listEsq, **listDir;

    listEsq = nullptr;
    listDir = nullptr;

    /*Presumisse que o tamanho do vetor está na potencia de 2, e
    trata as excessões travando a última coordenada da lista direira 
    no final*/
    for(tamAux = 1; tamAux < tam; tamAux *= 2){

        for(esquerda = 0; esquerda < tam; esquerda += 2*tamAux){

            direita = esquerda + (tamAux*2 - 1); // coordenada final da lista direita
            meio = esquerda + tamAux; //coordenada inicial da lista direita

            if(direita > tam-1)//Trava na última coordenada
                direita = tam- 1;
                
            if(meio > tam-1)//Trava na última coordenada
                meio = tam-1;

            tamEsq = meio - esquerda;
            tamDir = direita - (meio-1);

            listEsq = new Pessoa*[tamEsq];
            listDir = new Pessoa*[tamDir];
            

            for(i=0; i<tamEsq; i++)
                listEsq[i] = listSort[esquerda + i];
            for(j=0; j<tamDir; j++){
                listDir[j] = listSort[meio + j];
            }
                
            
            i = 0;
            j = 0;
            for(k = esquerda; i<tamEsq && j<tamDir; k++){

                if(listDir[j]->rg < listEsq[i]->rg){
                    listSort[k] = listDir[j];
                    j++;
                }
                else{
                    listSort[k] = listEsq[i];
                    i++;
                }
            }

            while(i<tamEsq){
                listSort[k] = listEsq[i];
                i++;
                k++;
            }

            while(j<tamDir){
                listSort[k] = listDir[j];
                j++;
                k++;
            }

            delete[] listEsq;
            delete[] listDir;

            listEsq = nullptr;
            listDir = nullptr;
        }
    }
    imprimir();
}

void Sort::imprimir(){

    for(int i = 0; i<tam; i++){
        printf("%s - rg: %d - %d\n", listSort[i]->nome, listSort[i]->rg, i);
    }

}