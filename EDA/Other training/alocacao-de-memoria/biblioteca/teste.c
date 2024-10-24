// compilar : gcc teste .c libvariaveis .o
// executar : ./a. out
#include "variaveis.h"

extern int var1; // global de variaveis .c
int var2;

int main()
{
    printf("%d\n", var1);          // 1
    printf("%d\n", retornaVar1()); // 1
    printf("%d\n", retornaVar2()); // 2

    var1 = 4;
    printf("%d\n", var1);          // 4
    printf("%d\n", retornaVar1()); // 4

    var2 = 5;
    printf("%d\n", var2);          // 5
    printf("%d\n", retornaVar2()); // 2
    return 0;
}