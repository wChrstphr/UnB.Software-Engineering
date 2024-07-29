#include <stdio.h>
#include "myBib.h"

int main()
{
    /*
    int a = 32;
    int *ptr;
    ptr = &a;
    printf("Valor de a: %d\n", *ptr);
    *ptr = 10;
    printf("Valor de a depois de derreferencia: %d\n", *ptr);
    */
    int *myInt;
    createVectInt(&myInt, 100);
    free(myInt);
    return 0;
}