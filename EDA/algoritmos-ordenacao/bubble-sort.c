#include "macros.h"

void bubbleSort (int *v, int l, int r){
    static int changes = 0;
    if (l >= r) return;
    do {
        for (int j = l; j < r; j++){
            if (less(v[j+1], v[j])){
                exch (v[j+1], v[j])
                changes++;
            }
        }
    } while (!changes); //changes != 0;
    bubbleSort (v, l, r-1);
}

int main () {
    long long tamanhoVetor = 30;
    Item vetor[tamanhoVetor];
    createVector(vetor, tamanhoVetor);
    printVector(vetor, tamanhoVetor);

    bubbleSort(vetor, 0, tamanhoVetor-1);
    printVector(vetor, tamanhoVetor);
    return 0;
}