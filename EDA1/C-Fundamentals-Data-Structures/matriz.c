#include <stdio.h>

int main()
{
    // Inicialização na declaração
    int a[][5] = {{10, 6, 7, 12, 11}, {23, 32, 14, 52, 22}, {33, 17, 18, 54, 28}};


    // Inicializa ção por atribui ção
    a[0][0] = 3;
    a[1][4] = 12;

    // Inicializa ção pela entrada padr ão
    int lin, col;
    // para cada linha
    for (lin = 0; lin < 3; lin++)
    {
        // e cada coluna
        for (col = 0; col < 5; col++)
        {
            scanf("%d", &a[lin][col]);
        }
    }
    printf("%d\n", a[1][1]);
    printf("%d\n", a[2][2]);
    printf("%d\n", a[1][3]);
}