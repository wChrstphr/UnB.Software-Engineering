#include <stdio.h>

int main()
{

    int v[2] = {3, 7};

    printf("%d %d\n", v[0], v[1]);         // 3 7
    printf("%d %d\n", &v, *(v + 1)); //? ?

    return 0;
}