#include <stdio.h>

int main()
{
    float dinheiro[5]; // 0 -> 99
    char letras[4];      // 0 -> 3
    int i = 0;

    while (i < 5)
    {
        scanf("%f", &dinheiro[i]);
        i++;
    }


    dinheiro[2] = 1; // acesso direto e aleat ório
    int x = dinheiro[3];

    printf("X: %d\n", x);
    dinheiro[2]++; // opera ções
    printf("\nDinheiro: %f", ++dinheiro[2]);
}