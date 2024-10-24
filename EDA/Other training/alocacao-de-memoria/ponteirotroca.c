#include <stdio.h>

void troca (int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main (){
    int a = 3, b = 10;

    printf("%d %d", a, b);
    troca(&a, &b);
    printf("\n%d %d", a, b);
}