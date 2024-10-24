#include <stdio.h>

void imprime_olas()
{
    int a;
    while (scanf("%d", &a) == 1 && a > 0)
    {
        if (a > 1000)
            return;
        while (a-- > 0)
            printf("Ola mundo !\n");
    }
}


int main()
{
    imprime_olas();
}
