#include <stdio.h>
void clear();

int main()
{
    int num;
    int i;
    int cont;
    char option;
    do
    {
        printf("\nType a number to know if it's a prime: \n");
        scanf("%d", &num);
        cont = 1; // Aqui já contabilizo que o numero é divisível por 1
        for (i = 2; i <= num; i++)
        {
            if (num % i == 0) {
                cont++;
            } 
        }
        if (cont == 2)
            printf("%d is prime!\n", num);
        else
            printf("%d isn't prime.\n", num);
        printf("Do you want to test another number: (Y/N)\n");
        clear();
        option = getchar();
    } while (option == 'Y' || option == 'y');
    return 0;
}

void clear (void)
{
    while ( getchar() != '\n' );
}