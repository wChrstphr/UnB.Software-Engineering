#include <stdio.h>

void incrementa(void)
{
    int a = 0;
    static int c = -2; // vari ável local , aloc . est á tica
    // alocada uma ú nica vez e
    // vá lida mesmo após o té rmino da fun ção

    printf("a: %d, c: %d\n", a, c);
    a++;
    c++;
}
int main(void)
{
    for (int i = 0; i < 5; i++)
        incrementa();
    return 0;
}
