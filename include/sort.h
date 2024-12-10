#include "listaEnc.h"
#include "pessoa.h"

class Sort{

    Pessoa* *listSort;
    int tam;
    
    float tempo;
    int n_atribuicoes;
    int n_condicoes;

private:

    // Função auxiliar que realiza a recuraao das sublistas
    void quick(int inicio, int fim);

public:

    Sort();
    ~Sort();

    void preencherList(ListaEnc* pL = nullptr);
    void deleteList();
    Pessoa** getListSort() const;
    
    void selectionSort();
    void insertionSort();
    void bubbleSort();
    void shellSort();
    void quickSort();
    void mergeSort();

    void salvarArquivo(FILE *file);
    
};