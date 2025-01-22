#ifndef _MACROS_H
#define _MACROS_H
#include <stdlib.h>
#include <stdio.h>

typedef int Item;
#define Key(A) (A) // (A.chave) em caso de structs
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if (less(A,B)) exch (A,B);}

void createVector (Item *vector, int vectorSize) {
    for (int i = 0; i <= vectorSize; i++)
        vector[i] = rand();
}

void printVector(Item *vector, int vectorSize){
    for (int i = 1; i <= vectorSize; i++) 
        printf ("%dº->%d\n", i, vector[i]);
}

#endif