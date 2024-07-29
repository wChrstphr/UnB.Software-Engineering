#include <stdlib.h>
#include <malloc.h>
/*
Crie uma biblioteca em linguagem C chamada VetoresC.c com as seguintes funções/procedimentos: 
a. Função CriaVetInt para alocação de vetores do tipo int. Esta função deverá receber a quantidade de 
elementos do vetor e retornar o ponteiro para o vetor alocado;  
b. Função CriaVetFloat para alocação de vetores do tipo float. Esta função deverá receber a quantidade 
de elementos do vetor e retornar o ponteiro para o vetor alocado; 
*/

void createVectInt (int **pointerReturned, int sizeVect) {
    int *pVect;
    pVect = (int*) malloc (10*sizeof(sizeVect));
    if (pVect == NULL){
        printf("Insufficient memory available!\n");
    } else {
        printf("Memory space alocated succesfully for your Flaot!\n");
    }
}

void createVectFloat (int **pointerReturn, int sizeVect) {
    float *pVect;
    pVect = (int*) malloc (10*sizeof(sizeVect));
    if (pVect == NULL){
        printf("Insufficient memory available!\n");
    } else {
        printf("Memory space alocated succesfully for your Int!\n");
    }
}