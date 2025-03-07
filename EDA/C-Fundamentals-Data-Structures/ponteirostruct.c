#include <stdio.h>
typedef struct
{
    int dia;
    int mes;
    int ano;

} Data;

typedef struct
{
    char name [20];
    int idade;
    int CPF;
    Data nascimento;

} Pessoa;

int main()
{

    Pessoa pessoa1;
    Pessoa *ptr = &pessoa1;

    // vari á vel simples
    pessoa1.nascimento.dia = 02; // campo acessado por ‘. ’

    // conte údo do apontado por ptr = vari á vel simples
    (*ptr).nascimento.mes = 01; // campo acessado por ‘.’

    // acesso ao campo pelo ponteiro
    ptr->nascimento.ano = 2002; // setinha ->

    printf("%d\n", pessoa1.nascimento.dia); // saída ??
    printf("%d\n", pessoa1.nascimento.mes); // saída ??
    printf("%d\n", pessoa1.nascimento.ano); // saída ??
    return 0;
}
