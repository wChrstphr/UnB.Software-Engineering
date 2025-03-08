// arquivo : variaveis .c
// redigindo as funções definidas em variaveis.h
// compilar : gcc -c variaveis .c -o libvariaveis .o
#include "variaveis.h"

int var1 = 1;        // variável global , aloc. estatica
static int var2 = 2; // variável está tica global , aloc. estática
// acessível somente no arquivo

int retornaVar1()
{
    return var1;
}

int retornaVar2()
{
    return var2;
}
