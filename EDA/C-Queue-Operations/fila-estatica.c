#include <stdio.h>

#define TAM 7

int fila[TAM];
int p, u;

// A fila vai de fila [p...u-1] 7 posições [0...6]
// Quando a fila chega ao final, ou seja, se u+1 == TAM, u passa a valer 0 (fila circular)
// Para a ideia de lista estática circular
// Fila cheia: u+1 == p ou (u+1 == TAM e p == 0)
// ou seja, se (u+1) % TAM == p
// Fila vazia: u == p
void criar_fila () {
    p = u = 0;
}

int vazia (){
    return p == u;
    // Retorna 0 se p == u = vazia
}

void insere_fim (int x) { // enfileira
    fila[u++] = x;
    // insere o elemento na última posição fila[u] e depois incrementa para a posição "nula" da fila (ou seja, o fim da fila)
    if (u == TAM) u = 0;
}

int remove_inicio () { // desenfileira
    int x = fila[p++];
    // retorno o elemento em fila [p] e depois incremento para a prox. posição
    if (p == TAM) p = 0;
    return x;
}
int busca_inicio () { // primeiro
    return fila[p++];
    // retorno o elemento em fila [p] e depois incremento para a prox. posição
}

int busca_fim () { // ultimo
    return fila[--u];
}


int main()
{
    int y = vazia();
    if (y == 1) {
        printf("Lista vazia\n");
    } else {
        printf("A lista contem %d elementos\n", p-u);
    }
    printf("%d\n", p);
    printf("%d\n", u);

    insere_fim(5);
    insere_fim(12);

    printf("%d\n", p);
    printf("%d\n", u);

    int x = busca_inicio();

    y = vazia();
    if (y == 1) {
        printf("Lista vazia\n");
    } else {
        printf("A lista contem %d elementos\n", u);
    }

    printf("%d\n", x);
    return 0;
}




