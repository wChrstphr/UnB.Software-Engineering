#include <stdio.h>
int *fa()
{
    static int a = -9;
    int *i = &a;
    return i;
}

int *fb()
{
    static int a = 1;
    int *i = &a;
    return i;
}

void fc()
{
    int s[10] = {0}; // stack ou data ?
    for (int i = 0; i < 10; i++)
    {
        printf("%d", s[i]);
    }
}

int main()
{
    int *b = fa();
    int *c = fb();
    fc();
    //int b = *b;
    //int c = *c;
    printf("\n%d %d", *b, *c); // saí das ??
    return 0;   
}
