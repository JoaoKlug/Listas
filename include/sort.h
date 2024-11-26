#include "listaEnc.h"
#include "pessoa.h"

class Sort{

    Pessoa* *listSort;
    int tam;

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
    
    void imprimir();
};