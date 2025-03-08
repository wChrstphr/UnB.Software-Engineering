#include <stdio.h>

int main()
{
    char nome1[100];
    char nome2[100];
    char nome3[100];
    printf("Nome1");
    scanf("%s", nome1); // sem & : vetor = endereco da 1a posicao
    // lendo 1 sequencia de caracteres ( palavra )
    // ate encontar ‘ ’, \t, \n


    printf("Nome2");
    scanf("%99s", nome2); // le no maximo 99 caracteres seguidos
    // ou ate encontrar ‘ ’, \t, \n

    printf("Nome3");
    scanf("Estrutura de %s", nome3);


    // especificador de formato : %s
    printf("%s %s %s\n", nome1, nome2, nome3);
}
