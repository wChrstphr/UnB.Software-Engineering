#include <stdio.h>

struct endereco
{
    char rua[50];
    int num;
};

void imprimir_endereco(struct endereco); // par â metro
struct endereco ler_endereco();          // retorno

int main()
{
    struct endereco e;
    e = ler_endereco();
    imprimir_endereco(e);
    return 0;
}
// retornar struct
struct endereco ler_endereco()
{
    struct endereco ender;
    scanf("%s", ender.rua);
    scanf("%d", &ender.num);
    return ender;
}
// por valor = somente conteudo
void imprimir_endereco(struct endereco ender)
{
    printf("%s\n", ender.rua);
    printf("%d\n", ender.num);
    ender.num = 20; // nao altera a original
    printf("%d\n", ender.num);
}