#include <string.h>
#include <stdio.h>

void f(int a)
{
    printf("%d\n", a);
}

void f2(int a)
{
    printf("%d\n", a + 1);
}

int main(int argc, char **argv)
{
    void (*fp)(int);

    if (argc > 1 && strcmp(argv[1], "f") == 0)
        fp = &f;
    else
        fp = &f2;

    (*fp)(10);

    void (*funcoes[2])(int) = {&f, &f2};
    for (int i = 0; i < 2; i++)
        (*funcoes[i])(i);

    return 0;
}