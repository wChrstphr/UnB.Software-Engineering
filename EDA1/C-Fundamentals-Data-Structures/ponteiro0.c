#include <stdio.h>

int main()
{
    int i;
    int *p;
    p = NULL;
    p = &i; // diz -se:
    // p aponta para i
    // p referencia a variavel i

    i = 5;

    //*p valor da variavel apontada por p, ou seja , valor de i
    printf("%d\n", *p); //*p eh igual a i
    // saida : 5
    printf("%ld\n", sizeof(p));

    return 0;
}