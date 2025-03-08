#include "macros.h"
#include <stdio.h>

void selectionSort (int *v, int l, int r) {
    if (l>=r) return;
    int min = l;
    for (int i = l+1; i <= r; i++){
        if (less(v[i], v[min])) min = i;
    } 
    exch(v[min], v[l]);
    selectionSort(v, l+1, r);
}

int main () {
    int tamanhoVetor = 100000;
    Item vetor[tamanhoVetor];
    createVector(vetor, tamanhoVetor);
    printVector(vetor, tamanhoVetor);
    
    selectionSort(vetor, 0, tamanhoVetor-1);
    printVector(vetor, tamanhoVetor);
    return 0;
}