#include "sort.h"
#include <cstdio>
#include <time.h>

Sort::Sort(){
    tam = 0;
    listSort = nullptr;
    n_atribuicoes = 0;
    n_condicoes = 0;
    tempo = 0;
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
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;
    
    
    for(i=0;i<tam;i++){

        n_condicoes++;

        menor = i;
        n_atribuicoes++;

        for(j=i+1; j<tam; j++){
            
            n_condicoes+=2;

            if(listSort[j]->rg < listSort[menor]->rg){
                menor = j;
                n_atribuicoes++;
            }
        }
        
        n_condicoes++;
        if(menor != i){

            pAux = listSort[i];
            listSort[i] = listSort[menor];
            listSort[menor] = pAux;

            n_atribuicoes += 3;
        }
    }

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nSelection Sort -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);

}

void Sort::insertionSort() {

    int i, j;
    Pessoa *pAux;// Ponteiro auxiliar para armazenar o valor atual a ser posicionado
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    // Laço principal que percorre o vetor da segunda posição até a última
    for (i = 1; i < tam; i++) {
        n_condicoes++;

        // Armazena o elemento atual a ser inserido na posição correta
        pAux = listSort[i];
        n_atribuicoes++;

        // Laço para comparar o elemento com os anteriores e movê-los se necessário
        // O vetor vai sendo deslocado para abrir espaço para o valor de pAux
        for (j = i - 1; j >= 0 && listSort[j]->rg > pAux->rg; j--) {
            n_condicoes+=2;

            listSort[j + 1] = listSort[j]; // Desloca os elementos maiores para a direita
            n_atribuicoes++;
            
        }

        // Coloca o elemento pAux no lugar certo (onde o loop interno parou)
        listSort[j + 1] = pAux;
        n_atribuicoes++;
    }

    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nInsertion Sort -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void Sort::bubbleSort() {
    
    Pessoa* pAux;  // Ponteiro auxiliar para realizar a troca de elementos
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    // Laço externo que percorre o vetor
    for (int i = 0; i < tam - 1; i++) {

        n_condicoes++;
        
        // Laço interno que percorre o vetor até a parte não ordenada
        // O número de comparações diminui a cada iteração do laço externo, já que os maiores elementos vão para o final
        for (int j = 0; j < tam - 1 - i; j++) {

            n_condicoes+=2;
            // Compara os elementos adjacentes, se o elemento da esquerda é maior, realiza a troca
            if (listSort[j]->rg > listSort[j + 1]->rg) {

                // Realiza a troca dos elementos
                pAux = listSort[j];         
                listSort[j] = listSort[j + 1];
                listSort[j + 1] = pAux;

                n_atribuicoes+=3;
            }
        }

        // Após cada iteração do laço externo, o maior elemento está garantido na última posição,
        // portanto o laço interno pode diminuir o número de comparações.
    }
    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nBubble Sort -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void Sort::shellSort() {

    int h, k, i, j;
    Pessoa *pAux;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    h = 1;  // Inicializa o valor de h

    // Laço para calcular o valor inicial de h usando a sequência de Knuth
    while (h < tam) {
        h = h * 3 + 1;
        n_atribuicoes++;
        n_condicoes++;
    }

    // Laço principal que vai diminuindo o valor de h
    for (h /= 3; h >= 1; h /= 3) {
        n_condicoes++;  

        // Processa grupos de elementos separados por h
        for (k = 0; k < h; k++) {
            n_condicoes++;
            
            // Ordena os elementos dentro de cada grupo
            for (i = k + h; i < tam; i += h) {
                n_condicoes++;
                
                pAux = listSort[i];  // Armazena o elemento atual a ser posicionado
                n_atribuicoes++;

                // Laço interno que compara os elementos com o valor de pAux
                for (j = i - h; j >= 0 && listSort[j]->rg > pAux->rg; j -= h) {
                    n_condicoes+=2;

                    // Move os elementos maiores para a direita
                    listSort[j + h] = listSort[j];
                    n_atribuicoes++;
                    
                }

                // Coloca pAux na posição correta
                listSort[j + h] = pAux;
                n_atribuicoes++;
            }
        }
    }
    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nShell Sort -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void Sort::quickSort() {
    clock_t t_1, t_2;
    n_atribuicoes = 0;
    n_condicoes = 0;

    t_1 = clock(); // Marca o início do tempo
    quick(0, tam - 1);
    t_2 = clock(); // Marca o fim do tempo

    tempo = (float)(t_2 - t_1) / CLOCKS_PER_SEC;
    printf("\nQuick Sort -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void Sort::quick(int inicio, int fim) {

    int esquerda = inicio;
    int direita = fim;
    int pivo = listSort[(inicio + fim) / 2]->rg; // Escolha do pivô como elemento central
    n_atribuicoes += 3; // Inicializações

    while (esquerda <= direita) {
        n_condicoes++; // Verificação do loop principal

        // Encontra o elemento na esquerda que deve ser trocado
        while (listSort[esquerda]->rg < pivo) {
            esquerda++;
            n_condicoes++; // Verificação da condição no laço
        }

        // Encontra o elemento na direita que deve ser trocado
        while (listSort[direita]->rg > pivo) {
            direita--;
            n_condicoes++; // Verificação da condição no laço
        }


        n_condicoes++; // Verificação da condição do `if`
        if (esquerda <= direita) {

            // Troca os elementos
            Pessoa* pAux = listSort[esquerda];
            listSort[esquerda] = listSort[direita];
            listSort[direita] = pAux;
            n_atribuicoes += 3; // Troca de elementos

            esquerda++;
            direita--;
        }
    }
    

    // Chamada recursiva para as partições

    n_condicoes++; // Verificação do `if`
    if (inicio < direita) {
        quick(inicio, direita);
    }

    n_condicoes++; // Verificação do `if`
    if (esquerda < fim) {
        quick(esquerda, fim);
    }
}

void Sort::mergeSort() {
    
    int i, j, k,tamAux;
    int esquerda, meio, direita, tamEsq, tamDir;
    Pessoa **listEsq, **listDir;
    clock_t t_1, t_2;

    t_1 = clock();
    n_atribuicoes = 0;
    n_condicoes = 0;

    // Inicializa os vetores temporários como ponteiros nulos
    listEsq = nullptr;
    listDir = nullptr;

    /*Presumi-se que o tamanho do vetor está na potencia de 2, e
    trata as excessões travando a última coordenada da lista direita 
    no final*/
    for(tamAux = 1; tamAux < tam; tamAux *= 2){
        n_condicoes++;

        for(esquerda = 0; esquerda < tam; esquerda += 2*tamAux){
            n_condicoes++;

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

            n_atribuicoes+=6;
            n_condicoes +=2;
            
            for(i=0; i<tamEsq; i++){
                n_condicoes++;

                listEsq[i] = listSort[esquerda + i];
                n_atribuicoes++;
            }
                
            for(j=0; j<tamDir; j++){
                n_condicoes++;

                listDir[j] = listSort[meio + j];
                n_atribuicoes++;
            }
                
            
            i = 0;
            j = 0;
            for(k = esquerda; i<tamEsq && j<tamDir; k++){
                n_condicoes+=2;

                if(listDir[j]->rg < listEsq[i]->rg){
                    listSort[k] = listDir[j];
                    j++;
                }
                else{
                    listSort[k] = listEsq[i];
                    i++;
                }
                n_atribuicoes++;
            }

            while(i<tamEsq){
                n_condicoes++;

                listSort[k] = listEsq[i];
                i++;
                k++;

                n_atribuicoes++;
            }

            while(j<tamDir){
                n_condicoes++;

                listSort[k] = listDir[j];
                j++;
                k++;

                n_atribuicoes++;
            }

            delete[] listEsq;
            delete[] listDir;

            listEsq = nullptr;
            listDir = nullptr;
        }
    }
    t_2 = clock();
    tempo = (float)(t_2-t_1) / CLOCKS_PER_SEC;
    printf("\nMerge Sort -> Tempo: %fs | Condicoes: %d | Atribuicoes: %d\n", tempo, n_condicoes, n_atribuicoes);
}

void Sort::salvarArquivo(FILE *file){
    
    int i;

    if(listSort == nullptr){
        printf("LISTA ORDENADA NULA\n");
        return;
    }
    
    for(i=0; i<tam; i++)
        fprintf(file,"%s %d\n",listSort[i]->nome,listSort[i]->rg);
    
    printf("LISTA ORDENADA-> SALVA COM SUCESSO\n");
}