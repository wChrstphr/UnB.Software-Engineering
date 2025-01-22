#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct {
    Item *item;
    int primeiro, ultimo;
} Fila;

Fila *criar ( int maxTam ) {
    Fila *p = malloc(sizeof(Fila));
    p->item = malloc(maxTam*sizeof(Item));
    p->primeiro = p->ultimo = 0;
    return p;
}

int vazia ( Fila *f) {
    return f->primeiro == f->ultimo;
}

void enfileira ( Fila *f, Item x ) {
    printf("%d\n", f->ultimo);
    f->item[f->ultimo++] = x;
    printf("%d\n", f->ultimo);
}

Item desenfileira ( Fila *f, Item x ) {
    return f->item[f->primeiro++];
}

void imprime ( Fila *f ) {
    printf("\nFILA p = %d e u = %d\n", f->primeiro, f->ultimo);
    for (int i=f->primeiro; i < f->ultimo; i++) 
        printf(" F [%d] |", i);
    printf ("\n");

    for (int i=f->primeiro; i < f->ultimo; i++)
        printf(" %3d   |", f->item[i]);
    printf("\n");
}

// void redimensiona ( Fila *f ) {
//     int maxTam = maxTam * 2;
//     int *novo = malloc (maxTam * sizeof (int));

//     int j = 0;
//     for (int i = f->primeiro; i < f->ultimo; i++, j++)
//        novo_item[f->primeiro] = fila [i];
// }

int main () {
    printf("\n\nCriando a fila e enfileirando 10 elementos");
    Fila *fila1 = criar(9);
    for (int i = 0; i < 15; i++) enfileira(fila1, i);
    imprime(fila1);
    desenfileira(fila1, 5);
    imprime(fila1);

    int x = vazia(fila1);
    printf("\n%d\n", x);
}