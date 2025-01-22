#include "macros.h"
#include <stdio.h>

void insertionSort (int *v, int l, int r) {
    
}

int main () {
    int tamanhoVetor = 100000;
    Item vetor[tamanhoVetor];
    createVector(vetor, tamanhoVetor);
    printVector(vetor, tamanhoVetor);
    
    insertionSort(vetor, 0, tamanhoVetor-1);
    printVector(vetor, tamanhoVetor);
    return 0;
}